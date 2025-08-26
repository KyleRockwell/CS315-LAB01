#include "SortedLinkedListDict.hpp"
#include <cmath>
#include <cstddef>
#include <cstdlib>
void SortedLinkedListDict::insert(int key)
{

    Node prev;
    Node newNode;
    newNode.next = nullptr;
    newNode.data = key;

    Node curr = *head;
    // start at head
    while (curr.data < key) {
        if (curr.next == nullptr) {
            curr.next = &newNode;
        }
        prev = curr;
        curr = *curr.next;
    }
    prev = curr;
    curr = *curr.next;
    prev.next = &newNode;
    newNode.next = &curr;
}

bool SortedLinkedListDict::lookup(int key) const
{
    Node prev;

    Node curr = *head;
    // start at head
    while (curr.data != key) {
        if (curr.next == nullptr) {
            return false;
        }
        prev = curr;
        curr = *curr.next;
    }
    return true;
}

void SortedLinkedListDict::remove(int key)
{
    Node prev;

    Node curr = *head;
    // start at head
    while (curr.data != key) {
        if (curr.next == nullptr) {
            return;
        }
        prev = curr;
        curr = *curr.next;
    }
    free(prev.next);
    prev.next = curr.next;
    curr.next = nullptr;
}
