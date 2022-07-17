#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

// Total time complexity is O(nlog(sum))

// greedy way of checking if count of subarray sums less than mid is <= k
bool check(ll mid, vector<int> arr,int k){
    int count = 0;
    ll sum = 0;
    for(int a : arr){
        if(a > mid) return false;
        sum += a;
        if(sum > mid){
            sum = a;
            count++;
        }
    }
    count++;
    return (count <= k);
}

void solve(){
    int n,k, max = 0;
    cin >> n >> k;
    vector<int> arr(n);
    ll sum = 0;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        sum += arr[i];
        if(arr[i] > max) max = arr[i];
    }
    ll low = max, high = sum,mid, result = sum;
    // binary searching for the minimum max subarray sum
    while(low <= high){
        mid = (low+high)/2;
        if(check(mid,arr,k)){
            if(mid < result) result = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}



