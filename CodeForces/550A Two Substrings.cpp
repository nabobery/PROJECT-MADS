#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    string s;
    cin >> s;
    int j = -1,k = -1;
    for(int i = 0; i < s.size()-1;i++){
        if(s[i] == 'A' && s[i+1] == 'B'){
            j = i;
            break;
        }
    }
    for(int i = j+2; i < s.size();i++){
        if(s[i] == 'B' && s[i+1] == 'A'){
            k = i;
            break;
        }
    }
    if(j != -1 && k != -1) cout<<"YES\n";
    else{
        j = -1, k= -1;
        for(int i = 0; i < s.size()-1;i++){
            if(s[i] == 'B' && s[i+1] == 'A'){
                j = i;
                break;
            }
        }
        for(int i = j+2; i < s.size();i++){
            if(s[i] == 'A' && s[i+1] == 'B'){
                k = i;
                break;
            }
        }
        if(j != -1 && k != -1) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}





