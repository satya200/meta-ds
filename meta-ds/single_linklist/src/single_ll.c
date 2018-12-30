/*
* AUTHOR: Satya Sundar Sahu
* mail id:- tinkusahu.com@gmail.com
*/

#include <single_head.h>

static FILE *log_fp = NULL;

/*
Name: Function to find the largest and second largest in linklist.
Parameters: 
      head = Starting Node of linklist
Return:
      -1  on Error 
       0  on Success
*/
int findLargest_secondLargest(single_ll_t *head)
{

	if (head == NULL) {
		printf("List is Empty\n");
		return -1;
	}

	single_ll_t *secondLargest = head;
	single_ll_t *largest = head;
	single_ll_t *traverse = head;
	
	while (traverse->next) {
		if ((largest->data).data < (traverse->next->data).data) {
			secondLargest = largest;
			largest = traverse->next;
		} else {
			/* If only two elements are there in list */
			if ((secondLargest == largest) && (traverse->next->next == NULL))
				secondLargest = traverse->next;
			if ((secondLargest->data).data < (traverse->next->data).data) {
				secondLargest = traverse->next;			
			}
		}		
		traverse = traverse->next;
	}	
	
	printf("Largest = %d SecondLargest = %d\n",(largest->data).data,(secondLargest->data).data);
	return 0;

}

/*
Name: Function to swap two nodes based on the given position in linklist.
Parameters: 
      head = Starting Node of linklist
      pos1 = position of first node which is to be swapped 
      pos2 = position of second node which is to be swapped

Return:
      -1  on Error 
       0  on Success
*/
int swap_node(single_ll_t **head, int pos1, int pos2)
{
        
	if ((head == NULL) || (*head == NULL)) {
		ERR_PRINT("%s:%d :head value is NULL\n",__FUNCTION__,__LINE__);
		return -1;	
	}
	else if ((*head)->next == NULL) {
                ERR_PRINT("%s:%d :Insufficient data in list to swap.\n",__FUNCTION__,__LINE__);
                return -1;
        }

	single_ll_t *pos1_pre_node = NULL,
		    *pos2_pre_node = NULL,
		    *pos1_node = NULL, 
		    *pos2_node = NULL,
		    *temp = NULL, 
		    *head_t = *head,
		    *newHead = *head;
	int count = 0;

	if (pos1 == pos2) {
		DATA_PRINT("%s:%d :Input Position1 and Position2 are same.\n",__FUNCTION__,__LINE__);
		return 0;
	}

	while (head_t->next) {
		if (pos1 == (count +1)){
			pos1_pre_node = head_t;
			pos1_node = head_t->next;
		}				
		if (pos2 == (count +1)) {
			pos2_pre_node = head_t;
			pos2_node = head_t->next;	
		}										
		count++;
		head_t = head_t->next;
	}

	if (pos1 == 0) {
		pos1_node = *head;
		newHead = pos2_node;	
	}
	else if (pos2 == 0) {
		pos2_node = *head;
		newHead = pos1_node;	
	}
	
	if ( (pos1_node== NULL) || (pos2_node == NULL))	{
		ERR_PRINT("%s:%d :Invalid position to swap.\n",__FUNCTION__,__LINE__);
		return -1; 
	}			
	
	temp = pos2_node->next;
	if (NULL != pos1_pre_node)
		pos1_pre_node->next = pos2_node;

	if (pos1_node->next == pos2_node) {
		pos2_node->next = pos1_node;	
	} else {
		pos2_node->next = pos1_node->next;
		if (NULL != pos2_pre_node)
			pos2_pre_node->next = pos1_node;
	}

	pos1_node->next = temp;
	*head = newHead;
	return 0;
	
}

