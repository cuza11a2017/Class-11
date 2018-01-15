///pb turelor
#include <iostream>
using namespace std;
int x[100],sol,n;

int valid(int k)
{
    for(int i=1;i<k;i++)
        if(x[i]==x[k]) return 0;


    return 1;
}
void afisare(int k)
{
for(int i=1;i<=n;i++)
    {for(int j=1;j<=n;j++)
        if(j==x[i])
        cout<<"T";
    else cout<<".";

cout<<endl;}
cout<<endl;
sol++;
}
void bk(int k)
{
    int i;
    for(i=1;i<=n;i++)
    {
        x[k]=i;
        if(valid(k))
            if(k==n)
                afisare(k);
            else bk(k+1);
    }
}
int main()
{
    cin>>n;
    bk(1);
    cout<<endl<<sol;

}
