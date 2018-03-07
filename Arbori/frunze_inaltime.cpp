#include<iostream>
using namespace std;
int h;
struct nod
{
    int nr;
    nod *st,*dr;
}*v;

nod *creare()
{
    int x;
    cout<<"x=";cin>>x;
    cout<<endl;
    if(x!=0)
    {
        nod *p=new nod;
        p->nr=x;
        cout<<"Stanga:";
        p->st=creare();
        cout<<"Dreapta:";
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

void frunze(nod *p)
{
    if(p!=0)
    {
        if(p->st==0 && p->dr==0)
            cout<<p->nr<<" ";
        frunze(p->st);
        frunze(p->dr);
    }
}

void inaltime(nod *p,int i)///i=nivel
{
    if(p!=0)
    {
        if(p->st==0 && p->dr==0)
            if(i>h) h=i;
        inaltime(p->st,i+1); inaltime(p->dr,i+1);
    }
}

void nod_nivel(nod *p,int i,int k)
{

    if(p!=0)
    {
        if(i==k)
        cout<<p->nr<<" ";
        nod_nivel(p->st,i+1,k);
    nod_nivel(p->dr,i+1,k);
    }
}

int main()
{
    v=creare();
    RSD(v);
    cout<<endl;
    frunze(v);
    cout<<endl;
    inaltime(v,0);
    cout<<"inaltimea:"<<h<<endl;
    int k;
    cin>>k;
    nod_nivel(v,0,k);

}
