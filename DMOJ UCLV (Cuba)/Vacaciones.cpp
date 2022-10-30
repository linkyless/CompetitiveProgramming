/*
linkyless
--Copyright DMOJ
*/
                                                     

#define linky main

#pragma GCC optimize("Ofast")

#include <cstdio>
#include <vector>

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

int linky() {

  int n, i;
 
	sf(n);

	int dp0, dp1, dp2, a, b, c, final1, final2;

  dp0 = dp1 = dp2 = 0;
 
	for( i = 0; i < n; i++ ) {

        sf(a); sf(b); sf(c);
        final1 = max(dp0, dp1) + a;
        final2 = max(dp1, dp2) + b;
        dp1 = max(dp2, dp0) + c;
        dp2 = final1;
        dp0 = final2;
	}
 
	printf("%d", max(dp0, max(dp1, dp2) ));
 
	return 0;
}
