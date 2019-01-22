#include <bst_head.h>

#define MAX_STACK_SIZE 100

struct data {
	BST *data_bst;
};

/*struct stack_operation {
	void (*destroy_stack)();
	int (*push)(struct data);
	int (*pop)(struct data *);
	void (*print_stack)();
	int (*free_space)();
};
*/

struct stack_user {
	size_t stack_size;
	int stack_idx;
	struct data *data;
	//struct stack_operation sop;
};

struct queue_user {
        size_t queue_size;
        int front;
        int rear;
        struct data *data;
        //struct queue_operation sop;

};

int create_queue(struct queue_user *);
void destroy_stack(struct stack_user *);
int push(struct stack_user *, struct data);
int pop(struct stack_user *, struct data *);
void print_stack(struct stack_user *);
int stack_free_space(struct stack_user);
int q_insert(struct queue_user *q, struct data data);
int q_del(struct queue_user *q, struct data *q_read);
void destroy_q(struct queue_user *q);
int q_free_space(struct queue_user q);
int bst_no_of_leavenode(BST *root);
int bst_no_of_fullnode(BST *root);

int create_stack(struct stack_user *);
