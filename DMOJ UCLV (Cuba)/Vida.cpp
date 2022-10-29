/*
linkyless
--Copyright DMOJ
// New Template
*/


#define linky main

#pragma GCC optimize("Ofast")

#include <stdio.h>
//#include <map>
//#include <algorithm>
//#include <set>
//#include <queue>
//#include <vector>
//#include <string>
//#include <stack>
//#include <utility>
//#include <cstring>
#include <iostream>
#include <math.h>
//#include <iterator>

using namespace std;

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

//#define left l, m, node * 2
//#define right m + 1, r, node * 2 + 1

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

//int dx[8] = {0,1,1,1,0,-1,-1,-1};
//int dy[8] = {1,1,0,-1,-1,-1,0,1};

string aBinario(ll n){

    string temp;
    while( n != 0 ){
        temp = ( n % 2 == 0 ? "0": "1") + temp; 
        n /= 2;
    }
    return temp;
}

int linky(){

    int n, i;
    ll t, aux, c1, oo, op;
    string circulos;

    sf(n);
    scanf("%lld", &t); 
    cin >> circulos;

    while( t > 0 ){

        aux = pow( 2, aBinario(t).size() - 1 );
        t -= aux;

        string K = "";

        rep(i, n){

            c1 = 0;
            oo = i - aux;
            op = i + aux;
            oo %= n;
            op %= n;

            if ( oo < 0 )
                oo+=n;

            if( circulos[oo] == '1' )
                c1+=1;
            
            if ( circulos[op] == '1' )
                c1+=1;

            // cout << oo << " " << op << '\n';

            if ( c1 == 1 )
                K+="1";
            else
                K+='0';
        }
        circulos = K;
    }

    cout << circulos;
    
}
