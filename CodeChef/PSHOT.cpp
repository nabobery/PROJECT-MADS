#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	string goals;
	bool flag;
	for(int i = 0; i < t;i++){
	    cin >> n >> goals;
	    int count1 = 0, count2 = 0, r1 = n, r2 = n;
	    flag = false;
	    for(int j = 0; j < 2*n;j++){
	        if(j % 2 == 0){
	            if(goals[j] == '1'){
	                count1++;
	            }
	            r1--;
	        }
	        if(j % 2 == 1){
	            if(goals[j] == '1'){
	                count2++;
	            }
	            r2--;
	        }
	        if((count1 - count2) > r2 || (count2 - count1) > r1){
	            cout<<j+1<<"\n";
	            flag = true;
	            break;
	        }
	    }
	    if(!flag) cout<<2*n<<"\n";
	}
	return 0;
}
