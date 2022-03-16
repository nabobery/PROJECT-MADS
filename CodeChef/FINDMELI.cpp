#include <iostream>
using namespace std;

int main() {
	int n, k, x;
	cin >> n >> k;
	bool flag = false;
	for(int i = 0; i < n;i++){
	    cin >> x;
	    if(x == k){
	        cout<<1;
	        flag = true;
	        break;
	    }
	}
	if(!flag){
	    cout<<-1;
	}
	return 0;
}
