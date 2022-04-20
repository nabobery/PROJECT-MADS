#include <iostream>
#include<set>
using namespace  std;

void solve(){
    int n,temp;
    cin >> n;
    set<int> s;
    for(int i = 0 ; i < n;i++){
        cin >> temp;
        if(!s.count(temp)) s.insert(temp);
    }
    int m  = s.size();
    for(int i = 0; i < m;i++){
        cout<<m<<" ";
    }
    temp = m+1;
    for(int i = m; i < n;i++){
        cout<<temp<<" ";
        temp++;
    }
    cout<<"\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

