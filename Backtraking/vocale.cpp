#include<fstream>
#include<cstring>
/// FIST
using namespace std;
int x[10],sol,n;
char s[20],v[]="aeiouAEIOU";
void afisare(int k)
{
    for(int i=0; i<=k; i++)
        cout<<s[x[i]];
    cout<<endl;
    sol++;
}
int valid(int k)
{
    for(int i=0; i<k; i++)
    {
        if(x[i]==x[k]) return 0;
    }
    if(strchr(v,s[k])==0 and x[k]!=k)
        return 0;

    return 1;
}
void bk(int k)
{
    int i;
    for(i=0; i<strlen(s); i++)
    {
        x[k]=i;
        if(valid(k))
            if(k==strlen(s)-1)
                afisare(k);
            else bk(k+1);
    }
}
int main()
{
    cin>>s;
    bk(0);
    cout<<sol;
}
