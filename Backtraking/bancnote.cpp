/**
plata unei sume folosind n bancnote/ money/mdnbjioasdbdaskhdsfah
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("uasfhhofsa.in");
int sol,n,x[1000],s,a[1000],b[1000];
void afisare(int k)
{
    for(int i=1;i<=k;i++)
        if(x[i]!=0)
        cout<<x[i]<<" Bancnote de "<<a[i]<<" lei"<<endl;
    cout<<endl;
    sol++;
}
void citire()
{
    fin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        fin>>a[i];
        b[i]=s/a[i];
    }
}
int valid(int k)
{
}
int bkt(int k,int suma)
{
    for(int i=1;i<=b[k];i++)
    {
        x[k]=i;
        suma = suma + x[k] * a[k];
        if(suma<=s)
            if(k<=n and suma==s)
                afisare(k);
            else
                bkt(k+1,suma);
    }
}
int main()
{
    citire();
    bkt(1,0);
    cout<<endl<<sol;
}
