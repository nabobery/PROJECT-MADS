#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n,k,x;
    cin >> n >> k;
    set <int> onScreen;
    queue<int> q;
    for(int i = 0; i < n;i++){
        cin >> x;
        if(!onScreen.count(x)){
            if(q.size() < k){
                q.push(x);
                onScreen.insert(x);
            }
            else{
                int temp = q.front();
                q.pop();
                onScreen.erase(temp);
                q.push(x);
                onScreen.insert(x);
            }
        }
    }
    cout<<q.size()<<"\n";
    vector<int> temp;
    while(!q.empty()){
        temp.push_back(q.front());
        q.pop();
    }
    for(int i = temp.size()-1; i >= 0;i--) cout<<temp[i]<<" ";
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}




