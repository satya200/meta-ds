/*
* AUTHOR: Satya Sundar Sahu
* mail id:- tinkusahu.com@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Below Macro value 1 : Implementation using recurssion
		     0 : With out Recurssion 
*/
#define NO_REC 1

struct Data
{
	int data;
};

typedef struct bst
{
	struct Data data;
	struct bst *parent;
	struct bst *left;
	struct bst *right;
	int level;
}BST;

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
	SUCCESS = 0, 
}err_t;

int bst_insert_node(BST **, struct Data, BST *parent);
int bst_print_list(BST *);
int bst_max_value(BST *);
int bst_exit(BST **root);
int bst_init();
int bst_no_of_leavenode(BST *root);
int bst_no_of_fullnode(BST *root);
int bst_ancestor(BST *root, int data);
int bst_height(BST *root);
int bst_find_level(BST *root, int data);
/*int traverse_list(BST *, int, single_ll_t **);
void exist_list(single_ll_t **);
int del_list(single_ll_t **head, int node_idx, int pos);
int find_len(single_ll_t *);
int reverse_list(single_ll_t **);*/
