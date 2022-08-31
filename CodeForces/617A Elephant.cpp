#include <iostream>
using namespace std;

void solve(){
    int x;
    cin >> x;
    cout<<x/5 + (x% 5 != 0)<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}




