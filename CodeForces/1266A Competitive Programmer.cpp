#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    string s;
    cin >> s;
    int counter[10];
    for(int i = 0; i < 10;i++) counter[i] = 0;
    for(auto ch : s){
        counter[ch - '0']++;
    }
    if(counter[0] == 0) cout<<"cyan\n";
    else{
        int sum = 0;
        for(int i = 1; i < 10;i++){
            if(i%3){
                sum += (i)*counter[i];
            }
        }
        if(sum % 3 != 0) cout<<"cyan\n";
        else{
            bool flag = counter[0] > 1;
            for(int i = 2; i < 10;i+=2){
                if(counter[i]){
                    flag = true;
                    break;
                }
            }
            cout<<(flag ? "red\n" : "cyan\n");
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
