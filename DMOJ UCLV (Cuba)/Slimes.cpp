/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <limits.h> // INT & LONG LONG MAX || MIN

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

ll dp[420][420];
int final[420][420];
ll arr[420];
 
int linky(){

    int n, i, j, k, max, aux, temp;
    ll currentSlime = 0x3f3f3f3;

	sf(n);

	for( i = 1; i <= n; i++ ){
		scanf("%lld", &arr[i]);
		arr[i] += arr[i - 1];
	}

    i = 1;

	for(/* i = 1 */; i <= n; i++ ){
		dp[i][i] = 0;
		final[i][i] = i;
	}

	for( max = 1; max < n; max++ ){
	
		for( i = 1; i + max <= n; i++ ){
		
			j = max + i;
			temp = final[i][j - 1];
            aux = final[i + 1][j];
			dp[i][j] = LONG_LONG_MAX;

			for( k = temp; k <= aux; k++ ){
			
				currentSlime = arr[j] - arr[i - 1] + dp[i][k] + dp[k + 1][j]; // - dp[k - 1][j]
				if( currentSlime < dp[i][j] ){
				
					dp[i][j] = currentSlime;
					final[i][j] = k;
				}
			}
		}
	}
    
	printf("%lld", dp[1][n]); // pf(dp[1][n]);

}
