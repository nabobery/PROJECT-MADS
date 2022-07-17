#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

void solve(){
    int n,k;
    cin >> n >> k;
    ordered_set s;
    for(int i = 1; i <= n;i++){
        s.insert(i);
    }
    long long int index  = 0;
    while(s.size() > 1){
        index = ((index + k) % s.size());
        cout<<*s.find_by_order(index)<<" ";
        s.erase(*s.find_by_order(index));
        index %= s.size();
    }
    cout<<*s.find_by_order(0)<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}





