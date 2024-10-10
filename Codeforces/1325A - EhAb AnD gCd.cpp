#pragma GCC optimize("Ofast")
 
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "TemplateDebugging.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
 
using namespace std;
 
#define int long long
#define ull unsigned long long
#define ios ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define maxelement(x) *max_element(all(x))
#define minelement(x) *min_element(all(x))
#define lb lower_bound
#define ub upper_bound
 
const int MAXN = 3e5 + 5;
const int MODO = 998244353;
const int MODI = 1e9 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e18;
 
int dx[8] = {-1,0,1,0,0,-1,-1,-1};
int dy[8] = {0,1,0,-1,-1,-1,0,1};
 
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
 
int32_t main(){
    ios;
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << 1 << ' ' << n - 1 << endl;
    }
}