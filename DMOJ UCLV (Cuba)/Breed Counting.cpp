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

int Holsteins[100001], Guernseys [100001], Jerseys[100001];

int main(){

    int n, m, i, temp, L, R;
    sff(n, m);

    for ( i = 1; i <= n; i++ ){

        sf(temp);

        if ( temp == 1 )
            Holsteins[i] = 1;
        if ( temp == 2 )
            Guernseys[i] = 1;
        if ( temp == 3 )
            Jerseys[i] = 1;

        Holsteins[i] = Holsteins[i] + Holsteins[i - 1];
        Guernseys[i] = Guernseys[i] + Guernseys[i - 1];
        Jerseys[i] = Jerseys[i] + Jerseys[i - 1];

    }
    
    while( m-- ){
        sff(L, R);
        printf("%d %d %d\n", Holsteins[R] - Holsteins[L - 1], Guernseys[R] - Guernseys[L - 1], Jerseys[R] - Jerseys[L - 1]);
    }

}
