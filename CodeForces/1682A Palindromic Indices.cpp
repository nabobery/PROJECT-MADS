#include <iostream>
using namespace std;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    int result = 0;
    if(n % 2){
        for(int i = n/2;i > 0; i--){
            if(s[i] == s[i-1]) result++;
            else break;
        }
        for(int i = n/2;i < n-1; i++){
            if(s[i] == s[i+1]) result++;
            else break;
        }
        result++;
    }
    else{
        for(int i = n/2-1;i > 0; i--){
            if(s[i] == s[i-1]) result++;
            else break;
        }
        for(int i = n/2;i < n-1; i++){
            if(s[i] == s[i+1]) result++;
            else break;
        }
        result += 2;
    }
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



