//set_all功能的hash表，原有基础上增加了时间戳功能，set_all_time之前的的所有value都变成了set_all_value
//设计的是通用版，使用更加方便
template<typename Key, typename Value>
class My_Unordered_Map {
public:
    My_Unordered_Map() : _set_all_value(Value{}), _set_all_time(-1), _cnt(0){}

    void put(const Key &key, const Value &value) {
        _map[key] = std::make_pair(value, _cnt++);
    }

    void set_all(const Value &value) {
        _set_all_time = _cnt++;
        _set_all_value = value;
    }

    Value get(const Key &key) const {      
        auto it = _map.find(key);
        if (it == _map.end()) {
            if constexpr (std::numeric_limits<Value>::is_specialized)
                return std::numeric_limits<Value>::lowest();
            else
                return Value{};
        }
        if (it->second.second < _set_all_time)
            return _set_all_value;
        else
            return it->second.first;
    }
private:
    std::unordered_map<Key, std::pair<Value, int>> _map;
    Value _set_all_value;
    int _set_all_time;
    int _cnt;
};



