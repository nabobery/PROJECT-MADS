#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    for(int i = 0; i < t;i++){
        cin >> n;
        int arr[n];
        int result = 1;
        cin >> arr[0];
        int min = arr[0];
        for(int j = 1; j < n;j++){
            cin >> arr[j];
            if(arr[j] <= min){
                result++;
            }
            if(arr[j] < min){
                min = arr[j];
            }
        }
        cout<<result<<"\n";
    }
	return 0;
}
