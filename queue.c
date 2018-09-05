/* SPDX-License-Identifier: The Unlicense */

#include "trifles.h"

#define __STDC_LIMIT_MACROS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>

#undef __always_inline
#if __GNUC_PREREQ (3,2)
# define LT_INLINE __inline __attribute__ ((__always_inline__))
#else
# define LT_INLINE __inline
#endif

#if !defined(likely) && !defined(unlikely)
# define likely(x)   __builtin_expect(!!(x), 1)
# define unlikely(x) __builtin_expect(!!(x), 0)
#endif

#if !defined(ARRAY_SIZE)
# define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#endif


struct lt_queue *lt_queue_create(unsigned int flags)
{
	struct lt_queue *queue;

	if (flags != 0) {
		/* no flags argument accepted yet,
		 * check this and return error if */
		return NULL;
	}

	queue = malloc(sizeof(*queue));
	if (!queue)
		return NULL;

	queue->head = NULL;
	queue->tail = NULL;
	queue->entries = 0;

	return queue;
}

uint64_t lt_queue_entries(struct lt_queue *queue)
{
	if (!queue)
		return 0;

	return queue->entries;
}


int lt_queue_destroy(struct lt_queue *queue, void (*destroy_fn)(void *data))
{
	if (!queue)
		return -EINVAL;

	// lt_queue_flush() cannot fail, see prev queue check
	lt_queue_flush(queue, destroy_fn);
	free(queue);

	return 0;
}


int lt_queue_flush(struct lt_queue *queue, void (*destroy_fn)(void *data))
{
	struct lt_queue_entry *entry, *tmp;

	if (!queue)
		return -EINVAL;

	entry = queue->head;
	while (entry) {
		if (destroy_fn)
			destroy_fn(entry->data);
		tmp = entry;
		entry = entry->next;
		free(tmp);
	}

	queue->entries = 0;
	queue->head = NULL;
	queue->tail = NULL;

	return 0;
}


int lt_queue_add(struct lt_queue *queue, void *data)
{
	struct lt_queue_entry *entry;

	if (!queue || !data)
		return -EINVAL;

	entry = malloc(sizeof(*entry));
	if (!entry)
		return -ENOBUFS;
	entry->next = NULL;
	entry->data = data;

	if (!queue->head) {
		// first element in queue
		queue->head = entry;
	}

	if (queue->tail) {
		// if at least one entry in queue,
		// reorder and previous tail will
		// become prev-prev now
		queue->tail->next = entry;
	}

	// add entry at the end/tail of queue
	queue->tail = entry;

	queue->entries++;

	return 0;
}


void *lt_queue_head(struct lt_queue *q)
{
	if (!q || !q->head)
		return NULL;

	// data must be !NULL, see add() - no check required
	return q->head->data;
}


void *lt_queue_tail(struct lt_queue *q)
{
	if (!q || !q->tail)
		return NULL;

	// data must be !NULL, see add() - no check required
	return q->tail->data;
}
