/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <cstring>
#include <vector>

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
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d\n",n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s\n",s)

//\\ COORDENADAS TÍPICAS \\//

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int pastizal[101], caminos[1001], final = 0;
bool mk[1001];
std::vector<int> picnics[1001];

void dfs(int n){

    int i;
    
    caminos[n]++; // islas
    mk[n] = 1;
    for( i = 0; i < picnics[n].size(); i++ ){
        if( mk[picnics[n][i]] == 0 )
        	dfs(picnics[n][i]);
    }

    return;
}

int main(){

    int vacas, vertices, aristas, i, A, B;
    sff(vacas, vertices); 
    sf(aristas);

    for( i = 0; i < vacas; i++)
	    sf(pastizal[i]);

    for( i = 0; i < aristas; i++){
        sff(A, B);
        picnics[A].pb(B);
    }

    for( i = 0; i <= vacas; i++){
        memset(mk, 0, sizeof(mk) );
        dfs(pastizal[i]);
    }

    for( i = 1; i <= vertices; i++ ){
        if( caminos[i] == vacas)
            final++;
    }

    pf(final);
    
}
