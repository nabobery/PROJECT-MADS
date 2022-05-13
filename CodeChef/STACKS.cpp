#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, n,x;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> stk;
        int arr[n];
        for(int i = 0; i < n;i++){
            cin >> arr[i];
        }
        int max = arr[0];
        stk.push_back(arr[0]);
        for(int i = 1; i < n;i++){
            if(arr[i] >= max){
                stk.push_back(arr[i]);
                max = arr[i];
            }
            else{
                auto upper = std::upper_bound(stk.begin(), stk.end(), arr[i]);
                int ind = upper - stk.begin();
                if(ind == stk.size() - 1){
                    stk[ind] = arr[i];
                    max = stk[ind];
                }
                else{
                    stk[ind] = arr[i];
                }
            }
        }
        cout<<stk.size()<<" ";
        for(int i = 0; i < stk.size();i++){
            cout<<stk[i]<<" ";
        }
        cout<<"\n";
    }
	return 0;
}
