# libtrifles

A utility libray for C with focus on

- simplicity
- low overhead
- ...

Licence: MIT

## Basics

### Return Values

Return values are harmonized: for pointer (object) return the object itself is
returned (success) or NULL is returned in the case of an error. All remaining
functions return 0 in the case of success or an negative return value to indicate
the particular error like (ENOMEM if allocation failed or EINVAL for wrong
parameter usage, etc)


## Queue

The queue provides no iteratior in the form of
`queue_iterate(queue, (void)(*callback)(void *data))` because this will result
in massive function call overhead for larger datasets. Rather the loop should
be open coded with a typical (and also not complex) loop. Sidenote: hashtables
amd rbtress on the other hand requires more complex iterators, so a callback
based interator is provided.

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

## Managed Strings - String Buffer

C native strings are not managed strings of the style natively provided in more
modern languages such as Go, Swift or D. String handling is more erroneous and
unsafe compared to other programming languages and the cause of many security
relevant bugs.

libtrifles buffer management try to simplify string manipulation by providing
higher level functionality and abstract away memory management.

```
struct lt_buf;

lt_buf_create()
lt_buf_destroy()
lt_buf_add()
```

# Development

## Coding Style

Linux Kernel Coding Guidelines apply

## Merge Requests
