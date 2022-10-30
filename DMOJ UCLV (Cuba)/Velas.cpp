/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <algorithm>
#include <queue>

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

int main(){

    int n, h, k, sumM = 0, i, j;
    ll sum[100001] = {};
    priority_queue<pair<ll,ll>> pq;
    
    sf(n);
    
    for( i = 0; i < n; i++ ){

        sff(h, k);
        sumM = max(sumM,h);
        
        sum[h]++;
        sum[h-k]--;
    }
    
    for( i = sumM; i > 0; i-- )
        sum[i - 1] += sum[i];
    
    for( i = 1; i <= sumM; i++ ){

        ll v = 1;
        sum[i] *= -1;
        
        while( pq.size() && pq.top().first > sum[i] / v ){
            pair<ll,ll> p = pq.top();
            pq.pop();
            sum[i] += p.first * p.second;
            v += p.second;
        }
    
        sum[i] *= -1;
        
        if( sum[i] % v == 0 )
            pq.push(make_pair(-(sum[i] / v), v));
        
        else{
            pq.push(make_pair(-( sum[i] / v + 1), sum[i] % v));
            pq.push(make_pair(-( sum[i] / v), v - sum[i] % v));
        }
    
    }
    
    ll final = 0;
    
    while(pq.size()){
        pair<ll,ll> p = pq.top();
        pq.pop();
        p.first *= -1;
        final += p.first*(p.first - 1) / 2 * p.second;
    }
    
    printf("%lld\n", final);
}
