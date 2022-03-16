#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t, n , x;
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> n >> x;
	    int arr[n];
	    for(int j = 0; j < n;j++){
	        cin >> arr[j];
	    }
	    sort(arr,arr + n);
	    int sum = 0;
	    bool flag = false;
	    for(int j = n - 1; j >= 0;j--){
	        sum += arr[j];
	        if(sum >= x){
	            cout<<n-j<<"\n";
	            flag = true;
	            break;
	        }
	    }
	    if(!flag){
	        cout<<"-1\n";
	    }
	}
	return 0;
}
