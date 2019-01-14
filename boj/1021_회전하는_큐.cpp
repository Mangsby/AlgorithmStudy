#include <iostream>
#include <deque>
#include <numeric>
#include <iterator>
#include <algorithm>

class RotatingQueue
{
public:
    RotatingQueue(int size) : operationCount_(0), queue_(size)
    {
        std::iota(std::begin(queue_), std::end(queue_), 1);
    }

    void Pop(int targetNumber)
    {
        if (queue_.front() == targetNumber)
        {
            queue_.pop_front();
            return;
        }
        
        using namespace std;
        auto position = find(begin(queue_), end(queue_), targetNumber);
        const int rightwiseDistance = distance(begin(queue_), position);
        const int leftwiseDistance = queue_.size() - rightwiseDistance;
        operationCount_ += std::min(rightwiseDistance, leftwiseDistance);

        rotate(begin(queue_), position, end(queue_));
        queue_.pop_front();
    }
    
    int GetOperationCount() const { return operationCount_; }

private:
    int operationCount_;
    std::deque<int> queue_;
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    RotatingQueue rq(n);
    for (int i=0; i<m; i++)
    {
        int targetNumber;
        std::cin >> targetNumber;
        rq.Pop(targetNumber);
    }

    std::cout << rq.GetOperationCount() << '\n';
    return 0;
}
