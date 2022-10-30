/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")

#include <stdio.h>

using namespace std;

//\\ PRINCIPAL \\//

#define ll long long
#define ull unsigned long long
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)

//\\ VECTOR \\//

#define pb push_back
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ordenar(x) sort( x.begin(), x.end() )
#define ordenarA(x) sort( x, x + n )

//\\ OPERACIONES RAPIDAS \\//

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d\n",n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s\n",s)

//\\ COORDENADAS TÍPICAS \\//

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

int dp[ 98309 ];

int max( int a, int b ){
    return (a > b ? a : b);
}

int linky () {

    int n, m, costo, retorno, i, j;

    sff(n, m);

    for ( i = 0; i <= m; i++)
        dp[ i ] = i;

    for ( i = 0; i < n; i++) {
        sff( costo, retorno );

        for ( j = costo; j <= m; j++)
            dp[ j ] = max( dp[ j ], dp [ j - costo ] + retorno - costo);
    }

    pf( dp[ m ] );
    return 0;
}
