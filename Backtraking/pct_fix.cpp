///fie s o permutare de ordin n, n>=1
///1<k<n, pct fix
///toate perm de ord n care au exact P pct fixe. af nr ac perm
#include <iostream>
using namespace std;
int x[50],n,sol,p;
int valid(int k)
{
    int i;
    int nr=0;
    for(i=1;i<k;i++)
        {if(x[i]==x[k])
        return 0;
        if(x[i]==i)
            nr++;
        }
        if(x[i]==k)
            nr++;
        if(nr>p)
            return 0;
        if(k==n && nr!=p)
            return 0;
    return 1;
}
void af(int k)
{
    for(int i=1;i<=n;i++)
    cout<<x[i]<<" ";
    cout<<endl;
    sol++;
}
void backt(int k)
{
    for(int i=n;i>=1;i--)
    {
        x[k]=i;
    if(valid(k)==1)
        if(k==n)
            af(k);
    else
        backt(k+1);
    }

}



int main()
{
    cout<<"n= ";
    cin >>n;
    cout<<endl<<"p=";
    cin>>p;
    backt(1);
    cout <<sol<<" solutii";
    return 0;
}
