#include <iostream>
using namespace std;

int Zero(int n){
    int k = 0, l = 0;
    int temp = n;
    while(temp){
        k += temp/2;
        temp /= 2;
    }
    temp = n;
    while(temp){
        l += temp/5;
        temp /= 5;
    }
    return (k < l) ? k : l;
}

int main() {
	int t,n;
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> n;
	    cout<< Zero(n) <<"\n";
	}
	return 0;
}
