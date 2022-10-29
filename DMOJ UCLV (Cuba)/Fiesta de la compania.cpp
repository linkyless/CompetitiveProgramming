/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

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

int arr[2001];

int main(){

    int n, i, j, temp;
    sf(n);

    for ( i = 0; i <= n; i++ )
        arr[i] = i;
    
    for ( i = 1; i <= n; i++ ){
        sf(temp);

        if ( temp != -1 )
            arr[i] = temp;
    }

    int final = 0, cont = 0;

    for ( i = 1; i <= n; i++ ){

        temp = i;
        cont = 1;

        while( temp != arr[temp] ){
            cont++;
            temp = arr[temp];
        }

        final = max( cont, final );
        
    }

    pf(final);

}
