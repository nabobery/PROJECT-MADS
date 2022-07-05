#include <iostream>
#include <cmath>
using namespace std;

void solve(){
    int n;
    long long int prev,result,curr = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    prev = 0;
    for(int i = 1; i < n;i++){
        long long int t = ceil(double(prev+1)/arr[i]);
        curr += t;
        prev = t*arr[i];
    }
    result = curr;
    //cout<<"0 "<<result<<"\n";
    for(int i = 1; i < n;i++){
        int temp = arr[i];
        arr[i] = 0;
        curr = 1;
        prev = -arr[i-1];
        if(i >= 2){
            for(int j = i-2; j > -1;j--){
                long long int t = floor(double(prev-1)/arr[j]);
                curr -= t;
                prev = t*arr[j];
            }
        }
        //cout<<i<<" "<<curr<<"\n";
        prev = 0;
        for(int j = i+1;j < n;j++){
            long long int t = ceil(double(prev+1)/arr[j]);
            curr += t;
            prev = t*arr[j];
        }
        arr[i] = temp;
        //cout<<i<<" "<<curr<<"\n";
        if(curr < result) result = curr;
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}





