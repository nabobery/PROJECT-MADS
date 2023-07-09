#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
 
#pragma GCC optimize("Ofast")
 
#define ll long long int
#define pi pair<int,int>
 
class Compare{
public:
    bool operator()(pi a, pi b){
        int l1 = a.second - a.first, l2 = b.second - b.first;
        if(l1 != l2) return l1 < l2;
        return a.first > b.first;
    }
};
 
void solve(){
    int n;
    cin >> n;
    priority_queue<pi, vector<pi>, Compare> pq;
    pq.push({1,n});
    int arr[n];
    int p = 1;
    while (!pq.empty()){
        pi temp = pq.top();
        //cout<<temp.first<<" "<<temp.second<<"\n";
        pq.pop();
        int l = temp.second - temp.first + 1;
        if(l == 1){
            arr[temp.first-1] = p;
        }
        else if(l == 2){
            arr[temp.first-1] = p;
            pq.push({temp.second, temp.second});
        }
        else{
            if(l%2){
                arr[temp.first + l/2 -1] = p;
                pq.push({temp.first, temp.first + l/2-1});
                pq.push({temp.first + l/2 +1, temp.second});
            }
            else{
                arr[temp.first + l/2 - 2] = p;
                pq.push({temp.first, temp.first + l/2 - 2});
                pq.push({temp.first + l/2,temp.second});
            }
        }
        p++;
    }
    for(auto i : arr) cout<<i<<" ";
    cout<<"\n";
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