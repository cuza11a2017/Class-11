#include<iostream>
#include<fstream>
using namespace std;
int triunghi[50][50],suma[50][50],n;
ifstream f("triunghiriunghi.in");

void citire()
{
    f>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            f>>triunghi[i][j];
}

void prelucrare()
{
    int i,j;
    for(j=1; j<=n; j++)
        suma[n][j]=triunghi[n][j];
    for(i=n-1; i>=1; i--)
        for(j=1; j<=i; j++)
        {
            suma[i][j]=triunghi[i][j]+suma[i+1][j];
            if(suma[i+1][j]<suma[i+1][j+1])
                suma[i][j]=triunghi[i][j]+suma[i+1][j+1];
        }
}

void drum(int i,int j)
{
    if(i<=n and j<=n)
    {
        cout<<triunghi[i][j]<<" ";
        if(suma[i+1][j]>suma[i+1][j+1])
            drum(i+1,j);
        else
            drum(i+1,j+1);
    }
}

int main()
{
    citire();
    prelucrare();
    cout<<suma[1][1]<<endl;
    drum(1,1);
}
