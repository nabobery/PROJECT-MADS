#include <iostream>
using namespace std;

void solve(){
    int n, k,count = 0;
    cin >> n >> k;
    string arr;
    int moves[n];
    for(int i = 0; i < n;i++) moves[i] = 0;
    cin >> arr;
    for(int i = 0; i < n;i++){
        if(count < k){
            if(arr[i] == '1'){
                if(k%2 == 1){
                    count++;
                    moves[i]++;
                }
            }
            else{
                if(k%2 == 0){
                    count++;
                    moves[i]++;
                }
            }
        }
    }
    count = k - count;
    bool flag = false;
    if(count % 2 == 0){
        for(int i = 0; i < n;i++){
            if(moves[i] % 2 == 0){
                moves[i] += count;
                flag = true;
                break;
            }
        }
        if(!flag) moves[n-1] += count;
    }
    else moves[n-1] += count;
    for(int i = 0; i < n;i++){
        if((k - moves[i]) % 2 == 0){
            cout<< (arr[i] == '1' ? "1" : "0");
        }
        else cout<< (arr[i] == '1' ? "0" : "1");
    }
    cout<<"\n";
    for(int move : moves) cout<<move<<" ";
    cout<<"\n";
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





