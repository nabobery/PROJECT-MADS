#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int mod = 32768;

vector<int> dp(32768,-1);

void BFS(int x){
    queue<int> q;
    q.push(x);
    int counter = 1;
    int result = 0;
    while(!q.empty()){
        int l = counter;
        for(int i = 0; i < l;i++){
            int temp = q.front();
            if(dp[temp%mod] == - 1){
                dp[temp%mod] = result;
                q.pop();
                counter--;
                if(temp%2 == 0){
                    q.push(temp/2);
                    counter++;
                    if(temp < mod){
                        q.push(16384 + temp/2);
                        counter++;
                    }
                }
                if(temp < mod && !(temp+mod % 2)) {
                    q.push((temp+mod)/2);
                    counter++;
                }
                q.push(temp - 1);
                counter++;
            }
            else{
                q.pop();
                counter--;
            }
        }
        if(result == 15) break;
        result++;
    }
}

void solve(){
    int n,x;
    cin >> n;
    BFS(32768);
    for(int i = 0; i < n;i++){
        cin >> x;
        cout<<dp[x]<<" ";
    }
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}





