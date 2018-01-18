#include <iostream>
#include <fstream>
/*
 6
1 2 4
1 5 3
1 6 2
2 3 1
2 4 2
3 4 4
3 5 12
3 6 9
4 6 8
5 6 8

 */
int n,m,h[50],cost;
using namespace std;
ifstream fin("Kruskal.in");
struct muchie
{
    int x,y,c;
}u[50];
void citire ()
{
    int x,y,c;
    fin>>n;
    while (fin>>x>>y>>c)
    {
        u[++m].x=x;
        u[m].y=y;
        u[m].c=c;
    }
}
void ordonare() {
    for (int i = 1; i < n; i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            if (u[i].c>u[j].c)
                swap(u[i],u[j]);
        }
    }
}
void reuneste (int x,int y)
{
    int k;
    x=h[x];
    y=h[y];
    for (k=1;k<=n;k++)
        if (h[k]==x)
            h[k]=y;
}
void kruskal ()
{
    int k;
    for (k=1;k<=n;k++)
        h[k]=k;
    ordonare();
    for (k=1;k<=m;k++) {
        int x, y, c;
        x = u[k].x;
        y = u[k].y;
        c = u[k].c;
        if (h[x]==h[y])
            continue;
        reuneste (x,y);
        cost +=c;
        cout<<"Media"<<u[k].x<<" "<<u[k].y<<"cost"<<u[k].c<<endl;
    }
    cout<<"cost min"<<cost;
}
int main() {
    citire();
    kruskal();
    return 0;
}
