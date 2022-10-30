/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <algorithm>
#include <utility>


#define left l, mid, node * 2
#define right mid + 1, r, node * 2 + 1

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

#define pf(n) printf("%lld\n",n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s\n",s)


//\\ COORDENADAS TÍPICAS \\//

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

const int MAX = 500001;

int ma[MAX * 4], mi[MAX * 4], dis[MAX * 4];

void build( int l, int r, int node ){

    if( l == r ){
        int x;
        sf(x);
        ma[node] = mi[node] = x;
        return;
    }

    int mid = (l + r) / 2;

    build( left );
    build( right );
    
    ma[node] = std::max(ma[node * 2], ma[node * 2 + 1]);
    mi[node] = std::min(mi[node * 2], mi[node * 2 + 1]);
}

std::pair<int, int> query(int L, int R, int l, int r, int node){

    std::pair<int, int> final;
    final.first = 999999999 * -1, final.second = 999999999;

    if( L <= l && r <= R){
        std::pair<int, int> temp;
        temp.first = ma[node], temp.second = mi[node];
        return temp;
    }

    int mid = (l + r) / 2;

    if ( L <= mid ){
        std::pair<int, int> aux = query(L, R, left);
        final.first = std::max(final.first, aux.first);
        final.second = std::min(final.second, aux.second);
    }

    if( R > mid ){
        std::pair<int, int> aux = query(L, R, right);
        final.first = std::max(final.first, aux.first);
        final.second = std::min(final.second, aux.second);
    }

    return final;
}

int linky(){
 
    int n, queries, L, R;
    
    sff(n, queries);

    build(1, n, 1);

    while(queries--){
        sff(L, R);
        std::pair<int, int> temp = query(L, R, 1, n, 1);
        printf("%d\n", temp.first - temp.second);
    }

    return 0;
}
