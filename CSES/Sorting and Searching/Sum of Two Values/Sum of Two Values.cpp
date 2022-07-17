#include <iostream>
#include <map>
#include <vector>
using namespace  std;

void solve(){
    int n,x,temp;
    cin >> n >> x;
    bool found = false;
    map <int, vector<int>> mp;
    for(int i = 0;i < n;i++){
        cin >> temp;
        mp[temp].push_back(i+1);
    }
    for(auto itr : mp){
        if((itr.first*2) > x) break;
        else{
            auto it = mp.find(x - itr.first);
            if(it != mp.end()){
                if(it->first == itr.first){
                    if(it->second.size() >= 2){
                        found = true;
                        cout<<it->second[0]<<" "<<it->second[1]<<"\n";
                        break;
                    }
                    else continue;
                }
                else{
                    found = true;
                    cout<<itr.second[0]<<" "<<it->second[0]<<"\n";
                    break;
                }
            }
            else continue;
        }
    }
    if(!found) cout<<"IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

