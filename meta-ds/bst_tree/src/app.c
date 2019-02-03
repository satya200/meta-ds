/*
* AUTHOR: Satya Sundar Sahu
* mail id:- tinkusahu.com@gmail.com
*/

#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <bst_head.h>

BST *root = NULL;

void sig_handler(int signum, siginfo_t *info, void *ptr)
{
	printf("Received signal %d\n", signum);
	printf("Signal originates from process %lu\n",(unsigned long)info->si_pid);
	bst_exit(&root);
	exit(0);
}

int main()
{
	int choice,data;
	int ret = -1;
	//BST *root = NULL; //Declare as Global to handle memory leak in intrupt trigger
	//BST *temp = NULL;
	struct Data val;

	struct sigaction act;
	printf("PROCESS ID:%u\n",getpid());
	memset(&act, '\0', sizeof(act));
	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;
	//act.sa_mask = ;
	sigaction(2, &act, NULL);

	printf("please enter tree hight:");
	scanf("%d",&choice);
	printf("return:-%d\n",bst_init(choice));
	printf("WELCOME TO BINARY SEARCH TREE\n");
	while(1) {
		printf("PLEASE ENTER UR CHOICE:\n");
		printf("0: Total App Exit\n1: for insert tree\n2: for print all\n3:Find Max Element in Tree\n4: No of leaves node\n5: No of Full Node\n6: Find Ancestor\n7: Find Height of Tree\n8: Find level of a node\n");
		scanf("%d",&choice);
		switch (choice) {
		case 1:
			printf("Enter data:");
			scanf("%d",&val.data);
			ret = bst_insert_node(&root, val, NULL);
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
		case 4:
			printf("Going to print no of leave node means the node\nwhich does not have any children\n");
			ret = bst_no_of_leavenode(root);
			if (ret < 0) {
				printf("return error in %s\n",__FUNCTION__);
			} else {
				printf("No of leaves node is===>: %d\n",ret);
			}
			break;
		case 5:
			printf("Going to print no of full node means the node\nwhich is  haveing 2 children\n");
			ret = bst_no_of_fullnode(root);
			if (ret < 0) {
				printf("return error in %s\n",__FUNCTION__);
			} else {
				printf("No of full node is: %d\n",ret);
			}
			break;
		case 6:
			printf("Please enter data for ancestor:");
			scanf("%d",&ret);
			ret = bst_ancestor(root, ret);
			if (ret == 0) {
				printf("Ancestor Printed\n");
			} else {
				printf("Ancestor not found or error\n");
			}
			break;
		case 7:
			if (root) {
				printf("%d\n",bst_height(root));
			} else {
				printf("Tree is Empty. Please Insert Node\n");
			}
			break;
		case 8:
			printf("Please enter data:");
			scanf("%d",&data);
			if (root) {
				ret = bst_find_level(root, data);
				if (ret > 0) {
					printf("Level of Node is :%d\n",ret);
				} else {
					printf("Level not foud. Please find out error code in header file:%d\n",ret);
				}
			} else {
				printf("Tree is Empty\n");
			}
			break;
#if 0
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
