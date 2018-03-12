# Definitie ~~proasta~~

> Un obiect este o structura de date asociata cu mai multe functii ce o modifica. `struct` cu functii plm, struct cu functii...

Aici aproape avem un obiect, o structua + functii ce modifica parametrul prin referinta.  
Acesta poate fi considerat un obiect in C, in C++ exista sintaxa speciala.  
Codul ar trebui sa se explice singur...
``` cpp
struct stack {
    int size;
    int data[100];
};

void init(stack& s) {
    s.size = 0;
}

void push(stack& s, int x){
    if(s.size >= 100)
        abort();
    s.data[s.size] = x;
    s.size++;
}

int pop(stack& s) {
    assert(s.size > 0);
    s.size--;
    return s.data[s.size];
}

int main() {
    stack s;
    init(s);
    push(s, 6);
    push(s, 3);
    cout << s.size << endl;
    cout << pop(s)  << endl;
    cout << s.size << endl;
}
```
Note:
* functia `abort` este definita in `<cstdlib>` ,si DA, face ce crezi ca face
* `assert` este definit in `<cassert>`, iar daca conditia este falsa atunci `abort` este apelat

---
Pentru ca suntem masochisti, o sa schimbam referintele cu **pointeri**.  
Logica codului este acceasi, dar acum apar mai multe sageti si dam adresa variabilei ca parametru.
``` cpp
struct stack {
    int size;
    int data[100];
};

void init(stack* s) {
    s->size = 0;
}

void push(stack* s, int x){
    if(s->size >= 100)
        abort();
    s->data[s->size] = x;
    s->size++;
}

int pop(stack* s) {
    assert(s->size > 0);
    s->size--;
    return s->data[s->size];
}

int main() {
    stack s;
    init(&s);
    push(&s, 6);
    push(&s, 3);
    cout << s.size << endl;
    cout << pop(&s)  << endl;
    cout << s.size << endl;
}
```

---
Inainte sa purcedem, o sa schimbam numele parametrului din `s` in `this`
```cpp
int pop(stack* this) {
    assert(this->size > 0);
    this->size--;
    return this->data[this->size];
}
```
Pentru transformare completa a codului in paradigma de obiecte:
* Mutam functiile pe care vrem sa le asociem cu tipul de data, in corpul structurii
* Stergem parametrul cu pointer catre structura, de restul argumentelor (daca mai sunt) nu ne atingem
* Pointerul `this` se refera la obiectul care este modificat de o functie
* Putem omite (din lene) pointerul `this` atunci cand ne referim la variabile din structura
* Apelam functia obiectului cu sintaxa `s.push(3)` in loc de `push(s,3)`
* Functia *init* are denumirea de *constructor*, iar in C++ se declara cu acelasi nume ca structura; este apelat la declararea obiectului
```cpp
struct stack {
    int size;
    int data[100];
    
    // constructorul
    stack() {
        this->size = 0;
    }

    void push(int x){
        if(size >= 100)
            abort();
        data[size] = x;
        size++;
    }

    int pop() {
        assert(this->size > 0);
        this->size--;
        return this->data[this->size];
    }
};

int main() {
    stack s; // contructorul este apelat
    s.push(6);
    s.push(3);
    cout << s.size << endl;
    cout << s.pop()<< endl;
    cout << s.size << endl;
}
```

---

Dar ce avem mai jos? Este un ~~dobitoc~~ progratamator neatent care modifica marimea stack-ului, si astfel, ~~fute~~ strica programul.
```cpp
void f(stack& s){
    s.push(78);
    s.size = 0;
    s.data[1000] = 4;
    s.push(6);
}

```
Ca sa impiedicam ~~dobitocul~~ persoana neatenta din a strica programul, facem variabilele private, si functiile publice.  
Doar o functie din corpul structurii poate modifica sau accesa o variabila privata
```cpp
class stack {
private:
    int size;
    int data[100];
public:
    stack() { size = 0; }
    void push(int x);
    //...
};

void f(stack& s){
    // da eroare de compilare (asta si vrem)
    s.size = 1000;
}
```

--- 
In C++, keyword-ul `struct` si `class` pot fi schimbate fara sa afecteze logica codului; au acelasi rol, fac acelasi lucru; exista doua denummiri pentru acelasi lucru din motive istorice.  
Singura diferenta este: `struct` are vizibilitatea `public` ca default, `class` are `private`.
Asta inseamna ca urmatoarele doua definitii sunt echivalente:

```cpp
struct vec {
private:
    ...
};

class vec {
    ...
};
```

Si urmatoarele sunt echivatele:
```cpp
struct vec{
    ...
};

class vec{
public:
    ...
};
```
Cam atat.