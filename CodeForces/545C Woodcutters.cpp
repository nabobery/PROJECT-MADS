#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n;
    cin >> n;
    int x[n], h[n];
    bool rightfell[n];
    for(int i = 0; i < n;i++){
        cin >> x[i] >> h[i];
        rightfell[i] = false;
    }
    int result;
    if(n == 1) result = 1;
    else result = 2;
    for(int i = 1; i < n-1;i++){
        if(!rightfell[i-1]){
            if(x[i-1] < (x[i] - h[i])){
                result++;
            }
            else if(x[i+1] > (x[i] + h[i])){
                result++;
                rightfell[i] = true;
            }
        }
        else{
            if((x[i-1] + h[i-1]) < (x[i] - h[i])){
                result++;
            }
            else if(x[i+1] > (x[i] + h[i])){
                result++;
                rightfell[i] = true;
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






