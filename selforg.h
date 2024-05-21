#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 99

enum err_cond {
    MALLOC_FAILURE = 1,
    INCORRECT_USAGE,
    FILE_OPEN_FAILURE,
    COUNT_LIMIT
};

typedef struct Node {
    struct Node *prev;
    int data;
    int count;
    struct Node *next;
} Node;

Node *createNode(int x);
void insertatbegin(Node **head, int x);
Node *find(Node **head, int x);
void move_to_front(Node **head, Node *node);
void write_to_file(Node *head, FILE *output_file);