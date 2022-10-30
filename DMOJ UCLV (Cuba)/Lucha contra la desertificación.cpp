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

// int dx[8] = {-1,-1,0,1,1,1,0,-1};
// int dy[8] = {0,1,1,1,0,-1,-1,-1};

char s[1001][1001];
int n;
 
bool cond ( int x, int y, int dx, int dy ){


    int cont, l;

	if( s[ x - dx ][ y - dy ] == '#' ) 
        return 0;

	for( l = 6, cont = 0; l--; x += dx, y += dy)
		if( x < 0 || y < 0 || x >= n || y >= n || (s[ x ][ y ] == '.' && ++cont > 2) )
			return 0;

	return true;
}
 
int main(){

    int i, j;

	sf(n);

	for( i = 0; i < n; i++ )
		scanf("%s", s[ i ]);

	for( i = 0; i < n; i++ )
		for( j = 0; j < n; j++ )
			if( cond( i, j, 0, 1 ) || cond( i, j, 1, 0 ) || cond( i, j, 1, 1 ) || cond( i, j, 1, -1 ) ){
				printf("Yes");
				return 0;
			}

	printf("No");
	return 0;
}
