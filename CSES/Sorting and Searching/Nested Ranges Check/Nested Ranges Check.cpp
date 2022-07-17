#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct range{
    int start,end, index;
};

bool compareRange(range r1, range r2){
    if(r1.start != r2.start) return r1.start < r2.start;
    else return r1.end > r2.end;
}

void solve(){
    int n;
    cin >> n;
    vector<range> vec(n);
    // contain[0] = contains contain[1] = contained
    vector<vector<bool>> contain(2, vector<bool>(n,false));
    for(int i = 0;i < n;i++){
        cin >> vec[i].start;
        cin >> vec[i].end;
        vec[i].index = i;
    }
    sort(vec.begin(),vec.end(), compareRange);
    int maxEnd = 0, minEnd = 1e9 + 1;
    for(int i = 0; i < n;i++){
        if(vec[i].end <= maxEnd) contain[1][vec[i].index] = true;
        maxEnd = max(maxEnd, vec[i].end);
    }
    for(int i = n-1;i > -1;i--){
        if(vec[i].end >= minEnd) contain[0][vec[i].index] = true;
        minEnd = min(minEnd, vec[i].end);
    }
    for(int i = 0; i < 2;i++){
        for(bool b : contain[i]){
            cout<<(b ? "1 " : "0 ");
        }
        cout<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}




