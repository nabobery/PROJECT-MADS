#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void solve(){
    int n, x, result = 0;
    cin >> n;
    map<int,int> mp;
    for(int i = 0,j = 0; i < n;i++){
        cin >> x;
        // to get the start point of unique sequence by getting the next occurrence of the element after the given element
        j = max(mp[x],j);
        // update the result by getting max of current unique sequence of elements and the current result
        result = max(result, i - j + 1);
        // set the index of the element to be i+1 which is the next element from where the unique sequence starts(if it occurs again)
        mp[x] = i+1;
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}





