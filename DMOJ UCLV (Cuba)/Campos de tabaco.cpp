/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

//\\ SGTREE \\//

#define left l, m, node * 2
#define right m + 1, r, node * 2 + 1

//\\ PRINCIPAL \\//

#define ll long long
#define ull unsigned long long
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)

//\\ VECTOR \\//

#define pb push_back
#define ff first
#define sec second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ordenar(x) sort( x.begin(), x.end() )
#define ordenarA(x) sort( x, x + n )
#define med (left + right)/2

//\\ OPERACIONES RAPIDAS \\//

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d\n",n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s\n",s)

//\\ COORDENADAS TÍPICAS \\//

int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,1,0,-1,1,0,-1};

int main(){

    int n, m, q, i, j, x1, y1, x2, y2;
    sff(n, m); sf(q);
    int matriz[n][m], tabla[n][m];

    for ( i = 0; i < n; i++)
        for ( j = 0; j < m; j++){
            sf(matriz[i][j]);
            if ( matriz[i][j] < 0 )
                matriz[i][j] = 0; // evitar los ceros
        }


    int final = 0;

    for ( i = 0; i < n ; i++){
        for ( j = 0; j < m; j++) {
            tabla[i][j] = matriz[i][j];
            if (i > 0) 
                tabla[i][j] += tabla[i - 1][j];
            if (j > 0) 
                tabla[i][j] += tabla[i][j - 1];
            if (i > 0 && j > 0) 
                tabla[i][j] -= tabla[i - 1][j - 1];
        }
    }

    while (q--) {

        sff(x1, y1); sff(x2, y2);

        x1--; // dy[4]
        y1--; // dx[2]
        x2--; // dy[1]
        y2--; // dx[3]

        final = tabla[x2][y2];

        if ( y1 > 0 )
            final -= tabla[x2][y1 - 1];
        if ( x1 > 0 )
            final -= tabla[x1 - 1][y2];
        if ( x1 > 0 && y1 > 0 )
            final += tabla[x1 - 1][y1 - 1];
        
        pf(final);
    }
}
