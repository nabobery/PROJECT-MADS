#include <iostream>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    string n, res = "";
    int s,sum = 0;
    cin >> n >> s;
    for(auto  ch : n) sum += (ch - '0');
    if(sum <= s) cout<<"0\n";
    else{
        int k = n.size();
        char ch;
        if(n[k-1] != '0'){
            ch = (( '9' - n[k-1]) + 1) + '0';
            res += ch;
            sum -= (n[k-1] - '0');
            int carry = 1, j = k-2;
            n[k-1] = '0';
            while(carry && j >= 0){
                int temp = n[j] - '0' + carry;
                if(temp/10){
                    sum -= (n[j] - '0');
                    n[j] = '0';
                    carry = 1;
                }
                else{
                    sum += (temp - (n[j] - '0'));
                    n[j] += 1;
                    carry = 0;
                }
                j--;
            }
        }
        else res += '0';
        for(int i =  k - 2; i >= 0 && sum > s;i--){
            if(n[i] != '0'){
                ch = (( '9' - n[i]) + 1) + '0';
                res += ch;
                sum -= (n[i] - '0');
                n[i] = '0';
                int carry = 1, j = i-1;
                while(carry && j >= 0){
                    int temp = n[j] - '0' + carry;
                    if(temp/10){
                        sum -= (n[j] - '0');
                        n[j] = '0';
                        carry = 1;
                    }
                    else{
                        sum += (temp - (n[j] - '0'));
                        n[j] += 1;
                        carry = 0;
                    }
                    j--;
                }
            }
            else res += '0';
        }
        reverse(res.begin(),res.end());
        cout<<res<<"\n";
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
