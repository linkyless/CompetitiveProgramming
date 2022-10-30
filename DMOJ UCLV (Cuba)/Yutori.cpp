/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

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

int linky(){

    int n, k, c;
    scanf("%d %d %d", &n, &k, &c);
    std::string s;
    std::cin >> s;
    
    std::vector<bool> l(n), r(n);
    int m = 0, lp = 0, rp = n, i;

    for ( i = 0; i < n; i++ )
        if (i >= lp && s[i] == 'o') {
            l[i] = 1;
            lp = i + c + 1;
            m++;
        }
    for ( i = n - 1; ~i; i--)
        if (i < rp && s[i] == 'o') {
            r[i] = 1;
            rp = i - c;
        }
    
    if (m == k) {
        for ( i = 0; i < n; i++)
            if (l[i] && r[i])
                printf("%d\n", i + 1);
    }
}
