/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

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

int arr[10001];

struct cow{
    int g;
    int d;
    cow(int u, int v) : g(u), d(v){}
};

vector<cow>a;


bool cond(cow x1, cow x2){
    if(x1.g!=x2.g)
        return x1.g > x2.g;
    else
        return x1.d < x2.d;
    
}

int res[10001];

int main(){

    int n, i, j, xx, yy;
    sf(n);

    for ( i = 1; i <= n; i++ ){
        std::cin >> xx >> yy;
        a.push_back(cow(xx, yy));
    }

    stable_sort(all(a), cond);

    int final = 0;

    for ( i = 0; i < n; i++ ){
        int fallo = 1;
        int k = a[i].d;
        for( j = k; j >= 1; j-- ){
            if(!arr[j]){
                fallo = 0;
                arr[j] = 1;
                break;
            }
        }
        if (!fallo)
            final+=a[i].g;
    }

    pf(final);
    
    
    return 0;
}
