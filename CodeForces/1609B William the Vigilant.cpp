#include <iostream>
#include <string>
using namespace  std;

int numberOfABC(string &s, int n){
    int result = 0;
    string temp;
    for(int i = 0; i < n - 2;i++){
        temp = s.substr(i,3);
        if(temp == "abc") result++;
    }
    return result;
}

void solve(){
    int n, q;
    string s;
    cin >> n >> q;
    cin >> s;
    int pos;
    char ch;
    int result = numberOfABC(s,n);
    for(int i = 0; i < q;i++){
        int temp1 = 0, temp2 = 0;
        cin >> pos >> ch;
        if(pos < n - 1)
            if(s.substr(pos - 1,3) == "abc") temp1++;
        if(pos > 1 && pos < n)
            if(s.substr(pos - 2,3) == "abc") temp1++;
        if(pos > 2)
            if(s.substr(pos - 3,3) == "abc") temp1++;
        s[pos-1] = ch;
        if(pos < n - 1)
            if(s.substr(pos - 1,3) == "abc") temp2++;
        if(pos > 1 && pos < n)
            if(s.substr(pos - 2,3) == "abc") temp2++;
        if(pos > 2)
            if(s.substr(pos - 3,3) == "abc") temp2++;
        result += (temp2 - temp1);
        cout<<result<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}


