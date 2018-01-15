#include <iostream>
#include <fstream>
using namespace std;
int n,a[50],b[50],x,x0;
ifstream fin("ciori.in");
void citire ()
{
    fin>>n;
    for (int i=1;i<=n;i++){
        fin>>a[i];
    if (a[i]==0)
        x0=i;}
        for (int i=1;i<=n;i++)
            fin>>b[i];}
int poz (int k)
{
    for (int i=1;i<=n;i++)
        if (b[k]==a[i])
            return i;
}
int main()
{
    citire();
    for (int i=1;i<=n;i++)
    {
        if (a[i]!=b[i])
        {
            if (a[i]!=0 and b[i]!=0)
            {
              int x=poz(i);
            cout<<"cioara "<<a[i]<<" zboara de pe copacul "<<i<<" pe copacul "<<x0<<endl;
            cout<<"cioara "<<a[x]<<" zboara de pe copacul "<<x<<" pe copacul "<<i<<endl;
            swap(a[i],a[x0]);
            swap(a[i],a[x]);
            x0=x;
            }

        }
    }
}
