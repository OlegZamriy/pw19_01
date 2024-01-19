#include <iostream>
#include "Array.h"

int main() {
    Array<int> arr;
    arr.SetSize(5, 5);

    std::cout << "Initial array size: " << arr.GetSize() << std::endl;

    for (int i = 0; i < arr.GetSize(); ++i) {
        arr.SetAt(i, i * 10);
    }

    std::cout << "Array elements: ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        std::cout << arr.GetAt(i) << " ";
    }
    std::cout << std::endl;

    arr.Add(50);
    std::cout << "Array size after adding an element: " << arr.GetSize() << std::endl;

    arr.InsertAt(2, 99);
    std::cout << "Array after inserting an element at index 2: ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        std::cout << arr.GetAt(i) << " ";
    }
    std::cout << std::endl;

    arr.RemoveAt(4);
    std::cout << "Array after removing an element at index 4: ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        std::cout << arr.GetAt(i) << " ";
    }
    std::cout << std::endl;

    Array<int> arr2;
    arr2.SetSize(3, 2);
    for (int i = 0; i < arr2.GetSize(); ++i) {
        arr2.SetAt(i, i * 5);
    }

    std::cout << "Second array elements: ";
    for (int i = 0; i < arr2.GetSize(); ++i) {
        std::cout << arr2.GetAt(i) << " ";
    }
    std::cout << std::endl;

    arr.Append(arr2);
    std::cout << "Array after appending the second array: ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        std::cout << arr.GetAt(i) << " ";
    }
    std::cout << std::endl;

    Array<int> arr3;
    arr3 = arr;
    std::cout << "Third array after assigning the first array: ";
    for (int i = 0; i < arr3.GetSize(); ++i) {
        std::cout << arr3.GetAt(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
