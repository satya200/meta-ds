/*
* AUTHOR: Satya Sundar Sahu
* mail id:- tinkusahu.com@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data
{
	int data;
};

typedef struct double_ll
{
	struct Data data;
	struct double_ll *next;
	struct double_ll *prev;
}double_ll_t;

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

int dll_insert_last(double_ll_t **, struct Data);
int dll_print_list(double_ll_t *, int);
int dll_traverse_list(double_ll_t *, int, double_ll_t **);
int dll_insert_fast(double_ll_t **, struct Data);
void dll_exist_list(double_ll_t **);
int dll_insert_middle(double_ll_t *, int, struct Data);
int dll_del_list(double_ll_t **head, int node_idx, int pos);
int dll_find_node_from_last(double_ll_t *temp, int node, double_ll_t **temp_last);
int dll_swap_adjusent_node(double_ll_t **, int);
int dll_find_middle_node(double_ll_t *, double_ll_t **);
int dll_check_loop(double_ll_t *, double_ll_t **);
