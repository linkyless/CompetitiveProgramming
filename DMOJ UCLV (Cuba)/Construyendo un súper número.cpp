#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	unsigned long long n;
	int v, k, tam;
	string num;
	
	cin>>v>>k>>num;
	n = num.size();
	tam = num.size();
	
	for(int i = 1; i < k; i++){
		n = ((n - 1) * tam + n) % 34047161064;
	}
	
	cout<<n<<endl;
	
	if(v == 2){
		int sum = 0, auxDig;
		string auxCad;
		for(int i = 0; i < tam; i++){
			auxCad = num[i];
			auxDig = atoi(auxCad.c_str());
			sum += auxDig;
		}
		if(sum % 3 == 0) cout<<"Si";
		else cout<<"No";
	}
	
	return 0;
}
