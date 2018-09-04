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

void init(void)
{
	unsigned int flags = 0;
	struct lt_queue *queue;

	queue = lt_queue_create(flags);
	assert(queue != NULL);

	lt_queue_destroy(queue, queue_destroy_fn);
}

void add(void)
{
	int ret;
	void *data;
	unsigned int flags = 0;
	struct lt_queue *queue;

	queue = lt_queue_create(flags);
	assert(queue != NULL);

	data = malloc(1);
	ret = lt_queue_add(queue, data);
	assert(ret == 0);

	ret = lt_queue_add(queue, NULL);
	assert(ret != 0);

	ret = lt_queue_add(NULL, NULL);
	assert(ret != 0);

	data = malloc(1);
	ret = lt_queue_add(NULL, data);
	assert(ret != 0);
	free(data);

	ret = lt_queue_destroy(queue, queue_destroy_fn);
	assert(ret == 0);
}


void destroy(void)
{
	int ret;
	unsigned int flags = 0;
	struct lt_queue *queue;

	queue = lt_queue_create(flags);
	assert(queue != NULL);

	ret = lt_queue_destroy(queue, NULL);
	assert(ret == 0);
}


void flush(void)
{
	int ret;
	void *data;
	unsigned int flags = 0;
	struct lt_queue *queue;

	queue = lt_queue_create(flags);
	assert(queue != NULL);

	ret = lt_queue_flush(queue, NULL);
	assert(ret == 0);

	ret = lt_queue_destroy(queue, NULL);
	assert(ret == 0);

	// next test
	queue = lt_queue_create(flags);
	assert(queue != NULL);

	data = malloc(1);
	ret = lt_queue_add(queue, data);
	assert(ret == 0);

	data = malloc(1);
	ret = lt_queue_add(queue, data);
	assert(ret == 0);

	ret = lt_queue_flush(queue, queue_destroy_fn);
	assert(ret == 0);

	ret = lt_queue_destroy(queue, queue_destroy_fn);
	assert(ret == 0);
}

int main(void)
{

	init();
	destroy();
	add();
	flush();

	return EXIT_SUCCESS;


}
