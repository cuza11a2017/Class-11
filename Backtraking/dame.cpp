#include <iostream>
#include <cmath>
///se dau n dame  si in toate modurile posibile sa se aseze damele cat sa nu se atace.
using namespace std;

int n,sol,x[10];

void afisare()
{
    int i,j;
     for(i=1;i<=n;i++)
     {
         for(j=1;j<=n;j++)
            if(j==x[i])
                cout<<"D";
            else
                cout<<".";
        cout<<endl;
     }
     cout<<"-------------------"<<endl;
     sol++;
}
int validare(int k)
{
    for(int i=1;i<k;i++)
    {
        if(x[i]==x[k])
            return 0;
        if(abs(k-i)==abs(x[k]-x[i]))
            return 0;
    }
    return 1;
}
void bk(int k)
{
    int i;
    for(i=1;i<=n;i++)
    {
        x[k]=i;
        if(validare(k))
            if(k==n)
                afisare();
        else bk(k+1);
    }
}
int main()
{
    cout<<"n=";
    cin>>n;
    bk(1);
    cout<<"Sunt "<<sol<<" solutii";
}
