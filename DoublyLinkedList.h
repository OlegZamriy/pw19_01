#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void AddToHead(const T& value);
    void AddToTail(const T& value);
    void DeleteFromHead();
    void DeleteFromTail();
    void DeleteAll();
    void Show() const;

    void InsertAtPosition(const T& value, int position);
    void DeleteAtPosition(int position);
    int Search(const T& value) const;
    int SearchAndReplace(const T& searchValue, const T& replaceValue);
    void Reverse();
};

#endif // DOUBLYLINKEDLIST_H
