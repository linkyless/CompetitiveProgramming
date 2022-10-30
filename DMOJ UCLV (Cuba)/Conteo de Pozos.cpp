/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <cstring>
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

char pozos[101][101];

void memoization(int x, int y){

    pozos[x][y] = '.';

    for ( int i = 0; i < 8; i++ ){
        int memo1 = x + dx[i];
        int memo2 = y + dy[i];

        if ( pozos[memo1][memo2] == 'W' )
            memoization(memo1, memo2);
    }
}

int main(){

    int n, m, cantPozos = 0, i, j;

    sff(n, m);

    for ( i = 1; i <= n; i++ ){
        for ( j = 1; j <= m; j++ )
            cin >> pozos[i][j];
    }

    for ( int i = 1; i <= n; i++ ){
        for ( int j = 1; j <= m; j++ ){
            if ( pozos[i][j] == 'W' ){
                memoization(i, j);
                cantPozos++;
            }
        }
    }

    pf(cantPozos);
}
