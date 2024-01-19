#include "DoublyLinkedList.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    DeleteAll();
}

template <typename T>
void DoublyLinkedList<T>::AddToHead(const T& value) {
    Node* newNode = new Node(value);
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
void DoublyLinkedList<T>::AddToTail(const T& value) {
    Node* newNode = new Node(value);
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
void DoublyLinkedList<T>::DeleteFromHead() {
    if (!head) {
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }

    delete temp;
}

template <typename T>
void DoublyLinkedList<T>::DeleteFromTail() {
    if (!tail) {
        return;
    }

    Node* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }

    delete temp;
}

template <typename T>
void DoublyLinkedList<T>::DeleteAll() {
    while (head) {
        DeleteFromHead();
    }
}

template <typename T>
void DoublyLinkedList<T>::Show() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::InsertAtPosition(const T& value, int position) {
    if (position < 0) {
        std::cerr << "Invalid position for insertion." << std::endl;
        return;
    }

    Node* newNode = new Node(value);

    if (position == 0) {
        newNode->next = head;
        if (head) {
            head->prev = newNode;
        }
        head = newNode;
        if (!tail) {
            tail = newNode;
        }
        return;
    }

    Node* current = head;
    for (int i = 0; i < position - 1 && current; ++i) {
        current = current->next;
    }

    if (!current) {
        std::cerr << "Invalid position for insertion." << std::endl;
        delete newNode;
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;

    if (newNode->next) {
        newNode->next->prev = newNode;
    }
    else {
        tail = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::DeleteAtPosition(int position) {
    if (position < 0) {
        std::cerr << "Invalid position for deletion." << std::endl;
        return;
    }

    if (position == 0) {
        DeleteFromHead();
        return;
    }

    Node* current = head;
    for (int i = 0; i < position && current; ++i) {
        current = current->next;
    }

    if (!current) {
        std::cerr << "Invalid position for deletion." << std::endl;
        return;
    }

    if (current->next) {
        current->next->prev = current->prev;
    }
    else {
        tail = current->prev;
    }

    current->prev->next = current->next;

    delete current;
}

template <typename T>
int DoublyLinkedList<T>::Search(const T& value) const {
    Node* current = head;
    int position = 0;

    while (current) {
        if (current->data == value) {
            return position;
        }

        current = current->next;
        ++position;
    }

    return -1;
}

template <typename T>
int DoublyLinkedList<T>::SearchAndReplace(const T& searchValue, const T& replaceValue) {
    Node* current = head;
    int count = 0;

    while (current) {
        if (current->data == searchValue) {
            current->data = replaceValue;
            ++count;
        }

        current = current->next;
    }

    return count;
}

template <typename T>
void DoublyLinkedList<T>::Reverse() {
    Node* current = head;
    Node* temp = nullptr;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp) {
        head = temp->prev;
    }
}

template class DoublyLinkedList<int>;
