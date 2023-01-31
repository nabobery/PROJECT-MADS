// 352. Data Stream as Disjoint Intervals

class SummaryRanges {
public:
    set<int> nums;
    SummaryRanges() {

    }

    void addNum(int value) {
        nums.insert(value);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto itr = nums.begin();itr != nums.end(); itr++){
            vector<int> temp(2, *itr);
            auto prev = itr;
            itr++;
            while(*prev+1 == *itr && itr !=nums.end()){
                prev = itr;
                itr++;
            }
            temp[1] = *prev;
            itr--;
            res.push_back(temp);
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
