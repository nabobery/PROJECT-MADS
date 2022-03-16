#include <iostream>
using namespace std;

int main() {
	int t, d_0,d_1,temp;
	cin >> t;
	long long int k;
	for(int i = 0; i < t;i++){
	    cin >> k >> d_0 >> d_1;
	    int temp = (d_0 + d_1)%10;
	    long long int sum = d_0 + d_1;
	    if(k == 2){
	        if(sum % 3 == 0){
	            cout<<"YES\n";
	        }
	        else{
	            cout<<"NO\n";
	        }
	        continue;
	    }
	    sum += temp;
	    long long int groups = (k - 3)/4;
	    int remdigits = (k - 3)%4;
	    if(temp == 5 || temp == 0)
	        sum += 0;
	   else{
	       sum += (20*groups);
	   }
	   for(int j = 0; j < remdigits;j++){
	       temp = (2*temp)%10;
	       sum += temp;
	   }
	   if(sum % 3 == 0){
	       cout<<"YES\n";
	   }
	   else{
	       cout<<"NO\n";
	   }
	}
	return 0;
}
