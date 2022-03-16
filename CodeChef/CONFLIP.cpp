#include <iostream>
using namespace std;

int main() {
	int t,g,I,n,q;
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> g;
	    for(int j = 0; j < g;j++){
	        cin >> I >> n >> q;
	        if(n % 2 == 0){
	            cout<<n/2<<"\n";
	        }
	        else{
	            if(I == 1){
	                if(q == 1){
	                    cout<<n/2<<"\n";
	                }
	                else{
	                    cout<<n/2 + 1<<"\n";
	                }
	            }
	            else{
	                if(q == 1){
	                    cout<<n/2 + 1<<"\n";
	                }
	                else{
	                    cout<<n/2<<"\n";
	                }
	            }
	        }
	    }
	}
	return 0;
}
