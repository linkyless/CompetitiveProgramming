/*
linkyless
--Copyright DMOJ
// New Template
*/


#define linky main

#pragma GCC optimize("Ofast")

#include <stdio.h>
#include <map>
//#include <algorithm>
#include <set>
//#include <vector>
//#include <stack>
//#include <utility>
#include <cstring>

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

std::set<int> s;
std::map<int, int> numbers;

int arr[1000001];

int linky(){

    int n, i, j;
    for (int i: arr) arr[i] = 0;
    sf(n);
    int b[n];

    for ( i = 0; i < n; i++ ){
        sf(b[i]);
        s.insert(b[i]);
    }

    for ( int i : s ) numbers[i] = 0;

    rep(i, n) numbers[b[i]]++;

    for ( int i : s ){
        for ( j = i - 1; j < 1000001; j += i){
            arr[j] += numbers[i];
        }
    }

    rep(i, n) pf(arr[b[i] - 1] - 1);
    
    return 0;

}
