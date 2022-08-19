#include <iostream>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int counter[26] = {0};
    for(int i = 0; i < s.size();i++){
        counter[s[i] - 'a']++;
    }
    int odd = 0;
    for(int i = 0; i < 26;i++){
        if(counter[i]%2) odd++;
    }
    // if number of characters having odd occurrence is <= 1 (it means the string has even (if 0) => can reorder for palindrome else can take one char and make it a palindrome)
    if(odd <= 1) cout<<"First\n";
        // else the person who changes to odd = 1 loses
    else{
        // it means when odd = 1, it's first's turn
        if(odd % 2) cout<<"First\n";
            // it means when odd = 1, it's second's turn
        else cout<<"Second\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}




