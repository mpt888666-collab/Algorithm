//O(1)时间插入、删除和获取随即元素

class RandomizedSet {
public:
    RandomizedSet() : _size(0){
        
    }
    
    bool insert(int val) {
        auto it = _map.find(val);
        if(it != _map.end()) return false;
        _map[val] = _size;
        _v.push_back(val);
        ++_size;
        return true;
    }
    
    bool remove(int val) {
        auto it = _map.find(val);
        if(it == _map.end()) return false;
        int value = _v[_size - 1];
        _v[it->second] = _v[_size - 1];
        _v.pop_back();
        --_size;
        _map[value] = it->second;
        _map.erase(val);
        return true;
    }
    
    int getRandom() {
        return _v[random() % _size];
    }

private:
    unordered_map<int, int> _map;
    vector<int> _v;
    int _size;
};
