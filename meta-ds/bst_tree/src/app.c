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
	//int data;
	//int node;

	printf("return:-%d\n",bst_init());
	printf("WELCOME TO BINARY SEARCH TREE\n");
	while(1) {
		printf("PLEASE ENTER UR CHOICE:\n");
		printf("0: Total App Exit\n1: for insert tree\n2: for print all\n5: Delete node\n6: Find length\n");
		scanf("%d",&choice);
		//printf("return:-%d\n",bst_init());
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
#if 0
		case 3:
			printf("Enter data");
			scanf("%d",&val.data);
			ret = insert_fast(&head, val);
			if (ret < 0) {
				printf("Err ret insert_fast():%d\n",ret);
			} else {
				temp = head;
				printf("success insert_fast() and temp update\n");
			}
			break;
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
		case 6:
			printf("Enter node idx");
			scanf("%d",&node);
			if (node <= 0) {
				printf("Invalid parameter.It will be > 0\n");
				break;
			}
			ret = swap_adjusent_node(&head, node);
			if (ret == 0) {
				printf("Swap node suucces\n");
			} else {
				printf("swap is failed\n");
			}
			break;
		case 7:
			ret = find_middle_node(head, &temp);
			if (ret < 0) {
				printf("main error in find_middle_node()\n");
				break;
			} else if (ret == 1) {
				printf("Middle Node Not Present:%d\n",temp->data.data);
				break;
			} else {
				printf("Middle Node:%d\n",temp->data.data);
				break;
			}
		case 8:
			ret = check_loop(head, &temp);
			if (ret == -1) {
				printf("NULL pointer\n");
			} else if (ret == -2) {
				printf("Loop found\n");
				if (temp) {
					printf("Start point:%d\n",temp->data.data);
				} else {
					printf("Starting point not avl in temp\n");
				}
			} else if (ret == 0) {
				printf("NO LOOP\n");
			} else {
				printf("Invalid return value\n");
			}
			break;
		case 9:
			printf("Enter start and end\n");
			scanf("%d%d",&data,&node);
			ret = create_loop(head, data, node);
			if (ret == 0) {
				printf("loop created.\n");
			} else {
				printf("Loop not created\n");
			}
			break;
		case 10:
			printf("FInding Length:");
			ret = find_len(head);
			printf("Length of List:%d\n",ret);
			break;
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
