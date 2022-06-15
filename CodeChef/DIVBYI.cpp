#include <iostream>

using namespace std;

int main() {
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];
        int i = n;
        int j = 1;
        for(int k = n - 1; k > -1;k--){
            if(k % 2 == 0){
                arr[k] = j;
                j++;
            }
            else{
                arr[k] = i;
                i--;
            }
        }
        for(int i = 0; i < n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
	return 0;
}
