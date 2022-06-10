#include <iostream>
using namespace  std;

bool check(string str, char c){
    for(int i = 0; i < str.size();i++){
        if(str[i] != c) return false;
    }
    return true;
}

void solve(){
    int n, ind = -1;
    char ch;
    string str;
    cin >> n >> ch >> str;
    for(int i = n-1; i >= 0;i--){
        if(str[i] == ch){
            ind = i;
            break;
        }
    }
    if(check(str,ch)) cout<<"0\n";
    else if(ind >= n/2){
        cout<<"1\n";
        cout<<ind+1<<"\n";
    }
    else{
        cout<<"2\n";
        if(n%2 == 0) cout<<n-1<<" "<<n<<"\n";
        else cout<<"2 "<<n<<"\n";
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
