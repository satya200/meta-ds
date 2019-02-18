//#include <bst_head.h>
#include <mystack_bst.h>

static FILE *log_fp = NULL;
struct stack_user bst_stack_user;
struct queue_user bst_queue_user;

int is_empty_queue(struct queue_user *);

/*
*  insert_node():
*	This Function will insort node in tree.
*	@root:- This the root Node.
*	@data:- This contains user data to be inserted in tree
*	@parent:- This is holds parent node address. This very much use full
		  if you want to move backward direction in tree.
*/
int bst_insert_node(BST **root, struct Data data, BST *parent)
{
	log_fp = stdout;

	if (root == NULL) {
		ERR_PRINT("root base address is NULL\n");
		return NULL_POINTER;
	}
	if ((*root) == NULL) {
		(*root) = (BST *)malloc(sizeof(BST));
		if ((*root) == NULL) {
			ERR_PRINT("malloc return NULL\n");
			return NULL_POINTER;
		}
		
		(*root)->parent = parent;
		if (parent) {
			(*root)->level = (parent->level + 1);
		} else {
			(*root)->level = 0;
		}
		(*root)->left = NULL;
		(*root)->right = NULL;

		memcpy(&((*root)->data.data), &data, sizeof(data));
		DBG_PRINT("Insert data success:%d:%d\n",data.data,(*root)->data.data);

		return SUCCESS;
	}
	if (data.data > (*root)->data.data) {
		bst_insert_node(&((*root)->right), data, (*root));
	} else if (data.data <= (*root)->data.data) {
		bst_insert_node(&((*root)->left), data, (*root));
	}
	return SUCCESS;
}

/* bst_find_level():
	This function will find out the level of a node.
	@root: This is root node
	@data: Node to find out level
*/
int bst_find_level(BST *root, int data)
{
	int level = -1;
	if (root == NULL) {
		return NULL_POINTER;
	}
	if (root->data.data == data) {
		printf("Data Found\n");
		level = root->level;
	} else {
		if (data < (root->data.data)) {
			level = bst_find_level(root->left, data);
		} else {
			level = bst_find_level(root->right, data);
		}
	}
	return level;
}
/* bst_height():-
	This Function will give height of tree
*/
int bst_height(BST *root)
{
	int left = 0,
	    right = 0;

	if (root == NULL) {
		return 0;
	}
	left = bst_height(root->left);
	right = bst_height(root->right);
	if (left >= right) {
		printf("left:%d\n",left+1);
		return left+1;
	} else {
		printf("right:%d\n",right+1);
		return right+1;
	}
}

void swap_data(struct stack_user *current, struct stack_user *nextlev)
{
	struct stack_user temp;
	//printf("i am in swap\n");
	memset(&temp, '\0', sizeof(temp));
	memcpy(&temp, current, sizeof(temp));
	memcpy(current, nextlev, sizeof(temp));
	memcpy(nextlev, &temp, sizeof(temp));
}

int bst_zigzag_print(BST *root)
{
	int ret = -1;
	int left_to_right = 1;
	BST *temp = NULL;
	struct data temp_stack,temp_stack_read;
	struct stack_user current_stack_user;
	struct stack_user nextlevel_stack_user;

	current_stack_user.stack_size = 10;
	nextlevel_stack_user.stack_size = 10;
	if (root == NULL) {
		return NULL_POINTER;
	}
	ret = create_stack(&current_stack_user);
        if (ret == 0) {
                printf("create_stack() return success\n");
                ret = 0;
        } else {
                printf("create_stack() return Fail. Please go to Recurssion methode\n");
        }

	ret = create_stack(&nextlevel_stack_user);
        if (ret == 0) {
                printf("create_stack() return success\n");
                ret = 0;
        } else {
                printf("create_stack() return Fail. Please go to Recurssion methode\n");
        }
	temp_stack.data_bst = root;
	ret = push(&current_stack_user, temp_stack);
	if (ret != 0) {
		printf("stack push return %d\n",ret);
		ret = -1;
	} else {
		while (current_stack_user.stack_idx != -1) {
			//printf("1====<cur=%d:nex:%d\n",current_stack_user.stack_idx, nextlevel_stack_user.stack_idx);
			pop(&current_stack_user, &temp_stack_read);
			temp = temp_stack_read.data_bst;
			if (temp) {
				printf("%d: ",temp->data.data);
			}
			if (left_to_right) {
				if (temp->left) {
					temp_stack.data_bst = temp->left;
					ret = push(&nextlevel_stack_user, temp_stack);
				}
				if (temp->right) {
					temp_stack.data_bst = temp->right;
					ret = push(&nextlevel_stack_user, temp_stack);
				} 
			} else {
				if (temp->right) {
					temp_stack.data_bst = temp->right;
					ret = push(&nextlevel_stack_user, temp_stack);
				}
				if (temp->left) {
					temp_stack.data_bst = temp->left;
					ret = push(&nextlevel_stack_user, temp_stack);
				} 
			}
			//printf("2===<cur=%d:nex:%d\n",current_stack_user.stack_idx, nextlevel_stack_user.stack_idx);
			if (current_stack_user.stack_idx == -1) {
				left_to_right = 1 - left_to_right;
				swap_data(&current_stack_user, &nextlevel_stack_user);
			}
			//printf("3===<cur=%d:nex:%d\n",current_stack_user.stack_idx, nextlevel_stack_user.stack_idx);
		}
			
	}
	printf("\n");
	return 0;
}

