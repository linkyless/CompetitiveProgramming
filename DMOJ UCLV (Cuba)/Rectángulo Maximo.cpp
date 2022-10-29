/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>

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
#define sfff(n,m,k) scanf("%d%d%d",&n,&m,%k)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d\n",n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s\n",s)

//\\ COORDENADAS TÍPICAS \\//

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int max (int a, int b){
    return a > b ? a : b;
}

int main(){

    int matriz[101][101], n, final = -0x3f3f3f3f, prefix[101][101], dp[101], i, j, k;

    sf(n);

    for ( i = 0; i < n; i++ )
        for ( j = 0; j < n; j++ ) 
            sf(matriz[i][j]);
    
    for ( i = 0; i < n; i++ ){
        prefix[i][0] = 0;
        for( j = 1; j <= n; j++ ) 
            prefix[i][j] = prefix[i][j - 1] + matriz[i][j-1];
    }
    
    for ( i = 0; i < n; i++ ){
        for ( j = i; j < n; j++ ){
            dp[0] = 0;
            for ( k = 0; k < n; k++ ){
                dp[k + 1] = max( prefix[k][j + 1] - prefix[k][i] + dp[k], prefix[k][j + 1] - prefix[k][i] );
                final = max( final, dp[k + 1] );
            }
        }
    }
    
    pf(final);

}
