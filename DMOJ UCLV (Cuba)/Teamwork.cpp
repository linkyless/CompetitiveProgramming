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

int max (int a, int b){
    return (a>b?a:b);
}

int min (int a, int b){
    return a<b?a:b;
}

const int MAX = 1e4;
int arr[MAX + 10], dp[MAX + 10]; 

int main(){

    int n, k;
    sff(n, k);
    
    for ( int i = 1; i <= n; i++ )
        sf(arr[i]);

    for ( int i = 1; i <= n; i++ ){

        dp[i] = dp[i - 1] + arr[i];
        int temp = arr[i];

        for ( int j = 1; j < k; j++){
            if ( i - j > 0 ){
                temp = max(temp, arr[i - j]);
                dp[i] = max(dp[i], dp[i - j - 1] + ( j + 1) * temp);
            }
        }
    }

    pf(dp[n]);
}