int preorder(BST *root)
{
	//int ret = -1;

	if (root == NULL) {
		//ERR_PRINT("root is NULL\n");
		return NULL_POINTER;
	}
#if NO_REC
	printf("%d | ",root->data.data);
	preorder(root->left);
	preorder(root->right);
#else
	int ret = -1;
	/* Below structure is use for sending tree node
	*  to the stack
	**/
	struct data root_stack;
	root_stack.data_bst = root;
	int max_element = 0;
	while(1) {
		while(root) {
			//sleep(1);
			printf("P=>%d | ",root->data.data);
			//bst_stack_user.sop.push(root_stack);
			push(&bst_stack_user, root_stack);
			root = root->left;
			root_stack.data_bst = root;
		}
		memset(&root_stack, '\0', sizeof(root_stack));
		//ret = bst_stack_user.sop.pop(&root_stack);
		ret = pop(&bst_stack_user, &root_stack);
		if (ret == 0) {
			printf("data success pop\n");
			root = root_stack.data_bst;
			if (root->data.data > max_element) {
				max_element = root->data.data;
			}
		} else {
			printf("error or underflow:%d\n",ret);
			break;
		}
		root = root->right;
		root_stack.data_bst = root;
	}
	//bst_stack_user.sop.destroy_stack();
	printf("=====>MAX ELEMENT IN TREE IS:%d\n",max_element);
#endif
	return SUCCESS;
}

int postorder(BST *root)
{
	//int ret = -1;

	if (root == NULL) {
		//ERR_PRINT("root is NULL\n");
		return NULL_POINTER;
	}
//#if NO_REC
	postorder(root->left);
	postorder(root->right);
	printf("%d | ",root->data.data);
//#endif
	return SUCCESS;
}

int inorder(BST *root)
{
	//int ret = -1;

	if (root == NULL) {
		//ERR_PRINT("root is NULL\n");
		return NULL_POINTER;
	}
//#if NO_REC
	inorder(root->left);
	printf("%d | ",root->data.data);
	inorder(root->right);
//#endif
	return SUCCESS;
}

int bst_print_list(BST *root)
{
	int ret = -1;

	if (root == NULL) {
		//ERR_PRINT("root is NULL\n");
		return NULL_POINTER;
	}
	ret = bst_zigzag_print(root);
	ret = preorder(root);
	printf("\n");
	ret = postorder(root);
	printf("\n");
	ret = inorder(root);
	printf("\nprint done:%d\n",ret);
	return SUCCESS;
}

int bst_exit(BST **root)
{
	if (root == NULL || (*root) == NULL) {
		//ERR_PRINT("NULL pointer\n");
		return NULL_POINTER;
	}
	bst_exit((&(*root)->left));
	bst_exit((&(*root)->right));
	//printf("%d | ",(*root)->data.data);
	free(*root);
	*root = NULL;
	return SUCCESS;
}
/*
* Below Function is for finding maximum Element in BST
* Logic:- Find left max element and right max element
* and Compare with root.
* RETURN:- max value 
*/
int bst_max_value(BST *root)
{
	int root_val, left_max, right_max, max_element;

	if (root == NULL) {
		//ERR_PRINT("NULL pointer\n");
		return NULL_POINTER;
	}
	root_val = root->data.data;
	left_max = bst_max_value(root->left);
	right_max = bst_max_value(root->right);
	
	if (left_max >= root_val && left_max >= right_max) {
		max_element = left_max;
	} else if (right_max >= root_val && right_max >= left_max) {
		max_element = right_max;
	} else {
		max_element = root_val;
	}
	return max_element;
}

