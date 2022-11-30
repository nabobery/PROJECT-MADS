#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n;
    string s;
    cin >> n >> s;
    // pos0 is for storing the subsequences that end with 0 and vice versa
    vector<int> pos0, pos1,result(n);
    for(int i = 0; i < n;i++){
        int newSubsequence = pos0.size() + pos1.size();
        // if we get 0
        if(s[i] == '0'){
            // if there's a subsequence ending with 1, we use that subsequence to insert 0 so that we get minimum number of subsequence
            if(!pos1.empty()){
                newSubsequence = pos1.back();
                pos1.pop_back();
            }
            // else push_back new subsequence
            pos0.push_back(newSubsequence);
        }
        else{
            // if there's a subsequence ending with 0, we use that subsequence to insert 1 so that we get minimum number of subsequence
            if(!pos0.empty()){
                newSubsequence = pos0.back();
                pos0.pop_back();
            }
            // else push_back new subsequence
            pos1.push_back(newSubsequence);
        }
        // store the subsequence for that current char
        result[i] = newSubsequence+1;
    }
    cout<<pos0.size() + pos1.size()<<"\n";
    for(auto res : result) cout<<res<<" ";
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




