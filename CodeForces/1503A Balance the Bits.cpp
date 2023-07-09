#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
 
#pragma GCC optimize("Ofast")
 
#define ll long long int
 
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s[0] == '0' || s[n-1] == '0') cout<<"NO\n";
    else{
        int zeroes = 0;
        for(auto ch : s) if(ch == '0') zeroes++;
        if(zeroes%2) cout<<"NO\n";
        else{
            cout<<"YES\n";
            int ones = n - zeroes, temp = zeroes;
            bool flag = false;
            for(int i = 0; i < n;i++){
                if(s[i] == '0'){
                    if(temp%2)cout<<")";
                    else cout<<"(";
                    temp--;
                }
                else{
                    ones--;
                    if(!flag){
                        cout<<"(";
                        if(ones <= (n-zeroes)/2) flag = true;
                    }
                    else{
                        cout<<")";
                    }
                }
            }
            cout<<"\n";
            flag = false;
            temp = zeroes, ones = n -zeroes;
            for(int i = 0; i < n;i++){
                if(s[i] == '0'){
                    if(temp%2)cout<<"(";
                    else cout<<")";
                    temp--;
                }
                else{
                    ones--;
                    if(!flag){
                        cout<<"(";
                        if(ones <= (n-zeroes)/2) flag = true;
                    }
                    else{
                        cout<<")";
                    }
                }
            }
            cout<<"\n";
        }
    }
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