#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;
typedef struct List list;

struct Node {
    int value;
    node* nextNode;
};

struct List {
    node* head;
    node* lastNode;
};

list* createList() {
    return malloc(sizeof(list));
}

node* createNode(int value) {
    node* node = malloc(sizeof(node));

    node->value = value;

    return node;
}

void addNode(list* list, int value) {
    node* newNode = createNode(value);

    if(list->head == NULL) {
        list->head = newNode;
        list->lastNode = newNode;
    } else {
        node* tempNode = list->lastNode;

        tempNode->nextNode = newNode;
        list->lastNode = newNode;
    }
}

void printList(list list) {
    node* aux = list.head;

    while(aux != NULL) {
        printf("--> %d", aux->value);

        aux = aux->nextNode;
    }
}

int main() {
    list* list = createList();

    addNode(list, 12);
    addNode(list, 14);
    addNode(list, 11);
    addNode(list, 10);

    printList(*list);
}
