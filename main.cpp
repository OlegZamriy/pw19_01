#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> intQueue;

    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);

    while (!intQueue.isEmpty()) {
        std::cout << intQueue.dequeue() << " ";
    }

    std::cout << std::endl;

    return 0;
}
