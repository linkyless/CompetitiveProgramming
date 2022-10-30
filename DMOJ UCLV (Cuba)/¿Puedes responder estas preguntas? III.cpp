/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <algorithm>
#include <utility>


#define left i * 2, l, m
#define right i * 2 + 1, m + 1, r

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

#define pf(n) printf("%lld\n",n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s\n",s)


//\\ COORDENADAS TÍPICAS \\//

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

const int MAX = 500005;

int sum[MAX * 4], lmaxn[MAX * 4], rmaxn[MAX * 4], dat[MAX * 4];
int a[MAX], final, pre;

void build( int i, int l, int r ){

    if( l == r ){
        sum[i] = a[l];
        lmaxn[i] = a[l];
        rmaxn[i] = a[l];
        dat[i] = a[l]; // = a[r];
        return;
    }

    int m = (l + r) / 2;
    build(left);
    build(right);

    sum[i] = sum[i * 2] + sum[i * 2 + 1];
    lmaxn[i] = std::max(lmaxn[i * 2], sum[i * 2] + lmaxn[i * 2 + 1]);
    rmaxn[i] = std::max(rmaxn[i * 2 + 1], sum[i * 2 + 1] + rmaxn[i * 2]);
    dat[i] = std::max(std::max(dat[i * 2], dat[i * 2 + 1]), lmaxn[i * 2 + 1] + rmaxn[i * 2]);
}

void query(int ql, int qr, int i, int l, int r){
    if( ql <= l && r <= qr ){
        final = std::max(final, dat[i]);
        final = std::max(final, pre + lmaxn[i]);
        pre = std::max(rmaxn[i], pre + sum[i]);
        return;
    }

    int m = (l + r) / 2;
    int final2 = 0;

    if ( ql <= m )
        query(ql, qr, left);
    if( m < qr )
        query(ql, qr, right);
}

void update(int id, int val, int i, int l, int r){

    if(l == r){
        sum[i] = val;
        lmaxn[i] = val;
        rmaxn[i] = val;
        dat[i] = val;
        return;
    }

    int m = (l + r) / 2;

    if ( id <= m)
        update(id, val, left);

    else
        update(id, val, right);

    sum[i] = sum[i * 2] + sum[i * 2 + 1];
    lmaxn[i] = std::max(lmaxn[i * 2], sum[i * 2] + lmaxn[i * 2 + 1]);
    rmaxn[i] = std::max(rmaxn[i * 2 + 1], sum[i * 2 + 1] + rmaxn[i * 2]);
    dat[i] = std::max(std::max(dat[i * 2], dat[i * 2 + 1]), lmaxn[i * 2 + 1] + rmaxn[i * 2]);
    
}

int linky(){
 
    int n, i;
    
    while(scanf("%d", &n) != EOF){
        for ( i = 1; i <= n; i++ )
            scanf("%d", &a[i]);

        build(1, 1, n);

        int b, u, v;
        int t;

        sf(t);

        while(t--){
            scanf("%d%d%d", &b, &u, &v);

            if ( b == 1){
                final = -1e9;
                pre = -1e9;

                if ( u > v )
                    std::swap(u, v);

                query(u, v, 1, 1, n);
                printf("%d\n", final);
            }

            else if ( b == 0 )
                update( u, v, 1, 1, n);
        }
    }

    return 0;
}
