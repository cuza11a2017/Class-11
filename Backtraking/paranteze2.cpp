#include <iostream>
///nr nat par n
///sa se afiseze toate parantezele care se inchid corect
using namespace std;

int x[100],n,sol;

void afis(){
for(int i=1;i<=n;i++)
    if(x[i]==-1)
    cout << "(";
    else
        cout << ")";
    sol ++;
    cout << endl;
}

int suma(int k){
    int s=0;
for(int i=1;i<=k;i++)
    s=s+x[i];
return s;
}

int valid (int k){
for (int i=1;i<=k;i++){
    if(suma(k)>0)
        return 0;
        if(k==n and suma(k)!=0)
            return 0;}
        return 1;

}

void bk (int k){
for(int i=1;i<=2;i++){
if(i==2)
    x[k]=-1;
    else
        x[k]=1;
    if(valid(k))
        if(k==n)
            afis();

        else
            bk(k+1);
}

}

int main()
{
   cin >> n;
   bk(1);
   cout << endl << sol;
}
