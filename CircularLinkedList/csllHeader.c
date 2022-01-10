// Circular Singly linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node nd;

// Function prototypes
void insertFront(nd *);
void insertRear(nd *);
void deleteFront(nd *);
void deleteRear(nd *);
void insertAtPos(nd *);
void delAtPos(nd *);
int countNode(nd *);
void search(nd *);
void display(nd *);
void deleteNodes(nd *);

int main()
{
    int ch;
    nd header = {.link = &header};

    for (;;)
    {
        printf("\n\nOperations in a CSLL\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Insert at a given position\n6.Delete from a given position\n7.Total number of nodes in a linked list\n8.Search for a given element\n9.Display\n10.Delete all the nodes\n10.Exit\n\nEnter a choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertFront(&header);
            break;
        case 2:
            insertRear(&header);
            break;
        case 3:
            deleteFront(&header);
            break;
        case 4:
            deleteRear(&header);
            break;
        case 5:
            insertAtPos(&header);
            break;
        case 6:
            delAtPos(&header);
            break;
        case 7:
            printf("There are %d nodes in the linked list !!", countNode(&header));
            break;
        case 8:
            search(&header);
            break;
        case 9:
            display(&header);
            break;
        case 10:
            deleteNodes(&header);
            break;
        default:
            exit(0);
            break;
        }
    }
}

// Inserting a node in the front end of the linked list
void insertFront(nd *h)
{
    nd *temp = (nd *)malloc(sizeof(nd));
    printf("Enter the value to be inserted in the front end of the node :");
    scanf("%d", &(temp->data));
    temp->link = h->link;
    h->link = temp;
}

// Inserting a node in the back end of the linked list
void insertRear(nd *h)
{
    if (h->link == h)
    {
        insertFront(h);
        return;
    }
    nd *temp = (nd *)malloc(sizeof(nd));
    printf("Enter the value to be inserted in the rear end of the node :");
    scanf("%d", &(temp->data));
    // ptr for traversinng
    nd *ptr = h->link;
    while (ptr->link != h)
    {
        ptr = ptr->link;
    }
    temp->link = ptr->link;
    ptr->link = temp;
}

// Displaying the contents of the linked list
void display(nd *h)
{
    if (h->link == h)
    {
        printf("The CSLL is empty !!");
        return;
    }
    nd *ptr = h->link;
    printf("The contents of the CSLL are : \n");
    while (ptr != h)
    {
        printf("%d ", (ptr->data));
        ptr = ptr->link;
    }
}

// Deleting the front side of the linked list
void deleteFront(nd *h)
{
    if (h->link == h)
    {
        printf("Linked list is empty !");
        return;
    }
    nd *t = h->link;
    printf("%d deleted from the linked list!! ", (t->data));
    h->link = t->link;
    free(t);
    t = 0;
}

// Deleting the rear side of the linked list
void deleteRear(nd *h)
{
    if (h->link == h)
    {
        printf("Linked list is empty !");
        return;
    }
    if(h->link->link == h)
    {
        deleteFront(h);
        return;
    }
    nd *prev = h->link;
    nd *curr = h->link;
    while (curr->link != h)
    {
        prev = curr;
        curr = curr->link;
    }
    prev->link = curr->link;
    printf("%d deleted from the linked list!! ", (curr->data));
    free(curr);
    curr = 0;
}

// Counting the total number of nodes present in a linked list
int countNode(nd *h)
{
    int count = 0;
    nd *t = h->link;
    while (t != h)
    {
        count++;
        t = t->link;
    }
    return count;
}

// Inserting a node at a given position
void insertAtPos(nd *h)
{
    int cnt, pos;
    cnt = countNode(h);
    printf("Enter the position where the node has to be inserted : ");
    scanf("%d", &pos);
    if ((pos > cnt + 1) || (pos < 1))
    {
        printf("Insertion is not possible !!");
        return;
    }
    if (pos == 1)
    {
        insertFront(h);
        return;
    }
    if (pos == cnt + 1)
    {
        insertRear(h);
        return;
    }
    nd *temp = (nd *)malloc(sizeof(nd));
    printf("Enter the value to be inserted in the rear end of the node :");
    scanf("%d", &(temp->data));
    nd *curr = h->link;
    nd *prev = h->link;
    while (pos != 1)
    {
        prev = curr;
        curr = curr->link;
        pos--;
    }
    temp->link = prev->link;
    prev->link = temp;
}

// Delete at a given position
void delAtPos(nd *h)
{
    int cnt = countNode(h);
    int pos;
    printf("Enter the postion for the node to be deleted :");
    scanf("%d", &pos);
    if (pos > cnt || pos <= 0)
    {
        printf("Deletion not possible !!");
        return;
    }
    if (pos == 1)
    {
        deleteFront(h);
        return;
    }
    if (pos == cnt)
    {
        deleteRear(h);
        return;
    }
    nd *prev = h->link;
    nd *curr = h->link;
    while (pos != 1)
    {
        prev = curr;
        curr = curr->link;
        pos--;
    }
    printf("%d deleted from the linked list !!", (curr->data));
    prev->link = curr->link;
    free(curr);
    curr = 0;
}

// Delete all the nodes from the linked list
void deleteNodes(nd *h)
{
    nd *ptr = h->link;
    nd *temp = h->link;
    while (ptr != h)
    {
        temp = ptr->link;
        free(ptr);
        ptr = temp;
    }
    h->link = temp;
    printf("All the nodes deleted from the linked list !!");
}

// Searching for a given element in a linked list
void search(nd *h)
{
    int key = 0, index = 1;
    printf("Enter the key element :");
    scanf("%d", &key);
    nd *ptr = h->link;
    while (ptr != h)
    {
        if (ptr->data == key)
        {
            printf("Key element %d is found at position %d", key, index);
            break;
        }
        ptr = ptr->link;
        index++;
    }
}