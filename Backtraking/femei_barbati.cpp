#include <iostream>

using namespace std;
int n,f,l,p,x[50],sol=0;
void af(int k)
{
    for (int i=1;i<=k;i++)
        if(x[i]<=f)
            cout<<"f"<<x[i]<<" ";
        else
            cout<<"b"<<x[i]<<" ";
        cout<<endl;
        sol++;
}
int valid(int k)
{
    int ent=0;
    for(int i=1;i<=k;i++)
        if(x[i]<=f)ent++;
    if(ent>l)
        return 0;
    if(k==p and ent!=l)
        return 0;
    return 1;
}
void backt(int k)
{
    for (int i=x[k-1]+1;i<=n;i++)
    {
        x[k]=i;
        if(valid(k))
            if(k==p)
                af(k);
            else
                backt(k+1);
    }

}
int main()
{
    cout<<"n=";
    cin>>n;
    cout<<"f=";
    cin>>f;
    cout<<"p=";
    cin>>p;
    cout<<"l=";
    cin>>l;
    backt(1);
    cout<<"sunt"<<sol<<"solutii";

}
