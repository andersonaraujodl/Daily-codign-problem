/*
Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.

Date: 15/04/2020
*/

#include <iostream>
#include "const.h"

class SingleLinkedList
{
public:
	int value;
	SingleLinkedList* next;
};

int Count(SingleLinkedList* head)
{
    SingleLinkedList* current = head;

    int count = 0;

    while (current != NULL)
    {
        ++count;
        current = current->next;
    }

    return count;
}

int GetIntersetctionPoint(SingleLinkedList* headA, SingleLinkedList* headB)
{
    int aCount = Count(headA);
    int intersection = -1;

    for (int i = 0; i < aCount; ++i)
    {
        if (headA->value == headB->value)
        {
            intersection = headA->value;
            continue;
        }

        return intersection;
    }
}

SingleLinkedList* ReverseList(SingleLinkedList* head)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    SingleLinkedList* list_to_do = head->next;

    SingleLinkedList* reversed_list = head;
    reversed_list->next = nullptr;

    while (list_to_do != nullptr) {
        SingleLinkedList* temp = list_to_do;
        list_to_do = list_to_do->next;

        temp->next = reversed_list;
        reversed_list = temp;
    }

    return reversed_list;
}

#ifdef _20_IntersectNode
int main()
{
    //A = 3 -> 7 -> 8 -> 10 

    SingleLinkedList* newItem;
    
    SingleLinkedList* headA = new SingleLinkedList();
    headA->value = 3;

    newItem = new SingleLinkedList();
    newItem->value = 7;
    headA->next = newItem;

    //B = 99 -> 1 -> 8 -> 10
    SingleLinkedList* headB = new SingleLinkedList();
    headB->value = 99;

    newItem = new SingleLinkedList();
    newItem->value = 1;
    headB->next = newItem;

    newItem = new SingleLinkedList();
    newItem->value = 8;
    headA->next->next = newItem;
    headB->next->next = newItem;

    newItem = new SingleLinkedList();
    newItem->value = 10;
    headA->next->next->next = newItem;
    headB->next->next->next = newItem;

    while (headA != NULL)
    {
        std::cout << headA->value << ", ";
        headA = headA->next;
    }
    std::cout << std::endl;
    std::cout << GetIntersetctionPoint(headA, headB) << std::endl;
    std::cin.get();
}
#endif