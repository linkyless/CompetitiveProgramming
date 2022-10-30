/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <iostream>
#include <map>
#include <iomanip>

//\\ SGTREE \\//

#define left l, m, node * 2
#define right m + 1, r, node * 2 + 1

//\\ PRINCIPAL \\//

#define ll long long int
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

ull MOD = (ull)1e9+7;
std::map<int, ull> f;

ull dp(int n){
    
    if( n == 0 ) return 0;
    if( n == 1 || n == 2 ) return (f[n] = 1);
    if(f.count(n)) return f[n];

    int mid = (n & 1) ? (n + 1) / 2 : n / 2;

    f[n] = (n & 1) ? ((dp(mid) * dp(mid)) % MOD + (dp(mid - 1) * dp(mid - 1)) % MOD) % MOD : ((2 * dp(mid - 1) + dp(mid)) % MOD * dp(mid)) % MOD;
    return f[n] %= MOD;
}

ull formule ( int n ){
    return dp(n + 2) - 1;
}

int linky(){

    std::cout << std::setprecision(10) << std::fixed;

    int T, n, m;
    sf(T);

    while(T--){
        sff(n, m);
        if( n - 1 <= 0 )
            printf("%lld\n", formule(m));
        else
            printf("%lld\n", (formule(m) - formule(n - 1) + MOD) % MOD);

        f.clear();
    }

    return 0;

}
