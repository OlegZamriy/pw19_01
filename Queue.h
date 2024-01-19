#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template <typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    Queue();
    ~Queue();

    void enqueue(const T& value);
    T dequeue();
    bool isEmpty() const;
};

template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr) {}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
void Queue<T>::enqueue(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }

    T data = front->data;
    Node<T>* temp = front;

    if (front == rear) {
        front = rear = nullptr;
    }
    else {
        front = front->next;
        front->prev = nullptr;
    }

    delete temp;
    return data;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return front == nullptr;
}

#endif // QUEUE_H
