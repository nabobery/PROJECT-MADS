#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;

// greedy strategy by sorting according to end points

// custom comparator function to sort values by second
bool customCompare(pair<int,int>& a,  pair<int,int>& b){
    return a.second < b.second;
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> intervals(n);
    for(int i = 0; i < n;i++) cin >> intervals[i].first >> intervals[i].second;
    sort(intervals.begin(),intervals.end(), customCompare);
    // the movie which ends first gives the chance to see other movies
    int result = 1, index = 0;
    for(int i = 1; i < n;i++){
        // we greedily choose the first movie(because we want maximum number of movies) whose start time is greater than equal to end time of the previous movie
        if(intervals[i].first >= intervals[index].second){
            result++;
            index = i;
        }
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

