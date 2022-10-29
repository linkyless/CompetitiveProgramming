/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <algorithm>

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

int max( int a, int b){
    return a > b ? a : b;
}

int prefix[50001], s1[7], s2[7];

int main(){

    int n, i, final = 0;
    sf(n);

    prefix[0] = 0;

    for ( i = 1; i <= n; i++ ){
        sf(prefix[i]);
        prefix[i] = (prefix[i] + prefix[i - 1] ) % 7;
    }

    for ( i = n; i >= 1; i-- )
        s1[prefix[i]] = i;
    
    s1[0] = 0;

    for ( i = 1; i <= n; i++ )
        s2[prefix[i]] = i;

    for ( i = 0; i < 7; i++ )
        final = max( final, s2[i] - s1[i] );

    pf(final);

}
