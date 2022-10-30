/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")

#include <stdio.h>
#include <algorithm>

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
#define sfl(n) scanf("%I64lld", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d\n",n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s\n",s)

//\\ COORDENADAS TÍPICAS \\//

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int BinarySearch(ll arr[], ll &n, ll &k){

    std::sort(arr, arr + n);
 
    ll minimo = 0, maximo = arr[n - 1], i;
 
    while (minimo <= maximo) {

        ll medio = minimo + ((maximo - minimo) / 2);
        ll sum = 0;

        for ( i = n - 1; ~i; i--) {
            if (arr[i] - medio <= 0)
                break;

            sum += (arr[i] - medio);
        }
 
        if (sum == k)
            return medio;
 
        if (sum > k)
            minimo = medio + 1;
 
        else
            maximo = medio - 1;
    }

    return maximo;
}


int main(){

    ll n, L, i;

    scanf("%lld%lld", &n, &L);

    ll arr[n];

    for ( i = 0; i < n; i++ )
        sfl(arr[i]);

    ll final = BinarySearch(arr, n, L);

    printf("%lld", final);
    
    return 0;
}
