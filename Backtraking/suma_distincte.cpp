#include <iostream>
#include<fstream>
#include<cmath>
// sa se af tote nr formate din cifre dist cu prop ca suma cifrelor e egala cu s
using namespace std;
int x[100],sol,s,n;
void cit()
{
    cin>>s;
    if(s<9)
        n=s;
    else
        n=9;
}
void af(int k)
{
    int p=1;
    for (int i=1; i<=k; i++)
        {
            cout<<x[i];
            p=p*x[i];
        }
    cout<<endl;
    if(p!=0)
    {
       for (int i=1; i<=k; i++)
        {
            cout<<x[i];
        }
        cout<<0;
        cout<<endl;
        sol++;
    }
    sol++;
}
int val(int k,int su)
{
    if(x[1]==0)
        return 0;
    for(int i=1; i<k; i++)
        if(x[i]==x[k])
            return 0;
    if(su>s)
        return 0;
    return 1;

}

void bk(int k,int su)
{
    for (int i=0; i<=n; i++)
    {
        x[k]=i;
        if(val(k,su+x[k]))
            if(su+x[k]==s)
                af(k);
            else
                bk(k+1,su+x[k]);
    }
}
int main()
{
   cit();
   bk(1,0);
   cout<<sol;
}
