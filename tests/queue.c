/* SPDX-License-Identifier: MIT License */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <assert.h>

#include "trifles.h"

void queue_destroy_fn(void *data)
{
	free(data);
}

void init_tests(void)
{
	unsigned int flags = 0;
	struct lt_queue *queue;

	queue = lt_queue_create(flags);
	assert(queue != NULL);

	lt_queue_destroy(queue, queue_destroy_fn);
}

int main(void)
{

	init_tests();

	return EXIT_SUCCESS;


}
