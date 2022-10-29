/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <cstring>

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

int dp[(int) (5e3 + 1)][(int) (5e3 + 1)];
int maxmod[10],maxnum[(int)(1e5 + 1)];
int a[(int) (5e3 + 1)];

int max(int a, int b){
    return a > b ? a : b;
}

int main(){

    int n, final = 0, i, j;

    scanf("%d",&n);

    for( i = 1; i <= n; i++ )
        sf(a[i]);

    for( i = 0; i <= n; i++){

        memset(maxmod,0,sizeof(maxmod));
        memset(maxnum,0,sizeof(maxnum));

        for( j = 1; j <= n; j++){

            if( i == j) 
                dp[i][j] = 0;

            else{

                int mod = a[j] % 7;
                
                if( i > j ){
                    maxmod[mod] = max(maxmod[mod],dp[i][j]);
                    maxnum[a[j]] = max(maxnum[a[j]],dp[i][j]);
                    continue;
                }

                dp[i][j] = max( maxmod[mod] + 1, maxnum[a[j] - 1] + 1);
                dp[i][j] = max( dp[i][j], maxnum[a[j] + 1] + 1);
                dp[i][j] = max( dp[i][j], dp[i][0] + 1);
                dp[j][i] = dp[i][j];
                maxmod[mod] = max(maxmod[mod], dp[i][j]);
                maxnum[a[j]] = max(maxnum[a[j]] ,dp[i][j]);
                final = max(final, dp[i][j]);
            }
        }
    }

    pf(final);

    return 0;
}
