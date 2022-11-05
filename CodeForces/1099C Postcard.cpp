#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    string s,result;
    int k, sn = 0, c = 0, n;
    cin >> s >> k;
    for(auto ch : s){
        if(ch  == '*') sn++;
        else if(ch == '?') c++;
    }
    n = s.size() - sn - c;
    if(sn == 0){
        if((n-c) <= k && k <= n){
            int counter = n - k;
            for(auto ch : s){
                if(ch == '?'){
                    if(counter > 0){
                        counter--;
                        result.pop_back();
                    }
                }
                else result.push_back(ch);
            }
            cout<<result<<"\n";
        }
        else cout<<"Impossible\n";
    }
    else{
        if((n-c-sn) <= k){
            int counter = k - n;
            if(counter <= 0){
                for(auto ch : s){
                    if(ch == '?' || ch == '*'){
                        if(counter < 0){
                            counter++;
                            result.pop_back();
                        }
                    }
                    else result.push_back(ch);
                }
            }
            else{
                bool flag = true;
                for(int i = 0; i < s.size();i++){
                    if(s[i] != '*' && s[i] != '?') result.push_back(s[i]);
                    else if(s[i] == '*'){
                        if(flag){
                            while(counter > 0){
                                result.push_back(s[i-1]);
                                counter--;
                            }
                            flag = false;
                        }
                    }
                }
            }
            cout<<result<<"\n";
        }
        else cout<<"Impossible\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

