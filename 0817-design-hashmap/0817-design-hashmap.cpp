class MyHashMap {
public:
 vector<int>map1;

    MyHashMap() {
          map1.resize(1e6+1,-1);
    }
    
    void put(int key, int value) {
        map1[key]=value;
    }
    
    int get(int key) {
        return map1[key];
    }
    
    void remove(int key) {
        map1[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */