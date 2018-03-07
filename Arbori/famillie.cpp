///arbore cu rude
///nod stg tata
///nod dreapta mama
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
char t[100];
ifstream fin("date.in");
struct nod
{
    char nume[100];
    nod *st,*dr;
}*varful;
nod *creare()
{
    char s[100];
    fin>>s;
    nod *c=new nod;
    if(s[0]!='.')
    {
        nod *c=new nod;
        strcpy(c->nume,s);
        c->st=creare();
        c->dr=creare();
        return c;
    }
    else
        return 0;
}
void RSD(nod *p)
{
    if(p!=0)
    {
        if(strcmp(t,p->nume);
            {
                if(p->st)
                {
                    cout<<"bunicii din partea tatalui ";
                    if(p->st->st)
                        cout<<p->st->st->nume<<" si ";
                    else
                        cout<<"nu exista";
                    if(p->st->dr)
                        cout<<p->st->dr->nume<<endl;
                    else
                        cout<<"nu exista";
                }
                if(p->dr)
                {
                    cout<<"bunicii din partea mamei ";
                    if(p->dr->st)
                        cout<<p->dr->st->nume<<" si ";
                    else
                        cout<<"nu exista";
                    if(p->dr->dr)
                        cout<<p->dr->dr->nume<<endl;
                    else
                        cout<<"nu exista";
                }
            }
    }
}
