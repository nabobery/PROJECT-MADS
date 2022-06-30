#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> find3numbers(){
    vector<vector<int>> result;
    vector<int> temp(3);
    for(int i = 0; i < 10;i++){
        for(int j = 0; j < 10;j++){
            for(int k = 0; k < 10;k++){
                if((i + j + k) != 3 && (i+j+k) != 13 && (i+j+k) != 23) continue;
                else{
                    temp[0] = i;
                    temp[1] = j;
                    temp[2] = k;
                    result.push_back(temp);
                }
            }
        }
    }
    return result;
}

vector<vector<int>> combinations = find3numbers();

void solve(){
    int lastdigit[10] = {0};
    int n,e;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> e;
        lastdigit[e%10]++;
    }
    bool flag = false;
    for(int i = 0; i < combinations.size();i++){
        int x = lastdigit[combinations[i][0]],y = lastdigit[combinations[i][1]], z = lastdigit[combinations[i][2]];
        if(x == 0 || y == 0 || z == 0) continue;
        else{
            lastdigit[combinations[i][0]]--;
            lastdigit[combinations[i][1]]--;
            lastdigit[combinations[i][2]]--;
            if(lastdigit[combinations[i][0]] >= 0 && lastdigit[combinations[i][1]] >= 0 && lastdigit[combinations[i][2]] >= 0){
                flag = true;
                break;
            }
            lastdigit[combinations[i][0]] = x;
            lastdigit[combinations[i][1]] = y;
            lastdigit[combinations[i][2]] = z;
        }
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
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





