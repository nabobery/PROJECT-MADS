#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n];
    vector<int> result;
    bool flag = false;
    for(int i = 0;i < n;i++) cin >> arr[i];
    for(int i = 0; i < n;i++){
        int j = i + 1;
        while (j < n && arr[j] == arr[j-1]){
            j++;
        }
        j--;
        if(i == j){
            flag = true;
            break;
        }
        else{
            result.push_back(j+1);
            for(int k = i;k < j;k++) result.push_back(k+1);
        }
        i = j;
    }
    if(!flag){
        for(int a : result) cout<<a<<" ";
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





