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

int max (int a, int b){
    return (a > b ? a : b);
}

int a[101];
bool dp[100001];

int linky(){

    int n, sum = 0, v, i, j;

	scanf("%d",&n);

	for ( i = 1 ; i <= n ; i++ ){
	    scanf( "%d", &a[i] );
        sum+=a[i];
    }

	v = ( sum ) / 2;

	dp[0] = 1;

	for ( i = 1; i <= n ; i++ )
	    for ( j = v; j >= a[i]; j--)
	        dp[j]+=dp[j - a[i] ];
	
	for ( i = v; ~i ; i--)
		if (dp[i]){
			printf("%d\n",max(i,sum-i));
			return 0;
		}
	
	return 0;
}
