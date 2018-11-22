#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct double_ll
{
	int data;
	struct double_ll *next;
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

int insert_last(double_ll_t **, int);
int print_list(double_ll_t *, int);
int traverse_list(double_ll_t *, int, double_ll_t **);
int insert_fast(double_ll_t **, int);
void exist_list(double_ll_t **);
int insert_middle(double_ll_t *, int, int);
int del_list(double_ll_t **head, int node_idx, int pos);
void exist_list(double_ll_t **);
int find_node_from_last(double_ll_t *temp, int node, double_ll_t **temp_last);
int swap_adjusent_node(double_ll_t **, int);
int find_middle_node(double_ll_t *, double_ll_t **);
