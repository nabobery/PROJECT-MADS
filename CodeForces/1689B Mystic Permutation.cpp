#include <iostream>
using namespace  std;

void solve(){
    int n;
    cin >> n;
    int arr[n], result[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    if(n == 1) cout<<"-1\n";
    else{
        for(int i = 1; i <= n;i++){
            if(i != arr[i-1]) result[i-1] = i;
            else{
                if(i < n){
                    result[i-1] = i + 1;
                    result[i] = i;
                    i++;
                }
                else{
                    result[i-1] = result[i-2];
                    result[i-2] = i;
                }
            }
        }
        for(int i = 0; i < n;i++){
            cout<<result[i] <<" ";
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
