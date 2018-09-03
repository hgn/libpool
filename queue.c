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


struct lt_queue {
	struct l_queue_entry *head;
	struct l_queue_entry *tail;
	uint64_t entries;
};


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


int lt_queue_destroy(struct lt_queue *queue, void (*destroy_fn)(void *data))
{
	if (!queue || !destroy_fn)
		return -EINVAL;

	//l_queue_clear(queue, destroy);
	free(queue);

	return 0;
}
