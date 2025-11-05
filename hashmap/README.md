

## Basic Hashmap


### Please read hashmap.h for more information about functions.



```
    // The hashmap size is rounded up to next power of two.
    const size_t hashmap_size = 200;

    struct hashmap_t map = create_hashmap(hashmap_size);


    // ...


    free_hashmap(&map);
```



## Inserting elements.

```c
    struct document_t A = (struct document_t) { 3.14, "(A) Hello hashmap!" };
    struct document_t B = (struct document_t) { 1.23, "(B) This should be another document." };
    struct document_t C = (struct document_t) { 6.28, "(C) Random document" };
    struct document_t D = (struct document_t) { 2.85, "(D) May used to replace something..." };


    // The key/id can be in range of -INT32_MAX to INT32_MAX
    // But they must be unique.
    const int document_A_ID = 1;
    const int document_B_ID = 2;
    const int document_C_ID = 3;

    if(!hashmap_add(&map, document_A_ID, &A)) {
        // Key already exists.
    }
    if(!hashmap_add(&map, document_B_ID, &B)) {
        // Key already exists.
    }
    if(!hashmap_add(&map, document_C_ID, &C)) {
        // Key already exists.
    }

    // ============ REPLACING ELEMENTS ============

    /*
    if(!hashmap_put(&map, document_A_ID, &C)) {
        fprintf(stderr, "Failed to replace document.\n");
    }
    */


    /*
    // ============ DELETING ELEMENTS =============
    if(hashmap_del(&map, document_E_ID)) {
        printf("Document was succesfully deleted from hashmap.\n");
    }
    */


    // ============ READING ELEMENTS ==============


    struct hashmap_pair_t* pair = NULL;

    pair = hashmap_get(&map, document_A_ID);
    if(pair) {
        struct document_t* document = (struct document_t*)pair->ptr;
        printf("(key = %i): %0.2f, %s\n", document_A_ID, document->num, document->name);
    }

    pair = hashmap_get(&map, document_B_ID);
    if(pair) {
        struct document_t* document = (struct document_t*)pair->ptr;
        printf("(key = %i): %0.2f, %s\n", document_B_ID, document->num, document->name);
    }


    // ============ INTERATING THROUGH MAP ELEMENTS ============

    struct hashmap_bucket_t* bucket = map.buckets_link_tail;
    while(bucket) {


        struct hashmap_pair_t* pair = &bucket->pairs[0];
        if(pair->ptr) {
            printf("%p (num_pairs = %li) %s\n",
                    bucket, bucket->num_pairs, ((struct document_t*)pair->ptr)->name);
        }
        else {
            printf("%p (num_pairs = %li) \033[31m(Linked list not correctly handled)\033[0m\n",
                    bucket, bucket->num_pairs);
        }

        bucket = bucket->next;
    }

```