int insert_last(single_ll_t **head, const struct Data data)
{
	log_fp = stdout;
	single_ll_t *new_node = NULL;

	if (head == NULL) {
		ERR_PRINT("%s:%d :head value is NULL\n",__FUNCTION__,__LINE__);
		return -1;
	}
	if (*head == NULL) {
		DBG_PRINT("Fast Node insert\n");
		(*head) = malloc(sizeof(single_ll_t)+8);
		if (*head == NULL) {
			ERR_PRINT("%s:%d: malloc fail\n",__FUNCTION__,__LINE__);
			return -2;
		}
		(*head)->next = NULL;
		memcpy(&((*head)->data), &data, sizeof(data));
		
	} else {
		DBG_PRINT("%s:Insert last node\n",__FUNCTION__);

		if ((*head)->next != NULL) {
			ERR_PRINT("head not in last node. Please send last node address\n");
			return -3;
		}

		new_node = malloc(sizeof(single_ll_t));
		if (new_node == NULL) {
			ERR_PRINT("%s:%d malloc fail\n",__FUNCTION__,__LINE__);
			return -2;
		} else {
			new_node->next = NULL;
			memcpy(&(new_node->data), &data, sizeof(data));
			(*head)->next = new_node;
			
		}
	}
	return 0;
}

int insert_fast(single_ll_t **head, struct Data data)
{
	log_fp = stdout;
	single_ll_t *new_node = NULL;

	if (head == NULL) {
		ERR_PRINT("%s:%d :head value is NULL\n",__FUNCTION__,__LINE__);
		return -1;
	}
	if (*head == NULL) {
		DBG_PRINT("%s:fast node insert\n",__FUNCTION__);

		(*head) = malloc(sizeof(single_ll_t));
		if (*head == NULL) {
			ERR_PRINT("%s:%d: malloc fail\n",__FUNCTION__,__LINE__);
			return -2;
		}
		(*head)->next = NULL;
		memcpy(&((*head)->data), &data, sizeof(data));
	} else {
		new_node = malloc(sizeof(single_ll_t));
		if (new_node == NULL) {
			ERR_PRINT("%s:%d: malloc fail\n",__FUNCTION__,__LINE__);
			return -2;
		}
		memcpy(&(new_node->data), &data, sizeof(data));
		new_node->next = (*head);
		(*head) = new_node;
	}
	return 0;
}

int insert_sort()
{
	return 0;
}

int insert_middle(single_ll_t *head, int node, struct Data data)
{
	int ret = -1;
	single_ll_t *temp = NULL,
		    *new_node = NULL;


	if (head == NULL) {
		ERR_PRINT("%s:%d: NULL pointer\n",__FUNCTION__,__LINE__);
		return -1;
	}
	if (node > 1) {
		temp = head;
		ret = traverse_list(head, node - 1, &temp);
		if (ret < 0) {
			ERR_PRINT("error in traverse return\n");
			return -3;
		}
		if (temp->next == NULL) {
			DBG_PRINT("NODE POSTION IS LARGER THAN LIST OR LAST NODE\n \
					if last node use insert_last() fun\n");
			return 1;
		}
		
	} else {
		ERR_PRINT("Invalide node position. maye be 0 or -ve no.give greter that zero\n");
		return -3;
	}	
	new_node = (single_ll_t *)malloc(sizeof(single_ll_t));
	if (new_node == NULL) {
		ERR_PRINT("%s:%d: malloc fail\n",__FUNCTION__,__LINE__);
		return -2;
	}

	memcpy(&(new_node->data), &data, sizeof(data));
	new_node->next = temp->next;
	temp->next = new_node;

	return 0;
}

