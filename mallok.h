//Author : Nicholas A. Hays

#ifndef MALLOK_H
#define MALLOK_H
//creates pool for heap and list.
void create_pool(int size);
//malloc's blocks from heap.
void *my_malloc(int size);
//free's a block back to heap.
void my_free(void *block);
//free's all blocks and heap.
void free_pool();

#endif
