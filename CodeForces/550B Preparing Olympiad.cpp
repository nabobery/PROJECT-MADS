#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

int n,l,r,x, result = 0;

// to find all subsets and see if the given subset can be a proper problemset
void findSubsets(int arr[], vector<int> subset, int index){
    if(subset.size() >= 2){
        vector<int> temp = subset;
        int sum = 0, k = temp.size();
        sort(temp.begin(),temp.end());
        for(int i = 0; i < k;i++){
            sum += temp[i];
        }
        if((temp[k-1] - temp[0] >= x) && (sum >= l && sum <= r)) result++;
    }
    for (int i = index; i < n; i++) {
        subset.push_back(arr[i]);
        findSubsets(arr, subset, i + 1);
        subset.pop_back();
    }
    return;
}

void solve(){
    cin >> n >> l >> r >> x;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    vector<int> subset;
    findSubsets(arr,subset,0);
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}



