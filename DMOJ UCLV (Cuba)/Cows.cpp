/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>

using namespace std;

#define MOD 97654321

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

int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,1,0,-1,1,0,-1};

int x[201], y[201], f[251][251][61];
char str[5];

int hashing( char caracter ){
    return caracter >= 'A' && caracter <= 'Z' ? caracter - 'A' : caracter - 'a' + 26;
}

int main(){

    int u, l, p, i, j, k, final = 0;
    sff(u, l); sf(p);
    
    for( i = 1 ; i <= p; i++ )
        scanf("%s" , str), x[i] = hashing(str[0]) , y[i] = hashing(str[1]);

    for( i = 0; i < 26; i++ ) 
        f[1][0][i] = 1;

    for( i = 26 ; i < 52; i++ ) 
        f[0][1][i] = 1;

    for( i = 2 ; i <= u + l; i++ ){
        for( j = 0 ; j <= i && j <= u ; j++ ){
            for( k = 1 ; k <= p; k++ ){
    
                if( y[k] < 26 && j > 0 )
                    f[j][i - j][y[k]] = (f[j][i - j][y[k]] + f[j - 1][i - j][x[k]]) % MOD;

                if( y[k] >= 26 && i - j > 0 )
                    f[j][i - j][y[k]] = (f[j][i - j][y[k]] + f[j][i - j - 1][x[k]]) % MOD;
            }
        }
    }

    for( i = 0; i < 52 ; i++ )
        final = (final + f[u][l][i]) % MOD;

    pf(final);
   
}
