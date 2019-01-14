#include <iostream>
#include <vector>
#include <numeric>

class CircularQueue
{
public:
    static constexpr int DELETED = -1;

    CircularQueue(int n) : queue_(n, true)
    {
        std::iota(queue_.begin(), queue_.end(), 1);
        head_ = queue_.begin();
    }
    
    void Step(int n)
    {
        for(int i=0; i<n; i++)
        {
            Step_();
            while(*head_ == DELETED) Step_();
        }
    }

    int Pop()
    {
        int index = *head_;
        *head_ = DELETED;

        return index;
    }

private:
    void Step_()
    {
        head_++;
        if(head_ == queue_.end())
            head_ = queue_.begin();
    }
    std::vector<int> queue_;
    std::vector<int>::iterator head_;
};

int main()
{
    int n, m;
    std::cin >> n >> m;

    CircularQueue cq(n);

    std::cout << '<';
    cq.Step(m-1);
    std::cout << cq.Pop();
    for(int i=1; i<n; i++)
    {
        cq.Step(m);
        std::cout << ", " << cq.Pop();
    }
    std::cout << ">\n";

    return 0;
}
