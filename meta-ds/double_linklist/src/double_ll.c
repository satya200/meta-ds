/*
* AUTHOR: Satya Sundar Sahu
* mail id:- tinkusahu.com@gmail.com
*/

#include <double_head.h>

static FILE *log_fp = NULL;

int dll_insert_last(double_ll_t **head, struct Data data)
{
	log_fp = stdout;
	double_ll_t *new_node = NULL;

	if (head == NULL) {
		ERR_PRINT("%s:%d :head value is NULL\n",__FUNCTION__,__LINE__);
		return -1;
	}
	if (*head == NULL) {
		DBG_PRINT("Fast Node insert\n");
		(*head) = malloc(sizeof(double_ll_t));
		if (*head == NULL) {
			ERR_PRINT("%s:%d: malloc fail\n",__FUNCTION__,__LINE__);
			return -2;
		}
		(*head)->next = NULL;
		(*head)->prev = NULL;
		memcpy(&((*head)->data), &data, sizeof(data));
		
	} else {
		DBG_PRINT("%s:Insert last node\n",__FUNCTION__);

		if ((*head)->next != NULL) {
			ERR_PRINT("head not in last node. Please send last node address\n");
			return -3;
		}

		new_node = malloc(sizeof(double_ll_t));
		if (new_node == NULL) {
			ERR_PRINT("%s:%d malloc fail\n",__FUNCTION__,__LINE__);
			return -2;
		} else {
			new_node->next = NULL;
			new_node->prev = (*head);
			memcpy(&(new_node->data), &data, sizeof(data));
			(*head)->next = new_node;
			
		}
	}
	return 0;
}

int dll_insert_fast(double_ll_t **head, struct Data data)
{
	log_fp = stdout;
	double_ll_t *new_node = NULL;

	if (head == NULL) {
		ERR_PRINT("%s:%d :head value is NULL\n",__FUNCTION__,__LINE__);
		return -1;
	}
	if (*head == NULL) {
		DBG_PRINT("%s:fast node insert\n",__FUNCTION__);

		(*head) = malloc(sizeof(double_ll_t));
		if (*head == NULL) {
			ERR_PRINT("%s:%d: malloc fail\n",__FUNCTION__,__LINE__);
			return -2;
		}
		(*head)->next = NULL;
		(*head)->prev = NULL;
		memcpy(&((*head)->data), &data, sizeof(data));
	} else {
		new_node = malloc(sizeof(double_ll_t));
		if (new_node == NULL) {
			ERR_PRINT("%s:%d: malloc fail\n",__FUNCTION__,__LINE__);
			return -2;
		}
		memcpy(&(new_node->data), &data, sizeof(data));
		new_node->prev = NULL;
		new_node->next = (*head);
		(*head)->prev = new_node;
		(*head) = new_node;
	}
	return 0;
}

int dll_insert_sort()
{
	/* TODO */
	return 0;
}

int dll_insert_middle(double_ll_t *head, int node, struct Data data)
{
	int ret = -1;
	double_ll_t *temp = NULL,
		    *new_node = NULL;


	if (head == NULL) {
		ERR_PRINT("%s:%d: NULL pointer\n",__FUNCTION__,__LINE__);
		return -1;
	}
	if (node > 1) {
		temp = head;
		ret = dll_traverse_list(head, node - 1, &temp);
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
	new_node = (double_ll_t *)malloc(sizeof(double_ll_t));
	if (new_node == NULL) {
		ERR_PRINT("%s:%d: malloc fail\n",__FUNCTION__,__LINE__);
		return -2;
	}

	memcpy(&(new_node->data), &data, sizeof(data));
	new_node->next = temp->next;
	new_node->prev = temp;
	temp->next->prev = new_node;
	temp->next = new_node;

	return 0;
}

int dll_traverse_list(double_ll_t *temp, int node_cnt, double_ll_t **temp_last)
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

int dll_del_list(double_ll_t **head, int node_idx, int pos)
{
	double_ll_t *temp = NULL;
	double_ll_t *temp_free = NULL;
	int ret = -1;

	if ((head == NULL) && (*head == NULL)) {
		ERR_PRINT("%s:NULL pointer\n",__FUNCTION__);
		return -1;
	}
	temp = (*head);
	if (pos == 1) {
		DBG_PRINT("Going to delete fast node\n");
		if ((*head)->next == NULL) {
			free(*head);
			(*head) = NULL;
			return 0;
		}
		(*head) = (*head)->next;
		(*head)->prev = NULL;
		free(temp);
		temp = NULL;
		
	} else if (pos == 2) {
		DBG_PRINT("Going to delete last node\n");
		ret = dll_find_node_from_last(*head, 2, &temp);
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
		ret = dll_traverse_list(*head, node_idx - 1, &temp);
		if (ret == -1) {
			ERR_PRINT("%s:Ret error in traverse_list()\n",__FUNCTION__);
			return -2;
		}
		if (temp) {
			DBG_PRINT("data:%d:data:%d\n",temp->data.data, temp->data.data);
			temp_free = temp->next;
			if (temp->next) {
				temp->next = temp->next->next;
				temp->next->prev = temp;
			}
			if (temp_free) {
				free(temp_free);
				temp_free = NULL;
			}
		}
	} else { 
		ERR_PRINT("%s:Invalid parameter\n",__FUNCTION__);
		return -3;
	}
	return 0;
}

int dll_rev_list()
{
	/* TODO */
	return 0;
}

int dll_print_list(double_ll_t *head, int pos)
{
	double_ll_t *temp = NULL;
	int print_cnt = 1;
	int ret = -1;

	if (head == NULL && pos > 0) {
		ERR_PRINT("List is Empty.or invalid position\n");
		return -3;
	}
	if (pos == 2) {
		ret = dll_traverse_list(head, -1, &temp);
		if (ret == -1) {
			ERR_PRINT("In traverse_list() ret\n");
			return -2;
		}
	} else {
		DBG_PRINT("In fwd print\n");
		temp = head;
	}
	DATA_PRINT("--------------------------------------------\n");
	while (temp) {
		DATA_PRINT("| %d |",temp->data.data);
		if (pos == 1) {
			temp = temp->next;
		} else {
			temp = temp->prev;
		}
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

int dll_swap_adjusent_node(double_ll_t **head, int node_idx)
{
	double_ll_t *temp = NULL;
	double_ll_t *temp_prev = NULL;
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
		temp_prev->next->prev = temp_prev;
		temp_prev->prev = temp;
		temp->next = temp_prev;
		(*head) = temp;
		(*head)->prev = NULL;
	} else if (node_idx-1 > 0) {
		ret = dll_traverse_list(*head, node_idx - 2, &temp_prev);
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
		temp_prev->next->prev = temp_prev;
		temp->next = temp_prev->next->next;
		if (temp->next) {
			temp->next->prev = temp;
		}
		temp->prev = temp_prev->next;
		temp_prev->next->next = temp;
	} 
	return 0;
}

int dll_find_middle_node(double_ll_t *head, double_ll_t **temp)
{
	double_ll_t *temp_1_move = NULL;
	double_ll_t *temp_2_move = NULL;

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
	DBG_PRINT("middle node:%d\n",(*temp)->data.data);
	return 0;
}

int dll_find_loop()
{
	return 0;
}

int dll_find_node_from_last(double_ll_t *temp, int node, double_ll_t **temp_last)
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

int dll_check_loop(double_ll_t *head, double_ll_t **temp)
{
        double_ll_t *head_bak = NULL;

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

void dll_exist_list(double_ll_t **head)
{
	double_ll_t *temp = NULL;
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
