#include <iostream>
using namespace std;

/**
 * TUTORIAL DINAMICA cu fibonacci
 */

/// size_t este un int foarte mare
size_t fibs[100];
size_t fib_rapid(int nr)
{
    if(nr == 0 || nr == 1)
        return 1;
    else if(fibs[nr] != 0) /// daca valoarea exista returneaz-o
        return fibs[nr];
    else{
        fibs[nr] = fib_rapid(nr - 1) + fib_rapid(nr - 2); /// daca nu exista: pula
        return fibs[nr];
    }
}

size_t fib_prost(int nr)
{
    if(nr == 0 || nr == 1)
        return 1;
    else
        return fib_prost(nr - 1) + fib_prost(nr - 2);
}

/**
 * ideea este ca fib_rapid SALVEAZA in vector rezultatele
 * ca sa nu fie recalculate
*/

int main()
{
    /// vezi diferenta de viteza/timp
    //cout << fib_prost(46);
    //cout << fib_rapid(46);
}
