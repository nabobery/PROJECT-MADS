#include <iostream>
#include<vector>
using namespace  std;

void solve(){
    string s, t;
    cin >> s >> t;
    vector<int> count1(26,0), count2(26,0);
    for(int i = 0; i < t.size();i++){
        count1[t[i] - 'A']++;
    }
    for(int i = 0; i < s.size();i++){
        count2[s[i] - 'A']++;
    }
    for(int i = 0; i < s.size(); i++){
        if(count2[s[i] - 'A'] - count1[s[i] - 'A'] == 0) continue;
        else{
            count2[s[i] - 'A']--;
            s[i] = '#';
        }
    }
    string result = "";
    for(int i = 0; i < s.size();i++){
        if(s[i] != '#') result += s[i];
    }
    if(result == t) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


