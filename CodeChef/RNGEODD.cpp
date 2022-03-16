#include <iostream>
using namespace std;

int main() {
	int l,r;
	cin >> l >> r;
	int start;
	if(l % 2 == 0){
	    start = l + 1;
	}
	else{
	    start = l;
	}
	for(int i = start; i <= r;i+=2){
	    cout<<i<<" ";
	}
	cout<<"\n";
	return 0;
}
