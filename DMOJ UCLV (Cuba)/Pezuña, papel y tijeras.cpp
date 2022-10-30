/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>

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

int dp[100001][25][3]; // 1-2 3-1 1-3
char gestos[3] = { 'P', 'S', 'H'};

int max ( int a, int b ){
    return (a > b ? a : b );
}

int linky(){

    int n, k, i, j;
    sff(n, k);
    int arr[n];

    for ( i = 1; i <= n; i++ ){
	         getchar();
	         arr[i] = getchar();
    }

    bool gestoComp = 1;

    for ( i = 1; i <= n; i++ ){
            dp[i][0][0] = dp[i - 1][0][0] + (arr[i] == gestos[0]); // P
            dp[i][0][1] = dp[i - 1][0][1] + (arr[i] == gestos[1]); // S
            dp[i][0][2] = dp[i - 1][0][2] + (arr[i] == gestos[2]); // H
    }

    for ( i = 1; i <= k; i++ ){
          for ( j = 1; j <= n; j++ ){
               dp[j][i][0] = max(dp[j - 1][i][0], max( dp[j - 1][i - 1][1], dp[j - 1][i - 1][2])) + (arr[j] == gestos[0]);
               dp[j][i][1] = max(dp[j - 1][i][1], max( dp[j - 1][i - 1][0], dp[j - 1][i - 1][2])) + (arr[j] == gestos[1]);
               dp[j][i][2] = max(dp[j - 1][i][2], max( dp[j - 1][i - 1][1], dp[j - 1][i - 1][0])) + (arr[j] == gestos[2]);
	        }
    }

    int final = max(dp[n][k][1], max(dp[n][k][0], dp[n][k][2]));

    pf(final);

    return 0;

}
