#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n,x,temp;
    cin >> n >> x;
    vector<int> counter(x+1,0);
    for(int i = 0; i < n;i++){
        cin >> temp;
        if(temp <= x) counter[temp]++;
    }
    bool flag = true;
    for(int i = 1; i < x;i++){
        if((counter[i] % (i+1)) == 0){
            counter[i+1] += counter[i]/(i+1);
            counter[i] = 0;
        }
        else{
            flag = false;
            break;
        }
    }
    if(!flag) cout<<"No\n";
    else{
        if(counter[x] >= 1) cout<<"Yes\n";
        else cout<<"No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

