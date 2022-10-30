/*
linkyless
--Copyright DMOJ
*/
                                                     

#define linky main

#pragma GCC optimize("Ofast")

#include <cstdio>
#include <cstring>
#include <set>

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

int min (int a, int b){
    return (a < b ? a : b);
}

int arr[1000001];

int cond(int x){

    if(arr[x] != -1)
        return arr[x];
    if(!x)
        return arr[x] = 0;

    set<int>S;

    int maximo = 0, minimo = __INT_MAX__;

    int aux = x;

    while(aux > 0 || aux != 0 ){
        if(aux % 10 != 0){
            maximo = max(aux % 10, maximo);
            minimo = min(aux % 10, minimo);
        }
        aux = aux / 10;
    }

    S.insert(cond(x - maximo));
    S.insert(cond(x - minimo));

    int i;

    for( i = 0;; i++){
        if(S.find(i) == S.end())
            return arr[x] = i;
    }
}

int linky() {

    int T, n;
    sf(T);

    memset(arr, -1, sizeof(arr));

    while(T--){
        sf(n);
        puts(cond(n)?"YES" : "NO");
    }
    
 
	return 0;
}
