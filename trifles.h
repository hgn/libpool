/* SPDX-License-Identifier: MIT License */

#ifndef LIBTRIFLES_H
#define LIBTRIFLES_H

#include <inttypes.h>
#include <stdbool.h>


struct lt_queue_entry {
	struct l_queue_entry *next;
	void *data;
};

/* forward declaration, opaque object for queue users */
struct lt_queue;

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
struct lt_queue *lt_queue_create(unsigned int flags);

int lt_queue_destroy(struct lt_queue *queue, void (*destroy_fn)(void *data));



#endif /* LIBTRIFLES_H */
