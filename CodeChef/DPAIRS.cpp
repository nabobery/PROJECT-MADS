#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int index1 = 0, index2 = 0, temp,x;
	cin >> x;
	temp = x;
	for(int i = 1; i < n;i++){
	    cin >> x;
	    if(x < temp){
	        index1 = i;
	        temp = x;
	    }
	}
	cin >> x;
	temp = x;
	for(int i = 1; i < m;i++){
	     cin >> x;
	    if(x > temp){
	        index2 = i;
	        temp = x;
	    }
	}
	for(int i = 0; i < m;i++){
	    cout<<index1<<" "<<i<<"\n";
	}
	for(int i = 0; i < n;i++){
	    if(index1 != i){
	        cout<<i<<" "<<index2<<"\n";
	    }
	}
	
	return 0;
}
