#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createList(int arr[], int n)
{
    // initializing first node
    struct Node *first = NULL;

    struct Node *t;
    struct Node *last;

    // setup a new node
    first = new struct Node;
    first->data = arr[0];
    first->next = NULL;

    // last is first as 1 element only
    last = first;

    for (int i = 1; i < n; i++)
    {
        // setup a new node
        t = new struct Node;
        t->data = arr[i];
        t->next = NULL;

        // make current last point to new node
        last->next = t;

        // update last
        last = t;
    }

    return first;
};

struct Node *createLoopedList(int arr[], int n, int loopedIndex)
{
    // initializing first node
    struct Node *first = NULL;

    struct Node *t;
    struct Node *last;
    struct Node *loopedPosition;

    // setup a new node
    first = new struct Node;
    first->data = arr[0];
    first->next = NULL;

    // last is first as 1 element only
    last = first;

    for (int i = 1; i < n; i++)
    {
        // setup a new node
        t = new struct Node;
        t->data = arr[i];
        t->next = NULL;

        // make current last point to new node
        last->next = t;

        // update last
        last = t;

        if (i == loopedIndex)
        {
            loopedPosition = last;
        }
    }

    last->next = loopedPosition;

    return first;
};

void printList(struct Node *p)
{
    // while address of next block is not null
    while (p != NULL)
    {
        cout << (p->data) << " ";
        p = p->next;
    }

    cout << endl;
};

// approach to find
// take 2 cars with variable speed
// if car moving faster meets the slow car that means the path is circular and not liner
bool isLooped(struct Node *A)
{
    struct Node *slow = A;
    struct Node *fast = A;

    while (fast->next != NULL)
    {
        // moved 2 nodes at a time
        fast = fast->next;
        if (fast->next == NULL)
        {
            return false;
        }

        fast = fast->next;

        slow = slow->next;

        // agar beech me null aagaya toh return ho gaye function
        if (fast->next == NULL)
        {
            return false;
        }

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int arr1[] = {6, 7, 9, 13, 18, 89, 100};
    int arr2[] = {16, 27, 19, 103, 108, 589, 700};
    int n = 7;
    struct Node *A = createList(arr1, n);
    struct Node *B = createLoopedList(arr2, n, 3);

    cout << isLooped(A) << endl;
    cout << isLooped(B) << endl;

    return 0;
}