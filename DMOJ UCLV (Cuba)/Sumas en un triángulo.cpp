/*
linkyless
--Copyright DMOJ
*/
                                                     

#define linky main

#pragma GCC optimize("Ofast")

#include <cstdio>
#include <vector>

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

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

int arr[351][351];

int max(int a, int b ){
    return (a > b ? a : b);
}

int suma( vector<vector<int>>& tri, int i, int j, vector<vector<int>>& dp ){

    if( i == tri.size() )
      return 0;

    if( dp[i][j] != -1 )
        return dp[i][j];

    return dp[i][j] = tri[i][j] + max( suma( tri, i + 1, j, dp), suma( tri, i + 1, j + 1, dp ) ); //dp[i][j] = 1;
}
 
int final(vector<vector<int>>& tri) {
    int n = tri.size() ;
    vector<vector<int>> dp(n, vector<int>(n, -1) ); // memset(sizeof)
    return suma( tri, 0, 0, dp ) ;
}

int linky(){

    vector<vector<int>>tri;

    int n, i, j;

    scanf("%d", &n);

    for( int val, i = 0; i < n; i++){

        vector<int> temp;
        for( j = 0; j <= i; j++){
            sf(val);
            temp.push_back(val);
        }
        tri.push_back(temp);
        temp.clear(); //clean
    }

    pf(final(tri));

}
