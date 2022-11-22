#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n,x;
    cin >> n;
    ll sum = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    // a greedy solution which takes potions at every point such that it's not negative such that we take max number of potions
    for(int i = 0; i < n;i++){
        cin >> x;
        sum += x;
        pq.push(x);
        // we greedily remove potions that make our sum negative and proceed again
        while(sum < 0){
            sum -= pq.top();
            pq.pop();
        }
    }
    cout<<pq.size()<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}