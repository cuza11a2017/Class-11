#include <iostream>
#include <cstring>
using namespace std;
struct nod{
    int fr;
    char s[100][100];
    nod *st,*dr;
}*rad,*aux;

void inserare(nod*& vf, char k[])
{
    if(vf)
        if(strlen(k)!=strlen(vf->s[1]))
            {if(strlen(vf->s[1])>strlen(k))
                inserare(vf->st,k);
            else
                if(strlen(vf->s[1])<strlen(k))
                    inserare(vf->dr,k);
                }
            else
            {
                
               vf->fr++;
               strcpy(vf->s[vf->fr],k);
            }
        else{
            vf=new nod;
            strcpy(vf->s[1],k);
            vf->fr=1;
            vf->st=vf->dr=0;
            
        }
}


void parc (nod *&r)
{
  if(r)
  {
    parc(r->st);
    for(int i=1;i<=r->fr;i++)
        cout<<r->s[i]<<" ";
    parc(r->dr);
  }
}

int main ()
{
    char k[100];
    while(cin>>k)
    inserare(rad,k);
    parc(rad);
}
