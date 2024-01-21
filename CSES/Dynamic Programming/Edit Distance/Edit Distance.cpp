#include <iostream>
#include <vector>
#include <unordered_map>
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

int helper(string& s1, string& s2, int n, int m){
    // dp[i][j] is the edit distance to convert s1[0...i] to s2[0...j]
    int dp[5001][5001];
    // base case if we reached the start of s1, we return m as we would need to insert m characters
    if(n == 0) return m;
    // base case if we reached the start of s2, we return m as we would need to delete n characters
    if(m == 0) return n;
    // if already calculated then return
    if(dp[n][m] != -1) return dp[n][m];
    // if both characters match we proceed by moving the pointer backwards for both strings
    if(s1[n-1] == s2[m-1]) return dp[n][m] = helper(s1,s2,n-1,m-1);
    // if we insert a new character to s1
    int insert = helper(s1,s2,n, m-1);
    // if we replace a character in s1
    int replace = helper(s1,s2, n-1, m-1);
    // if we delete a character in s1
    int remove = helper(s1,s2, n-1, m);
    // return the minimum number of moves taken by either insertion, replacing, deletion
    return dp[n][m] = 1 + min({insert, replace, remove});
}

// O(nm) time complexity and O(nm) space complexity top down DP Solution
void solve1(){
    string s1, s2;
    cin >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    cout<<helper(s1,s2, s1.size(), s2.size())<<"\n";
}

// O(nm) time complexity and O(nm) space complexity bottom up DP Solution
void solve2(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    // dp[i][j] represents the minimum number of operations to convert s1[0..i) to s2[0..j)
    int dp[n+1][m+1];
    // if any of the string is empty then return the length of other string
    // if s2 is empty then we need to remove all the characters of s1
    for(int i = 0; i <= n;i++) dp[i][0] = i;
    // if s1 is empty then we need to insert all the characters of s2
    for(int j = 0; j <= m;j++) dp[0][j] = j;
    // if last characters of both the strings are same then we don't need to do any operation
    // else we need to perform one of the three operations
    // replace the last character of s1 with last character of s2
    // insert the last character of s2 at the end of s1
    // remove the last character of s1
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= m;j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
        }
    }
    cout<<dp[n][m]<<"\n";
}

// O(nm) time complexity and O(m) space complexity bottom up DP Solution
void solve3(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    // dp[i] represents the edit distance to convert s1[0...n] to s2[0...i]
    // this helps us to store only row if information and makes us not store unnecessary n rows of info
     int dp[m+1];
     // base case if s1 is empty then we need to insert all the characters of s2 => dp[0][i] = i
    for(int i = 0; i <= m;i++) dp[i] = i;
    // we traverse row by row and update column information
    for(int i = 1; i <= n;i++){
        // prev is initialised to represent dp[i-1][0] and is used to represent dp[i-1][j-1] info
        int prev = dp[0];
        // if s2 is empty then we need to remove all the characters of s1
        dp[0] = i;
        for(int j = 1; j <= m;j++){
            // we store the dp[i-1][j-1] in temp to use it later
            int temp = dp[j];
            // if characters of both the strings are same then we don't need to do any operation
            if(s1[i-1] == s2[j-1]) dp[j] = prev;
            // else we see which one os the operations is better
            // dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            else dp[j] = 1 + min({prev, dp[j], dp[j-1]});
            // now we update prev to use it in the next iteration
            prev = temp;
        }
    }
    cout<<dp[m]<<"\n";
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




