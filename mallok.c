/*
 * Author: Nicholas A. Hays
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    void *addr;
    int size;
    int isFree;
    struct node *next;
} Node, List;

static void *heap;
static List *list;

Node * get_node(int);
void free_node(void *);
void collase(Node *);
/*
 * The heap object.
 * 
 * @param size - the size of the heap. 
 */
void create_pool(int size) {
    if (heap) {
        return;
    }
    heap = (void *) malloc(size);
    list = malloc(sizeof(Node));
    list->addr = heap;
    list->isFree = 1;
    list->next = NULL;
    list->size = size;

}

/*
 * How many bytes needed for user request.
 * @param size - the block size to return from the heap.
 */
void *my_malloc(int size) {
    if (heap == NULL) {
        return NULL;
    }
    Node *n = get_node(size);
    if (n != NULL) {
        return n->addr;
    } else {
        return NULL;
    }
}

/*
 * Free the block in the heap.
 *
 * @param block - the block to free.
 */
void my_free(void *block) {
    if (block == NULL || heap == NULL) {
        return;
    }
    free_node(block);
}

/*
 * Free the heap.
 *
 */
void free_pool() {
    if (heap == NULL) {
        return;
    }
    Node *scan = list;
    Node *temp = scan;
    while (scan) {
        temp = scan->next;
        free(scan);
        scan = temp;
    }
    heap = NULL;
    list = NULL;
    free(heap);
    free(list);

}

/*
 * Private function to retrieve a node from the heap if space is available.
 *
 * @param size - the size of a block to search for.
 */
Node * get_node(int size) {

    Node *scan;
    scan = list;

    while (scan != NULL && !(scan->isFree == 1 && scan->size >= size)) {
        scan = scan->next;
    }
    if (scan != NULL) {
        int diff = scan->size - size;
        if (diff == 0) {
            scan->isFree = 0;
            return scan;
        } else {
            Node *newNode = malloc(sizeof(Node));
            newNode->addr = scan->addr + size;
            newNode->size = diff;
            newNode->next = scan->next;
            newNode->isFree = 1;
            scan->next = newNode;
            scan->size = size;
            scan->isFree = 0;
            scan->next = newNode;
            return scan;

        }
    } else {
        return NULL;
    }
}

/*
 * private function that frees and collases'.
 * @param addr - the address of the node to free.
 */
void free_node(void * addr) {
    Node *scan;
    scan = list;

    while (scan != NULL && !(scan->isFree == 0 && scan->addr == addr)) {
        scan = scan->next;
    }
    if (scan != NULL) {
        scan->isFree = 1;
        collase((Node *) list);
    }
}

/*
 * Combines adjacent free blocks to one.
 * Single pass.
 * @param - the node to start from.
 */
void collase(Node *node) {
    Node *scan;
    scan = node;

    while (scan != NULL && scan->next != NULL
            && !(scan->isFree == 1 && scan->next->isFree == 1)) {
        scan = scan->next;
    }
    if (scan != NULL && scan->next != NULL) {
        scan->size = scan->size + scan->next->size;
        Node *rm = scan->next;
        scan->next = scan->next->next;

        free(rm);
        collase(scan);
    }
}

