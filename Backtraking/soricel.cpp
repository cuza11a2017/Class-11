///soricel in m linii n coloane
///peretii=1
///culoar=0
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("labirint.txt");
struct pozitie
{
    int x,y;
};
int a[50][50];///labirintul
int vx[4]={-1,0,1,0};
int vy[4]={0,1,0,-1};
pozitie d[50];///drum
int n,m,Li,Ci,sol;
void citire()
{
    fin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        fin>>a[i][j];
    fin>>Li>>Ci;
}
void afis_mat()
{
    cout<<endl;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
void tipar(int k)
{
    cout<<"solutia "<<++sol<<endl;
    for(int i=1;i<=k;i++)
        cout<<"("<<d[i].x<<","<<d[i].y<<")";
    afis_mat();
    cout<<endl;
}
int valid(int k,int x,int y)
{
 if(a[x][y]==1 || a[x][y]==2)
        return 0;
 return 1;
}
void bk(int k,int x,int y)
{
    if(x==0 || y==0 || x==m+1 || y==n+1)
    {
        d[k].x=x;
        d[k].y=y;
        tipar(k);
    }
    else
        for (int i=0;i<4;i++)
    {
        d[k].x=x;
        d[k].y=y;
        a[x][y]=2;
        if(valid(k,x+vx[i],y+vy[i])==1)
            bk(k+1,x+vx[i],y+vy[i]);
        a[x][y]=0;
    }
}
int main()
{
    citire();
    bk(1,Li,Ci);
    return 0;
}
