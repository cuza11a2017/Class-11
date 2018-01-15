#include <iostream>
#include<cmath>
using namespace std;
int x[20],sol,n;
void afisare(int k)
{
    for(int i=1;i<=k;i++)
        cout<<x[i]<<" ";
        cout<<endl;
        sol++;
}
int valid(int k)
{
    if(k>1 && abs(x[k]-x[k-1])!=1)
        return 0;
    if((k==1 && x[k]!=0) ||(k==n && x[k]!=0))
        return 0;
    return 1;
}
void bk(int k)
{
    for(int i=0;i<=9;i++)
    {
        x[k]=i;

        if(valid(k))
        if(k==n)

                afisare(k);
            else
                bk(k+1);

    }
}
int main()
{
    cin>>n;
    bk(1);
    cout<<sol<<" solutii";
}
