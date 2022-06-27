#include <iostream>

using namespace std;

int main() {
    int t,n,x;
    cin >> t;
    while(t--){
        cin >> n >> x;
        int arr[n];
        for(int i  = 0; i < n;i++) cin >> arr[i];
        int max = arr[0];
        bool flag = false;
        for(int i = 1; i < n;i++){
            if(arr[i] < max){
                if(max + arr[i] > x){
                    flag = true;
                    break;
                }
            }
            if(arr[i] > max) max = arr[i];
        }
        if(!flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}
