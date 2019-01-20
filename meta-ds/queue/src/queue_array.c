/*
AUTHOR: Satya Sundar Sahu
DATE:   13th-Jan-2019
Description:
	This file contains Queue implementation using array
*/

#include <myqueue.h>


/* This Function will destroy Queue */
void destroy_q(struct queue_user *q)
{
	if (q == NULL) {
		printf("NULL Pointer in destroy_q()\n");
		return;
	}
	if (q->data != NULL) {
		free(q->data);
		q->data = NULL;
	} else {
		printf("Queue is empty. Queue data pointer is NULL");
	}
}

int is_full_queue(struct queue_user *q)
{
	if (q == NULL) {
		printf("NULL Pointer in is_full_queue()\n");
		return -1;
	}
	return (((q->rear + 1) % (q->queue_size)) == q->front);
}

/* Inserting data in Queue */
int q_insert(struct queue_user *q, struct data data)
{
	int idx;
	if (q == NULL) {
		printf("NULL Pointer\n");
		return -1;
	}
	if (is_full_queue(q)) {
		printf("OVERFLOW\n");
		return 1;
	} else {
		q->rear = (q->rear+1) % (q->queue_size);
		idx = q->rear;
		memcpy(&(q->data[idx]), &data, sizeof(data));
		if (q->front == -1) {
			q->front = q->rear;
		}
	}	
	return 0;
}

/* Checking Queue is Empty or not */
int is_empty_queue(struct queue_user *q)
{
	if (q == NULL) {
		printf("NULL Pointer is_empty_queue()\n");
		return -1;
	}
	if (q->front == -1) {
		return 1;
	} else {
		return 0;
	}
}

/* Deleting Data inside Queue */
int q_del(struct queue_user *q, struct data *q_read)
{
	int idx;

	if (q == NULL && q_read == NULL) {
		printf("NULL pointer q_del\n");
		return -1;
	}

	if (is_empty_queue(q)) {
		printf("Queue is Empty\n");
		return 1;
	} else {
		idx = q->front;
		memcpy(q_read, &(q->data[idx]), sizeof(struct data));
		if (q->front == q->rear) {
			q->front = q->rear = -1;
		} else {
			q->front = (q->front+1) % (q->queue_size);
		}
	}
	return 0;
}
#if 0
void q_print(struct queue_user *q, struct data *q_read)
{
	int idx;
	int i;
	if (q == NULL && q_read == NULL) {
		printf("NULL pointer q_print\n");
		return -1;
	}
	printf("	********* QUEUE DATA ****************\n");
	if (idx < 0) {
		printf("	Queue Is Empty\n");
	} else {
		printf("	");
		for (i = 0; i <= idx; i++) {
			printf("%d | ",stack_ptr[i].data);
		}
	}
	printf("\n	********* Queue Data End *************\n");
}
#endif

int q_free_space(struct queue_user q)
{
	printf("%lu:%d:%d\n",q.queue_size, q.front, q.rear);
	return (q.queue_size - (q.rear - q.front) - 1);
}

int create_queue(struct queue_user *q_ptr_usr)
{
	if (q_ptr_usr == NULL) {
		printf("NULL in parameter\n");
		return -1;
	}
	q_ptr_usr->data = (struct data *)malloc((q_ptr_usr->queue_size) * sizeof(struct data));
	if (q_ptr_usr == NULL) {
		printf("NULL\n");
		return -1;
	}
	q_ptr_usr->front = -1;
	q_ptr_usr->rear = -1;
	/* Assign stack max size */
	//stack_max_size = stack_ptr_usr->stack_size;

	/*q_ptr_usr->sop.q_insert = q_insert;
	q_ptr_usr->sop.destroy_q = destroy_q;
	q_ptr_usr->sop.q_del = q_del;
	q_ptr_usr->sop.q_print = q_print;
	q_ptr_usr->sop.q_free_space = q_free_space;*/

	return 0;
}
