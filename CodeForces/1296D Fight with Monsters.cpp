#include <iostream>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n,a,b,k,result = 0;
    cin >> n >> a >> b >> k;
    int h[n];
    for(int i = 0; i < n;i++){
        cin >> h[i];
        int temp = h[i]/(a+b);
        if(h[i] %(a+b) == 0){
            temp--;
        }
        h[i] -= (temp*(a+b));
    }
    sort(h, h + n);
    for(int i = 0; i < n;i++){
        if(h[i] <= a) result++;
        else{
            int temp = (h[i]/a) + (h[i]%a != 0);
            temp--;
            if(k - temp >= 0){
                k -= temp;
                result++;
            }
        }
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

