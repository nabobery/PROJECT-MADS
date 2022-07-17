#include <iostream>
#include <set>
using namespace std;

void solve(){
    int n, x,t;
    cin >> x >> n;
    set<int> s;
    s.insert(0);
    s.insert(x);
    multiset<int> distance;
    distance.insert(x);
    for(int i = 0; i < n;i++){
        cin >> t;
        auto it1 = s.upper_bound(t);
        auto it2 = it1;
        it2--;
        distance.erase(distance.find(*it1 - *it2));
        distance.insert(*it1 - t);
        distance.insert(t - *it2);
        s.insert(t);
        it1 = distance.end();
        it1--;
        cout<<*it1<<" ";
    }
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}





