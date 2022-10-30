/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//\\ SGTREE \\//

//#define left l, m, node * 2
//#define right m + 1, r, node * 2 + 1

//\\ PRINCIPAL \\//

#define ll long long
#define ull unsigned long long
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)

//\\ VECTOR \\//

#define pb push_back
#define ff first
#define seccc second
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

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int main(){

    string s; 
    cin >> s; //
    vector<vector<int>> adj(10); 

    for(int i = 0 ; i < s.size() ; i++ )
        adj[s[i]-'0'].push_back(i); 

    queue<pair<int,int>> q; 
    q.push({0,0}) ; 

    vector<bool> mk(s.size(),false); 
    int final = -1 ; 

    while(q.size() != 0){
    
        auto fr = q.front() ; 
        if(fr.first == s.size() - 1 ) 
            break;

        q.pop();

        mk[fr.first] = true ;
        int val = s[fr.first] - '0'; 

        for(auto x : adj[val]){
            mk[x] = true ; 
            q.push({x,fr.second+1}) ; 
        }
        if(final!=-1) break; 
        if( fr.first -1 >= 0  && mk[fr.first-1] == false ){

            q.push({fr.first-1, fr.second + 1 } ) ;
            mk[fr.first-1] = true ; 
        }

        if(fr.first+1 < s.size() &&  mk[fr.first + 1] == false){
        
            q.push({fr.first + 1,fr.second + 1}) ; 
            mk[fr.first+1] = true ; 
        } 
    }
    pf(q.front().second);
}
