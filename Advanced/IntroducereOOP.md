# Definitie ~~proasta~~

> Un obiect este o structura de date asociata cu mai multe functii ce o modifica. `struct` cu functii plm, struct cu functii...

In C++, keyword-ul `struct` si `class` pot fi schimbate fara sa afecteze codulul; au acelasi rol, fac acelasi lucru, exista doua denummiri pentru acelasi lucru din motive istorice.</br>
Singura diferenta este: `struct` are vizibilitatea `public` ca default, `class` are `private`.</br>
Asta este singura diferenta, vorbesc serios.</br>
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
Doar pentru ca `struct` si `class` pot fi interschimbate nu inseamna ca este bine sa le amestecam.<br>
O conventie folosita des spune ca folosim `struct` pentru tipuri de date simple si `class` pentru tipuri complexe.

---
Aici aproape avem un obiect, o structua + functii ce modifica argumentul prin referinta.
`assert()` este definit in `<cassert>`, daca conditia este falsa atunci `exit()` este apelat.

``` cpp
struct stack {
    int size;
    int data[100];
};

void init(stack& s) {
    s.size = 0;
}

// insereaza in fundul vectorulul o variabila
void push(stack& s, int x){
    assert(s.size < 100);
    s.data[s.size] = x;
    s.size++;
}

// returneaza ultima valoare
// de ce '-1'? daca 'size' este 1 atunci valoarea din varf este 'data[0]'
int top(stack& s) {
    return s.data[s.size - 1];
}

// sterge din stack si returneaza ultima valoare
int pop(stack& s) {
    assert(s.size >= 0);
    int val = top(s);
    s.size--;
    return val;
}

int main() {
    stack s;
    init(s);
    push(s, 54);
    push(s, 69);
    cout << s.size << endl; // 2
    cout << pop(s) << endl; // 69
    cout << s.size << endl; // 1
}
```

---

Pentru ca suntem masochisti, o sa schimbam referintele cu **pointeri**.
Logica codului este acceasi, dar in loc de `.` folosim `->` si dam adresa variabilei ca argument.

``` cpp
struct stack {
    int size;
    int data[100];
};

void init(stack* s) {
    s->size = 0;
}

void push(stack* s, int x){
    assert(s->size < 100);
    s->data[s->size] = x;
    s->size++;
}

int top(stack* s) {
    return s->data[s->size - 1];
}

int pop(stack* s) {
    assert(s->size > 0);
    s->size--;
    return s->data[s->size];
}

int main() {
    stack s;
    init(&s);
    push(&s, 54);
    push(&s, 69);
    cout << s.size << endl; // 2
    cout << pop(&s)<< endl; // 69
    cout << s.size << endl; // 1
}
```

---

Inainte sa purcedem, o sa schimbam numele argumentului din `s` in `this`.
`this` este numele pe care compilatorul il alege pentru pointerul catre obiect.

```cpp
int pop(stack* this) {
    assert(this->size > 0);
    this->size--;
    return this->data[this->size];
}
```

Pentru transformare completa a codului:
* Mutam functiile pe care vrem sa le asociem cu tipul de data, in corpul structurii, functiile se vor numi functii membru.
* Stergem argumentul cu pointer catre structura, nu ne atingem de restul argumentelor (daca mai sunt).
* Pointerul `this` se refera la obiectul curent.
* Putem omite (din lene) pointerul `this` atunci cand ne referim la variabile din structura.
* Apelam functia membru cu sintaxa `s.push(3)` in loc de `push(s,3)`.
* Functia `init` are denumirea de *constructor*, iar in C++ se declara cu acelasi nume ca structura; este apelat la declararea obiectului.</br>
Exemlu simplu:
```cpp
struct pair {
    int x, y;
};
void add(pair* p, int a) {
    p->x += a;
    p->y += a;
}
```
Devine:
```cpp
class pair {
public:
    int x, y;
    void add(int a) {
        // 'this' poate fi omis
        this->x += a;
        y += a;
    }
};
```

Exemplu mai mare:
```cpp
class stack {
public:
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

    int top() {
        return this->data[size - 1];
    }

    int pop() {
        assert(this->size > 0);
        this->size--;
        return this->data[this->size];
    }
};

int main() {
    stack s; // constructorul este apelat
    s.push(54);
    s.push(69);
    cout << s.size << endl; // 2
    cout << s.pop()<< endl; // 69
    cout << s.size << endl; // 1
}
```

---

Dar ce avem mai jos? Este un ~~dobitoc~~ progratamator neatent care modifica marimea stack-ului, si astfel, ~~fute~~ strica programul.
```cpp
void f(stack& s){
    s.push(78);
    s.size = 0;
    s.push(54);
}

```
Ca sa impiedicam ~~dobitocul~~ persoana neatenta din a strica programul, facem variabilele private, si functiile publice.  
Doar o functie membru sau `friend` poate modifica sau accesa o variabila privata.
```cpp
class stack {
private:
    int size;
    int data[100];
public:
    stack() { size = 0; }
    void push(int x);
    friend void print(stack&);
    //...
};

void f(stack& s){
    // da eroare de compilare (asta si vrem)
    s.size = 1000;
}

void print(stack& s){
    for(int i = 0; i < s.size; i++)
        cout << s.data[i] << " ";        
}

```
---
Daca declaram doar numele functiei in `class` sau `struct`, si definitia in afara clasei atunci punem <nume-clasa>::<nume-functie>, fie ea functie, operator sau contructor.
```cpp
class pair{
    int x, y;
public:
    pair(int, int);
    pair operator+(pair);
    void print();
};

point::point(int a, int b) {
    x = a;
    y = b;
}

pair pair::operator(point p) {
    point tmp;
    tmp.x = this->x + p.y;
    tmp.y = this->y + p.y;
    return tmp;
}
void pair::print(){
    cout << x << ' ' << y;
}
```
Cam atat.
