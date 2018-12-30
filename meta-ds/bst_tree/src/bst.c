#include <bst_head.h>

static FILE *log_fp = NULL;

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
	printf("%d | ",root->data.data);
	preorder(root->left);
	preorder(root->right);
	return SUCCESS;
}

int postorder(BST *root)
{
	//int ret = -1;

	if (root == NULL) {
		//ERR_PRINT("root is NULL\n");
		return NULL_POINTER;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d | ",root->data.data);
	return SUCCESS;
}

int inorder(BST *root)
{
	//int ret = -1;

	if (root == NULL) {
		//ERR_PRINT("root is NULL\n");
		return NULL_POINTER;
	}
	inorder(root->left);
	printf("%d | ",root->data.data);
	inorder(root->right);
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
