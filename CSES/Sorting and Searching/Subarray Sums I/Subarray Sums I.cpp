#include <iostream>
#include <set>
using namespace std;

void solve(){
    int n,x,ai;
    cin >> n >> x;
    set <long long int> prevSum;
    long long int result = 0, currSum = 0;
    for(int i = 0; i < n;i++){
        cin >> ai;
        currSum += ai;
        if(currSum == x) result++;
        if(prevSum.find(currSum - x) != prevSum.end()) result++;
        prevSum.insert(currSum);
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

