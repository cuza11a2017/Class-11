//subsir cel mai lung cresc -PD
#include <iostream>
using namespace std;
int n=7,l[50];
int v[50] = { 8, 0, 3, 9, 4, 11, 12};
int main()
{
    /*
    cin>>n;
    for(int i=1;i<=n;i++)
       cin>>v[i];*/
    l[n]=1;
    for(int k=n-1; k>=1; k--)
    {
        int maxx=0;
        for(int i=k+1; i<=n; i++)
            if(v[k]<=v[i] and l[i]>maxx)
                maxx=l[i];
        l[k]=maxx+1;
    }
    int poz,maxxx=0;
    for(int i=1; i<=n; i++)
        if(l[i]>maxxx)
        {
            maxxx=l[i];
            poz=i;
        }
    cout<<v[poz]<<" ";
    for(int i=poz+1; i<=n; i++)
        if(l[i]==l[poz]-1 and v[i]>=v[poz])
        {
            cout<<v[i]<<" ";
            poz=i;
        }
}
