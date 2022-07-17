#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
    int n, x;
    cin >> n;
    cin >> x;
    vector<int> vec;
    vec.push_back(x);
    for(int i = 1; i < n;i++){
        cin >> x;
        auto it = upper_bound(vec.begin(),vec.end(),x);
        if(it != vec.end()){
            vec[it-vec.begin()] = x;
        }
        else vec.push_back(x);
    }
    cout<<vec.size()<<"\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}




