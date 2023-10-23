// Project Euler #13: Large sum

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string add(string a, string b){
    int alen = a.size(), blen = b.size();
    int n = max(alen, blen); 
    if (alen > blen) 
        b.insert(0, alen - blen, '0'); 
    else if (alen < blen) 
        a.insert(0, blen - alen, '0'); 
    string res(n + 1, '0'); 
    int carry = 0; 
    for (int i = n - 1; i >= 0; i--) { 
        int digit = (a[i] - '0') + (b[i] - '0') + carry; 
        carry = digit / 10; 
        res[i + 1] = digit % 10 + '0'; 
    } 
    if(carry == 1){
        res[0] = '1';
        return res;
    }
    return res.substr(1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    string s, res;
    cin >> s;
    res = s;
    for(int i = 1; i < n;i++){
        cin >> s;
        res = add(s, res);
    }
    cout<<res.substr(0, 10)<<"\n";
    return 0;
}
