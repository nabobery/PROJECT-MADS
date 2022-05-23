#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;

vector<int> sugar(150001);

void solve(){
    int n, q,x;
    cin >> n >> q;
    long long int sum = 0;
    for(int i = 0; i < n;i++){
        cin >> sugar[i];
    }
    sort(sugar.begin(),sugar.begin() + n, greater<int>());
    vector<int> prefixsum;
    for(int i = 0; i < n;i++){
        sum += sugar[i];
        prefixsum.push_back(sum);
    }
    for(int i = 0; i < q;i++){
        cin >> x;
        if(x > prefixsum[n-1]) cout<< "-1 \n";
        else{
            int pos = lower_bound(prefixsum.begin(),prefixsum.end(), x) - prefixsum.begin();
            cout<< pos + 1 <<"\n";
        }
        /* using binary search
            int l = 1, r = n, result = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(prefixsum[mid - 1] >= x) {
                    result = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            cout << result << "\n";
        */
    }
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




