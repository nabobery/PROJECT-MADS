#include <iostream>
#include <set>
using namespace std;

#pragma GCC optimize("Ofast")

#define INF 1e9

void solve(){
    int n,x_0, y_0,x,y;
    double m;
    cin >> n >> x_0 >> y_0;
    set<double> s;
    for(int i = 0; i < n;i++){
        cin >> x >> y;
        if(x - x_0 == 0){
            s.insert(INF);
        }
        else{
            m = y - y_0;
            m /= (x - x_0);
            s.insert(m);
        }
    }
    cout<<s.size()<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}


