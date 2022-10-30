/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>

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

ll a[3000005];
ll n, i;

ll final[3000005];
ll s1, s2, s3;

int main(){

    int n, i;

    scanf("%d", &n);

    for ( i = 0; i < n; i++ ){
        scanf("%d", a + i);
    }
    if ( n % 3) {

        for ( i = 0; i < n; i++) {
            final[( i * 3 + 3) % n] = final[ (i * 3) % n] - a[(i * 3 + 1) % n] + a[( i * 3 + 2) % n ];
        }
        s1 = (final[0] + final[1] + final[2] - a[1]) / 3;

        for ( i = 0; i < n; i++)
            printf("%lld\n", final[i] - s1);

        return 0;
    }

    for ( i = 3; i < n; i++ ){
        final[i] = final[i - 3] - a[i - 2] + a[i - 1];
    }

    for ( i = 3; i < n; i+=3 ){

        if (s1 > final[i + 0]) 
            s1 = final[i + 0];

        if (s2 > final[i + 1]) 
            s2 = final[i + 1];

        if (s3 > final[i + 2]) 
            s3 = final[i + 2];
    }
    for ( i = 0; i < n; i+=3 ) {
        final[i + 0]+=1 - s1;
        final[i + 1]+=1 - s2;
        final[i + 2]+=1 - s3;
    }
    
    s1 = final[0] + final[1] + final[2] - a[1];
    for ( i = 2; i < n; i+=3)
        final[i]-=s1 - 1;

    for ( i = 0; i < n; i++ )
        printf("%lld\n",final[i]);
}
