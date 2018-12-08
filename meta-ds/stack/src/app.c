/*
AUTHOR: Satya Sundar Sahu
DATE:   27th-Nov-2018
Description:
        This file contains App to test 
	stack implementation using array
*/

#include "mystack.h"

int main()
{
	int ret = -1;
	int choice, data;
	struct data data1;
	struct stack_user stack_data;
	printf("Enter size of stack\n");
	scanf("%d",&data);
	stack_data.stack_size = data;
	ret = create_stack(&stack_data);
	while (1) {
		printf("1: For Push.\n2: For Pop\n3: print\n4: no of free space\n0: clear\n");
		printf("Please enter opt:");
		scanf("%d",&choice);

		switch (choice) {
			
			case 1:
				printf("Emter data");
				scanf("%d",&data1.data);
				ret = stack_data.sop.push(data1);
				if (ret == 0) 
					printf("success\n");
				else if (ret == 1) {
					printf("OVER-FLOW\n");
				} else {
					printf("Error\n");
				}
				break;
			case 2:
				ret = stack_data.sop.pop(&data1);
				if (ret == 0) 
					printf("success data:%d\n",data1.data);
				else if (ret == 1) {
					printf("UNDER-FLOW\n");
				} else {
					printf("Error\n");
				}
				break;
			case 3:
				stack_data.sop.print_stack();
				break;
			case 4:
				printf("free space: %d\n",stack_data.sop.free_space());
				break;
			case 0:
				stack_data.sop.destroy_stack();
				exit(0);
			default:
				printf("Unknown case\n");
				
		}	
	}
	return 0;
}
