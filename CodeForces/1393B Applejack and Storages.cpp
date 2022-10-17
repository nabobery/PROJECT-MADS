#include <iostream>
#include <map>
using namespace std;

#pragma GCC optimize("Ofast")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>

void myerase(ordered_set &t, int v){
    int rank = t.order_of_key(v);//Number of elements that are less than v in t
    ordered_set::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}

int l = 1e5 + 1;

void solve(){
    int n,x,q;
    cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n;i++){
        cin >> x;
        mp[x]++;
    }
    ordered_set counter;
    for(auto it : mp){
        counter.insert(it.second);
    }
    char sign;
    cin >> q;
    for(int i = 0; i < q;i++){
        cin >> sign >> x;
        if(sign == '+'){
            int temp = mp.count(x) ? mp[x] : 0;
            mp[x]++;
            counter.insert(mp[x]);
            if(temp != 0) myerase(counter, temp);
        }
        else{
            int temp = mp[x];
            mp[x]--;
            counter.insert(mp[x]);
            myerase(counter, temp);
        }
        int t1 = counter.order_of_key(8) - counter.order_of_key(6), t2 = counter.order_of_key(4) - counter.order_of_key(2), t3 = counter.order_of_key(6) - counter.order_of_key(4);
        if(counter.order_of_key(l) - counter.order_of_key(8) >= 1) cout<<"YES\n";
        else if(t1 > 1 || (t1 == 1 && (t2 >= 1 || t3 >= 1))) cout<<"YES\n";
        else if(t3 > 1 || (t3 == 1 && t2 > 1)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}




