#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
int st[50],dr[50],n;
void citire ()
{
    fin>>n;
    for (int i=1;i<=n;i++)
        fin>>st[i];
    for (int i=1;i<=n;i++)
        fin>>dr[i];
}
void RSD (int x)
{
    if (x!=0)
    {
        cout<<x<<" ";
        RSD (st[x]);
        RSD (dr[x]);
    }
}
void SRD (int x)
{
    if (x!=0)
    {
        SRD (st[x]);
        cout<<x<<" ";
        SRD (dr[x]);
    }
}
void SDR (int x)
{
    if (x!=0)
    {
        SDR (st[x]);
        SDR (dr[x]);
        cout<<x<<" ";
    }
}
int main() {
    citire();
    RSD(1);
    cout<<endl;
    SRD(1);
    cout<<endl;
    SDR(1);
    cout<<endl;
}
