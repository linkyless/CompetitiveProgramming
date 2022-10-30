/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

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

#define pf(n) prllf("%d\n",n)
#define pfl(n) prllf("%I64d ",n)
#define pfs(s) prllf("%s\n",s)

//\\ COORDENADAS TÍPICAS \\//

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int divisores(int n){

    int cont = 0, i;
    int ans = 1;

    while(!(n&1)){
        n/=2;
        cont++;
    }

    ans*=(cont + 1);
    cont = 0;

    for (i = 3; i * i <= n; i+=2){
        while(n % i == 0){
            n/=i;
            cont++;
        }
        ans*=(cont + 1);
        cont = 0;
    }
    if(n > 2){
        cont++;
    }
    ans*=(cont + 1);

    return ans;
}

int linky(){

    ios;

    int n, num ;
    cin >> n;

    pair<int, int> v;
    v.second = 0;

    for( int i = 0; i < n; i++ ){
        cin >> num;
        int divisors = divisores(num);
        if( v.second < divisors ){
            v.first = num;
            v.second = divisors;
        }

        else if( v.second == divisors ){
            v.first = min(num, v.first);
        }
    }

    cout << v.first;




}
