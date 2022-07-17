#include <iostream>
#include <map>
using namespace std;

// Sliding Window Algorithm
void solve(){
    int n,k;
    cin >> n >> k;
    int arr[n];
    long long int result = 0;
    for(int i = 0; i < n;i++) cin >> arr[i];
    int l = 0,size = 0;
    map<int,int> mp;
    // increment the right pointer until size = k
    for(int r = 0; r < n;r++){
        mp[arr[r]]++;
        if(mp[arr[r]] == 1) size++;
        // if we are at a point where subarray [l,r] has size > k, increment the left pointer and slide the window until size == k
        while(size > k){
            mp[arr[l]]--;
            if(mp[arr[l]] == 0) size--;
            l++;
        }
        // increment the result by size of the subarray as number of subarrays possible will be size of
        // the subarray(as subarray has atmost k distinct values)
        result += (r-l+1);
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}



