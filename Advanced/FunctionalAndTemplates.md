# Programare Functionala si Generica

> Duplicate code is the root of all evil in software design. When a system is littered with many snippets of indentical, or nearly identical code, it is indicative of sloppiness, carelessness, and sheer unprofessionalism. It is the guilt-edged responsibility of all software developers to root out and eliminate duplication whenever they find it.<br>
> -- *Uncle Bob*

### Ideea este simpla: **NU DA COPY PASTE**
Pentru a rezolva problema dam ca parametru/argument variabila diferita dintre functiile asemanatoare.

Exemplu simplu:
```cpp
int max10(int a){
    if(a > 10)
        return a;
    else return 10;
}
int max54(int a){
    if(a > 54)
        return a;
    else return 54;
}
```
Devine:
```cpp
int max(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}
```
## Aicisa sunt exemple care arata cum sa aplicam principiul DRY (don't repeat yourself)
O sa folosim structura aceasta intensiv.
```cpp
struct vector_int {
    int data[100];
    int size;
    vector_int(int x): size(x) {  }
};

bool este_prim(int);
```

Ok, avem o functie care modifica o varibila globala.
```cpp
vector_int v1(100);

void filterPrim_v1()
{
    for (int i = 0; i < v1.size; i++) {
        if (!este_prim(v1.data[i])) {
            for (int j = i; j < v1.size; j++) {
                v1.data[j] = v1.data[j + 1];
            }
            v1.size--;
        }
    }
}
```

Dar mai incolo declaram alt vector, si facem o functie noua.
```cpp
vector_int v2(50);

void filterPrim_v2()
{
    for (int i = 0; i < v2.size; i++) {
        if (!este_prim(v2.data[i])) {
            for (int j = i; j < v2.size; j++) {
                v2.data[j] = v2.data[j + 1];
            }
            v2.size--;
        }
    }
}
```
Din pacate, tocmai ai violat princiul DRY si ai esuat in viata, naspa, esti o dezamagire pentru rasa umana, bitch.  
Dar nu fi depresiv tinere ~~idiot~~ programator, poti sa-ti speli pacatele cu apa sfintita si prin parametrizarea(dai ca argument) variabilei diferite, crearea unei functii noi si eradicare pe rug a functiilor pacatoase.
```cpp
void filterPrim(vector_int& vec)
{
    for (int i = 0; i < vec.size; i++) {
        if (!este_prim(vec.data[i])) {
            for (int j = i; j < vec.size; j++) {
                vec.data[j] = vec.data[j + 1];
            }
            vec.size--;
        }
    }
}
```
Acum ca stii ca nu vei fi ucis in somn de alti programatori care iti citesc codul, putem continua...  
Ce? Vrei sa filtrezi un vector pe mai multe criterii? Si faci o functie noua care are in `if` o alta conditie?
```cpp
void filterPar(vector_int& vec)
{
    for (int i = 0; i < vec.size; i++) {
        if (!este_par(vec.data[i])) {
            for (int j = i; j < vec.size; j++) {
                vec.data[j] = vec.data[j + 1];
            }
            vec.size--;
        }
    }
}
```
Singura diferenta dintre `filterPar` si `filterPrim` este conditia din `if` care este o functie... Cum ar trebui sa o dam ca argument?  
Pai... tipul variabilei vec este `vector_int`, iar tipul unei functii este `int f(int)`.  
Asta inseamna ca vom lua ca argument o functie `bool f(int)`; `bool` deoarece verificam o conditie, functia se va numi *predicat*; denumirea este o conventie si se foloseste pentru functiile care verifica o conditie.
```cpp
void filter_int(vector_int& vec, bool predicat(int))
{
    for (int i = 0; i < vec.size; i++) {
        if (!predicat(vec.data[i])) {
            for (int j = i; j < vec.size; j++) {
                vec.data[j] = vec.data[j + 1];
            }
            vec.size--;
        }
    }
}
```
In loc de `filterPrim(v1)`, `filterPar(v2)` si alte functii, vom folosi:
```cpp
bool este_par(int);
bool este_palindrom(int);
bool este_patrat(int);

void f() {
    // treaba
    filter_int(v1, este_par);
    filter_int(v2, este_palindrom);
    filter_int(v3, este_patrat);
    filter_int(v4, este_prim);
    // mai multa treaba
}
```

