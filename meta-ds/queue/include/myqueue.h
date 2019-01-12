#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

struct data {
	int data;
};

/*struct queue_operation {
	void (*destroy_q)();
	int (*q_insert)(struct data);
	int (*q_del)(struct data *);
	void (*q_print)();
	int (*q_free_space)();
};
*/

struct queue_user {
	size_t queue_size;
	int front;
	int rear;
	struct data *data;
	//struct queue_operation sop;
	
};

int create_queue(struct queue_user *);
int q_insert(struct queue_user *q, struct data data);
int q_del(struct queue_user *q, struct data *q_read);