int traverse_list(single_ll_t *temp, int node_cnt, single_ll_t **temp_last)
{
	if (temp == NULL || temp_last == NULL) {
		ERR_PRINT("%s:%dParameter NULL\n",__FUNCTION__,__LINE__);
		return -1;
	}
	(*temp_last) = temp;

	if (node_cnt == -1) {
		DBG_PRINT("FULL TRAVERSE\n");
		while (temp->next) {
			temp = temp->next;
		}
	}
	if (node_cnt == 0) {
		DBG_PRINT("Giving 1st node\n");
		return 0;
		
	}
	while(node_cnt--) {
		if (temp->next) {
			temp = temp->next;
		} else {
			DBG_PRINT("HEAD IS IN LAST NODE\n");
			break;
			//return 0;
		}
	}
	if (*temp_last) {
		(*temp_last) = temp;
		DBG_PRINT("In trav:%d:data:%d\n",(*temp_last)->data.data, temp->data.data);
	} else {
		ERR_PRINT("Error in Trav\n");
		return -1;
	}
	return 0;
}

int del_list(single_ll_t **head, int node_idx, int pos)
{
	single_ll_t *temp = NULL;
	single_ll_t *temp_free = NULL;
	int ret = -1;

	if ((head == NULL) && (*head == NULL)) {
		ERR_PRINT("%s:NULL pointer\n",__FUNCTION__);
		return -1;
	}
	temp = (*head);
	if (pos == 1) {
		DBG_PRINT("Going to delete fast node\n");
		if ((*head)->next == NULL) {
			DBG_PRINT("List contains only one node\n");
                        free(*head);
                        (*head) = NULL;
                        return 0;
                }
		(*head) = (*head)->next;
		free(temp);
		temp = NULL;
		
	} else if (pos == 2) {
		DBG_PRINT("Going to delete last node\n");
		ret = find_node_from_last(*head, 2, &temp);
		if (ret == -1) {
			ERR_PRINT("%s:Ret error in traverse_list()\n",__FUNCTION__);
			return -2;
		}
		if (temp) {
			DBG_PRINT("last node:%d\n",temp->data.data);
			if (temp->next == NULL) {
                                free(temp);
                                *head = NULL;
                                return 0;
                        }
			temp_free = temp->next;
			temp->next = NULL;
			free(temp_free);
			temp_free = NULL;
		}
	} else if (pos == 0 && node_idx > 0) {
		DBG_PRINT("Going to delete randome node\n");
		ret = traverse_list(*head, node_idx - 1, &temp);
		if (ret == -1) {
			ERR_PRINT("%s:Ret error in traverse_list()\n",__FUNCTION__);
			return -2;
		}
		if (temp) {
			DBG_PRINT("data:%d:data:%d\n",temp->data.data, temp->data.data);
			temp_free = temp->next;
			if (temp->next) {
				temp->next = temp->next->next;
			}
			if (temp_free) {
				free(temp_free);
			}
			temp_free = NULL;
		}
	} else { 
		ERR_PRINT("%s:Invalid parameter\n",__FUNCTION__);
		return -3;
	}
	return 0;
}

int rev_list()
{
	return 0;
}

int print_list(single_ll_t *head)
{
	single_ll_t *temp = NULL;
	int print_cnt = 1;

	if (head == NULL) {
		ERR_PRINT("List is Empty.\n");
		return -3;
	}
	temp = head;
	DATA_PRINT("--------------------------------------------\n");
	while (temp) {
		//sleep(1); Use for Testing
		DATA_PRINT("| %d |",temp->data.data);
		fflush(stdout);
		temp = temp->next;
		if (print_cnt == 8) {
			//DATA_PRINT("\n");
			DATA_PRINT("\n--------------------------------------------\n");
			print_cnt = 0;
		}
		print_cnt++;
	}
	DATA_PRINT("\n");
	return 0;
}

