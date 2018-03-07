#include<iostream>
using namespace std;
struct nod
{
    int nr;
    nod *st,*dr;
};
nod *creare()
{
    int x;
    cout<<"x=";cin>>x;
    cout<<endl;
    if(x!=0)
    {
        nod *p=new nod;
        p->nr=x;
        cout<<"Stanga ";
        p->st=creare();
        cout<<"dreapta ";
        p->dr=creare();
        return p;
    }
    else return 0;
}

void RSD(nod *p)
{
    if(p!=0)
    {
        cout<<p->nr<<" ";
        RSD(p->st);
        RSD(p->dr);
    }
}
int main()
{
    nod* v=creare();
    RSD(v);
}
