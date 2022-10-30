/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>

using namespace std;

//\\ SGTREE \\//

//#define left l, m, node * 2
//#define right m + 1, r, node * 2 + 1

//\\ PRINCIPAL \\//

#define ll long long
#define ull unsigned long long
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)

//\\ VECTOR \\//

#define pb push_back
#define ff first
#define seccc second
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

int max (int a, int b){
    return a>b?a:b;
}

int dp[1001][31], arr[1001];

int linky(){

    int n, k, final = 0, i = 1, j = 1;

    sff(n, k);

    for ( ; i <= n; i++ )
        sf(arr[i]);

    for ( i = 1; i <= n; i++ ){
        for ( j = 0; j <= k; j++ ){
            if ( j == 0 ){
                dp[i][j] = dp[i - 1][j];
                if ( (j % 2 + 1) == arr[i])
                    dp[i][j]++;
                continue;
            }

            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);

            if ( (j % 2 + 1) == arr[i] )
                dp[i][j]++;

            //printf("dp[%d][%d]\t:\t%d\n", i, j, dp[i][j]);
        }
    }

    j = 0;

    for ( ; j <= k; j++ )
        final = final > dp[n][j] ? final : dp[n][j];

    pf(final);
   
}