Timpul trece, pasarele canta, cazi, te lovesti cu capul de o piatra si incepi sa crezi ca esti Eminemscu.  
Ai nevoie de un vector cu `string`-uri!
```cpp
struct vector_string {
    std::string data[100];
    int size;
    vector_string(int x): size(x) {  }
} cuvinte(300), versuri(50), strofe(13);
```
Pisica ta, Ceciliu, a pasit pe tastatura si ti-a ruinat poezia!
Faci o functie care filtreaza poezia de cuvinte generate de talpita pisicii.
```cpp
bool CuvantCareNuEsteGenetatDeTalpitaPisicii(string);
bool CuvantVulgar(string);
void filter_string(vector_string& vec, bool predicat(std::string))
{
    for (int i = 0; i < vec.size; i++) {
        if (!predicat(vec.data[i])) {
            for (int j = i; j < vec.size; j++) {
                vec.data[j] = vec.data[j + 1];
            }
            vec.size--;
        }
    }
}

void f(){
    // treaba ;)
    filter_string(cuvinte, CuvantCareNuEsteGenetatDeTalpitaPisicii);
    filter_string(cuvinte, CuvantVulgar);
    filter_string(versuri, CuvantCareNuEsteGenetatDeTalpitaPisicii);
    filter_string(strofe, CuvantCareNuEsteGenetatDeTalpitaPisicii);
    // treaba ;)
}
```

Ce este sunetul acela?  
Vine dinspre geam...  
Este un programator furios care incearca sa sparga greamul si sa intre in casa ca sa-ti fure colectia de gay porn!  
Repede!  
Impresioneaza-l ;) prin aplicarea principiului DRY!  
Dar cum?  
Doar tipul vectorului si al functiei predicat este diferit in functia `filter_int` si `filter_string`.
    
---
> Bara! Nu mai folosi `template`!  
> -- *Un om intelept*

```cpp
template <typename T>
T max(T a, T b){
    if(a > b) return a;
    return b;
}
void f(){
    int a = max(4, 5);
    float f = max(23.5, 43.2);
    string s = max<string>("asdf", "ma-ta");
}
```
* Pentru a da ca argument un tip folosim `template`
* `typename` declara o *variabila de tipuri* `T` care va fi inlocuit cu un tip: `int`, `string`, `point`
* `T` poate fi dedus de functie si nu trebuie neaparat specificat `max<int>(3, 4)`

---

* Tipul functiilor ca argument poate si el sa fie dedus: `F`
* Declarare: `vector<int> v(4);`
* Tipul lui `v`: vector<int>
* Folosinta: normal
* Poti sa faci o matrice cu `vector<vector<int>> matrix` 
* O alta varianta pentru argumentele lui filter ar fi `void filter(vector<T>& vec, bool predicat(T))`
```cpp
template <typename T>
struct vector {
    T data[100];
    int size;
    vector(int x) : size(x) {  }
};

template<typename T, typename F>
void filter(vector<T>& vec, F predicat)
{
    for (int i = 0; i < vec.size; i++) {
        if (!predicat(vec.data[i])) {
            for (int j = i; j < vec.size; j++) {
                vec.data[j] = vec.data[j + 1];
            }
            vec.size--;
        }
    }
}

struct point { int x, y; };
bool aproape_de_origine(int);

void f(){
    vector<int> numere(40);
    vector<string> cuvinte(50); 
    vector<point> puncte(100);
    filter(numere, este_prim);
    filter(cuvinte, CuvantCareNuEsteGenetatDeTalpitaPisicii);
    filter(puncte, aproape_de_origine);
}
```

Daca ai un `struct` sau `class` `template` si definesti o functie in afara clasei faci asa:
```cpp
template <typename T, typename U>
class pair {
public:
    T first;
    U second;
    pair(T, U);
};

template <typename T, typename U>
pair::pair(T x, U y) : first(x), second(y) { }
```

Cam atat.
