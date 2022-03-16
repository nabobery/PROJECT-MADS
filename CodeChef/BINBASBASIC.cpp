#include <iostream>
using namespace std;

int main() {
	int t, n, k;
	string s;
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> n >> k >> s;
	    int temp = 0;
	    for(int j = 0; j < n/2;j++){
	        if(s[j] ^ s[n-j-1]){
	            temp++;
	        }
	    }
	    if(k < temp){
	        cout<<"NO\n";
	    }
	    else if((k-temp) % 2 == 0){
	        cout<<"YES\n";
	    }
	    else{
	        if(n%2){
	            cout<<"YES\n";
	        }
	        else{
	            cout<<"NO\n";
	        }
	    }
	}
	return 0;
}