int swap_adjusent_node(single_ll_t **head, int node_idx)
{
	single_ll_t *temp = NULL;
	single_ll_t *temp_prev = NULL;
	int ret = -1;
	if (head == NULL && (node_idx > 0)) {
		ERR_PRINT("Invalid Param\n");
		return -2;
	}
	if (*head == NULL && ((*head)->next == NULL)) {
		DBG_PRINT("LIST IS EMPTY OR ONLY ONE NODE\n");
		return -1;
	}
	if (node_idx-1 == 0) {
		DBG_PRINT("Swap 1st and 2nd node\n");
		temp_prev = (*head);
		temp = temp_prev->next;
		temp_prev->next = temp->next;
		temp->next = temp_prev;
		(*head) = temp;
	} else if (node_idx-1 > 0) {
		ret = traverse_list(*head, node_idx - 2, &temp_prev);
		if (ret < 0) {
			ERR_PRINT("Error in traverse_list() ret\n");
			return -2;
		}
		if (temp_prev->next->next == NULL) {
			DBG_PRINT("List is in Last node. So swap not possible\n");
			return 0;
		}
		temp = temp_prev->next;
		temp_prev->next = temp->next;
		temp->next = temp_prev->next->next;
		temp_prev->next->next = temp;
	} 
	return 0;
}

/*
* find_middle_node():
	This Finction will find out middle node.
* @head: Starting Node
* @temp: Out put Will Store Here 
*/

int find_middle_node(single_ll_t *head, single_ll_t **temp)
{
	int ret = 0;
	single_ll_t *temp_1_move = NULL;
	single_ll_t *temp_2_move = NULL;

	if (head == NULL || temp == NULL) {
		ERR_PRINT("%s:NULL POINTER\n",__FUNCTION__);
		return -1;
	}
	temp_1_move = head;
	temp_2_move = head;
	if ((temp_1_move->next == NULL) || (temp_2_move->next->next == NULL)) {
		ERR_PRINT("List contains only one or two node\n");
		return -3;
	}
	while (temp_2_move && (temp_2_move->next)) {
		/* The no of List is Even. So Middle Node not Present */
		if (temp_2_move->next->next != NULL) {
			temp_1_move = temp_1_move->next;
		}
		temp_2_move = temp_2_move->next->next;
	}
	if (temp_2_move == NULL) {
		ERR_PRINT("List does not contains middle node\n");
		ret = 1;
	}
	(*temp) = temp_1_move;
	DBG_PRINT("middle node:%d\n",(*temp)->data.data);
	return ret;
}

int find_node_from_last(single_ll_t *temp, int node, single_ll_t **temp_last)
{
	if (temp == NULL || temp_last == NULL) {
		ERR_PRINT("%s:%dParameter NULL\n",__FUNCTION__,__LINE__);
		return -1;
	}
	(*temp_last) = temp;
	if ((*temp_last)->next == NULL) {
                return 0;
        }
	if (node > 1) {
		node = node - 1;
		while ((temp->next) && ((*temp_last)->next)) {
			if (node) {
				temp = temp->next;
				node--;
			} else {
				(*temp_last) = (*temp_last)->next;
				temp = temp->next;
			}
		}
	} else {
		DBG_PRINT("PLEASE USE traverse_list() to get last node\n");
		return -3;
	}
	return 0;
}

int create_loop(single_ll_t *head, int start, int end)
{
	single_ll_t *temp = NULL,
		   *temp1 = NULL;;

	if ((head != NULL) && (start > 1) && (end > 1) && (start > end)) {
		temp = head;
		start--;
		end--;
		while (start) {
			if (temp) {
				temp = temp->next;
				if (end == 1)
					temp1 = temp;
				start--;
				end--;
				
			} else {
				return -1;
			}
		}
		temp->next = temp1;
		DBG_PRINT("LOOP CREATED\n");
	} else {
		printf("Not valid input\n");
		return -1;
	}
	return 0;
}

