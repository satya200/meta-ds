/*
* AUTHOR: Satya Sundar Sahu
* mail id:- tinkusahu.com@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Data
{
	int data;
};

typedef struct single_ll
{
	struct Data data;
	struct single_ll *next;
}single_ll_t;

#define   DBG_PRINT(fmt, args...) \
        ((NULL != log_fp) ? fprintf(log_fp,"Debug: " fmt, ##args) : (void) 0 )

#define   ERR_PRINT(fmt, args...) \
        ((NULL != log_fp) ? fprintf(log_fp,"ERROR: " fmt, ##args) : (void) 0 )

#define   DATA_PRINT(fmt, args...) \
        ((NULL != log_fp) ? fprintf(log_fp,"" fmt, ##args) : (void) 0 )

typedef enum error_t {
	INVALID_PARAM = -3,
	ERR_FUNC,
	NULL_POINTER, 
}err_t;

int insert_last(single_ll_t **, struct Data);
int print_list(single_ll_t *);
int traverse_list(single_ll_t *, int, single_ll_t **);
int insert_fast(single_ll_t **, struct Data);
void exist_list(single_ll_t **);
int insert_middle(single_ll_t *, int, struct Data);
int del_list(single_ll_t **head, int node_idx, int pos);
void exist_list(single_ll_t **);
int find_node_from_last(single_ll_t *temp, int node, single_ll_t **temp_last);
int swap_adjusent_node(single_ll_t **, int);
int find_middle_node(single_ll_t *, single_ll_t **);
int create_loop(single_ll_t *head, int, int);
int check_loop(single_ll_t *, single_ll_t **);
int find_len(single_ll_t *);
int reverse_list(single_ll_t **);
int sl_check_palindrome(single_ll_t *head);
int swap_node(single_ll_t **head, int pos1, int pos2);
int findLargest_secondLargest(single_ll_t *head);
