#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	vector <int> factors;
	int count = 0;
	for(int i = 1; i <= n;i++){
	    if(n % i == 0){
	        count++;
	        factors.push_back(i);
	    }
	}
	cout<<count<<"\n";
	for(auto f : factors){
	    cout<<f<<" ";
	}
	return 0;
}
