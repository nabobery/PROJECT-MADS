#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    string s;
    cin >> s;
    bool flag1 = isupper(s[0]), flag2;
    if(!flag1){
        flag2 = true;
        for(int i = 1; i < s.size();i++){
            if(isupper(s[i]) == flag2) continue;
            else{
                flag2 = false;
                break;
            }
        }
        if(flag2){
            s[0] = toupper(s[0]);
            for(int i = 1; i < s.size();i++) s[i] = tolower(s[i]);
            cout<<s<<"\n";
        }
        else{
            cout<<s<<"\n";
        }
    }
    else{
        flag2 = true;
        for(int i = 1; i < s.size();i++){
            if(isupper(s[i]) == flag2) continue;
            else{
                flag2 = false;
                break;
            }
        }
        if(flag2){
            for(int i = 0; i < s.size();i++) s[i] = tolower(s[i]);
            cout<<s<<"\n";
        }
        else cout<<s<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

