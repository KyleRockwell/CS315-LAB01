#include "SortedLinkedListDict.hpp"
#include <cstdlib>
void SortedLinkedListDict::insert(int key)
{
    // head points to first (smallest node in the list)
    // create new node (newNode) with key as data & nullptr as next

    // if head-> == nullptr; ie the list is empty
    //   head->next = newNode

    // iterate thru linked list until either A, or B,
    // need pointer to current node, and pointer to previous node
    // curr starts at head, prev points to curr, if head->next != nullptr

    //

    //
    // A:if current node points to null, curr->next == nullptr
    //  then that means we are at the end of the list, and therefore newNode.data is the greatest value in the list
    //
    // B:if the current node is greater than key
    //  set prev->next = &NewNode
    //      set newnode.next = curr

    // when I define newNodw as: Node* newNode
    //       "node->next = nullptr" gives a segfault
    //       im not sure why

    Node* newNode = new Node;

    newNode->next = nullptr;
    newNode->data = key;

    Node* curr = new Node;
    // Node* prev = new Node;
    curr = head;
    if (head == nullptr || newNode->data < curr->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    //  advance one element in linked list

    // while not at the end of the list
    while (curr->next != nullptr) {
        //
        if (curr->next->data >= newNode->data) {

            // prev->next = newNode;

            newNode->next = curr->next;
            curr->next = newNode->next;
            return;
        }

        curr = curr->next;
    }
    //  curr->next = newNode;

    curr->next = newNode;

    // curr = &newNode;

    // Node* prev;
    // Node newNode;
    // newNode.next = nullptr;
    // newNode.data = key;
    //
    // Node* curr = head->next;
    // // start at head
    // while (curr->data < key) {
    //     if (curr->next == nullptr) {
    //         curr->next = &newNode;
    //         head->next = &newNode;
    //         return;
    //     }
    //     prev = curr;
    //     curr = curr->next;
    // }
    // // prev = curr;
    // // curr = curr->next;
    // prev->next = &newNode;
    // newNode.next = curr;
}

bool SortedLinkedListDict::lookup(int key) const
{
    Node* look = new Node;
    look = head;
    while (look->next != nullptr) {
        if (look->next->data == key) {
            return true;
        }
        look = look->next;
    }
    return false;
}

void SortedLinkedListDict::remove(int key)
{
    Node* curr = new Node;
    curr = head;
    if (curr == nullptr) {
        return;
    }
    while (curr->next != nullptr) {
        if (curr->next->data == key) {
            curr->next = curr->next->next;
        }
        curr = curr->next;
    }
}
