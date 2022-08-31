#include <iostream>
#include <set>
using namespace std;

// As n*k <= 10^4, we can use this strategy
void solve(){
    int n, k,x;
    cin >> n >> k;
    set<int> s;
    for(int i = 0; i < n;i++){
        cin >> x;
        s.insert(x);
    }
    // if number of unique elements greater than k it's not possible to get same sum using same set of elements
    if(s.size() > k) cout<<"-1\n";
    // if  number of unique elements equal to k, we can just print it n times as it will be periodic with same sum
    else if(s.size() == k){
        cout<<n*k<<"\n";
        string temp = "";
        for(auto itr : s){
            temp += to_string(itr);
            temp += " ";
        }
        for(int i = 0; i < n;i++){
            cout<<temp;
        }
        cout<<"\n";
    }
    // if  number of unique elements less than k, we just use unique elements + k-c other elements (like 1) and print it n times to get beautiful array
    else{
        cout<<n*k<<"\n";
        string temp = "";
        for(auto itr : s){
            temp += to_string(itr);
            temp += " ";
        }
        for(int i = s.size(); i < k;i++){
            temp += "1 ";
        }
        for(int i = 0; i < n;i++){
            cout<<temp;
        }
        cout<<"\n";
    }
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




