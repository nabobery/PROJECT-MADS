#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

// The strategy for Tina is to sit at the ends so that she can get the maximum possible distance from Rahul and Rahul would like to sit at a
// place where distance from all ends is minimum
// Therefore Tina would paint the seats that are minimum distance from the ends
// So, we just find the max distances from ends from the given seat and then sort them. This is the min max distance for Rahul and Tina when k = i
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= m;j++){
            int dist1 = max(abs(n-i) + abs(m-j), abs(n-i) + abs(j-1));
            int dist2 = max(abs(i-1) + abs(m-j), abs(i-1) + abs(j-1));
            arr.push_back(max(dist1,dist2));
        }
    }
    sort(arr.begin(),arr.end());
    for(int k : arr) cout<<k<<" ";
    cout<<"\n";
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
