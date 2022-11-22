#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    ll k, temp;
    cin >> k;
    int res = 1;
    string word = "codeforces";
    for(int i = 2; ;i++) {
        temp = 1;
        for (int j = 0; j < 10; j++) temp *= i;
        if (temp >= k) {
            res = i - 1;
            break;
        }
    }
    vector<int> t(10,res);
    temp = 1;
    for(int i = 0; i < 10;i++) temp *= res;
    if(temp >= k){
        for(int i = 0; i < 10;i++){
            for(int j = 0; j < t[i];j++) cout<<word[i];
        }
        cout<<"\n";
    }
    else{
        for(int i = 0; i < 10;i++){
            t[i]++;
            temp /= res;
            temp *= t[i];
            if(temp >= k) break;
        }
        for(int i = 0; i < 10;i++){
            for(int j = 0; j < t[i];j++) cout<<word[i];
        }
        cout<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

