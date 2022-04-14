#include <iostream>
using namespace  std;

void solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    int result = 0;
    for(int i = 0; i < n;i++){
        if((i == 0 || i == n-1) && str[i] == '1') continue;
        if(str[i] == '0') {
            int j = i + 1;
            while (j < n && str[j] != '0') {
                j++;
            }
            if (j == n) break;
            if (j - i == 1) result += 2;
            else if (j - i == 2) result += 1;
            j--;
            i = j;
        }
    }
    cout<<result<<"\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


