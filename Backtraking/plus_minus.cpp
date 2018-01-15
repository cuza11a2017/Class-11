#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("date.in");
///pg 19 pb 8
///se citesc de la tastatura un nr nat n si n nr nat
///sa se af toate posib de a intercala intre toate cele n nr operatorii + si - a.i evaluand expresia obtinuta de la stanga la dr la fiecare pas, rez sa fie >0
int n,x[20],sol;
void print()
{
    for(int i=1;i<=n;i++)
        if(x[i]<0)cout<<x[i];
        else if(i!=1)cout<<"+"<<x[i];
        else cout<<x[i];
    cout<<endl;
    sol++;
}
int valid(int k)
{
    int s=0;
    for(int i=1;i<=k;i++)
        s+=x[i];
    if(s<=0)return 0;
    return 1;
}
int backt(int k)
{
    for(int i=1;i>=-1;i-=2)
    {
        x[k]=i*x[k];
        if(valid(k))
            if(k==n)
                print();
            else backt(k+1);
    }
}
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
        fin>>x[i];

    backt(1);
    cout<<"sunt "<<sol<<" solutii";
}
