# Constructori (ctor)

### Default Constructor
```cpp
struct point {
    // default value
    int x = 0;
    int y;
};

struct stack {
    int size;
    int data[100];
    stack() { size = 0; };
    int pop();
    void push();
};

int main()
{
    point p; // x este 0
    p.y = 0;
    stack s; // size este 0
}
```
---
### Parameterized Constructor
```cpp
struct point {
    int x;
    int y;
    point(int x, int y) { 
        this->x = x; 
        this->y = y;
    }
};

void f() {
    point p(4, 6);
}
```
---
### Copy Constructor
```cpp
struct point {
    int x;
    int y;
    point(int x, int y) {
        // this->var este variabila obiectului, x simplu este parametru
        this->x = x; 
        this->y = y;
    }
    // copy ctor
    // 'const' inseamna read-only, nu se modifica
    point(const point& p) {
        x = p.x;
        y = p.y;
    }
    point& operator=(const point& p) {
        x = p.x;
        y = p.y;
        return *this;
    }
};

struct point2 {
    int x, y;
    point2& operator=(const point2& p) {
        x = p.x;
        y = p.y;
        return *this;
    }

    point2(const point2& p) {
        // dirty trick
        // pointerul 'this' arata catre obiectul curent 
        // asa ca folosim operatorul= definit anterior pt copy ctor
        *this = p;
    }
};

void f() {
    point p(5, 4);
    point a(p);  // copy ctor
    point b = p; // operator =
    // de obicei cele doua functii au implemetari identice
}
``` 
---
### Lista de initializare
```cpp
struct point {
    int x, y;
    point(int a, int b) : x(a), y(b) { }
};

struct point2 {
    int x, y;
    // argumetele pot avea acelasi nume ca si variabilele membru
    point(int x, int y) : x(x), y(y) { }
}

```
---
### Destructor (dtor)
```cpp
struct point {
    int x, y;
    ~point() { cout << "pa"; }
};

int main()
{
    // ceva treaba
    point p;
    // mai multa treaba
} // acum este apelat dtor si afiseaza 'pa'
```
Este folositor in alocarea dinamica, dtor-ul poate sterge automat valoarea alocata cand variabila nu mai este folosita.  
```cpp
struct vector {
    int* data;
    int size;
    vector(int s) : size(s) {
        data = new int[size];
    }
    ~vector() {
        delete[] data;
    }
};

void treaba()
{
    vector v(10); // alocam 10 elemente
    // ceva treaba cu vectorul
} // vectorul este sters automat
```

## Exemplu
Uite si un exemplu util si folositor: un vector care isi mareste dimesiunea.
```cpp
class vector {
    // sunt private implicit deoarece este o clasa
    int* data;
    int size;
    int cap;  // capacitate
public:
    vector() : size(0), cap(0), data(NULL) { }

    vector(int size, int elem = 0) : size(size), cap(size), data(new int[size]) {
        for(int i=0; i<size; i++)
            data[i] = elem;
    }

    vector& operator=(const vector& v) : size(v.size), cap(v.size) {
        for(int i = 0; i < size; i++)
            data[i] = v.data[i];
        return *this;
    }

    vector(const vector& v) {
        *this = v;
    }

    int size() {
        return size;
    }

    void push_back(int);

    int& at(int i){
        if(i < 0 || i >= size)
            abort(); // ar trebui sa fie 'throw OutOfBoundsExeption()' dar inca nu am explicat 'try-catch'
        return data[i];
    }
    
    /* acum putem scrie:
     * vector v(10); v[4] = 69;
     * in loc de: v.data[4] = 69;
     * returnam o referinta ca sa putem modifica variabila direct
    */
    int& operator[](int i){
        return data[i];
    }

    ~vector() {
        delete[] data;
    }
};

void vector::push_back(int x)
{
    if(cap <= size){
        cap *= 2;
        int* new_data = new int[cap];
        for(int i=0; i<size; i++)
            new_data[i] = data[i];
        new_data[size] = x;
        delete[] data;
        data = new_data;
    } else {
        data[size] = x;
    }
    size++;
}

int f() {
    vector v(2, 69); // are 2 elemte cu valoarea 69
    v.push_back(54);
    v.push_back(23); // marime: 4
    vector a(v); // copiat
    return a[3];
}
```
Cam atat.