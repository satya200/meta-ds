#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct single_ll
{
	int data;
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

int insert_last(single_ll_t **, int);
int print_list(single_ll_t *);
int traverse_list(single_ll_t *, int, single_ll_t **);
int insert_fast(single_ll_t **, int);
void exist_list(single_ll_t **);
int insert_middle(single_ll_t *, int, int);
int del_list(single_ll_t **head, int node_idx, int pos);
void exist_list(single_ll_t **);
int find_node_from_last(single_ll_t *temp, int node, single_ll_t **temp_last);
int swap_adjusent_node(single_ll_t **, int);
int find_middle_node(single_ll_t *, single_ll_t **);
