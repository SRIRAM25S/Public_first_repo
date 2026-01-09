#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void step1_understanding_node(){
    Node head; // creating one node manually
    printf("Address of head %p\n", (void *)&head );
    head.data = 1;
    head.next = NULL;
    printf("Value of 1st node %d and %p\n", head.data,(void *)head.next);
}

void step2_creating_node_with_malloc(){
    Node *node1 = malloc(sizeof(Node)); //allocate memory for the node in heap
    
    printf("We used malloc to create a node on heap:\n");
    printf("  node1 pointer value:  %p (this is the address)\n", (void*)node1);
    printf("  Size allocated:       %zu bytes\n", sizeof(Node));
    printf("\n");

    node1->data = 2;
    node1->next = NULL;

    printf("After filling the node \n");
    printf("node1 --> data: %d\n", node1->data);
    printf("node1 --> next: %p\n", (void *)node1->next);
    printf("\n");


    free(node1); //free the allocated memory
    printf("After freeing the node1 memory\n"); 
}


int main(){
    
    step1_understanding_node();
    step2_creating_node_with_malloc();

    return 0;
}