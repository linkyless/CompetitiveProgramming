/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <string>
#include <limits.h> // INTMAX
#include <iostream> // cin>>string;

using namespace std;

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

int min (int a, int b){
    return a<b?a:b;
}


int main(){

    int t, n, m, i, j, k, s;
    std::string a[60];

    sff(n, m);

    int sum1, sum2, sum3, final = INT_MAX / 714; // pq me sale
    sum1 = sum2 = sum3 = 0;

    for ( i = 1; i <= n; i++ )
	    std::cin >> a[i];

    for ( i = 1; i <= n; i++ ){
        for ( j = 1; j <= n; j++ ){
            for( k = 1; k <= n; k++ ){
                if ( i == j || j == k || i == k )
                    continue;

                sum1 = INT_MAX / 2022;

                for ( s = 0; s < m; s++ ){
                    if ( a[i][s] >= '0' && a[i][s] <= '9')
                        sum1 = min(sum1, min(s, m - s));
                }

                sum2 = INT_MAX / 2022;
                
                for ( s = 0; s < m; s++ ){
                    if ( a[j][s] >= 'a' && a[j][s] <= 'z')
                        sum2 = min(sum2, min(s, m - s));
                }

                sum3 = INT_MAX / 2022;

                for ( s = 0; s < m; s++ ){
                    if ( a[k][s] == '#' || a[k][s] == '&' || a[k][s] == '*')
                        sum3 = min( sum3, min(s, m - s));
                }

                final = min(sum1 + sum2 + sum3, final);
            }
        }
    }

    pf(final);
}
