#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;

void leftRotate(vector<int>& vec, int l, int r){
    vector<int> temp;
    for(int i = l - 1; i < r - 1;i++){
        temp.push_back(vec[i]);
    }
    vec[l-1] = vec[r-1];
    int j = 0;
    for(int i = l; i < r;i++){
        vec[i] = temp[j];
        j++;
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n), temp(n);
    for(int i = 0; i < n;i++) cin >> arr[i];
    temp = arr;
    sort(temp.begin(),temp.end());
    vector<int> l, r, d;
    for(int i = 0; i < n;i++){
        int curr = temp[i];
        if(arr[i] == curr) continue;
        else{
            int j = i;
            while(j < n && arr[j] != curr){
                j++;
            }
            l.push_back(i+1);
            r.push_back(j+1);
            d.push_back(j-i);
            leftRotate(arr,i+1,j+1);
        }
    }
    cout<<l.size()<<"\n";
    for(int i = 0; i < l.size();i++){
        cout<<l[i]<<" "<<r[i]<<" "<<d[i]<<"\n";
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

