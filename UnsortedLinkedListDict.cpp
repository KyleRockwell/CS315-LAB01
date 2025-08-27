#include "UnsortedLinkedListDict.hpp"
void UnsortedLinkedListDict::insert(int key)
{
    Node newNode;

    newNode.next = head;
    newNode.data = key;
    head = &newNode;
}
bool UnsortedLinkedListDict::lookup(int) const { return false; }
void UnsortedLinkedListDict::remove(int) { }
