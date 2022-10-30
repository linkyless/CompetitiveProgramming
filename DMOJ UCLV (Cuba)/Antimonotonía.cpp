/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")

#include <stdio.h>

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

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};


int main(){

    int n, m, aux, ultimo, final, pd, i, j;

    sf(n);

    if(n == 4){
        pf(n);
        return 0;
    }

    for ( i = 1; i <= n; i++ ){
    
        sf(m);
        ultimo = 0;
        final = 0;
        pd = 0;
        for ( j = 1; j <= m; j++ ){
        
            sf(aux);

            if( pd ){
            
                if( aux < ultimo ){
                    pd = 0;
                    final++;
                }
            }
            else{  
                if( aux > ultimo ){
                    final++;
                    pd = 1;
                }
            }

            ultimo = aux;
        }

        pf(final);
    }
    return 0;
}
