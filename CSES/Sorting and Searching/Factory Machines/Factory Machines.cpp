#include <iostream>
using namespace std;

/* Idea: Traversing through all times from 1 to 10^18 and finding the products produced at that time and checking if products produced is
 * greater than or equal to t then go to left side and continue binary search else go to right side if number of products is lesser than t.
 * We need to continue this process until l <= h so that we get the minimum time such that products produced at that time is greater than or equal to t
 * As number of products is directly proportional to time we can use t=binary search.
*/

// Time complexity : O(n) for calculating products produced at time t and log(10^18) for binary search => nlog(10^18)

void solve(){
    int n, t;
    cin >> n >> t;
    int k[n];
    for(int i = 0; i < n;i++) cin >> k[i];
    long long int l = 1, h = 1e18, result;
    while(l <= h){
        long long int mid = (l + h)/2;
        long long int products = 0;
        for(int i = 0; i < n;i++){
            products += mid/k[i];
            if(products >= t){
                break;
            }
        }
        if(products >= t){
            result = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}





