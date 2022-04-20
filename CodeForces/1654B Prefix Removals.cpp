#include <iostream>
#include <unordered_map>
using namespace  std;

void solve(){
    unordered_map<char,int> lastSeen;
    string str;
    cin >> str;
    for(int i = 0; i < str.size();i++){
        lastSeen[str[i]] = i;
    }
    int j = 0;
    for(int i = 0; i < str.size();i++){
        if(i ==  lastSeen[str[i]]){
            j = i;
            break;
        }
    }
    for(int i = j; i < str.size();i++){
        cout<<str[i];
    }
    cout<<"\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
