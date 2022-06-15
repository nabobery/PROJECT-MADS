#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace  std;

void solve(){
    int n,x,y;
    cin >> n;
    vector<pair<int,int>> time;
    for(int i = 0; i < n;i++){
        cin >> x >> y;
        time.push_back({x,y});
    }
    // sorting based on arrival time
    sort(time.begin(),time.end());
    // using a min heap to store departure time
    priority_queue<int, vector<int>, greater<int> > q;
    int result = 1;
    q.push(time[0].second);
    // finding out the maximum number of customers in the restaurant at any time
    for(int i = 1; i < n;i++){
        if(q.top() > time[i].first) result++;
        else q.pop();
        q.push(time[i].second);
    }
    cout<<result<<"\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

