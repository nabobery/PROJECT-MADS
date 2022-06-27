#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string findDiff(string str1, string str2){
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    int diff = n1 - n2;
    int carry = 0;
    for (int i = n2 - 1; i >= 0; i--) {
        int sub = ((str1[i + diff] - '0') - (str2[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }
    for (int i = n1 - n2 - 1; i >= 0; i--) {
        if (str1[i] == '0' && carry) {
            str.push_back('9');
            continue;
        }
        int sub = ((str1[i] - '0') - carry);
        if (i > 0 || sub > 0)
            str.push_back(sub + '0');
        carry = 0;
    }
    reverse(str.begin(), str.end());
    return str;
}

void solve(){
    int n;
    string s;
    cin >> n >> s;
    string temp = s;
    /* Another Solution
    if(s[0] != '9'){
        string str(n,9);
        string result = findDiff(str,s);
    }
    else{
        string str(n+1,1);
        string result = findDiff(str,s);
    }
    */
    if(temp[0] - '0' < 8) temp[0] += 2;
    else{
        temp[0] = '0' + (temp[0] - '0' - 8);
        temp = "1" + temp;
    }
    int m = temp.size();
    for(int i = 0; i < m/2;i++){
        temp[m-i-1] = temp[i];
    }
    string str = findDiff(temp,s);
    cout<<str<<"\n";
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





