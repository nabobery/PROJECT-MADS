#include <iostream>
#include <cmath>
using namespace std;

void solve(){
    int r, x,y, x_1, y_1,d;
    double dist;
    cin >> r >> x >> y >> x_1 >> y_1;
    d = 2*r;
    dist = pow((x_1 - x),2) + pow((y_1 - y),2);
    dist = sqrt(dist);
    cout<<ceil(dist/d);
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}




