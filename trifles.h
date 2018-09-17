/* SPDX-License-Identifier: MIT License */

#ifndef LIBTRIFLES_H
#define LIBTRIFLES_H

#include <inttypes.h>
#include <stdbool.h>

#ifdef __GNUC__
#  define LIB_PUBLIC __attribute__ ((visibility ("default")))
#  define LIB_LOCAL  __attribute__ ((visibility ("hidden")))
#else
#  warning "not compiling with GCC, please add your compiler"
#  define LIB_PUBLIC
#  define LIB_LOCAL
#endif

struct lt_queue_entry {
	struct lt_queue_entry *next;
	void *data;
};

struct lt_queue {
	struct lt_queue_entry *head;
	struct lt_queue_entry *tail;
	uint64_t entries;
};


/**
 * ev_entries - return number of active event entries
 * @ev: pointer instance of ev object
 *
 * This function returns the number of active event entries, like timers,
 * descriptors or signals. With each ev_event_add the counter is incremented
 * and vice versa for delete operations.
 *
 * This function cannot fail.
 */
LIB_PUBLIC struct lt_queue *lt_queue_create(unsigned int flags);

LIB_PUBLIC int lt_queue_destroy(struct lt_queue *queue, void (*destroy_fn)(void *data));


LIB_PUBLIC int lt_queue_add(struct lt_queue *queue, void *data);
#define lt_queue_push_tail lt_queue_add

LIB_PUBLIC int lt_queue_flush(struct lt_queue *queue, void (*destroy_fn)(void *data));

LIB_PUBLIC uint64_t lt_queue_entries(struct lt_queue *queue);

LIB_PUBLIC void *lt_queue_peek_head(struct lt_queue *queue);
LIB_PUBLIC void *lt_queue_peek_tail(struct lt_queue *queue);

LIB_PUBLIC void *lt_queue_pop_head(struct lt_queue *queue);



#endif /* LIBTRIFLES_H */
