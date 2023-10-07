// Project Euler #4: Largest palindrome product

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isPalindrome(string s){
    for(int i = 0; i < s.size()/2;i++){
        if(s[i] != s[s.size() -i - 1]) return false;
    }
    return true;
}


int main(){
    int t;
    cin >> t;
    set<int> s;
    for(int i = 101101; i < 1e6;i++){
        if(isPalindrome(to_string(i))){
            for(int j = 100; j < 1000;j++){
                if(i%j == 0 && (i/j >= 100 && i/j <= 999)){
                    s.insert(i);
                }
            }
        }
    }
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        auto it = s.lower_bound(n);
        it--;
        cout<<*it<<"\n";
    }
    return 0;
}
