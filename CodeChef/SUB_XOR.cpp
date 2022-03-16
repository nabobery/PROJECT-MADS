#include <iostream>
using namespace std;

long long int mod = 998244353;

int main() {
	int t,n;
	string bin;
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> n >> bin;
        int arr[n] = {0};
	    long long int temp = 1;
	    long long int result = 0;
	    if(bin[0] == '1'){
	        arr[0] = 1;
	    }
	    long long int count = arr[0];
	    for(int j = 1; j < n; j++){
	        if(bin[j] == '1') count += (j+1);
	        arr[j] = count%2;
	    }
	    for(int j = n-1; j > -1; j--){
	        if(arr[j]){
	            result += temp;
	            result = result%mod;
	        }
	        temp = temp*2;
	        temp = temp%mod;
	    }
	    cout<<result%mod<<"\n";
	}
	return 0;
}
