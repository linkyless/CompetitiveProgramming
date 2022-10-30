/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <limits.h> //INT_MAX
#include <cstring>

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

ll dp[150][16];
ll p[16];
ll a, b;
ll minimo = -LONG_LONG_MAX * -1;

ll topDown ( ll n, int sum, int digit) {

	if ( sum < 0 )
		return 0;

	if( n > b || n + p[digit] - 1 < a)
	    return 0;

	if ( digit == 0 ) {

		if ( sum > 0 )
			return 0;

		else {
			minimo = minimo < n ? minimo : n;
			return 1;
		}
	}

	if ( dp[sum][digit] != -1 && n >= a && n + p[digit] - 1 <= b )
		return dp[sum][digit];

    ll final = 0;

	for ( int i = 0; i < 10; i++ )
		final += topDown( n + i * p[digit - 1], sum - i, digit - 1 ); // potencias de 2

	if ( n >= a && n + p[digit] - 1 <= b )
		dp[sum][digit] = final;

	return final;
}

int linky(){

    memset(dp, -1, sizeof(dp));

    ll temp = 1;
	int i, s;
	for ( i = 0; i < 16; i++) {
		p[i] = temp;
		temp *= 10;
	}

	scanf("%lld %lld %d", &a, &b, &s);
	printf("%lld\n", topDown(0, s, 15));
	printf("%lld\n", minimo);

   
}
