#include <bits/stdc++.h> 
#include "ex1.h"
using namespace std;

int main()
{
    int k = 3; // Number of linked lists 
    int n = 4; // Number of elements in each list 

    // an array of pointers storing the head nodes 
    // of the linked lists 
    Node* arr[k];

    // creating k = 3 sorted lists 
    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);

    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);

    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);

    // merge the k sorted lists 
    struct Node* head = mergeKSortedLists(arr, k);

    // print the merged list 
    printList(head);

    return 0;
}