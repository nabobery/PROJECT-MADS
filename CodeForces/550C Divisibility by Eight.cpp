#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

// brute force by checking if the last 3 digits of the number is divisible by 8
void solve(){
    string s;
    cin >> s;
    bool flag = false;
    int n = s.size(),result;
    for(int i = 0; i < n;i++){
        int temp = s[i] - '0';
        if(temp % 8 == 0){
            flag = true;
            result = temp;
            break;
        }
        for(int j = i+1; j < n;j++){
            temp = s[i] - '0';
            temp *= 10;
            temp += (s[j] - '0');
            if(temp % 8 == 0){
                flag = true;
                result = temp;
                break;
            }
            for(int k = j+1; k < n;k++){
                temp = 10*(s[i] - '0') + (s[j] - '0');
                temp *= 10;
                temp += (s[k] - '0');
                if(temp % 8 == 0){
                    flag = true;
                    result = temp;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) break;
    }
    cout<<(flag ? "YES\n" : "NO\n");
    if(flag) cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}






