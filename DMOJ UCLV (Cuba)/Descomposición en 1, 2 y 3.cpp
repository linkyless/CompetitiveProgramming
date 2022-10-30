/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")

#include <stdio.h>

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

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

bool cond1( ll n ){

	if( n == 0 )
		return 1;

	if( n % 10 >= 1 && n % 10 <= 3 )
		return cond1( n / 10 );
	else
		return 0;
}

bool cond2( ll n ){

	if( n == 0 )
		return 1;

	if( n % 10 >= 2 && n % 10 <= 6)
		return cond2( n / 10 );

	else
		return cond1(n); 
}

bool cond3( ll n ){

	if( n == 0 )
		return 1;
		
	if( n % 10 >= 3 && n % 10 <= 9 )
		return cond3( n / 10 );
		
	else
		return cond2( n );
}

bool cond4( ll a ){

	ll aux = 0; //int bool

	while( a != 0 ){
	
		if(cond3( a - aux) )
			return 1;

		ll d = a % 10 - aux;

		if( d == 3 )
			return 0;

        if( d < 3 )
            aux = 1;

        if( d > 3 )
            aux = 0;

		a /= 10;
	}

	return 0;
}

bool cond5(){
    return 1;
}

int linky(){

    ll T, a;

    scanf("%lld", &T);

    while(T--){

        scanf("%lld", &a);
        
        if(cond1(a) == 1)
			puts("1");

		else if( cond2(a) )
			puts("2");

		else if( cond3(a))
			puts("3");

		else if( cond4(a) )
			puts("4");
			
		/*else if( cond5(a))
		    puts("5");*/

		else
			puts("5");
    }

    return 0;
}
