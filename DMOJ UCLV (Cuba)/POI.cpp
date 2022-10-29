/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>

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

int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,1,0,-1,1,0,-1};

int puntuacion[2001];
vector<int> soluciones[2001];

int main(){

    int n, t, p, temp, i, j;
    sff(n, t); sf(p);

    for ( i = 1; i <= n; i++) {
        for ( j = 1; j <= t; j++) {
            sf(temp);
            if ( temp == 0 ) 
                puntuacion[j]++;

            else 
                soluciones[i].pb(j);
        }
    }
 
    vector<pair<int, pair<int, int>>> v;

    int aux = 0;

    for ( i = 1; i <= n; i++) {
        aux = 0;
        for (auto j : soluciones[i]) 
            aux += puntuacion[j];
    
        v.pb({aux, {soluciones[i].size(), -i}});
    }
 
    sort(v.rbegin(), v.rend());
 
    for ( i = 0; i < n; i++) {
        if (v[i].second.second == -p) {
            cout << v[i].first << " " << i + 1 << endl;
        }
    }

    return 0;
}
