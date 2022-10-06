#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("Ofast")

// greedy solution
void solve(){
    string s;
    cin >> s;
    vector<string> result;
    string temp,end;
    temp.append(s.size(), '1');
    end.append(s.size(), '0');
    // find the optimal quasi binary to be subtracted, the way is whenever we find a digit which is not 0, we keep that digit as 1 in quasi binary else 0
    // in this way we get the minimum number of quasi binary numbers
    while(true){
        temp = "";
        for(int i = 0; i < s.size();i++){
            if(s[i] != '0'){
                s[i]--;
                temp += '1';
            }
            else temp += '0';
        }
        if(temp != end) result.push_back(temp);
        else break;
    }
    cout<<result.size()<<"\n";
    for(auto it : result) cout<<stoi(it)<<" ";
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
