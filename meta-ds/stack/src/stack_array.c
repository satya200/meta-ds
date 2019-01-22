/*
AUTHOR: Satya Sundar Sahu
DATE:   27th-Nov-2018
Description:
	This file contains stack implementation using array
*/

#include <mystack.h>

/* stack pointer */
//struct data *stack_ptr = NULL;
//size_t stack_max_size = 0;
//int stack_idx = -1;

/* Below Function will create stack 
*  stack_size:- max size of stack
*/

/* This Function will destroy stack */

void destroy_stack(struct stack_user *stack_ptr)
{
	if (stack_ptr != NULL) {
		free(stack_ptr->data);
		stack_ptr->data = NULL;
	} else {
		printf("Stack is empty. stack pointer is NULL");
	}
}

/* Inserting data in stack */

int push(struct stack_user *stack, struct data data)
{
	int idx;

	if (stack == NULL) {
		printf("Null Pointer\n");
		return -1;
	}
	//if (stack_idx == stack_max_size - 1) {
	if (stack->stack_idx == stack->stack_size - 1) {
		printf("OVERFLOW\n");
		return 1;
	} else {
		//stack_idx++;
		stack->stack_idx++;
		idx = stack->stack_idx;
		//stack_ptr[idx] = data;
		//memcpy(&stack_ptr[idx], &data, sizeof(data));
		memcpy(&(stack->data[idx]), &data, sizeof(data));
	}	
	return 0;
}

/* Deleting Data inside Stack */
int pop(struct stack_user *stack, struct data *stack_read)
{
	int idx;

	if (stack_read == NULL || stack == NULL) {
		printf("NULL pointer\n");
		return -1;
	}
	idx = stack->stack_idx;

	if (idx == -1) {
		printf("UNDER-FLOW\n");
		return 1;
	} else {
		//memcpy(stack_read, &stack_ptr[idx], sizeof(struct data));
		//memset(&stack_ptr[idx], '\0', sizeof(struct data));
		memcpy(stack_read, &(stack->data[idx]), sizeof(struct data));
		memset(&(stack->data[idx]), '\0', sizeof(struct data));
		stack->stack_idx = stack->stack_idx - 1;
	}
	return 0;
}

void print_stack(struct stack_user *stack)
{
	if (stack == NULL) {
		printf("Null Pointer\n");
		return;
	}
	//int idx = stack_idx;
	int idx = stack->stack_idx;
	int i;
	printf("	********* STACK DATA ****************\n");
	if (idx < 0) {
		printf("	STACK IS EMPTY\n");
	} else {
		printf("	");
		for (i = 0; i <= idx; i++) {
			//printf("%d | ",stack_ptr[i].data);
			printf("%d | ",stack->data[i].data);
		}
	}
	printf("\n	********* STACK DATA END *************\n");
}

int stack_free_space(struct stack_user stack)
{
	//printf("%lu:%d\n",stack_max_size, stack_idx);
	printf("%lu:%d\n",stack.stack_size, stack.stack_idx);
	//return (stack_max_size - stack_idx - 1);
	return (stack.stack_size - stack.stack_idx - 1);
}

int create_stack(struct stack_user *stack_ptr_usr)
{
	if (stack_ptr_usr == NULL) {
		printf("NULL in parameter\n");
		return -1;
	}
	//stack_ptr = (struct data *)malloc((stack_ptr_usr->stack_size) * sizeof(struct data));
	stack_ptr_usr->data = (struct data *)malloc((stack_ptr_usr->stack_size) * sizeof(struct data));
	if (stack_ptr_usr->data == NULL) {
		printf("NULL\n");
		return -1;
	}
	/* Assign stack max size */
	//stack_max_size = stack_ptr_usr->stack_size;
	stack_ptr_usr->stack_idx = -1;

	/*stack_ptr_usr->sop.push = push;
	stack_ptr_usr->sop.destroy_stack = destroy_stack;
	stack_ptr_usr->sop.pop = pop;
	stack_ptr_usr->sop.print_stack = print_stack;
	stack_ptr_usr->sop.free_space = stack_free_space;	
	*/
	return 0;
}
