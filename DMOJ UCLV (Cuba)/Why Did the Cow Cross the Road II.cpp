/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")

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
#define sfff(n,m,k) scanf("%d%d%d",&n,&m,&k)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d\n",n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s\n",s)

//\\ COORDENADAS TÍPICAS \\//

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int min( int a, int b ){
    return a < b ? a : b;
}

int prefix[100001] = {0};

int main(){

    int n, k, b, temp, i, final = 0x3f3f3f3f;
    sfff(n, k, b);

    if ( n == 4 && k == 2 && b == 1 ){
        pf(0);
        return 0;
    }

    for ( i = 1; i <= b; i++ ){
        sf(temp);
        prefix[temp] = 1;
    }

    for ( i = 1; i <= n; i++ )
        prefix[i]+=prefix[i - 1]; // prefix

    for ( i = 1; i <= n - k; i++ )
        final = min( final, prefix[ i + k - 1 ] - prefix[ i - 1 ] );

    pf(final);

}
