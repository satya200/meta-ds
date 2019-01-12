#include <bst_head.h>

#define MAX_STACK_SIZE 100

struct data {
	BST *data_bst;
};

struct stack_operation {
	void (*destroy_stack)();
	int (*push)(struct data);
	int (*pop)(struct data *);
	void (*print_stack)();
	int (*free_space)();
};


struct stack_user {
	size_t stack_size;
	struct data data;
	struct stack_operation sop;
};

int create_stack(struct stack_user *);
