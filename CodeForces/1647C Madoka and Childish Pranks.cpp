#include <iostream>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    string arr[n];
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    if(arr[0][0] == '1') cout<<"-1\n";
    else{
        int count = 0;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(arr[i][j] == '1') count++;
            }
        }
        cout<<count<<"\n";
        for(int i = n-1; i >= 0;i--){
            for(int j = m-1; j >= 0;j--){
                if(arr[i][j] == '1'){
                    if(j != 0)  cout<<i+1<<" "<<j<<" "<<i+1<<" "<<j+1<<"\n";
                    else cout<<i<<" "<<j+1<<" "<<i+1<<" "<<j+1<<"\n";
                }
            }
        }
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