int check_loop(single_ll_t *head, single_ll_t **temp)
{
	single_ll_t *head_bak = NULL;

	if (head == NULL && temp == NULL) {
		ERR_PRINT("NULL pointer\n");
		return -1;
	}
	if (head->next == NULL) {
		DBG_PRINT("Only one node.No loop\n");
	} else {
		head_bak = head;
		(*temp) = head;
		do {
			if ((*temp) && head && head->next) {
				(*temp) = (*temp)->next;
				head = head->next->next;
				
			} else {
				DBG_PRINT("check_loop():NO LOOP\n");
				break;
			}
		}while ((*temp) != head);
		if ((*temp) == head) {
			DBG_PRINT("LOOP FOUND.%d:%d\n",(*temp)->data.data,head->data.data);
			head = head_bak;
			while (head) {
				head = head->next;
				if ((*temp)->next == head) {
					DBG_PRINT("LOOP START FOUND\n");
					return -2;
				} else {
					(*temp) = (*temp)->next;
				}
			}
		}
	}
	return 0;
}

int find_len(single_ll_t *head)
{
	int ret = -1,
	    cnt = -11;
	single_ll_t *temp = head,
		     *temp_speed = head;

	if (!(head)) {
		ret = -1;
	} else {
		cnt = 1;
		while(temp_speed) {
			if (temp_speed->next) {
				if (temp->next->next) {
					temp_speed = temp_speed->next->next;
				}
				if (temp_speed == NULL) {
					cnt = cnt + 1;
				} else {
					cnt = cnt + 2;
				}
			} else {
				break;
			}
		}
	}
	ret = cnt;
	return ret;
}

int reverse_list(single_ll_t **head)
{
	int ret = -1;
	single_ll_t *temp = NULL;
	single_ll_t *temp_next = NULL;

	if (head == NULL && (*head) == NULL) {
		DBG_PRINT("NULL pointer\n");
		return -ret;
	}
	if ((*head)->next == NULL) {
		DBG_PRINT("Only One Node Present\n");
		return 0;
	}
	while ((*head)) {
		temp_next = (*head)->next;
		(*head)->next = temp;
		temp = (*head);
		if (temp_next != NULL)
			(*head) = temp_next;
		else
			break;
	}
	return 0;
}

void exist_list(single_ll_t **head)
{
	single_ll_t *temp = NULL;
	if (head && (*head)) {
		DBG_PRINT("IN %s\n",__FUNCTION__);
		while(*head) {
			temp = (*head);
			(*head) = (*head)->next;
			if (temp) {
				free(temp);
				temp = NULL;
			}
		}
	}
}

int sl_check_palindrome(single_ll_t *head)
{
	int ret = -1;

	single_ll_t *mid_node = NULL;
	single_ll_t *rev_node = NULL;
	single_ll_t *temp = NULL;

	if (head == NULL) {
		DBG_PRINT("Head is NULL. may be list is empty\n");
		return -1;
	}
	ret = find_middle_node(head, &mid_node);
	if (ret < 0) {
		ERR_PRINT("Error in find_middle_node()\n");
		return -1;
	}
	if (mid_node == NULL) {
		ERR_PRINT("NULL in ret find_middle_node()\n");
		return -1;
	}
	//DBG_PRINT("====>%d\n",mid_node->data.data);
	rev_node = mid_node->next;
	ret = reverse_list(&rev_node);
	if (ret != 0) {
		ERR_PRINT("Error in ret reverse_list()\n");
		return -1;
	}
	//DBG_PRINT("rev===>%d\n",rev_node->data.data);
	mid_node->next = rev_node;
	mid_node = mid_node->next;
	temp = head;
	while (mid_node) {
		if (temp->data.data == mid_node->data.data) {
			temp = temp->next;
			mid_node = mid_node->next;
			continue;
		} else {
			break;
		}
	}
	if (mid_node == NULL) {
		DBG_PRINT("WARNNING: LIST DATA MODIFIED. CALL AGAIN THIS FUNCTION TO GET ORGINAL DATA\n");
		ret = 0;
	} else {
		DBG_PRINT("WARNNING: LIST DATA MODIFIED. CALL AGAIN THIS FUNCTION TO GET ORGINAL DATA\n");
		ret = 1;
	}
	return ret;
}
