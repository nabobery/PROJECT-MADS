// 2349. Design a Number Container System

// Solution 1: Using 2 Hash maps
// Time complexity: O(logn) for all operations
// Space complexity: O(n)

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

class NumberContainers {
public:
    unordered_map<int, set<int>> number_to_indices;
    unordered_map<int,int> index_to_number;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(index_to_number.count(index)){
            int prev_number = index_to_number[index];
            number_to_indices[prev_number].erase(index);
            if(number_to_indices[prev_number].empty()) number_to_indices.erase(prev_number);
        }
        index_to_number[index] = number;
        number_to_indices[number].insert(index);
    }
    
    int find(int number) {
        if(!number_to_indices.count(number)) return -1;
        return *number_to_indices[number].begin();
    }
};