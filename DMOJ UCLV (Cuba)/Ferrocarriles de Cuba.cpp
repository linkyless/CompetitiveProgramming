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
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d\n",n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s\n",s)

//\\ COORDENADAS TÍPICAS \\//

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

int arr[ 10005 ];

int min ( int a, int b ){
    return (a < b ? a : b);
}

int linky(){

    int n, x, i;

    scanf("%d%d", &n, &x);

    int minimo = 0;
    
    arr[0] = 1;
    

    for ( i = 1; i <= n; i++){

        int a, b;

        scanf("%d%d", &a, &b);
        minimo += std::min(a, b);
        int num = (a - b < 0 ? (a - b) * - 1 : a - b);

        for ( int i = 10000; ~i; i--)
            if (arr[ i ])
                arr[ i + num ] = 1;
    }
    
    if ( x >= minimo && arr[ x - minimo ] )
        printf("Yes\n");

    else
        printf("No\n");

    return 0;
}
