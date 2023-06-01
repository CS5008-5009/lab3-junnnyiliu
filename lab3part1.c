#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

int searchElement(struct Node* head, int element) {
    struct Node* current = head;
    int position = 0;

    while (current != NULL) {
        if (current->value == element) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;
}

void insertAtPosition(struct Node** head, int element, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = element;

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    int currentPosition = 0;

    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void insertAtHead(struct Node** head, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = element;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = element;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void deleteElement(struct Node** head, int element) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    if ((*head)->value == element) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node* current = *head;

    while (current->next != NULL && current->next->value != element) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Element not found\n");
        return;
    }

    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void deleteHead(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* current = *head;

    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

void printLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 23);
    insertAtEnd(&head, 52);
    insertAtEnd(&head, 19);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 100);

    printf("Original linked list: ");
    printLinkedList(head);

    int elementToSearch;
    printf("Enter an element to search: ");
    scanf("%d", &elementToSearch);
    int position = searchElement(head, elementToSearch);

    if (position != -1) {
        printf("Element found at position %d\n", position);
    }
    else {
        printf("Element not found\n");
    }

    int elementToInsert, insertPosition;
    printf("Enter an element to insert: ");
    scanf("%d", &elementToInsert);
    printf("Enter the position to insert: ");
    scanf("%d", &insertPosition);
    insertAtPosition(&head, elementToInsert, insertPosition);

    printf("Linked list after insertion: ");
    printLinkedList(head);

    int elementToInsertHead;
    printf("Enter an element to insert at the head: ");
    scanf("%d", &elementToInsertHead);
    insertAtHead(&head, elementToInsertHead);

    printf("Linked list after insertion at the head: ");
    printLinkedList(head);

    int elementToInsertEnd;
    printf("Enter an element to insert at the end: ");
    scanf("%d", &elementToInsertEnd);
    insertAtEnd(&head, elementToInsertEnd);

    printf("Linked list after insertion at the end: ");
    printLinkedList(head);

    int elementToDelete;
    printf("Enter an element to delete: ");
    scanf("%d", &elementToDelete);
    deleteElement(&head, elementToDelete);

    printf("Linked list after deletion: ");
    printLinkedList(head);

    deleteHead(&head);

    printf("Linked list after deleting the head: ");
    printLinkedList(head);

    deleteLast(&head);

    printf("Linked list after deleting the last element: ");
    printLinkedList(head);

    return 0;
}
