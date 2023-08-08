class MedianFinder
{
public:
    MedianFinder()
    {}

    void addNum(int num)
    {
        max_heap.push(num);

        if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top())
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        if (max_heap.size() > min_heap.size() + 1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        if (max_heap.size() + 1 < min_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian()
    {
        if (max_heap.size() > min_heap.size())
            return max_heap.top();
        if (max_heap.size() < min_heap.size())
            return min_heap.top();
        return (max_heap.top() + min_heap.top()) / 2.0f;
    }
private:
    priority_queue<int> max_heap;                               // Max Heap - finding max in O(1)
    priority_queue<int, vector<int>, greater<int>> min_heap;    // Min Heap - finding min in O(1)
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */