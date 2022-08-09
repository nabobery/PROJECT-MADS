// Using Radix Sort
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


// Using Counting Sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(n) sort solution
void count_sort(vector<int> &order, vector<int>& classes){
    // sort the pairs by first using the previous equivalence classes
    int n = order.size();
    vector<int> counter(n);
    for(auto itr : classes){
        counter[itr]++;
    }
    vector<int> pos(n);
    pos[0] = 0;
    for(int i = 1; i < n;i++){
        pos[i] = pos[i-1] + counter[i-1];
    }
    vector<int> temp(n);
    for(auto itr : order){
        int x = classes[itr];
        temp[pos[x]] = itr;
        pos[x]++;
    }
    order = temp;
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
        // go left by 2^k in the string to generate classes for 2^k+1
        for(int i = 0; i < n;i++){
            order[i] = (order[i] - (1 << k) +n)%n;
        }
        // get the new positions after counting sort
        count_sort(order,equivalentClasses);
        vector<int> newClasses(n);
        newClasses[order[0]] = 0;
        // get the new equivalence classes using the sort and previous equivalence classes
        for(int i = 1; i < n;i++){
            pair<int,int> prev = {equivalentClasses[order[i-1]], equivalentClasses[(order[i-1] + (1 << k))%n]};
            pair<int,int> curr = {equivalentClasses[order[i]], equivalentClasses[(order[i] + (1 << k))%n]};
            // if both pairs are same they have same equivalence class
            if(prev == curr){
                newClasses[order[i]] = newClasses[order[i-1]];
            }
            else{
                newClasses[order[i]] = newClasses[order[i-1]] + 1;
            }
        }
        equivalentClasses = newClasses;
        k++;
    }
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
