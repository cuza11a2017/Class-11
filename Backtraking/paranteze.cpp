///-1=( 
/// 1=)
#include<iostream>
using namespace std;
int x[50],n,sol;
int valid(int k)
{
    int s=0;
    for(int i=1;i<=k;i++)
        s+=x[k];
    if(s!=0 and k==n)
        return 0;
    if(s>0)
        return 0;
    return 1;
}
void af()
{
    for(int i=1;i<=n;i++)
        if(x[i]==1)
            cout<<")";
        else
            cout<<"(";
}
int bkt(int k)
{
    int s=0;
    for(int i=-1;i<=1;i+=2)
    {x[k]=i;
    for(int i=1;i<=k;i++)
        s+=x[k];
    if(valid(k))
        if(k<n)
            bkt(k+1);
        else
            af();}
}
int main()
{
    cin>>n;
    bkt(1);
    
}
