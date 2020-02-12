class LRUCache {
public:
    LRUCache(int capacity):capacity(capacity) {}
    int get(int key) {
        if(mp.count(key)) {
            put(key,mp[key]->second);
            return ls.front().second;
        }
        return -1;
    }
    void put(int key, int value) {
        if(mp.count(key)) {
            ls.erase(mp[key]);
        }
        ls.push_front(make_pair(key,value));
        mp[key]=ls.begin();
        if(ls.size()>capacity) {
            mp.erase(ls.back().first);
            ls.pop_back();
        }
    }
private:
    int capacity;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> ls;
};
