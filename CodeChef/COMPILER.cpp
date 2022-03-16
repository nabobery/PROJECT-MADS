#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	string exp;
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> exp;
	    int count = 0, result = 0;
	    for(int j = 0; j < exp.size();j++){
	        if(exp[j] == '<') count++;
	        else if(exp[j] == '>') count--;
	        if(count < 0) break;
	        if(count == 0) result = max(result,j+1);
	    }
	    cout<<result<<"\n";
	}
	return 0;
}
