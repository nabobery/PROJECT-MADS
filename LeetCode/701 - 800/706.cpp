// 706. Design HashMap
/* failed solution
class MyHashMap {
public:
    vector<pair<int,int>> map;
    MyHashMap() {

    }

    void put(int key, int value) {
        bool flag = false;
        for(pair<int,int> &p : map){
            if(p.first == key){
                p.second = value;
                flag = true;
                break;
            }
        }
        if(!flag) map.push_back(make_pair(key,value));
    }

    int get(int key) {
        for(pair<int,int> p : map){
            if(p.first == key){
                return p.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int i;
        for(i = 0; i < map.size();i++){
            if(map[i].first == key){
                break;
            }
        }
        for(int j = i; j < map.size() - 1;j++){
            map[i] = map[i+1];
        }
        map.pop_back();
    }
};
*/

class MyHashMap {
public:
    array<int,1000001> map;
    MyHashMap() {
        map.fill(-1);
    }

    void put(int key, int value) {
        map[key] = value;
    }

    int get(int key) {
        return map[key];
    }

    void remove(int key) {
        map[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

