#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace  std;

void solve(){
    int n,l,r,d;
    cin >> n;
    set <pair<int,int>> ranges;
    vector <pair<int,int>> temp;
    bool done[n];
    for(int i = 0; i < n;i++){
        cin >> l >> r;
        ranges.insert({l,r});
        done[i] = false;
    }
    temp.push_back({1,n});
    bool flag = false;
    while(!temp.empty()){
        flag = false;
        l = temp.back().first;
        r = temp.back().second;
        for(int i = 0; i < n;i++){
            if(l == r){
                temp.pop_back();
                cout<<l << " " << l << " " << l<<"\n";
                done[l-1] = true;
                break;
            }
            if(!done[i]){
                d = i + 1;
                if(((l <= d-1)  && ranges.count({l,d-1})) && ((r >= d+1)  && ranges.count({d+1,r}))){
                    temp.pop_back();
                    temp.push_back({d+1,r});
                    temp.push_back({l,d-1});
                    cout<<l << " "<< r << " "<< d<<"\n";
                    done[i] = true;
                    break;
                }
                else if(((l > d-1)  && !ranges.count({l,d-1})) && ((r >= d+1)  && ranges.count({d+1,r}))){
                    temp.pop_back();
                    temp.push_back({d+1,r});
                    cout<<l << " "<< r << " "<< d<<"\n";
                    done[i] = true;
                    break;
                }
                else if(((l <= d-1)  && ranges.count({l,d-1})) && ((r < d+1)  && !ranges.count({d+1,r}))){
                    temp.pop_back();
                    temp.push_back({l,d-1});
                    cout<<l << " "<< r << " "<< d<<"\n";
                    done[i] = true;
                    break;
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


