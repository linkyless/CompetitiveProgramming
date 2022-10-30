/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>

using namespace std;

//\\ SGTREE \\//

//#define left l, m, node * 2
//#define right m + 1, r, node * 2 + 1

//\\ PRINCIPAL \\//

#define ll long long
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

ll arr[100001];

int aux = 0, i;

bool check (ll a, ll b){

    if ( b < a ) //while(b < a)
        return 0;

    arr[aux] = b;
    aux++;

    if ( a == b ){
        printf("YES\n");
        pf(aux);

        for ( i = aux - 1; ~i; i-- )
            printf("%lld ", arr[i]);

        aux--;
        return 1;
    }

    bool cond = 0;

    if ( b % 10 == 1 ){
        cond = check( a, b / 10 );
        aux--;
        return cond;
    }

    if ( b % 2 == 0 ){
        cond = check( a, b / 2 );
        aux--;
        return cond;
    }

    aux--;
    return 0;
    
}


int linky(){

    ll a, b;
    scanf("%lld%lld", &a, &b);

    if ( !check (a, b))
        puts("NO");

    return 0;
   
}
