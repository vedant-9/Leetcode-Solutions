// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    // Idea is to maintain two heaps max and min their length diff should at most 1.
    // insert all elements according to their half where it belongs
    // both heap tops are middle elements
    // max from first half top of p and min of second half is top of q
    
private:
    priority_queue<int> p; // max_heap for the first half
    priority_queue<int,vector<int>,greater<int>> q; // min_heap for the second half
public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        if (p.empty() || (p.top() > num))
            p.push(num); // if it belongs to the smaller half
        else
            q.push(num);

        // rebalance the two halfs to make sure the length difference is no larger than 1
        if (p.size() > (q.size() + 1))
        {
            q.push(p.top());
            p.pop();
        }
        else if (p.size() + 1 < q.size())
        {
            p.push(q.top());
            q.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        if (p.size() == q.size())
            return p.empty() ? 0 : ((p.top() + q.top()) / 2.0);
        else
            return (p.size() > q.size()) ? p.top() : q.top();
    }
};