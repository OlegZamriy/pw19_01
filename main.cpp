#include <iostream>
#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> list1;
    list1.addBack(1);
    list1.addBack(2);
    list1.addBack(3);
    list1.display();

    DoublyLinkedList<int> list2;
    list2.addBack(2);
    list2.addBack(3);
    list2.addBack(4);
    list2.display();

    DoublyLinkedList<int>* clonedList = list1.clone();
    clonedList->display();

    DoublyLinkedList<int>* mergedList = list1 + list2;
    mergedList->display();

    DoublyLinkedList<int>* intersectionList = list1 * list2;
    intersectionList->display();

    list1.remove(2);
    list1.display();

    delete clonedList;
    delete mergedList;
    delete intersectionList;

    return 0;
}
