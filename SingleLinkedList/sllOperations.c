//Single Linked List 
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link; // Self referential structure;
};
typedef struct node nd;

// Function prototypes

nd *insertFront(nd *);
nd *insertRear(nd *);
nd *deleteFront(nd *);
nd *deleteRear(nd *);
nd *deleteAllNodes(nd *);
nd *insertAtPos(nd *);
nd *deleteAtPos(nd *);
nd *reverseSll(nd *);
void count(const nd *);
void display(const nd *);

int main()
{
    nd *first = 0;
    int ch;
    for (;;)
    {
        printf("\n\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Total nodes in a linked list\n6.Insert at a position\n7.Delete at a position\n8.Reverse a linked list\n9.Display\n10.Delete all nodes of a linked list\n11.Exit\nEnter a choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            first = insertFront(first);
            break;
        case 2:
            first = insertRear(first);
            break;
        case 3:
            first = deleteFront(first);
            break;
        case 4:
            first = deleteRear(first);
            break;
        case 5:
            count(first);
            break;
        case 6:
            first = insertAtPos(first);
            break;
        case 7:
            first = deleteAtPos(first);
            break;
        case 8:
            first = reverseSll(first);
            break;
        case 9:
            display(first);
            break;
        case 10:
            first = deleteAllNodes(first);
            break;

        default:exit(0);
            break;
        }
    }
}

// Inserting a node to the front end of the linked list
nd *insertFront(nd *first)
{
    nd *temp;
    temp = (nd *)malloc(sizeof(nd));
    printf("Enter a value to be inserted in a Linked list: ");
    scanf("%d", &(temp->data));
    temp->link = first;
    first = temp;
    return first;
}

// Inserting a node to the rear end of the linked list
nd *insertRear(nd *first)
{
    nd *temp;
    nd *last = first;
    temp = (nd *)malloc(sizeof(nd));
    printf("Enter a value to be inserted in a Linked list: ");
    scanf("%d", &(temp->data));
    temp->link = 0;
    if (first == 0)
        return temp;
    // for(last=first;last->link!=0;last=last->link);
    while (last->link != 0)
    {
        last = last->link;
    }
    last->link = temp;
    return first;
}

//?Deleting the front side of the node
nd *deleteFront(nd *first)
{
    if (first == 0)
    {
        printf("SLL is empty!!");
        return 0;
    }
    if (first->link == 0)
    {
        printf("%d removed from front end of the Linked List", (first->data));
        free(first);
        return 0;
    }
    nd *temp = first;
    printf("%d removed from front end of Linked List", (temp->data));
    first = first->link;
    free(temp);
    temp = 0;
    return first;
}

// Deleting the rear side of the node
nd *deleteRear(nd *first)
{
    if (first == 0)
    {
        printf("SLL is empty !!");
        return 0;
    }
    if (first->link == 0)
    {
        printf("%d removed from rear end of Linked List", (first->data));
        free(first);
        return 0;
    }
    nd *prev = first;
    nd *current = first;
    while (current->link != 0)
    {
        prev = current;
        current = current->link;
    }
    prev->link = 0;
    printf("%d removed from rear end of Linked List", (current->data));
    free(current);
    current = 0;
    return first;
}

// Counting the number of nodes in a linked list
void count(const nd *first)
{
    int count;
    while (first != 0)
    {
        first = first->link;
        count++;
    }
    printf("There are %d nodes in the linked list!!", count);
}

// Displaying the nodes of a given linked list
void display(const nd *first)
{
    if (first == 0)
    {
        printf("The linked list doesn't contain any node!");
        return;
    }
    printf("The contents of the linked list are: \n");
    while (first != 0)
    {
        printf("%d ", (first->data));
        first = first->link;
    }
}
// Inserting a element at a given position
nd *insertAtPos(nd *first)
{
    int pos, count;
    nd *temp = first;
    if (first == 0)
        count = 0;
    else // for(temp=first;temp!=0;temp=temp->link,cnt++);
    {
        while (temp != 0)
        {
            count++;
            temp = temp->link;
        }
    }
    printf("Enter the position for the element to be inserted :");
    scanf("%d", &pos);
    if ((pos > count + 1) || (pos < 1))
    {
        printf("Insertion not possible");
        return first;
    }
    if (pos == 1)
    {
        first = insertFront(first);
        return first;
    }
    if (pos == count + 1)
    {
        first = insertRear(first);
        return first;
    }
    nd *ptr = first;
    temp = (nd *)malloc(sizeof(nd));
    printf("Enter the value to be inserted at %d position :", pos);
    scanf("%d", &(temp->data));
    temp->link = 0;
    pos--;
    while (pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }
    temp->link = ptr->link;
    ptr->link = temp;
    return first;
}

// Deleting a element from a given position
nd *deleteAtPos(nd *first)
{
    int pos, count;
    nd *temp = first;
    if (first == 0)
        count = 0;
    else // for(temp=first;temp!=0;temp=temp->link,cnt++);
    {
        while (temp != 0)
        {
            count++;
            temp = temp->link;
        }
    }
    printf("Enter the position for the element to be removed :");
    scanf("%d", &pos);
    if ((pos <= 0) || (pos > count))
    {
        printf("Deletion not possible !");
        return first;
    }
    if (pos == 1)
    {
        first = deleteFront(first);
        return first;
    }
    if (pos == count)
    {
        first = deleteRear(first);
        return first;
    }
    nd *current = first;
    nd *previous = first;
    while (pos != 1)
    {
        previous = current;
        current = current->link;
        pos--;
    }
    previous->link = current->link;
    printf("%d removed from Linked List", (current->data));
    free(current);
    current = 0;
    return first;
}

// Deleting all the nodes from a linked list
nd *deleteAllNodes(nd *first)
{
    nd *temp = first;
    while (temp != 0)
    {
        temp = first->link; // First take the address of 2nd node and save in temp and deallocate first ,store the value of temp in first
        free(first);
        first = temp;
    }
    printf("All the nodes successfully deleted %d!!"); // temp will be equal to 0
    return 0;
}

// Reverse the single linked list
nd *reverseSll(nd *first)
{
    nd *prev = 0;
    nd *next = 0;
    while (first != 0)
    {
        next = first->link;
        first->link = prev;
        prev = first;
        first = next;
    }
    first = prev;
    printf("Linked list is successfully reversed !!\n ");
    return first;
}


//********************************* END ********************************************