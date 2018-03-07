#include<iostream>
#include<cstring>
using namespace std;
char E[100],e[100];
int P[100],p[100];
struct nod{
char inf;
nod *st,*dr;
}*rad;

nod *creare(int li,int ls, char e[100],int p[100]);
void SDR(nod *c);
int main()
{
    cout<<"Expresia: ";
    cin>>E;
    int j=0,i;

    for(i=0;i<strlen(E);i++)
    {
        switch(E[i])
        {
            case'(':j=j+10;break;
            case')':j=j-10;break;
            case'+':P[i]=j+1;break;
            case'-':P[i]=j+1;break;
            case'*':P[i]=j+10;break;
            case'/':P[i]=j+10;break;
            case'%':P[i]=j+10;break;

            default:P[i]=1000;
        }
    }
    j=0;
    for(i=0;i<strlen(E);i++)
        if(E[i]!=')' && E[i]!='(')
    {
        e[j]=E[i];
        p[j]=P[i];
        j++;
    }
    rad=creare(0,j-1,e,p);
    SDR(rad);
    return 0;
}
nod *creare(int li,int ls, char e[100],int p[100])
{
    int mini,poz,i;
    mini=p[ls];
    poz=ls;
    for(i=ls;i>=li;i--)
        if(p[i]<mini)
    {
        mini=p[i];
        poz=i;
    }
    nod *c=new nod;
    c->inf=e[poz];
    if(li==ls)
        c->st=c->dr=0;
    else
    {
        c->st=creare(li,poz-1,e,p);
        c->dr=creare(poz+1,ls,e,p);
    }
    return c;
}
void SDR(nod *c)
{
    if(c!=0)
    {
        SDR(c->st);
        SDR(c->dr);
        cout<<c->inf<<" ";
    }
}

/// ORDINEA EFECTUARII OPERATILOR INTR-O EXPRESIE ARITMETICA SCRISA IN POSTORDINE SDR .
int main()
{
    int k=0,i,j=0;
    fin>>e;
    for(i=0;i<strlen(e);i++)
        if(e[i]>='a' and e[i]<='z')
    {
        k++;
        st[k][0]=e[i];
        st[k][1]=' ';
    }
        else {
            cout<<"x"<<j<<" "<<"="<<st[k-1][0]<<st[k-1][1]<<e[i]<<st[k][0]<<st[k][1]<<endl;
            k--;
            st[k][0]='x';
            itoa(j,sir,10);
            st[k][1]=sir[0];
            j++;
        }
}
