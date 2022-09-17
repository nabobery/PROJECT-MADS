#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n, d = 0;
    string s;
    cin >> n >> s;
    for(char ch : s)
        if(ch == 'D') d++;
    if(d > (n-d)) cout<<"Danik\n";
    else if(d == (n-d)) cout<<"Friendship\n";
    else cout<<"Anton\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

