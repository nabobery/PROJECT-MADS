#include <iostream>
using namespace  std;

bool arr[26];

int check(string s, char c){
    int r = s.size() - 1, l = 0, count = 0;
    while(r > l){
        if(s[r] == s[l]){
            l++;
            r--;
            continue;
        }
        else {
            if(s[r] == c){
                count++;
                r--;
            }
            else if(s[l] == c){
                count++;
                l++;
            }
            else return -1;
        }
    }
    return count;
}

void solve(){
    int n, result = 200000;
    string s;
    cin >> n >> s;
    for(int i = 0; i < 26;i++) arr[i] = false;
    for(int i = 0; i < n;i++){
        arr[s[i] - 'a'] = true;
    }
    for(int i = 0; i < 26;i++){
        if(arr[i]){
            char ch = 'a' + i;
            int temp = check(s,ch);
            if(temp == -1) continue;
            else{
                if(result > temp) result = temp;
            }
        }
    }
    if(result == 200000) cout<<"-1\n";
    else cout<<result<<"\n";
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

