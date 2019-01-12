/*
* AUTHOR: Satya Sundar Sahu
* mail id:- tinkusahu.com@gmail.com
*/

#include <bst_head.h>

int main()
{
	int choice;
	int ret = -1;
	BST *root = NULL;
	//BST *temp = NULL;
	struct Data val;
	
	printf("please enter tree hight:");
	scanf("%d",&choice);
	printf("return:-%d\n",bst_init(choice));
	printf("WELCOME TO BINARY SEARCH TREE\n");
	while(1) {
		printf("PLEASE ENTER UR CHOICE:\n");
		printf("0: Total App Exit\n1: for insert tree\n2: for print all\n3:Find Max Element in Tree\n");
		scanf("%d",&choice);
		switch (choice) {
		case 1:
			printf("Enter data:");
			scanf("%d",&val.data);
			ret = bst_insert_node(&root, val);
			if (ret == 0) {
				printf("Node inserted\n");
			}
			break;
		case 2:
			ret = bst_print_list(root);
			printf("in print:%d\n",ret);
			break;
		case 3:
			printf("Enter data");
			ret = bst_max_value(root);
			if (ret < 0) {
				printf("Err ret in max_value():%d\n",ret);
			} else {
				printf("Maximum Element in BST:%d\n",ret);
			}
			break;
#if 0
		case 4:
			printf("Enter data and node:");
			scanf("%d%d",&val.data,&node);
			ret = insert_middle(head,node,val);
			if (ret == 0 && ret == 1) {
				printf("Function success\n");
			} else {
				printf("=======> main insert_middle() FAIL\n");
			}
			break;
		case 5:
			printf("Enter node idx:");
			scanf("%d",&node);
			printf("Enter  position[0 -middle\n 1 - fast\n 2 - last\n] and node no\n");
			scanf("%d",&data);
			ret = del_list(&head, node - 1, data);
			if (ret == 0) {
				printf("In main finc Delete success\n");
			} else {
				printf("In main Error in Delet:ret=%d\n",ret);
			}
			break;
				break;
			}
		case 11:
			ret = reverse_list(&head);
			if (ret == 0) {
				printf("Reverse Done\n");
			} else {
				printf("Error in Rev\n");
			}
			break;
		case 12:
			ret = sl_check_palindrome(head);
			if (ret == 0) {
				printf("It is palindrome\n");
			} else {
				printf("It is not palindrome\n");
			}
			break;
#endif
		case 0:
			bst_exit(&root);
			return 0;
			
		default:
			printf("Invalid choice\n");
			break;
		}
	}
	return 0;
}
