#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

string findDiff(string str1, char ch)
{
    string str = "";
    int n = str1.length();
    reverse(str1.begin(), str1.end());
    int carry = 0;
    int sub = ((str1[0] - '0') - (ch - '0') - carry);
    if (sub < 0) {
        sub = sub + 10;
        carry = 1;
    }
    else
        carry = 0;
    str.push_back(sub + '0');
    for (int i = 1; i < n; i++) {
        int sub = ((str1[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        str.push_back(sub + '0');
    }
    string result = "";
    while(str.size() > 1 && str.back() == '0'){
        str.pop_back();
    }
    while (!str.empty()){
        result += str.back();
        str.pop_back();
    }
    return result;
}

void solve(){
    int n, result = 0;
    cin >> n;
    string str = to_string(n);
    set<int> s;
    for(int i = 0; i < str.size();i++) s.insert(str[i] - '0');
    while(str != "0"){
        char ch = *s.rbegin() + '0';
        str = findDiff(str,ch);
        result++;
        s.clear();
        for(int i = 0; i < str.size();i++) s.insert(str[i] - '0');
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}



