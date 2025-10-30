// 实现 LRUCache 类：
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

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
