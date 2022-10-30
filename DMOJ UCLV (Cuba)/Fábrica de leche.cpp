/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <iostream>
#include <map>
#include <iomanip>

//\\ SGTREE \\//

#define left l, m, node * 2
#define right m + 1, r, node * 2 + 1

//\\ PRINCIPAL \\//

#define ll long long int
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

int linky(){

    int n, a[101] = {0}, b[101] = {0}, u, v, i, final;

    sf(n);

    for ( i = 1; i <= n - 1; i++ ){
        sff(u,v);
        a[u]++;
        b[v]++;
    }

    for ( i = 1; i <= n; i++ ){

        if( a[i] > 1 ){
            printf("%d", -1);
            return 0;
        }

        if( a[i] == 0 && b[i] > 1 )
            final = i;
    }

    pf(final);
    
    return 0;

}
