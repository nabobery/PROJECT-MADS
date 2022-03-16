#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	string bin;
	for(int i = 0; i < t;i++){
	    int count = 0;
	    cin >> n >> bin;
	    for(int j = 0; j < n;j++){
	        if(bin[j] == '1') count++;
	    }
	    if(n % 2 == 0){
	        if(count%2 == 0 || n/2 == count){
	            cout<<"YES\n";
	        }
	        else {
	            cout<<"NO\n";
	        }
	    }
	    else {
	        if(count % 2 == 0 || (n-count)%2 == 0) cout<<"YES\n";      
            else cout<<"NO\n";
	    }
	        
	}
	return 0;
}
