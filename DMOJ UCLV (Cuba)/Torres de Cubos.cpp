/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <string>
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
#define sfff(n,m,k) scanf("%d%d%d",&n,&m,&k)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d\n",n)
#define pff(n) printf("%d ", n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s\n",s)

//\\ COORDENADAS TÍPICAS \\//

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int max (int a, int b){
    return a > b ? a : b;
}

int linky(){

    int n, q, i, j;
    sff(n, q);

    int mx, mx2, cont, cubo1, cubo2;
    mx = mx2 = cont = cubo1 = cubo2 = 0;

    while(n--){
    
        string s;
        cin >> s;

        mx = 0;
        string s2 = s;
        reverse(s.begin(), s.end());

        if (s2 == s)
            cubo2++;

        for ( i = 0; i < s.size(); i++){
            mx = max( mx, s[i] - '0');
            cubo1+=abs( s[i] - s2[i] );
        }

        if (mx > mx2){
            mx2 = mx;
            cont = 1;
        }

        else if ( mx == mx2 )
            cont++;
    }

    cubo1 /= 2;

    if ( q == 1 ){
        printf("%d ", mx2);
        printf("%d\n", cont);
    }

    if ( q == 2 )
        pf(cubo2);

    if ( q == 3 )
        pf(cubo1);
    
    if ( q == 4 ){
        printf("%d ", mx2);
        printf("%d\n", cont);
        pf(cubo2);
        pf(cubo1);
    }
}
