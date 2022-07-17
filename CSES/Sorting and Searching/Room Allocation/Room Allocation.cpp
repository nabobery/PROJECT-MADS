#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct customer{
    int arrival, departure, index;
};

bool customCompare(customer a, customer b){
    return a.arrival < b.arrival;
}

void solve(){
    int n;
    cin >> n;
    vector<customer> customers(n);
    for(int i = 0; i < n;i++){
        cin >> customers[i].arrival >> customers[i].departure;
        customers[i].index = i;
    }
    sort(customers.begin(),customers.end(), customCompare);
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
    vector<int> rooms(n);
    int room = 1;
    q.push({customers[0].departure,customers[0].index});
    rooms[customers[0].index] = room;
    for(int i = 1; i < n;i++){
        if(q.top().first < customers[i].arrival){
            rooms[customers[i].index] = rooms[q.top().second];
            q.pop();
            q.push({customers[i].departure,customers[i].index});
        }
        else{
            q.push({customers[i].departure,customers[i].index});
            room++;
            rooms[customers[i].index] = room;
        }
    }
    cout<<room<<"\n";
    for(auto r : rooms) cout<<r<<" ";
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}





