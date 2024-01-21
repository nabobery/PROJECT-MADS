#include <iostream>
#include <cstring>

using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

const int mod = 1e9 + 7;

// dp for memoization
ll dp[20][10][2][2];

// A function to return count of numbers from 0 to num where no two adjacent digits are the same
// This function takes the following arguments
// string number, number size, prev digit, current index of number, if the number can have leading zeroes, tight bound for the number
ll helper(string& num, int n, int prev_dig, int i, bool leading_zeroes, bool tight){
    // if we reached the end successfully
    if(i == n) return 1;
    // if not first digit and already calculated return it
    if(prev_dig != -1 && dp[i][prev_dig][leading_zeroes][tight] != -1) return dp[i][prev_dig][leading_zeroes][tight];
    // lower bound for digit and upperbound is the digit itself if tight else 9
    int lb = 0, ub = tight ? (num[i]-'0'):9;
    ll res = 0;
    // traverse all possible digits
    for(int d = lb; d <= ub;d++){
        // if prev dig is same as current digit and dig != 0 because we can have leading zeroes
        if(d==prev_dig && d!=0) continue;
        // if we can't have leading zeroes continue
        if(d==prev_dig && d==0 && leading_zeroes==0) continue;
        // go to the next digit and see if the current digit is ending zero and if the current digit gives a tight bound
        res += helper(num,n,d,i+1,leading_zeroes&d==0 ,tight&(d==ub));
    }
    // store the answer and return it
    return dp[i][prev_dig][leading_zeroes][tight] = res;
}

// res = helper(b) - helper(a-1)
void solve(){
    ll a,b;
    cin >> a >> b;
    string a_s = to_string(a-1), b_s = to_string(b);
    memset(dp, -1, sizeof(dp));
    ll res = helper(b_s,b_s.size(), -1,0,true,true);
    memset(dp, -1, sizeof(dp));
    res -= helper(a_s,a_s.size(), -1,0,true,true);
    cout<<res<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}





