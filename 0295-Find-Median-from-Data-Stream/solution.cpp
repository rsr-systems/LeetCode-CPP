#include <queue>
#include <vector>

class MedianFinder {
private:
    std::priority_queue<int> max_heap; // stores the smaller half
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap; // stores the larger half

public:
    MedianFinder() {}

    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();

        if (max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian() {
        if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        }
        return (max_heap.top() + min_heap.top()) / 2.0;
    }
};
