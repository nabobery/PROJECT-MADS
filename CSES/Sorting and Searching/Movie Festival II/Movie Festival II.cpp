// Solution 1
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct movie{
    int starting, ending;
};

bool customCompare(movie a, movie b){
    return a.ending < b.ending;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<movie> movies(n);
    for(int i = 0; i < n; i++) cin >> movies[i].starting >> movies[i].ending;
    // sort based on ending so that we can greedily watch the movie that completes fast
    sort(movies.begin(),movies.end(), customCompare);
    // set of pairs for storing the movies being watched
    set<pair<int,int>> s;
    int notWatched = 0;
    s.insert({-movies[0].ending, 0});
    for(int i = 1; i < n;i++){
        auto it = s.lower_bound({-movies[i].starting,-1});
        // if there's a movie such that he current movie can be watched after that
        if(it != s.end()){
            s.erase(it);
            s.insert({-movies[i].ending,i});
        }
        // if there's no movie like that and size < k make another member watch the movie
        else if(it == s.end() && s.size() < k) s.insert({-movies[i].ending,i});
        // else skip the movie
        else notWatched++;
    }
    // total number of movies that be watched
    cout<<n - notWatched<<"\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

// Solution 2
/*
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct movie{
    int starting, ending;
};

bool customCompare(movie a, movie b){
    return a.ending < b.ending;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<movie> movies(n);
    for(int i = 0; i < n; i++) cin >> movies[i].starting >> movies[i].ending;
    sort(movies.begin(),movies.end(), customCompare);
    multiset<int> s;
    int maxWatched = 0;
    for(int i = 0; i < k;i++) s.insert(0);
    for(int i = 0; i < n;i++){
        auto it = s.upper_bound(movies[i].starting);
        if(it == s.begin()) continue;
        s.erase(--it);
        s.insert(movies[i].ending);
        maxWatched++;
    }
    cout<<maxWatched<<"\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}*/





