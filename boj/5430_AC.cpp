#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <deque>
#include <cctype>

class AC
{
public:
    AC(std::string input) : mode_(Mode::Normal)
    {
        container_ = Parse_(input);
    }

    void PrintContainer() const
    {
        if (container_.empty()) 
        {
            std::cout << "[]\n";
            return;
        }

        std::cout << '[';
        
        if (mode_ == Mode::Normal)
        {
            auto it = std::begin(container_);
            for(; it != std::end(container_) - 1; it++)
            {
                std::cout << *it << ',';
            }
            std::cout << *it << "]\n";
        }
        else
        {
            auto it = std::rbegin(container_);
            for(; it != std::rend(container_) - 1; it++)
            {
                std::cout << *it << ',';
            }
            std::cout << *it << "]\n";
        }
    }

    bool Command(char command)
    {
        if (command == 'R')
        {
            Reverse_();
        }
        else if (command == 'D' && !container_.empty())
        {
            Pop_();
        }
        else
        {
            return false;
        }

        return true;
    }

private:
    enum class Mode
    {
        Normal,
        Reverse
    };

    std::deque<int> Parse_(std::string input)
    {
        std::deque<int> result;
        input = input.substr(1, input.size()-2);

        std::stringstream ss(input);
        std::string number;
        while(std::getline(ss, number, ','))
        {
            result.push_back(std::stoi(number));
        }

        return std::move(result);
    }

    void Reverse_()
    {
        mode_ = (mode_ == Mode::Normal ? Mode::Reverse : Mode::Normal);
    }

    void Pop_()
    {
        if (mode_ == Mode::Normal)
        {
            container_.pop_front();
        }
        else
        {
            container_.pop_back();
        }
    }


    std::deque<int> container_;
    Mode mode_;
};


int main()
{
    int t;
    std::cin >> t;
    
    while (t--)
    {
        std::string command;
        int n;
        std::string input;
        std::cin >> command >> n >> input;

        AC ac(input);
        bool complete = true;
        for (const auto& it : command)
        {
            if(ac.Command(it) == false)
            {
                std::cout << "error\n";
                complete = false;
                break;
            }
        }

        if (complete)
        {
            ac.PrintContainer();
        }
    }
    return 0;
}
