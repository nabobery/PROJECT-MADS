#include <iostream>
#include <set>
using namespace  std;

void solve(){
    int n,x;
    cin >> n;
    set <int> s;
    for(int i = 0; i < n;i++){
        cin >> x;
        s.insert(x);
    }
    cout<<s.size()<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}



