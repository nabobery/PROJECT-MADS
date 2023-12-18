// 2353. Design a Food Rating System

// Solution 1 by maintaining a map of cuisine to {food,rating} pair and a set of {rating,food} pairs
// Time complexity: O((n+m)logn)
// Space complexity: O(n)
class FoodRatings {
public:
    struct comparator {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second; 
        }
    };
    unordered_map<string, map<string, int>> mp;
    unordered_map<string, set<pair<int,string>, comparator>> mp2;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < ratings.size();i++){
            mp[cuisines[i]][foods[i]] = ratings[i];
            mp2[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        for(auto&it : mp){
            if(it.second.count(food)){
                mp2[it.first].erase({it.second[food], food});
                it.second[food] = newRating;
                mp2[it.first].insert({it.second[food], food});
                return;
            }
        }
    }
    
    string highestRated(string cuisine) {
        return mp2[cuisine].begin()->second;
    }
};


// Solution 2 by maintaining a map of cuisine to {rating,food} pair and  2 maps food to cuisine and food to rating
// Time complexity: O((n+m)logn)
// Space complexity: O(n)
class FoodRatings {
    unordered_map<string, int> foodRatingMap;
    unordered_map<string, string> foodCuisineMap;
    unordered_map<string, set<pair<int, string>>> cuisineFoodMap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            foodRatingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            cuisineFoodMap[cuisines[i]].insert({ -ratings[i], foods[i] });
        }
    } 

    void changeRating(string food, int newRating) {
        auto cuisineName = foodCuisineMap[food];
        auto oldElementIterator = cuisineFoodMap[cuisineName].find({ -foodRatingMap[food], food });
        cuisineFoodMap[cuisineName].erase(oldElementIterator);
        foodRatingMap[food] = newRating;
        cuisineFoodMap[cuisineName].insert({ -newRating, food });
    }
    
    string highestRated(string cuisine) {
        return cuisineFoodMap[cuisine].begin()->second;
    }
};



/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */