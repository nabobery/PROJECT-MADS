#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int a,b,c,temp;
    cin >> a >> b >> c;
    int result = a + b*c;
    temp = a*(b+c);
    if(temp > result) result = temp;
    temp = a*b*c;
    if(temp > result) result = temp;
    temp = (a+b)*c;
    if(temp > result) result = temp;
    temp = a + b + c;
    if(temp > result) result = temp;
    temp = a*b + c;
    if(temp > result) result = temp;
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
