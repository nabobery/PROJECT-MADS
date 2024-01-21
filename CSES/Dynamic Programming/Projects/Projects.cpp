#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

int mod = 1e9 + 7;

struct project{
    int start, end, profit;
};

bool compare(project p1, project p2){ return p1.start < p2.start;}

int n;
vector<project> projects;
vector<ll> dp;

ll helper(int i){
    // base case, if we reach the end return 0
    if(i == n) return 0;
    // if already calculated return the calcualtdd value
    if(dp[i] != -1) return dp[i];
    // get the current profit of the project
    ll profit = projects[i].profit;
    // don't do the current project
    ll res = helper(i+1);
    // search for project with starting date just greater than end day of current project ( As 2 projects can't be done on the same day)
    project p = {projects[i].end + 1, projects[i].end + 1, 0};
    int ind = std::lower_bound(projects.begin(), projects.end(), p, compare) - projects.begin();
    // if we get a project, add the profit of current project and  recurse and choose that next project
    if(ind != n){
        res = max(res, profit + helper(ind));
    }
    // if we can't get a project this, just include this project's profit
    else{
        res = max(res, profit);
    }
    // get the max of either choosing the current project or not choosing the current project
    return dp[i] = res;
}

void solve(){
    cin >> n;
    projects.resize(n);
    for(int i = 0; i < n;i++){
        cin >> projects[i].start >> projects[i].end >> projects[i].profit;
    }
    // sort the projects based on start time
    sort(projects.begin(), projects.end(), compare);
    // intialise dp to be all -1 initially
    // dp[i] indicates the maximum profit we can get till i projects
    dp.assign(n, -1);
    cout<<helper(0)<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}






