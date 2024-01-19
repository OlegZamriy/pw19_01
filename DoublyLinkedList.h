#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

    bool contains(const T& value) const;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void addFront(const T& value);
    void addBack(const T& value);
    void remove(const T& value);
    void display() const;

    DoublyLinkedList<T>* clone() const;
    DoublyLinkedList<T>* operator+(const DoublyLinkedList<T>& other) const;
    DoublyLinkedList<T>* operator*(const DoublyLinkedList<T>& other) const;
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void DoublyLinkedList<T>::addFront(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::addBack(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (!tail) {
        head = tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::remove(const T& value) {
    Node<T>* current = head;
    while (current) {
        if (current->data == value) {
            if (current == head) {
                head = current->next;
                if (head) {
                    head->prev = nullptr;
                }
            }
            else if (current == tail) {
                tail = current->prev;
                if (tail) {
                    tail->next = nullptr;
                }
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            delete current;
            return;
        }
        current = current->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::display() const {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
bool DoublyLinkedList<T>::contains(const T& value) const {
    Node<T>* current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
DoublyLinkedList<T>* DoublyLinkedList<T>::clone() const {
    DoublyLinkedList<T>* clonedList = new DoublyLinkedList<T>();

    Node<T>* current = head;
    while (current) {
        clonedList->addBack(current->data);
        current = current->next;
    }

    return clonedList;
}

template <typename T>
DoublyLinkedList<T>* DoublyLinkedList<T>::operator+(const DoublyLinkedList<T>& other) const {
    DoublyLinkedList<T>* resultList = clone();

    Node<T>* current = other.head;
    while (current) {
        if (!resultList->contains(current->data)) {
            resultList->addBack(current->data);
        }
        current = current->next;
    }

    return resultList;
}

template <typename T>
DoublyLinkedList<T>* DoublyLinkedList<T>::operator*(const DoublyLinkedList<T>& other) const {
    DoublyLinkedList<T>* resultList = new DoublyLinkedList<T>();

    Node<T>* current = head;
    while (current) {
        if (other.contains(current->data)) {
            resultList->addBack(current->data);
        }
        current = current->next;
    }

    return resultList;
}

#endif // DOUBLYLINKEDLIST_H
