#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n,k;
    cin >> n >> k;
    string s,result,temp;
    cin >> s;
    result = s;
    vector<int>counter(10, 0);
    for(auto ch : s) counter[ch - '0']++;
    int res = 1e9;
    for(int i = 0; i < 10;i++){
        int count = counter[i],minimum = 0;
        temp = s;
        char ch = i + '0';
        for(int j = 1; j < 10 && count < k;j++){
            if(ch + j <= '9'){
                for(int l = 0; l < n && count < k;l++){
                    if(temp[l] == ch + j){
                        minimum += j;
                        temp[l] = ch;
                        count++;
                    }
                }
            }
            if(ch - j >= '0'){
                for(int l = n-1; l >= 0 && count < k;l--){
                    if(temp[l] == ch - j){
                        minimum += j;
                        temp[l] = ch;
                        count++;
                    }
                }
            }
        }
        if(minimum < res){
            res = minimum;
            result = temp;
        }
        if(res == minimum && temp < result){
            result = temp;
        }
    }
    cout<<res<<"\n";
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}


