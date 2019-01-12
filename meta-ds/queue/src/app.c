/*
AUTHOR: Satya Sundar Sahu
DATE:   13th-Jan-2019
Description:
        This file contains App to test 
	Queue implementation using array
*/

#include "myqueue.h"

int main()
{
	int ret = -1;
	int choice, data;
	struct data data1;
	struct queue_user q_data;
	printf("Enter size of Queue\n");
	scanf("%d",&data);
	q_data.queue_size = data;
	ret = create_queue(&q_data);
	while (1) {
		printf("1: For Insert.\n2: For Delete\n3: print\n4: Free space\n0: Clear\n");
		printf("Please enter opt:");
		scanf("%d",&choice);

		switch (choice) {
			
			case 1:
				printf("Emter data");
				scanf("%d",&data1.data);
				//ret = queue_data.sop.q_insert(data1);
				ret = q_insert(&q_data, data1);
				if (ret == 0) 
					printf("success\n");
				else if (ret == 1) {
					printf("QUEUE IS FULL\n");
				} else {
					printf("Error\n");
				}
				break;
			case 2:
				//ret = stack_data.sop.pop(&data1);
				ret = q_del(&q_data, &data1);
				if (ret == 0) 
					printf("success data:%d\n",data1.data);
				else if (ret == 1) {
					printf("QUEUR IS EMPTY\n");
				} else {
					printf("Error\n");
				}
				break;
			/*case 3:
				stack_data.sop.print_stack();
				break;
			case 4:
				printf("free space: %d\n",stack_data.sop.free_space());
				break;
			case 0:
				stack_data.sop.destroy_stack();
				exit(0);*/
			default:
				printf("Unknown case\n");
				
		}	
	}
	return 0;
}
