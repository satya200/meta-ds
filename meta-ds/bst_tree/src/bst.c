//#include <bst_head.h>
#include <mystack_bst.h>

static FILE *log_fp = NULL;
struct stack_user bst_stack_user;

/*
*  insert_node():
*	This Function will insort node in tree.
*	@root:- This the root Node.
*	@data:- This contains user data to be inserted in tree
*/
int bst_insert_node(BST **root, struct Data data)
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

		(*root)->left = NULL;
		(*root)->right = NULL;

		memcpy(&((*root)->data.data), &data, sizeof(data));
		DBG_PRINT("Insert data success:%d:%d\n",data.data,(*root)->data.data);

		return SUCCESS;
	}
	if (data.data > (*root)->data.data) {
		bst_insert_node(&((*root)->right), data);
	} else if (data.data <= (*root)->data.data) {
		bst_insert_node(&((*root)->left), data);
	}
	return SUCCESS;
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
	struct data root_stack;
	root_stack.data_bst = root;
	while(1) {
		while(root) {
			sleep(1);
			printf("P=>%d | ",root->data.data);
			bst_stack_user.sop.push(root_stack);
			root = root->left;
			root_stack.data_bst = root;
		}
		ret = bst_stack_user.sop.pop(&root_stack);
		if (ret == 0) {
			printf("data success pop\n");
			root = root_stack.data_bst;
		} else {
			printf("error or underflow:%d\n",ret);
			break;
		}
		root = root->right;
		root_stack.data_bst = root;
	}
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
		ERR_PRINT("NULL pointer\n");
		return NULL_POINTER;
	}
	bst_exit((&(*root)->left));
	bst_exit((&(*root)->right));
	printf("%d | ",(*root)->data.data);
	free(*root);
	*root = NULL;
	return SUCCESS;
}

int bst_init()
{
	int ret = -1;
	bst_stack_user.stack_size = 10;
	ret = create_stack(&bst_stack_user);
	if (ret == 0) {
		printf("create_stack() return success\n");
		ret = 0;
	} else {
		printf("create_stack() return Fail. Please go to Recurssion methode\n");
	}
	return ret;
}