/* Below Function Will give no of node which does not 
   have ant children 
*/
int bst_no_of_leavenode(BST *root)
{
	int ret = -1, count = 0;
	BST *temp_root = NULL;
	struct data bst_queue_data;
	bst_queue_data.data_bst = root;
	q_insert(&bst_queue_user, bst_queue_data);

	while (!is_empty_queue(&bst_queue_user)) {
		//printf("Inside\n");
		memset(&bst_queue_data, '\0', sizeof(bst_queue_data));
		ret = q_del(&bst_queue_user, &bst_queue_data);
		if (ret != 0) {
			printf("return error in q_del():%d\n",ret);
			ret = -2;
			return ret;
		} else {
			temp_root = bst_queue_data.data_bst;
			if ((temp_root) && (!temp_root->left) && (!temp_root->right)) {
				count++;
				//printf("count increment:%d\n",count);
			} else {
				if (temp_root && temp_root->left) {
					//printf("Inside1\n");
					bst_queue_data.data_bst = temp_root->left;
					q_insert(&bst_queue_user, bst_queue_data);
				}

				if (temp_root && temp_root->right) {
					//printf("Inside2\n");
					bst_queue_data.data_bst = temp_root->right;
					q_insert(&bst_queue_user, bst_queue_data);
				}
			}
		}
	}
	return count;	
}

/* Below Function Will give no of node which is 
   haveing 2 children 
*/
int bst_no_of_fullnode(BST *root)
{
	int ret = -1, count = 0;
	BST *temp_root = NULL;
	struct data bst_queue_data;
	bst_queue_data.data_bst = root;
	q_insert(&bst_queue_user, bst_queue_data);

	while (!is_empty_queue(&bst_queue_user)) {
		//printf("Inside\n");
		memset(&bst_queue_data, '\0', sizeof(bst_queue_data));
		ret = q_del(&bst_queue_user, &bst_queue_data);
		if (ret != 0) {
			printf("return error in q_del():%d\n",ret);
			ret = -2;
			return ret;
		} else {
			temp_root = bst_queue_data.data_bst;
			if ((temp_root) && (temp_root->left) && (temp_root->right)) {
				count++;
				//printf("count increment:%d\n",count);
			} else {
				if (temp_root && temp_root->left) {
					//printf("Inside1\n");
					bst_queue_data.data_bst = temp_root->left;
					q_insert(&bst_queue_user, bst_queue_data);
				}

				if (temp_root && temp_root->right) {
					//printf("Inside2\n");
					bst_queue_data.data_bst = temp_root->right;
					q_insert(&bst_queue_user, bst_queue_data);
				}
			}
		}
	}
	return count;	
}

int bst_ancestor(BST *root, int data)
{
	int ret = -1;
	if (root == NULL) {
		//printf("NULL Pointer Exception\n");
		return -1;
	}
	if (root->data.data == data) {
		printf("data:%d\n",root->data.data);
		return 0;
	}
	ret = bst_ancestor(root->left, data);
	if (ret == 0) {
		printf("data:%d\n",root->data.data);
		return ret;
	}
	ret = bst_ancestor(root->right, data);
	if (ret == 0) {
		printf("data:%d\n",root->data.data);
		return ret;
	}
	return ret;
}

/* bst_init():
	This Function is for tree init.
	Currently stack and Queue is emplemented as static
	TODO: Need to make Stack and Queue Dynamic
*/
int bst_init(int size)
{
	int ret = -1;
	if (size > 0) {
		bst_stack_user.stack_size = size;
		bst_queue_user.queue_size = size * size;
	} else {
		bst_stack_user.stack_size = 5; // This is default size
		bst_queue_user.queue_size = 10;
	}

	ret = create_stack(&bst_stack_user);
	if (ret == 0) {
		printf("create_stack() return success\n");
		ret = 0;
	} else {
		printf("create_stack() return Fail. Please go to Recurssion methode\n");
	}

	ret = create_queue(&bst_queue_user);
	if (ret == 0) {
		printf("create_queue() return success\n");
		ret = 0;
	} else {
		printf("create_queue() return Fail. Please go to Recurssion methode\n");
	}
	return ret;
}
