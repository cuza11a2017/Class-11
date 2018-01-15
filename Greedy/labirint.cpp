#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("date.in");

struct{
    int x, y;
} stack[100];

struct{
    int val;
    bool visited;
} harta[10][10];

int n, m;

void print(int k)
{
    for(int i=1; i<=k; i++){
        printf("(%d, %d)\n", stack[i].x, stack[i].y);
    }
}

void back(int k, int x, int y)
{
    if( 0 == n || n+1 == x || 0 == y || m+1 == y)
        print(k);
    else{
        stack[k] = { x, y };
        harta[x][y].visited = true;

        for(int i=1; i<=4; i++){
            switch(i)
            {
            case 1:
                if(harta[x][y].val & 8 && harta[x][y].visited) // nord
                    back(k+1, x-1, y); break;
            case 2:
                if(harta[x][y].val & 4 && harta[x][y].visited) // est
                    back(k+1, x, y+1); break;
            case 3:
                if(harta[x][y].val & 2 && harta[x][y].visited) // sud
                    back(k+1, x, y-1); break;
            case 4:
                if(harta[x][y].val & 1 && harta[x][y].visited) // vest
                    back(k+1, x+1, y); break;
            }
        }
    }
}

int main()
{
    fin >> n >> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            fin >> harta[i][j].val;
}
