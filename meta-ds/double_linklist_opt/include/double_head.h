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

int dlopt_insert_last(double_ll_t **, int);
int dlopt_print_list(double_ll_t *, int);
int dlopt_traverse_list(double_ll_t *, int, double_ll_t **);
int dlopt_insert_fast(double_ll_t **, int);
void dlopt_exist_list(double_ll_t **);
int dlopt_insert_middle(double_ll_t *, int, int);
int dlopt_del_list(double_ll_t **head, int node_idx, int pos);
int dlopt_find_node_from_last(double_ll_t *temp, int node, double_ll_t **temp_last);
int dlopt_swap_adjusent_node(double_ll_t **, int);
int dlopt_find_middle_node(double_ll_t *, double_ll_t **);
