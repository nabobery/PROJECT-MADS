#include <iostream>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    string s;
    cin >> s;
    int result = s.size(), temp = 0;
    for(char c = '0'; c <= '9';c++){
        for(char ch = '0'; ch <= '9'; ch++){
            int i = 0,count = 0;
            while(i < result){
                for(; i < result;i++){
                    if(s[i] == c){
                        count++;
                        i++;
                        break;
                    }
                }
                for(; i < result;i++){
                    if(s[i] == ch){
                        count++;
                        i++;
                        break;
                    }
                }
            }
            if(c != ch && count % 2) count--;
            temp = max(temp,count);
        }
    }
    result -= temp;
    cout<<result<<"\n";
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






