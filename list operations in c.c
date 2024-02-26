#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct Node
{
    int number;
    struct Node *next;
};

// Function prototypes
struct Node *createNode(int num);
void printList(struct Node *head);
void append(struct Node **head, int num);
void prepend(struct Node **head, int num);
void deleteByKey(struct Node **head, int key);
void deleteByValue(struct Node **head, int value);
void insertAfterKey(struct Node **head, int key, int value);
void insertAfterValue(struct Node **head, int searchValue, int newValue);


int main()
{
    struct Node *head = NULL;
    int choice, data;

    while (1)
    {
        printf("Linked Lists\n");
        printf("1. Print List\n");
        printf("2. Append\n");
        printf("3. Prepend\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printList(head);
            continue;
        }
        else if (choice == 2)
        {
            printf("Enter data to append: ");
            scanf("%d", &data);
            append(&head, data);
            continue;
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
            continue;
        }
    }

    return 0;
}

// Create a new node
struct Node *createNode(int num)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->number = num;
    newNode->next = NULL;
    return newNode;
}

// Print the linked list
void printList(struct Node *head)
{
    struct Node *current = head;
    printf("List: ");
    while (current != NULL)
    {
        printf("%d ", current->number);
        current = current->next;
    }
    printf("\n");
}

// Append a node to the end of the list
void append(struct Node **head, int num)
{
    struct Node *newNode = createNode(num);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Prepend a node to the beginning of the list
void prepend(struct Node **head, int num)
{
    struct Node *newNode = createNode(num);
    newNode->next = *head;
    *head = newNode;
}

// Delete a node by key
void deleteByKey(struct Node **head, int key)
{
    struct Node *current = *head;
    struct Node *prev = NULL;
    while (current != NULL && current->number != key)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Key not found.\n");
        return;
    }
    if (prev == NULL)
    {
        *head = current->next;
    }
    else
    {
        prev->next = current->next;
    }
    free(current);
}

// Delete a node by value
void deleteByValue(struct Node **head, int value)
{
    struct Node *current = *head;
    struct Node *prev = NULL;
    while (current != NULL && current->number != value)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Value not found.\n");
        return;
    }
    if (prev == NULL)
    {
        *head = current->next;
    }
    else
    {
        prev->next = current->next;
    }
    free(current);
}

// Insert a node after a given key
void insertAfterKey(struct Node **head, int key, int value)
{
    struct Node *current = *head;
    while (current != NULL && current->number != key)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Key not found.\n");
        return;
    }
    struct Node *newNode = createNode(value);
    newNode->next = current->next;
    current->next = newNode;
}

// Insert a node after a given value
void insertAfterValue(struct Node **head, int searchValue, int newValue)
{
    struct Node *current = *head;
    while (current != NULL && current->number != searchValue)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Value not found.\n");
        return;
    }
    struct Node *newNode = createNode(newValue);
    newNode->next = current->next;
    current->next = newNode;
}
