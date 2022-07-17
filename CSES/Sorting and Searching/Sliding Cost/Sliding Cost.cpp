#include <iostream>
#include <set>
using namespace std;

multiset<int> l,r;
long long int leftSum = 0, rightSum = 0;

// for inserting into the 2 sets
void ins(int val){
    // value <= median, insert in left set
    if(val <= *l.rbegin()){
        l.insert(val);
        leftSum += val;
        // left set size > (k+1)/2 meaning left set has more elements so to balance insert into right set and erase from left set
        if(l.size() > (l.size() + r.size() + 1)/2){
            auto it = *l.rbegin();
            leftSum -= it;
            rightSum += it;
            l.erase(l.find(it));
            r.insert(it);
        }
    }
    // else insert into right set
    else{
        r.insert(val);
        rightSum += val;
        // right set size > k/2 meaning right set has more elements so to balance insert into left set and erase from right set
        if(r.size() > (r.size() + l.size())/2){
            auto it = *r.begin();
            leftSum += it;
            rightSum -= it;
            r.erase(r.find(it));
            l.insert(it);
        }
    }
}

// for erasing a val from 2 sets
void er(int val){
    if(l.count(val)){
        l.erase(l.find(val));
        leftSum -= val;
    }
    else{
        r.erase(r.find(val));
        rightSum -= val;
    }
    // boundary condition for k == 2
    if(l.empty()){
        auto it = *r.begin();
        leftSum += it;
        rightSum -= it;
        r.erase(r.find(it));
        l.insert(it);
    }
}

void solve(){
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    // if k = 1 => length of subarray = 1 therefore cost = 0
    if(k == 1){
        for(int i = 0; i < n;i++) cout<<"0 ";
    }
    // we can add this and remove the boundary condition in er
    /*else if(k == 2){
        for(int i = 1; i < n;i++) cout<<abs(arr[i] - arr[i-1])<<" ";
    }*/
    else{
        l.insert(arr[0]);
        leftSum += arr[0];
        for(int i = 1; i < k;i++) ins(arr[i]);
        // median is 0 if k is even and is median if k is odd (as we're counting an extra in leftSum)
        auto median = (k%2 == 0) ? 0 : *l.rbegin();
        // cost = rightsum - leftsum + med
        cout<<rightSum - leftSum + median<<" ";
        for(int i = k; i < n;i++){
            er(arr[i-k]);
            ins(arr[i]);
            median = (k%2 == 0) ? 0 : *l.rbegin();
            cout<<rightSum - leftSum + median<<" ";
        }
    }
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}


