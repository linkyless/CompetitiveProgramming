/*
linkyless
--Copyright DMOJ
// New Template
*/


#define linky main

#pragma GCC optimize("Ofast")

#include <stdio.h>
//#include <map>
#include <algorithm>
//#include <set>
//#include <vector>
//#include <stack>
//#include <utility>
//#include <cstring>

//\\ DEBUGGING \\//

/*template <typename T>
void printcoll (T const& coll){
    typename T::const_iterator pos;
    typename T::const_iterator end(coll.end());

    for ( pos = coll.begin(); pos!=end; ++pos ) {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}

*/

//\\ SGTREE \\//

#define left l, m, node * 2
#define right m + 1, r, node * 2 + 1

//\\ PRINCIPAL \\//

#define ll long long
#define ull unsigned long long
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)

//\\ RAPIDEZ DE CODIGO \\//

#define rep(i,n) for (i = 0; i < n; i++)
#define repzero(i,n) for (i = 0; i <= n; i++)
#define repone(i,n) for (i = 1; i < n; i++)
#define repi(i,n) for (i = 1; i <= n; i++)
#define REP(i,k,n) for (i = k; i <= n; i++)
#define REPR(i,k,n) for (i = k; i >= n; i--)

//\\ STL \\//

#define vi vector<int, int>
#define pi pair<int, int>
#define mapa map<int, int>

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

int a[50001], b[50001], g[100002];

bool descendente ( int a, int b ){
    return a > b;
}

int linky(){

    int n, final = 0, i, temp;
    
    sf(n);

    repi(i, n / 2){
        sf(a[i]);
        g[a[i]] = 1;
    }

    repi(i, n / 2){
        sf(b[i]);
        g[b[i]] = 1;
    }

    std::stable_sort(a + 1, a + n / 2 + 1, descendente);
    std::stable_sort(b + 1, b + n / 2 + 1 ); // ascendente

    temp = n * 2;

    repi(i, n / 2){

        while( g[temp] && temp >= 1 )
            --temp;

        if( temp < a[i] )
            continue;
        else{
            g[temp] = 2;
            final++;
        }
    }

    temp = 1;

    repi(i, n / 2){
        while( g[temp] && temp <= n * 2 )
            ++temp;
        
        if( temp > b[i] )
            continue;
        else{
            g[temp] = 2;
            final++;
        }
    }

    pf(final);
}
