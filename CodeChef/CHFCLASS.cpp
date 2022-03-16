#include <iostream>
using namespace std;

int main() {
	int t,n;
	cin >> t;
	for(int i = 0; i < t;i++){
	   cin >> n;
	   int result = n/7;
	   if(n % 7 == 6) result++;
	   cout<<result<<"\n";
	}
	return 0;
}
