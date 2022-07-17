#include <iostream>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

void solve(){
    ordered_set s;
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    for(int i = 0; i < k;i++) s.insert({arr[i],i});
    cout<<s.find_by_order((k-1)/2)->first<<" ";
    for(int i = k; i < n;i++){
        s.erase({arr[i-k],i-k});
        s.insert({arr[i],i});
        cout<<s.find_by_order((k-1)/2)->first<<" ";
    }
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}


