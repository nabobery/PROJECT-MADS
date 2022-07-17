#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

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
    vector<vector<int>> contain(2, vector<int>(n,0));
    ordered_set rightEnds;
    for(int i = 0;i < n;i++){
        cin >> vec[i].start;
        cin >> vec[i].end;
        vec[i].index = i;
    }
    sort(vec.begin(),vec.end(), compareRange);
    for(int i = 0; i < n;i++){
        rightEnds.insert({vec[i].end, -i});
        // get the number of ends which are greater than the current end to get the number of range that contain the current range
        contain[1][vec[i].index] = rightEnds.size() - (rightEnds.order_of_key({vec[i].end, -i})) - 1;
    }
    rightEnds.clear();
    for(int i = n-1; i > -1;i--){
        rightEnds.insert({vec[i].end, -i});
        // get the number of ends which are less than the current end to get the number of ranges that are contained by the current range
        contain[0][vec[i].index] = rightEnds.order_of_key({vec[i].end, -i});
    }
    for(int i = 0; i < 2;i++){
        for(int num : contain[i]){
            cout<<num<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}





