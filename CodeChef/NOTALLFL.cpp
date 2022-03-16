#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int t, n,k;
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> n >> k;
	    int arr[n];
	    for(int i = 0; i < n;i++)
	        cin >> arr[i];
	    int count[k] = {0};
	    int curr = 0, result = 0;
	    for(int  l = 0, r = 0; l < n;l++){
	        while((r < n) && (count[arr[r] - 1] > 0 || curr < k - 1)){
	            if(count[arr[r] - 1] == 0) curr++;
	            ++count[arr[r] - 1];
	            r++;
	        }
	        result = max(result, r-l);
	        --count[arr[l] - 1];
	        if(count[arr[l] - 1] == 0) --curr;
	    }
	    cout<<result<<"\n";
	}
	return 0;
}
