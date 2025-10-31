//最大频率栈, 采用哈希表存每个val出现的次数，并更新_max（全局出现次数最大值）, vector存list，vector下标代表val出现的频率，每层链表越靠后，代表在该频率下最接近栈顶

class FreqStack {
public:
    FreqStack() : _v(20000), _max(0){
        
    }
    
    void push(int val) {
        if(!_map.contains(val)) _map[val] = 1;
        else _map[val]++;
        _max = _map[val] > _max ? _map[val] : _max;
        _v[_map[val] - 1].push_back(val);
    }
    
    int pop() {
        int val = _v[_max - 1].back();
        _map[val]--;
        _v[_max - 1].pop_back();
        if(_v[_max - 1].empty()) _max--;
        return val;
    }

private:
    unordered_map<int, int> _map;
    vector<list<int>> _v;
    int _max;
};
