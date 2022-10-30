/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <algorithm>
#include <queue>

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

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int main(){

    int n;
	sf(n);
	vector<int> z, o;
	int fg = 0, sl = 0;
	for(int i = 0; i < n; i++) {
		int a;
		sf(a);
		if(a % 3 == 0)
			z.push_back(a);
		else {
			o.push_back(a);
			if(a % 3 == 1)
				fg++;
			else
				sl++;
		}
	}
	vector<int> mid;

	if( z.size() > 0 ) {
		mid.push_back(z[0]);
		for( int i = 1; i < z.size(); i++) {
			if(o.empty()) {
				printf("impossible\n");
				return 0;
			}
			mid.push_back(o.back());
			o.pop_back();
			mid.push_back(z[i]);
		}
	}
	if(mid.empty() && sl > 0 && fg > 0){
		puts("impossible\n");
		return 0;
	}

	for( int i : o )
		if( i % 3 == 1 )
			printf("%d ", i);

	for( int i : mid)
		printf("%d ", i);

	for( int i : o)
		if(i % 3 == 2)
			printf("%d ", i);
    
}
