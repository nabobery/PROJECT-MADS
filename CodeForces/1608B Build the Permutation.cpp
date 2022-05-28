#include <iostream>
#include <vector>
#include <cstdlib>
using namespace  std;

void solve(){
    int n, a , b;
    cin >> n >> a >> b;
    if(a + b + 2 > n || abs(a-b) > 1) cout <<"-1\n";
    else {
        vector<int> result;
        for(int i = 1; i < (n - a - b - 1);i++) result.push_back(i);
        for(int i = n;i >= n - a - b -1; i -= 2){
            if(i == (n - a -b - 1)) result.push_back(i);
            else{
                result.push_back(i-1);
                result.push_back(i);
            }
        }
        if(a >= b){
            for(int num : result) cout<<num<<" ";
            cout<<"\n";
        }
        else{
            for(int i = 0; i < n;i++){
                result[i] = n - result[i] + 1;
            }
            for(int num : result) cout<<num<<" ";
            cout<<"\n";
        }
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

