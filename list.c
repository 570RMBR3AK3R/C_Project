#include "selforg.h"


Node *createNode(int x){

    Node *newnode = (Node *)malloc(sizeof(Node));
    if(newnode == NULL){
        printf("No memory created");
        exit(MALLOC_FAILURE);
    }
    newnode->data=x;
    newnode->next=NULL;
    newnode->count=1;
    newnode->prev=NULL;
    return newnode;

}


void insertatbegin(Node **head , int x){

    Node *newnode = createNode(x);
    if(*head == NULL){
        *head = newnode;
        //printf("New Node attached successfully");
        return;
    }
    newnode->next=(*head);
    (*head)->prev=newnode;
    *head=newnode;
    //printf("Node attached successfully");

}

Node *find(Node** head, int x){
    Node *current = *head;
    while(current != NULL){
        if(current->data == x){
            current->count++;
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void move_to_front(Node **head, Node *node){
    if (*head == node){
        return;
    }
    if(node->prev){
        node->prev->next = node->next;
    }
    if(node->next){
        node->next->prev = node->prev;
    }

    node->next = *head;
    node->prev = NULL;
    (*head)->prev = node;
    *head = node;

}

void write_to_file(Node *head, FILE *output_file){
    Node *current = head;
    while (current != NULL) {
        fprintf(output_file, "Number: %d, Access Count: %d\n", current->data, current->count);
        current = current->next;
    }
}

