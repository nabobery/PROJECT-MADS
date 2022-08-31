#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    string result;
    for(int i = 0; i < n;i++){
        if(s[i] == '0' || s[i] == '1') continue;
        else if(s[i] == '4'){
            result.push_back('2');
            result.push_back('2');
            result.push_back('3');
        }
        else if(s[i] == '6'){
            result.push_back('5');
            result.push_back('3');
        }
        else if(s[i] == '8'){
            result.push_back('2');
            result.push_back('2');
            result.push_back('2');
            result.push_back('7');
        }
        else if(s[i] == '9'){
            result.push_back('2');
            result.push_back('3');
            result.push_back('3');
            result.push_back('7');
        }
        else result.push_back(s[i]);
    }
    sort(result.begin(),result.end());
    reverse(result.begin(),result.end());
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}



