#include <iostream>
using namespace  std;

void solve(){
    string s;
    cin >> s;
    int count  = 0;
    bool flag = false;
    for(int i = 0; i < s.size();i++){
        if(s[i] == '1'){
            while(s[i] == '1'){
                count++;
                i++;
            }
            if(count >= 7){
                flag = true;
                cout<<"YES\n";
                break;
            }
            count = 0;
            i--;
        }
        else{
            while(s[i] == '0'){
                count++;
                i++;
            }
            if(count >= 7){
                flag = true;
                cout<<"YES\n";
                break;
            }
            count = 0;
            i--;
        }
    }
    if(!flag) cout<<"NO\n";
}

int main() {
    solve();
    return 0;
}


