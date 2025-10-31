//根据大小根堆的性质把数据分成"较小的部分和较大的部分"这两部分，堆顶元素为所求


class MedianFinder {
public:
    void addNum(int num) {
        if(_maxheap.empty() || _maxheap.top() >= num){
            _maxheap.push(num);
        }else{
            _minheap.push(num);
        }

        if(_maxheap.size() - _minheap.size() == 2){
            _minheap.push(_maxheap.top());
            _maxheap.pop();
        }else if(_minheap.size() - _maxheap.size() == 2){
            _maxheap.push(_minheap.top());
            _minheap.pop();
        }

    }
    
    double findMedian() {
        int n = _maxheap.size() + _minheap.size();
        if(n % 2 == 0) return (_maxheap.top() + _minheap.top()) / 2.0;
        else return _maxheap.size() > _minheap.size() ? 
            _maxheap.top() : _minheap.top();
    }

private:
    priority_queue<double> _maxheap;
    priority_queue<double, vector<double>, greater<double>> _minheap;
};
