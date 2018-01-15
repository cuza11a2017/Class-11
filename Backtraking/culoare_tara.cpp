#include <iostream>
#include <fstream>
using namespace std;
ifstream in ("date.in");
int n,a[20][20],x[10]={1,2,3,4},sol;
void af(){
for (int i=0;i<n;i++)
    cout << "Tara "<<i<<" are culoare "<<x[i];
cout << endl;
sol++;
}

int valid(int k){
for(int i=0;i<k;i++)
    if(a[i][k]==1 and x[i]==x[k])
        return 0;
return 1;
}

void bk(int k){
for (int i=1;i<=4;i++){
    x[k]=i;
    if(valid(k))
        if(k==n)
        af();
    else
        bk(k+1);
}

}

int main()
{
int i,j;
cin >> n;
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    in >> a[i][j];
    bk(1);
    cout << endl << sol;
}
