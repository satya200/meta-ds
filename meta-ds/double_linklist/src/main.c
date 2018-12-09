/*
* AUTHOR: Satya Sundar Sahu
* mail id:- tinkusahu.com@gmail.com
*/

#include <double_head.h>

int main()
{
	int choice;
	int ret = -1;
	double_ll_t *head = NULL;
	double_ll_t *temp = NULL;
	struct Data  val;
	int data;
	int node;

	printf("WELCOME TO SINGLE LINKLIST DATA STRUCTURE\n");
	while(1) {
		printf("PLEASE ENTER UR CHOICE:\n");
		printf("0: Total App Exit\n1: for inser last\n2: for print all\n3: insert fast\n4: insert middle\n\
5: Delete node\n6: Swap 2 adj node\n7: Find Middle Node\n");
		scanf("%d",&choice);
		switch (choice) {
		case 1:
			printf("Enter data:");
			scanf("%d",&val.data);
			ret = dll_traverse_list(head, -1, &temp);
			printf("======>main in tarverse:%d\n",ret);
			if (ret == -1) {
				ret = dll_insert_last(&head, val);
				if (ret == 0) {
					temp = head;
					printf("Insert fast node and update temp\n");
				}
			} else {
				ret = dll_insert_last(&temp, val);
			}
			printf("=======>main in last insert:%d\n",ret);
			break;
		case 2:
			ret = dll_print_list(head, 1);
			printf("in print:%d\n",ret);
			printf("==========================================\n");
			ret = dll_print_list(head, 2);
			printf("in print:%d\n",ret);
			break;
		case 3:
			printf("Enter data");
			scanf("%d",&val.data);
			ret = dll_insert_fast(&head, val);
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
			ret = dll_insert_middle(head,node-1,val);
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
			ret = dll_del_list(&head, node - 1, data);
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
			ret = dll_swap_adjusent_node(&head, node);
			if (ret == 0) {
				printf("Swap node suucces\n");
			} else {
				printf("swap is failed\n");
			}
			break;
		case 7:
			ret = dll_find_middle_node(head, &temp);
			if (ret < 0) {
				printf("main error in find_middle_node()\n");
				break;
			} else {
				printf("MIDDLE NODE:%d\n",temp->data.data);
				break;
			}
		case 0:
			dll_exist_list(&head);
			return 0;
			
		default:
			dll_exist_list(&head);
			break;
		}
	}
	return 0;
}
