#include <iostream>
#include<fstream>
using namespace std;
int n,c;
ifstream f("rucsac.in");
struct ob
{
    int p,d,poz;
}a[20];
void ordonare_citire()
{
    f>>n>>c;
    for(int i=1;i<=n;i++)
        {f>>a[i].p>>a[i].d;
        a[i].poz=i;}


    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
           if(a[i].p/(a[i].d * 1.0) < a[j].p/(a[j].d * 1.0))
             swap(a[i],a[j]);
}

int main()
{int i;
float S[20];
ordonare_citire();
    for(i=1;i<=n;i++)
        S[i]=0;
    i=1;
    while(c>0 && i<=n)
{
    if(c>=a[i].d)
    {   S[a[i].poz]=1;
        c=c-a[i].d;
    }
    else
    {   S[a[i].poz]=c/(a[i].d * 1.0);
        c=0;
    }
        i++;
}
      for(i=1;i<=n;i++)
            cout<<a[i].poz<<" ** "<< S[a[i].poz]<<endl;

}
