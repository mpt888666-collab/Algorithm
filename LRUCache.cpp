class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity){
        
    }
    
    int get(int key) {
        auto it = _map.find(key);
        if(it == _map.end()) return -1;
        _list.splice(_list.begin(), _list, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = _map.find(key);
        if(it != _map.end()){
            it->second->second = value;
            _list.splice(_list.begin(), _list, it->second);
            return;
        }
        if(_list.size() == _capacity){
            auto l = _list.back();
            _map.erase(l.first);
            _list.pop_back();
        }
        _list.emplace_front(key, value);
        _map[key] = _list.begin();
    }
private:
    int _capacity;
    list<pair<int, int>> _list;
    unordered_map<int, list<pair<int, int>>::iterator> _map;
};
