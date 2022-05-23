#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace  std;

void solve(){
    string a, s;
    cin >> a >> s;
    int j = a.size() - 1;
    string rev = string(s.rbegin(), s.rend());
    vector<int> result;
    bool flag = false;
    for(int i = 0; i < rev.size();i++){
        int c1, c2;
        if(j < 0){
            c1 = rev[i] - '0';
            c2 = 0;
        }
        else{
            c1 = rev[i] - '0';
            c2 = a[j] - '0';
        }
        if(c1 >= c2){
            result.push_back(c1 - c2);
            j--;
        }
        else if(c2 > c1){
            string temp = rev.substr(i,2);
            reverse(temp.begin(),temp.end());
            c1 = stoi(temp);
            if(c1 - c2 > 9 || c1 - c2 < 0){
                flag = true;
                break;
            }
            result.push_back(c1 - c2);
            j--;
            i++;
        }
    }
    if(flag || j >= 0) cout<< -1 <<"\n";
    else{
        while(result.back() == 0){
            result.pop_back();
        }
        while(!result.empty()){
            cout<<result.back();
            result.pop_back();
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




