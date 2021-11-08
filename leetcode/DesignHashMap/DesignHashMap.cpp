class MyHashMap {
public:
    vector<vector<int>> v;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(int i = 0; i < v.size(); i++) {
            if(key == v[i][0]) {
                v[i][1] = value;
                return;
            }
        }
        v.push_back(vector<int> ({key, value}));
    }
    
    int get(int key) {
        for(int i = 0; i < v.size(); i++) {
            if(key == v[i][0])
                return v[i][1];
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i = 0; i < v.size(); i++) {
            if(key == v[i][0]) {
                v.erase(v.begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */