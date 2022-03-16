#include <iostream>
using namespace std;

int main() {
	int t,n,s,v,p;
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> n;
	    int result = 0;
	    for(int j = 0; j < n;j++){
	        int curr;
	        cin >> s >> p >> v;
	        curr = p/(s + 1);
	        curr *= v;
	        if(curr > result){
	            result = curr;
	        }
	    }
	    cout<<result<<"\n";
	}
	return 0;
}
