SINGLE = $(PWD)/meta-ds/single_linklist/src/single_ll.o 
DOUBLE = $(PWD)/meta-ds/double_linklist/src/double_ll.o
DOUBLE_OPT = $(PWD)/meta-ds/double_linklist_opt/src/double_ll.o
STACK = $(PWD)/meta-ds/stack/src/stack_array.o
BST = $(PWD)/meta-ds/bst_tree/src/bst.o

#INCLUDE = -I ./meta-ds/single_linklist/include/*.h

CFLAGS = -fPIC

all:
	$(MAKE) -C $(PWD)/meta-ds/single_linklist/
	$(MAKE) -C $(PWD)/meta-ds/double_linklist/
	$(MAKE) -C $(PWD)/meta-ds/double_linklist_opt/
	$(MAKE) -C $(PWD)/meta-ds/stack/
	$(MAKE) -C $(PWD)/meta-ds/bst_tree/

lib : ${SINGLE} ${DOUBLE} ${DOUBLE_OPT} ${STACK} ${BST}
	${CC} -shared -o libDataStructure.so ${SINGLE} ${DOUBLE} ${DOUBLE_OPT} ${STACK} ${BST} ${CFLAGS}

clean:
	$(MAKE) -C $(PWD)/meta-ds/single_linklist/ clean
	$(MAKE) -C $(PWD)/meta-ds/double_linklist/ clean
	$(MAKE) -C $(PWD)/meta-ds/double_linklist_opt/ clean
	$(MAKE) -C $(PWD)/meta-ds/stack/ clean
	$(MAKE) -C $(PWD)/meta-ds/bst_tree/ clean
