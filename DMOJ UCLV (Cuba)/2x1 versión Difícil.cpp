/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <algorithm>
#include <queue>

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

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int tensor1D[65][262144 + 1];

int main(){

    int n, final = 0, i, j, temp;
    sf(n);

    for ( i = 1; i <= n; i++ ){
        sf(temp);
        tensor1D[temp][i] = i + 1;
    }

    for ( i = 2; i <= 58; i++ ){
        for ( j = 1; j <= n; j++ ){
            if( !tensor1D[i][j] )
                tensor1D[i][j] = tensor1D[i - 1][tensor1D[i - 1][j]];
            if( tensor1D[i][j] )
                final = i;
        }
    }

    pf(final);
}
