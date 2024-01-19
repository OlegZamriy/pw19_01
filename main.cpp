#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> list;

    list.AddToHead(3);
    list.AddToHead(2);
    list.AddToHead(1);

    list.AddToTail(4);
    list.AddToTail(5);

    list.Show();

    list.InsertAtPosition(10, 2);
    list.Show();

    list.DeleteAtPosition(1);
    list.Show();

    int searchResult = list.Search(4);
    if (searchResult != -1) {
        std::cout << "Element 4 found at position " << searchResult << std::endl;
    }
    else {
        std::cout << "Element 4 not found" << std::endl;
    }

    int replaceCount = list.SearchAndReplace(3, 30);
    std::cout << "Replaced " << replaceCount << " occurrences of 3 with 30" << std::endl;
    list.Show();

    list.Reverse();
    list.Show();

    list.DeleteAll();

    return 0;
}
