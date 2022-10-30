/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <stack>

using namespace std;

#define MOD 97654321

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

void lowerBound(int arr[], int n, int i, int dp[]){

    stack<int> s;

    for ( i = 0; i < n; i++){
        
        while (!s.empty()){
            if (s.top() < arr[i]){
                dp[i] = s.top();
                break;
            }
        
            else{
                s.pop();
            }
        }
 
        if (s.empty()) {
            dp[i] = -1;
        }
 
        s.push(arr[i]);
    }
}

int main(){

    int n, i, j, q;
    sf(n); sf(q);
    int arr[n], dp[n];
    
    for ( i = 0; i < n; i++ )
        sf(arr[i]);

    lowerBound(arr, n, 0, dp);

    while(q--){
        int A;
        sf(A);
        pf(dp[A-1]);
    }

}
