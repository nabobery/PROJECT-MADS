#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// order is position of the start of the substring and equivalent classes is the class for getting the strings in ascending order
void solve(){
    string s;
    cin >> s;
    s += "$";
    int n = s.size();
    // if k = 0 (base case)
    vector<int> order(n), equivalentClasses(n);
    vector<pair<char,int>> temp(n);
    for(int i = 0; i < n;i++) temp[i] = {s[i],i};
    sort(temp.begin(), temp.end());
    for(int i = 0; i < n;i++) order[i] = temp[i].second;
    equivalentClasses[order[0]] = 0;
    for(int i = 1; i < n;i++){
        if(temp[i].first == temp[i-1].first){
            equivalentClasses[order[i]] = equivalentClasses[order[i-1]];
        }
        else{
            equivalentClasses[order[i]] = equivalentClasses[order[i-1]] + 1;
        }
    }
    int k = 0;
    // while 2^k < n use the previous case to generate equivalence classes for the current case
    while((1 << k) < n){
        vector<pair<pair<int,int>,int>> t(n);
        for(int i = 0; i < n;i++){
            t[i] = {{equivalentClasses[i], equivalentClasses[(i + (1 << k)) % n]}, i};
        }
        sort(t.begin(),t.end());
        for(int i = 0; i < n;i++) order[i] = t[i].second;
        equivalentClasses[order[0]] = 0;
        for(int i = 1; i < n;i++){
            if(t[i].first == t[i-1].first){
                equivalentClasses[order[i]] = equivalentClasses[order[i-1]];
            }
            else{
                equivalentClasses[order[i]] = equivalentClasses[order[i-1]] + 1;
            }
        }
        k++;
    }
    // string = s.substr(p[i], n- p[i]) (pos, len)
    for(int i = 0; i < n;i++){
        cout<<order[i]<<" ";
    }
    cout<<"\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}



