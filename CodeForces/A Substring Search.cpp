#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(n) sort solution
void radix_sort(vector<pair<pair<int,int>,int>>& t){
    // sort the pairs by second
    int n = t.size();
    vector<int> counter(n);
    for(auto itr : t){
        counter[itr.first.second]++;
    }
    vector<int> pos(n);
    pos[0] = 0;
    for(int i = 1; i < n;i++){
        pos[i] = pos[i-1] + counter[i-1];
    }
    vector<pair<pair<int,int>,int>> temp(n);
    for(auto itr : t){
        int x = itr.first.second;
        temp[pos[x]] = itr;
        pos[x]++;
    }
    t = temp;
    // sort the pairs by first
    for(int i = 0; i < n;i++) counter[i] = 0;
    for(auto itr : t){
        counter[itr.first.first]++;
    }
    pos[0] = 0;
    for(int i = 1; i < n;i++){
        pos[i] = pos[i-1] + counter[i-1];
    }
    for(auto itr : t){
        int x = itr.first.first;
        temp[pos[x]] = itr;
        pos[x]++;
    }
    t = temp;
}

bool binarySearch(string x,string s, vector<int>& arr){
    int l = 0, r = arr.size()-1,mid, k = x.size();
    bool flag;
    while(l <= r){
        mid = (l+r)/2;
        flag = true;
        for(int i = 0; i < k;i++){
            if(s[arr[mid] + i] > x[i]){
                r = mid-1;
                flag = false;
                break;
            }
            if(s[arr[mid] + i] < x[i]){
                l = mid+1;
                flag = false;
                break;
            }
        }
        if(flag) return true;
    }
    return false;
}

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
        radix_sort(t);
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
    int q;
    cin >> q;
    string sub;
    for(int i = 0; i < q;i++){
        cin >> sub;
        cout<<(binarySearch(sub,s,order) ? "Yes\n" : "No\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

