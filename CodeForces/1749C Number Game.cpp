#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

// O(n^2logn) solution
void solve(){
    int n,x,result = 0;
    cin >> n;
    multiset<int> ms,temp;
    // insert all elements into multiset
    for(int i = 0; i < n;i++){
        cin >> x;
        ms.insert(x);
    }
    // go from k = 1 to k = n to get max k
    for(int k = 1; k <= n;k++){
        // store it in temp multiset and simulate if it's possible with given k
        temp = ms;
        // simulate the game by going through k stages (we're going from i = 0 to i = k-1 but in game they go for i =1 to i =k)
        for(int i = 0; i < k;i++){
            // alice will try to erase the greatest element <= k-i+1
            // find the element greater than k-i+1 which is k-i (as we're going from i = 0 to i=k-1)
            auto it = temp.upper_bound(k-i);
            // if there're no elements less than k-i+1 then break off
            if(it == temp.begin()) break;
            temp.erase(--it);
            // bob will try to delete the smallest element possible and insert the incremented number to decrease Alice's chance to win
            if(!temp.empty()){
                x = *temp.begin();
                temp.erase(temp.begin());
                temp.insert(x+k-i);
            }
        }
        // if it's possible with given k store that value
        if(temp.size() + k == n) result = k;
    }
    cout<<result<<"\n";
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




