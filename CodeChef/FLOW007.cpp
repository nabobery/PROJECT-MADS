#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin >> t;
	string s;
	for(int i = 0; i < t;i++){
	    cin >> s;
	    int result = 0;
	    for(int j =0; j < s.size();j++){
	        result += pow(10,j)*(s[j] - '0');
	    }
	    cout<<result<<"\n";
	}
	return 0;
}
