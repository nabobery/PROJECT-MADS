// 1912. Design Movie Rental System

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */

// Solution 1: Using HashMaps and Hashsets
// Time Complexity: O(log n) for rent, drop, search and report
// Space Complexity: O(n)
struct MovieObj {
    int shop;
    int movie;
    int price;
};

struct MovieObjComparator {
    bool operator()(const MovieObj& a, const MovieObj& b) const{
        if(a.price != b.price) return a.price < b.price;
        if(a.shop != b.shop) return a.shop < b.shop;
        return a.movie < b.movie;
    }
};

struct cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.second == b.second)
            return a.first < b.first;  
        return a.second < b.second;        
    }
};

struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};


class MovieRentingSystem {
public:
    set<MovieObj, MovieObjComparator> rentedMovies;
    unordered_map<pair<int, int>, int, PairHash> movieShopToPrice;
    unordered_map<int, set<pair<int,int>, cmp>> unRentedMovieToShops;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(int i = 0; i < entries.size();i++){
            int shop = entries[i][0], movie = entries[i][1], price = entries[i][2];
            unRentedMovieToShops[movie].insert({shop, price});
            movieShopToPrice[{shop, movie}] = price;
        }
    }

    // unrented movies
    vector<int> search(int movie) {
        int li = min(5, int(unRentedMovieToShops[movie].size())), p = 0;
        vector<int> res;
        auto it = unRentedMovieToShops[movie].begin();
        while(p < li){
            res.push_back(it->first);
            p++;
            it++;
        }
        return res;
    }

    void rent(int shop, int movie) {
        int price = movieShopToPrice[{shop, movie}];
        rentedMovies.insert(MovieObj(shop, movie, price));
        unRentedMovieToShops[movie].erase({shop, price});
    }

    void drop(int shop, int movie) {
        int price = movieShopToPrice[{shop, movie}];
        rentedMovies.erase(MovieObj(shop, movie, price));
        unRentedMovieToShops[movie].insert({shop, price});
    }

    // rented movies
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int li = min(5, int(rentedMovies.size())), p = 0;
        auto it = rentedMovies.begin();
        while(p < li){
            res.push_back({it->shop, it->movie});
            p++;
            it++;
        }
        return res;
    }
};