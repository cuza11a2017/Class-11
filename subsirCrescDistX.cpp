#include <iostream>
using namespace std;

int n=6,l[50];
int x=4;
int v[50] = {0, 5, 7, 9, 10, 14, 15};

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
            if(v[k]+x<=v[i] and l[i]>maxx) // aici +x
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
        if(l[i]==l[poz]-1 and v[i]>=v[poz]+x) // aici +x
        {
            cout<<v[i]<<" ";
            poz=i;
        }
}
