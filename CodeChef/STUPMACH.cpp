#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t,n;
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> n;
	    int s[n];
	    for(int j = 0; j < n;j++){
	        cin >> s[j];
	    }
	    int maximum[n];
	    maximum[0] = s[0];
	    long long int result = s[0];
	    for(int j = 1; j < n;j++){
	        maximum[j] = min(maximum[j-1],s[j]);
	        result += maximum[j];
	    }
	    cout<<result<<"\n";
	}
	return 0;
}
