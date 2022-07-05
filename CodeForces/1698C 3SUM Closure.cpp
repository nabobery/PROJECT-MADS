#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve(){
    int n,x;
    cin >> n;
    int count_p = 0, count_n = 0,count_z = 0;
    vector<int> res;
    for(int i = 0; i < n;i++){
        cin >> x;
        if(x > 0){
            count_p++;
            if(count_p <= 2) res.push_back(x);
        }
        else if(x < 0){
            count_n++;
            if(count_n <= 2) res.push_back(x);
        }
        else count_z++;
    }
    if(count_p > 2 || count_n > 2) cout<<"NO\n";
    else {
        if(count_z > 2) count_z = 2;
        while(count_z--) res.push_back(0);
        n = res.size();
        long long int sum;
        set<int> s(res.begin(),res.end());
        bool flag = false;
        for(int i = 0; i < n-2;i++){
            for(int j = i+1;j < n-1;j++){
                for(int k = j+1; k < n;k++){
                    sum = res[i] + res[j] + res[k];
                    if(!s.count(sum)){
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
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




