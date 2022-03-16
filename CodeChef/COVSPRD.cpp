#include <iostream>
using namespace std;

int main() {
	int t, n, d;
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> n >> d;
	    if(d > 20){
	        cout<<n<<"\n";
	    }
	    else{
	        long long int result = 1;
	        for(int j = 1; j <= d;j++){
    	        if(j < 11){
    	            result *= 2;
    	        }
    	        else{
    	            result *= 3;
    	        }
	        }
    	    if(result < n){
    	        cout<<result<<"\n";
    	    }
    	    else{
    	        cout<<n<<"\n";
    	    }
	    }
	}
	return 0;
}
