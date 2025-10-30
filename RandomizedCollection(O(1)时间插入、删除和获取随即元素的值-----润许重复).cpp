//O(1)时间插入、删除和获取随即元素的值-----润许重复

class RandomizedCollection {
public:
    RandomizedCollection() : _size(0){
        
    }
    
    bool insert(int val) {
        auto it = _map.find(val);
        _map.insert({val, _size++});
        _v.push_back(val);
        if(it != _map.end()) return false;
        return true;
    }
    
    bool remove(int val) {
        auto it = _map.find(val);
        if(it == _map.end()) return false;
        _v[it->second] = _v[_size - 1];
        _v.pop_back();
        --_size;
        auto range = _map.equal_range(_v[it->second]);
        for (auto its = range.first; its != range.second; ++its) {
            if(its->second == _size){
                its->second = it->second;
                break;
            }
        }
        _map.erase(it);
        return true;
    }
    
    int getRandom() {
        return _v[random() % _size];
    }
private:
    vector<int> _v;
    unordered_multimap<int, int> _map;
    int _size;
};
