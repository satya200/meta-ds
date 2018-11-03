#include <single_head.h>

FILE *log_fp = NULL;

int insert_last(single_ll_t **head, int data)
{
	log_fp = stdout;
	single_ll_t *new_node = NULL;

	if (head == NULL) {
		ERR_PRINT("%s:%d :head value is NULL\n",__FUNCTION__,__LINE__);
		return -1;
	}
	if (*head == NULL) {
		DBG_PRINT("Fast Node insert\n");
		(*head) = malloc(sizeof(single_ll_t));
		if (*head == NULL) {
			ERR_PRINT("%s:%d: malloc fail\n",__FUNCTION__,__LINE__);
			return -2;
		}
		(*head)->next = NULL;
		(*head)->data = data;
		
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
			new_node->data = data;
			(*head)->next = new_node;
			
		}
	}
	return 0;
}

int insert_fast(single_ll_t **head, int data)
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
		(*head)->data = data;
	} else {
		new_node = malloc(sizeof(single_ll_t));
		if (new_node == NULL) {
			ERR_PRINT("%s:%d: malloc fail\n",__FUNCTION__,__LINE__);
			return -2;
		}
		new_node->data = data;
		new_node->next = (*head);
		(*head) = new_node;
	}
	return 0;
}

int insert_sort()
{
	return 0;
}

int insert_middle(single_ll_t *head, int node, int data)
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

	new_node->data = data;
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
		DBG_PRINT("In trav:%d:data:%d\n",(*temp_last)->data, temp->data);
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
		//temp = (*head);
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
			DBG_PRINT("last node:%d\n",temp->data);
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
			DBG_PRINT("data:%d:data:%d\n",temp->data, temp->data);
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
		DATA_PRINT("| %d |",temp->data);
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

int find_middle_node(single_ll_t *head, single_ll_t **temp)
{
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
		temp_1_move = temp_1_move->next;
		temp_2_move = temp_2_move->next->next;
	}
	(*temp) = temp_1_move;
	DBG_PRINT("middle node:%d\n",(*temp)->data);
	return 0;
}

int find_loop()
{
	return 0;
}

int find_node_from_last(single_ll_t *temp, int node, single_ll_t **temp_last)
{
	if (temp == NULL || temp_last == NULL) {
		ERR_PRINT("%s:%dParameter NULL\n",__FUNCTION__,__LINE__);
		return -1;
	}
	(*temp_last) = temp;
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
