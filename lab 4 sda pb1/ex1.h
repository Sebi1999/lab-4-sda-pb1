#pragma once
struct Node {
    int data;
    struct Node* next;
};

// 'compare'-function to build  priority queue

struct compare {
    bool operator()(struct Node* a, struct Node* b)
    {
        return a->data > b->data;
    }
};

// function to merge k sorted linked lists 
struct Node* mergeKSortedLists(struct Node* arr[], int k)
{
    struct Node* head = NULL, * last;

    // priority_queue 'pq' implemeted as min heap with the 
    // help of 'compare' function 
    priority_queue<Node*, vector<Node*>, compare> pq;


    for (int i = 0; i < k; i++)
        if (arr[i] != NULL)
            pq.push(arr[i]);


    while (!pq.empty()) {


        struct Node* top = pq.top();
        pq.pop();

        // check if there is a node next to the 'top' node 
        // in the list of which 'top' node is a member 
        if (top->next != NULL)

            pq.push(top->next);

        // if final merged list is empty 
        if (head == NULL) {
            head = top;



            last = top;
        }

        else {
            // insert 'top' at the end of the merged list so far 
            last->next = top;


            last = top;
        }
    }


    return head;
}

// function to print the singly linked list 
void printList(struct Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Utility function to create a new node 
struct Node* newNode(int data)
{

    struct Node* new_node = new Node();


    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}
