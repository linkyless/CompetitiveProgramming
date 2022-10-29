/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <map>
#include <set>
#include <utility>

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

pair<int, int> programmers[50001];

set<int> xset, yset, xset2, yset2; // 0,0,1,1,1,-1,-1,-1 // 1,-1,1,0,-1,1,0,-1
map<int, int> xmap, ymap;

int main(){

    int n, i, a, b, temp = 3, maxX = 0, maxXCont, maxY = 0, maxYCont;
    sf(n);

    for( i = 0; i < n; i++ ){

        sff(a, b);

        programmers[i] = {a, b};
        xset.insert(programmers[i].first); 
        yset.insert(programmers[i].second);
        xmap[programmers[i].first] = 0; 
        ymap[programmers[i].second] = 0;
    }

    for( i = 0; i < n; i++){

        xmap[programmers[i].first]++; 
        ymap[programmers[i].second]++;

        if( xmap[programmers[i].first] > maxX ){
            maxX = xmap[programmers[i].first];
            maxXCont = programmers[i].first;
        }

        if( ymap[programmers[i].second] > maxY ){
            maxY = ymap[programmers[i].second];
            maxYCont = programmers[i].second;
        }
    }

    if( xset.size() <= 3 || yset.size() <= 3 ){
        puts("1");
        return 0;
    }

    for( i = 0; i < n; i ++)
        if( programmers[i].first != maxXCont ) 
            yset2.insert(programmers[i].second);

    if( yset2.size() <= 2 ){
        puts("1"); 
        return 0;
    }

    for( i = 0; i < n; i++)
        if(programmers[i].second != maxYCont) 
            xset2.insert(programmers[i].first);

    if( xset2.size() <= 2 ){
        puts("1"); 
        return 0;
    }

    else{
        puts("0");
        return 0;
    }
    

    return 0;
}
