/*
AUTHOR: Satya Sundar Sahu
DATE:   27th-Nov-2018
Description:
	This file contains stack implementation using array
*/

#include <mystack.h>

struct data *stack_ptr = NULL; //stack pointer
size_t stack_max_size = 0;
int stack_idx = -1;

/* Below Function will create stack 
*  stack_size:- max size of stack
*/

/*int create_stack(struct stack_user *stack_ptr_usr)
{
	if (stack_ptr_usr == NULL) {
		printf("NULL in parameter\n");
		return -1;
	}
	stack_ptr = (struct data *)malloc((stack_ptr_user->stack_size) * sizeof(struct data));
	if (stack_ptr == NULL) {
		printf("NULL\n");
		return -1;
	}
	stack_max_size = stack_ptr_usr->stack_size;
	stack_ptr_usr->sop.push = push;
	stack_ptr_usr->sop.destroy_stack = destory_stack;
	stack_ptr_usr->sop.pop = pop;
	stack_ptr_usr->sop.print_stack = print_stack;
	stack_ptr_usr->sop.free_space = free_space;	

	return 0;
}*/

/* This Function will destroy stack */

void destroy_stack()
{
	if (stack_ptr != NULL) {
		free(stack_ptr);
		stack_ptr = NULL;
	} else {
		printf("Stack is empty. stack pointer is NULL");
	}
}

/* Inserting data in stack */

int push(struct data data)
{
	int idx;

	if (stack_idx == stack_max_size - 1) {
		printf("OVERFLOW\n");
		return 1;
	} else {
		stack_idx++;
		idx = stack_idx;
		//stack_ptr[idx] = data;
		memcpy(&stack_ptr[idx], &data, sizeof(data));
	}	
	return 0;
}

/* Deleting Data inside Stack */
int pop()
{
	int idx = stack_idx;

	if (idx == -1) {
		printf("UNDER-FLOW\n");
		return 1;
	} else {
		//stack_ptr[idx] = 0;
		memset(&stack_ptr[idx], '\0', sizeof(struct data));
		stack_idx--;
	}
	return 0;
}

void print_stack()
{
	int idx = stack_max_size;
	for (; idx > 0; idx--) {
		printf("%d ",stack_ptr[idx].data);
	}
	printf("\n");
}

int free_space()
{
	printf("%lu:%d\n",stack_max_size, stack_idx);
	return (stack_max_size - stack_idx - 1);
}

int create_stack(struct stack_user *stack_ptr_usr)
{
	if (stack_ptr_usr == NULL) {
		printf("NULL in parameter\n");
		return -1;
	}
	stack_ptr = (struct data *)malloc((stack_ptr_usr->stack_size) * sizeof(struct data));
	if (stack_ptr == NULL) {
		printf("NULL\n");
		return -1;
	}
	stack_max_size = stack_ptr_usr->stack_size;
	stack_ptr_usr->sop.push = push;
	stack_ptr_usr->sop.destroy_stack = destroy_stack;
	stack_ptr_usr->sop.pop = pop;
	stack_ptr_usr->sop.print_stack = print_stack;
	stack_ptr_usr->sop.free_space = free_space;	

	return 0;
}
