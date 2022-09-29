#include <iostream>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n,x;
    cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    sort(arr, arr+n);
    int temp, result = 0,curr;
    for(int i = n-1; i >= 0; i--){
        if(arr[i] >= x) result++;
        else{
            temp = arr[i],curr = arr[i];
            int j = i-1;
            while(j >= 0 && curr < x){
                temp = min(arr[j], temp);
                curr = (i-j+1)*temp;
                j--;
            }
            if(curr >= x){
                i = j+1;
                result++;
            }
            else break;
        }
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

