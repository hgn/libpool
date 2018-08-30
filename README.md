# libtrifles

A utility libray for C with focus on

- simplicity
- low overhead
- ...

Licence: MIT


## List

```
struct lt_list;

struct lt_list *lt_list_create();
lt_list_destroy(struct lt_list *);
lt_list_add(struct lt_list, void *);
```


## Hash Table

```
struct lt_hashtable;

struct lt_hashtable *lt_hashtable_create(LT_HASHTABLE_KEY_STRING);
lt_hashtable_destroy(struct lt_hashtable *);
lt_hashtable_add(struct lt_hashtable, const char *key, void *data);
```

## RB Tree

```
struct lt_rbtree;

lt_rbtree_create()
lt_rbtree_destroy()
lt_rbtree_add()
```

## Buffer

```
struct lt_buf;

lt_buf_create()
lt_buf_destroy()
lt_buf_add()
```
