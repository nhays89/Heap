//Author : Nicholas Hays

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mallok.h"

//run tests on mallok

int main() {

    //test 1
    printf("testing test 1...\n");
    printf("creating 1000 byte pool\n");

    create_pool(1000);

    printf("malloc'ing 10 byte chunks\n");
    int count = 0;
    while (my_malloc(10) != NULL) {
        count++;
    }
    printf("total number of 10 byte chunks is: %d\n", count);
    free_pool();
    printf("free'ing pool\n");
    //test 2

    printf("running test 2....\n");
    printf("creating pool for test 2 1000 byte block \n");
    create_pool(1000);
    int i;
    printf("malloc'ing 5 200 byte blocks and free'ing them 5 times \n");
    for (i = 0; i < 5; i++) {
        printf("test %d\n", i);
        printf("malloc'ing 5 200 byte blocks\n");
        void * p1 = (char *) my_malloc(200);
        void * p2 = (char *) my_malloc(200);
        void *p3 = (char *) my_malloc(200);
        void *p4 = (char *) my_malloc(200);
        void *p5 = (char *) my_malloc(200);
        printf("free'ing 5 200 byte blocks\n", i);
        my_free(p2);
        my_free(p3);
        my_free(p4);
        my_free(p1);
        my_free(p5);

    }
    printf("free'ing pool on test 2\n");
    free_pool();

    //test 3
    printf("running test 3...\n");
    printf("creating 1000 byte pool\n");
    create_pool(1000);
    printf("malloc'ing 5 200 block blocks to 5 pointers\n");
    char * b1 = (char *) my_malloc(200);
    char * b2 = (char *) my_malloc(200);
    char *b3 = (char *) my_malloc(200);
    char *b4 = (char *) my_malloc(200);
    char *b5 = (char *) my_malloc(200);
    printf("freeing middle block of 200 bytes \n");
    my_free(b3);
    printf("malloc'ing 210 byte block... test should fail \n");
    char *large = (char *) my_malloc(210);
    printf("value of 210 byte block is: %s\n", large);
    printf("mallocing 150 byte block...test should pass\n");
    char *onefiftyy = (char *) my_malloc(150);
    printf("testing 60 byte block....test should fail \n");
    char *sixty = (char *) my_malloc(60);
    printf("value of 60 byte block is: %s\n", sixty);
    printf("mallocing 50 byte block...test should pass \n");
    char *fifty = (char *) my_malloc(50);
    printf("freeing pool for test 3\n");
    free_pool();

    //test 4
    printf("running test 4...\n");
    printf("creating pool\n");
    create_pool(1000);
    printf("malloc'ing 5 200 byte blocks\n");
    char * d1 = (char *) my_malloc(200);
    char * d2 = (char *) my_malloc(200);
    char *d3 = (char *) my_malloc(200);
    char *d4 = (char *) my_malloc(200);
    char *d5 = (char *) my_malloc(200);
    printf(
            "filling up each block with letters A B C D E for block 1 2 3 4 5\n");
    for (i = 0; i < 200; i++) {
        *(d1 + i) = 'A';
        *(d2 + i) = 'B';
        *(d3 + i) = 'C';
        *(d4 + i) = 'D';
        *(d5 + i) = 'E';
    }
    i = 0;
    while (d1 != NULL && *(d1 + i) == 'A') {
        i++;
    }
    printf("the number of A's are : %d\n", i);
    i = 0;
    while (d2 != NULL && *(d2 + i) == 'B') {
        i++;
    }
    printf("the number of B's are : %d\n", i);
    i = 0;
    while (d3 != NULL && *(d3 + i) == 'C') {
        i++;
    }
    printf("the number of C's are : %d\n", i);
    i = 0;
    while (d4 != NULL && *(d4 + i) == 'D') {
        i++;
    }
    printf("the number of D's are : %d\n", i);
    i = 0;
    while (d5 != NULL && *(d5 + i) == 'E') {
        i++;
    }
    printf("the number of E's are : %d\n", i);
    printf("free'ing pool...\n");
    free_pool();

    //test 5
    printf("running test 5...\n");
    printf("creating pool...\n");
    create_pool(1000);

    printf("malloc'ing 1000 bytes\n");
    void * thousand = my_malloc(1000);
    printf("free'ing 1000 bytes\n");
    my_free(thousand);

    printf("mallo'ing 4 250 byte blocks\n");
    void *f0 = my_malloc(250);
    void *f1 = my_malloc(250);
    void *f2 = my_malloc(250);
    void *f3 = my_malloc(250);
    printf("free'ing 4 250 byte blocks\n");
    my_free(f0);
    my_free(f1);
    my_free(f2);
    my_free(f3);
    printf("malloc'ing 10 blocks of 100 bytes\n");
    void *t0 = my_malloc(100);
    void *t1 = my_malloc(100);
    void *t2 = my_malloc(100);
    void *t3 = my_malloc(100);
    void *t4 = my_malloc(100);
    void *t5 = my_malloc(100);
    void *t6 = my_malloc(100);
    void *t7 = my_malloc(100);
    void *t8 = my_malloc(100);
    void *t9 = my_malloc(100);
    printf("free'ing 10 blocks of 100 bytes\n");
    my_free(t0);
    my_free(t1);
    my_free(t2);
    my_free(t3);
    my_free(t4);
    my_free(t5);
    my_free(t6);
    my_free(t7);
    my_free(t8);
    my_free(t9);
    printf("free'ing pool\n");
    free_pool();

    //extra tests
    printf("running extra tests\n");
    printf("creating pool...\n");
    create_pool(1000);
    printf("malloc'ing pointer to location not in heap\n");
    void * notInHeap = malloc(sizeof(char));
    printf("using my_free to free pointer...should fail silently\n");
    my_free(notInHeap);
    printf("free'ing pool\n");
    free_pool();
    printf("tests over...");
    return 0;
}
