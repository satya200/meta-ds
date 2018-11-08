/*
* AUTHOR: Satya Sundar Sahu
* mail id:- tinkusahu.com@gmail.com
*/

#include <single_head.h>

int main()
{
	int choice;
	int ret = -1;
	single_ll_t *head = NULL;
	single_ll_t *temp = NULL;
	int data;
	int node;

	printf("WELCOME TO SINGLE LINKLIST DATA STRUCTURE\n");
	while(1) {
		printf("PLEASE ENTER UR CHOICE:\n");
		printf("0: Total App Exit\n1: for inser last\n2: for print all\n3: insert fast\n4: insert middle\n\
5: Delete node\n6: Swap 2 adj node\n7: Find Middle Node\n8: check loop\n9: create loop\n");
		scanf("%d",&choice);
		switch (choice) {
		case 1:
			printf("Enter data:");
			scanf("%d",&data);
			ret = traverse_list(head, -1, &temp);
			printf("======>main in tarverse:%d\n",ret);
			if (ret == -1) {
				ret = insert_last(&head, data);
				if (ret == 0) {
					temp = head;
					printf("Insert fast node and update temp\n");
				}
			} else {
				ret = insert_last(&temp, data);
			}
			printf("=======>main in last insert:%d\n",ret);
			break;
		case 2:
			ret = print_list(head);
			printf("in print:%d\n",ret);
			break;
		case 3:
			printf("Enter data");
			scanf("%d",&data);
			ret = insert_fast(&head, data);
			if (ret < 0) {
				printf("Err ret insert_fast():%d\n",ret);
			} else {
				temp = head;
				printf("success insert_fast() and temp update\n");
			}
			break;
		case 4:
			printf("Enter data and node:");
			scanf("%d%d",&data,&node);
			ret = insert_middle(head,node,data);
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
			} else {
				printf("MIDDLE NODE:%d\n",temp->data);
				break;
			}
		case 8:
			ret = check_loop(head, &temp);
			if (ret == -1) {
				printf("NULL pointer\n");
			} else if (ret == -2) {
				printf("Loop found\n");
				if (temp) {
					printf("Start point:%d\n",temp->data);
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
		case 0:
			exist_list(&head);
			return 0;
			
		default:
			exist_list(&head);
			break;
		}
	}
	return 0;
}
