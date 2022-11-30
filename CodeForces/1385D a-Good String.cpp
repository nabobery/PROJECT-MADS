#include <iostream>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

// recursive function where at every step we see which is the best move (O(nlogn) solution where n is for calculating count and logn for dividing the string by 2)
int helper(string s, char c){
    // if string is of size 1, then if s == c then s is a good string, we need 0 moves if s[0] == c else 1
    if(s.size() == 1) return s[0] != c;
    // get midpoint of string
    int mid = s.size()/2;
    // if we take 1st part of string to be made as a c+1 good string
    int countl = helper(string(s.begin(),s.begin() + mid), c+1);
    // then 2nd part must be a c-good string => number of moves = size - number of c's in string
    countl += s.size()/2 - count(s.begin() + mid, s.end(), c);
    // if we take 2nd part of string to be called a c+1 good string
    int countr = helper(string(s.begin() + mid, s.end()), c+1);
    // then 1st part must be a c-good string => number of moves = size - number of c's in string
    countr += s.size()/2 - count(s.begin(), s.begin() + mid, c);
    // return minimum
    return min(countl,countr);
}

void solve(){
    int n;
    string s;
    cin >> n >> s;
    cout<<helper(s,'a')<<"\n";
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

