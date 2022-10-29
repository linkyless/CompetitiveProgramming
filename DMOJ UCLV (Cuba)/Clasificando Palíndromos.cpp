/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:102400000, 102400000")

#include <stdio.h>
#include <iostream>
#include <algorithm>

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
#define sfff(n,m,k) scanf("%d%d%d",&n,&m,&k)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d\n",n)
#define pff(n) printf("%d ", n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s\n",s)

//\\ COORDENADAS TÍPICAS \\//

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int linky(){

    int n, i;
    sf(n);

    bool cond = false;
    std::string str1, str2, temp1, temp2;

    while( n-- ){

        cond = false;
        std::cin >> str1;
        temp1 = str1;

        reverse(all(str1));

        if( temp1 == str1 ){
            puts("palindrome");
            cond = true;
        }

        else{
            
            for( i = temp1.size() - 1; i >= 1; i-- ){

                str2 = str1.substr( 0, i );
                temp2 = str2;
                reverse(all(str2));

                if( str2 == temp2 ){

                    str2 = str1.substr(i, str1.size() - i);
                    temp2 = str2;
                    reverse(all(str2));

                    if( str2 == temp2 ){
                        puts("bi-palindrome");
                        cond = true;
                        break;
                    }
                }
            }
        }

        if( !cond ){
            puts("non-palindrome");
        }
    }

}
