/*
linkyless
--CopyR DMOJ
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
#define med (L + R)/2

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


int n, m;
int ti[1001], wi[1001];
double val[1001], dp[1001];

const double decimal = 0.00000001;

bool check(double final) {

    int i, j;

    for( i = 1; i <= n; i++) 
        val[i] = wi[i] - final * ti[i];

    for( i = 1; i <= m + 1; i++) 
        dp[i] = -0x3f3f3f3f;

    for( i = 1; i <= n; i++ ) {
        for( j = m + 1; ~j; j-- ) {
            dp[std::min( m + 1, j + ti[i] )] = std::max(dp[std::min( m + 1, j  + ti[i] )], dp[j] + val[i]);
        }
    }
    return dp[m] >= decimal || dp[m + 1] >= decimal;
}


int main(){

    sff(n, m);

    int i, j;

    double L = 0, R = 0, final = -1;

    for( i = 1; i <= n; i++){
        sff(ti[i], wi[i]);
        R += wi[i];
    }
    while( R - L > decimal ){

        double mid = (L + R) * 0.5; // >> 2 / 2

        if( check(mid)){
            final = mid;
            L = mid + decimal;
        }
        else 
            R = mid - decimal;
    }

    printf("%d", (int)(final * 1000));

}
