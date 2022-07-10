#include <iostream>
#include <vector>
using namespace std;

void leftRotate(vector<int>& vec){
    int temp = vec[0];
    for(int i = 1; i < vec.size();i++){
        vec[i-1] = vec[i];
    }
    vec[vec.size()-1] = temp;
}

void solve(){
    int n;
    cin >> n;
    vector<int> d(n,-1);
    vector<int> arr(n);
    for(int i = 0; i < n;i++) cin >> arr[i];
    bool flag = false;
    for(int i = n-1; i >= 0;i--){
        vector<int> temp(arr.begin(),arr.begin() + i+1);
        for(int j = 0; j < temp.size();j++){
            if(temp[i] == i + 1){
                d[i] = j;
                break;
            }
            leftRotate(temp);
        }
        if(d[i] == -1){
            flag = true;
            break;
        }
        for(int j = 0; j < temp.size();j++) arr[j] = temp[j];
    }
    if(!flag){
        for(auto it : d) cout<<it<<" ";
        cout<<"\n";
    }
    else cout<<"-1\n";

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





