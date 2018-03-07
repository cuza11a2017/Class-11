#include<iostream>
using namespace std;
 struct nod
 {
     int info;
     nod *dr,*st;
 }*rad;

void inserare(nod *&v,int k)
{
    if(v)
    {
        if(v->info!=k)
            if(v->info>k)
            inserare(v->st,k);
            else inserare(v->dr,k);
    }
    else
    {
        v=new nod;
        v->info=k;
        v->st=0;
        v->dr=0;

    }
}
void SRD(nod *c)
{
    if(c!=0)
    {
        SRD(c->st);
        cout<<c->info<<" ";
        SRD(c->dr);
    }
}
int main()
{
    int n,p;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>p;
        inserare(rad,p);
    }
    SRD(rad);
}
