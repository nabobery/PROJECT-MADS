#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

// moves when we arrange sheep such that they start from x => x1,x2,x3,....xk where k is number of sheep
// total number of moves = abs(s1 - x) + abs(s2 - (x+1) + .... abs(sk - (x+k-1))
ll moves(vector<int>&a, ll x){
    ll result = 0;
    for(int i = 0; i < a.size();i++){
        result += abs(a[i] -(x+i+1));
    }
    return result;
}

// O(nlogn) Solution 1
void solve(){
    int n;
    string str;
    cin >> n >> str;
    vector<int> arr;
    // get sheep positions
    for(int i = 0; i < n;i++){
        if(str[i] == '*') arr.push_back(i+1);
    }
    ll l = 0, r = 1e12;
    // store some result
    ll result = moves(arr,0);
    // binary search for the position where the line of sheep begins which gives the minimum number of moves
    while(l <= r){
        ll mid = (l+r)/2;
        ll temp = moves(arr,mid);
        ll temp1 = moves(arr,mid+1);
        // get min of result, moves(mid), moves(mid+1)
        result= min(result,min(temp,temp1));
        // if we're seeing a decreasing trend(moves(mid) > moves(mid+1)) go right
        if(temp > temp1) l = mid+1;
        // else go left
        else r = mid-1;
    }
    cout<<result<<"\n";
}

// Solution 2 is O(n), We make use of the observation that middle sheep(ceil(numberofsheeps)/2) doesn't move when we get optimal number of moves
// So using this fixed position of the middle sheep, we calculate how many moves we make to get the optimal solution

void solve(){
    int n,cnt = 1;
    string str;
    cin >> n >> str;
    int s[n];
    for(int i = 0; i < n;i++){
        if(str[i] == '*') s[cnt++] = i;
    }
    int mid = cnt/2;
    long long int result = 0;
    for(int i = 1; i < cnt;i++){
        result += abs(s[i] - s[mid] + mid - i);
    }
    cout<<result<<"\n";
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

