#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve(){
    int n,x;
    cin >> n;
    vector<int> result(n,0);
    map<int,int> lastSeen;
    for(int i = 0; i < n;i++){
        cin >> x;
        if(lastSeen.find(x) == lastSeen.end()){
            lastSeen[x] = i;
            result[x-1]++;
        }
        else{
            if((lastSeen[x] - i - 1)%2 == 0){
                result[x-1]++;
                lastSeen[x] = i;
            }
        }
    }
    for(int r : result) cout<<r<<" ";
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
