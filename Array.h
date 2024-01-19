#ifndef ARRAY_H
#define ARRAY_H

#include "Node.h"

template <typename T>
class Array {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
    int grow;

public:
    Array();
    ~Array();

    int GetSize() const;
    void SetSize(int size, int grow = 1);
    int GetUpperBound() const;
    bool IsEmpty() const;
    void FreeExtra();
    void RemoveAll();
    T GetAt(int index) const;
    void SetAt(int index, const T& value);
    T operator[](int index) const;
    void Add(const T& value);
    void Append(const Array<T>& other);
    Array<T>& operator=(const Array<T>& other);
    T* GetData() const;
    void InsertAt(int index, const T& value);
    void RemoveAt(int index);
};

template <typename T>
Array<T>::Array() : head(nullptr), tail(nullptr), size(0), grow(1) {}

template <typename T>
Array<T>::~Array() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
int Array<T>::GetSize() const {
    return size;
}

template <typename T>
void Array<T>::SetSize(int newSize, int newGrow) {
    if (newSize < size) {
        Node<T>* current = head;
        for (int i = 0; i < newSize; ++i) {
            current = current->next;
        }

        while (current) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }

        if (newSize == 0) {
            head = tail = nullptr;
        }
        else {
            tail->next = nullptr;
        }
    }
    else if (newSize > size) {
        int additionalSize = newSize - size;
        int newSizeWithGrowth = size + additionalSize + newGrow - 1;
        newSizeWithGrowth -= newSizeWithGrowth % newGrow;

        Node<T>* current = tail;
        for (int i = 0; i < newSizeWithGrowth - size; ++i) {
            Node<T>* newNode = new Node<T>(T());
            current->next = newNode;
            newNode->prev = current;
            tail = newNode;
            current = newNode;
        }
    }

    size = newSize;
    grow = newGrow;
}

template <typename T>
int Array<T>::GetUpperBound() const {
    return size - 1;
}

template <typename T>
bool Array<T>::IsEmpty() const {
    return size == 0;
}

template <typename T>
void Array<T>::FreeExtra() {
    int newSizeWithGrowth = size + grow - 1;
    newSizeWithGrowth -= newSizeWithGrowth % grow;

    if (newSizeWithGrowth < size) {
        // Видаляємо "зайві" елементи
        Node<T>* current = head;
        for (int i = 0; i < newSizeWithGrowth; ++i) {
            current = current->next;
        }

        while (current) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }

        if (newSizeWithGrowth == 0) {
            head = tail = nullptr;
        }
        else {
            tail->next = nullptr;
        }

        size = newSizeWithGrowth;
    }
}

template <typename T>
void Array<T>::RemoveAll() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }

    head = tail = nullptr;
    size = 0;
}

template <typename T>
T Array<T>::GetAt(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }

    Node<T>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current->data;
}

template <typename T>
void Array<T>::SetAt(int index, const T& value) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }

    Node<T>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    current->data = value;
}

template <typename T>
T Array<T>::operator[](int index) const {
    return GetAt(index);
}

template <typename T>
void Array<T>::Add(const T& value) {
    SetSize(size + 1, grow);
    SetAt(size - 1, value);
}

template <typename T>
void Array<T>::Append(const Array<T>& other) {
    SetSize(size + other.size, grow);

    Node<T>* current = other.head;
    for (int i = 0; i < other.size; ++i) {
        SetAt(size - other.size + i, current->data);
        current = current->next;
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        RemoveAll();
        Append(other);
    }
    return *this;
}

template <typename T>
T* Array<T>::GetData() const {
    T* data = new T[size];
    Node<T>* current = head;
    for (int i = 0; i < size; ++i) {
        data[i] = current->data;
        current = current->next;
    }
    return data;
}

template <typename T>
void Array<T>::InsertAt(int index, const T& value) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index out of bounds");
    }

    if (index == size) {
        Add(value);
        return;
    }

    Node<T>* newNode = new Node<T>(value);

    if (index == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else {
        Node<T>* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }

    ++size;
}

template <typename T>
void Array<T>::RemoveAt(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }

    Node<T>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    if (index == 0) {
        head = current->next;
        if (head) {
            head->prev = nullptr;
        }
    }
    else {
        current->prev->next = current->next;
        if (current->next) {
            current->next->prev = current->prev;
        }
    }

    delete current;
    --size;
}

#endif // ARRAY_H
