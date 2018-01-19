#include<iostream>
#include<fstream>
#define INF 1000
using namespace std;
ifstream fin("Prim.in");
int a[50][50],c[50],s[50],n,cost;
void cit()
{
    int i,j,k;
    fin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j)
                a[i][j]=INF;
    while(fin>>i>>j>>k)
        a[i][j]=a[j][i]=k;
}
void Prim(int x)
{
    int y,i;
    for(i=1;i<=n;i++)
        c[i]=a[x][i];
    s[x]=1;
    cout<<x<<" ";
    while(1)
    {
        int mini=INF;
        for(i=1;i<=n;i++)
            if(s[i]==0 && c[i]<mini)
            {
                mini=c[i];
                y=i;
            }
        if(mini==INF)
            break;
        cost+=c[y];
        cout<<y<<" ";
        s[y]=i;
        for(i=1;i<=n;i++)
            if(c[i]>a[y][i])
                c[i]=a[y][i];
    }
}

int main()
{
    cit();
    Prim(1);
    cout<<endl<<cost;
}
