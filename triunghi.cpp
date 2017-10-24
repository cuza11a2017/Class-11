#include<iostream>
#include<fstream>
using namespace std;
int t[50][50],s[50][50],n;
ifstream f("triunghi.in");

void citire()
{
    f>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            f>>t[i][j];
}

void prelucrare()
{
    int i,j;
    for(j=1; j<=n; j++)
        s[n][j]=t[n][j];
    for(i=n-1; i>=1; i--)
        for(j=1; j<=i; j++)
        {
            s[i][j]=t[i][j]+s[i+1][j];
            if(s[i+1][j]<s[i+1][j+1])
                s[i][j]=t[i][j]+s[i+1][j+1];
        }
}

void drum(int i,int j)
{
    if(i<=n and j<=n)
    {
        cout<<t[i][j]<<" ";
        if(s[i+1][j]>s[i+1][j+1])
            drum(i+1,j);
        else
            drum(i+1,j+1);
    }
}

int main()
{
    citire();
    prelucrare();
    cout<<s[1][1]<<endl;
    drum(1,1);
}
