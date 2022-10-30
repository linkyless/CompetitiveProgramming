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

int arr[51][51];

int max (int a, int b){
    return (a > b ? a : b);
}

int linky() {
    
    int a, b, i, j;

    scanf("%d %d\n",&a,&b);

    for ( i = 1; i <= a; i++)
        for ( j = 1; j <= b; j++)
            scanf("%d",&arr[i][j]);

    int final = 0;
   
    for ( i = 1; i <= a; i++)
        for ( j = 1; j <= b; j++)
            if (arr[i - 1][j]  == arr[i][j] || arr[i + 1][j] == arr[i][j] || arr[i][j + 1] == arr[i][j] || arr[i + 1][j + 1] == arr[i][j] || arr[i - 1][j + 1] == arr[i][j] || arr[i + 1][j - 1] == arr[i][j] || arr[i][j - 1] == arr[i][j] || arr[i - 1][j - 1] == arr[i][j]) 
                final = max(final, arr[i][j]);
            
    printf("%d\n",final);
  
    

    return 0;
}
