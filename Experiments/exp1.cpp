#include <iostream>
#include <queue>

int main()
{
    std::priority_queue<int> pq;

    pq.push(100);
    pq.push(105);
    pq.push(99);
    pq.push(110);

    while(!pq.empty())
    {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }

    return 0;
}