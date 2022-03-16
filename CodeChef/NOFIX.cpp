#include <iostream>
using namespace std;

int main() {
	int t, x, n;
	cin >> t;
	for(int i = 0; i < t; i++){
	    int result = 0, count = 1;
	    cin >> n;
	    for(int j = 1; j <= n;j++){
	        cin >> x;
	        if(count != x){
	            count++;
	            continue;
	        }
	        else{
	            count += 2;
	            result++;
	        }
	    }
	    cout<<result<<"\n";
	}
	
	return 0;
}
