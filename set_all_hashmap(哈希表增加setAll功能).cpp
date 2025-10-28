//set_all功能的hash表，原有基础上增加了时间戳功能，set_all_time之前的的所有value都变成了set_all_value

class My_Unordered_Map {
public:
    My_Unordered_Map() : _set_all_value(0), _set_all_time(-1), _cnt(0){}

    void put(const int &key, const int &value) {
        _map[key] = std::make_pair(value, _cnt++);
    }

    void set_all(const int &value) {
        _set_all_time = _cnt++;
        _set_all_value = value;
    }

    int get(const int &key) {
        if (!_map.contains(key)) return std::numeric_limits<int>::min();
        if (_map[key].second < _set_all_time) return _set_all_value;
        else return _map[key].first;
    }
private:
    std::unordered_map<int, std::pair<int, int>> _map;
    int _set_all_value;
    int _set_all_time;
    int _cnt;
};
