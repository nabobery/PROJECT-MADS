#include <iostream>
#include <cstring>
using namespace std;

bool arr[26];

void solve(){
    string s;
    cin >> s;
    int n = s.size(), temp = 0;
    memset(arr,0,sizeof(arr));
    for(int i = 0; i < n;i++){
        if(!arr[s[i] - 'a']) arr[s[i] - 'a'] = true;
        else{
            temp += 2;
            memset(arr,0,sizeof(arr));
        }
    }
    n -= temp;
    cout<<n<<"\n";
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





