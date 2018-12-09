SINGLE = $(PWD)/meta-ds/single_linklist/src/single_ll.o 
DOUBLE = $(PWD)/meta-ds/double_linklist/src/double_ll.o
DOUBLE_OPT = $(PWD)/meta-ds/double_linklist_opt/src/double_ll.o
STACK = $(PWD)/meta-ds/stack/src/stack_array.o

#INCLUDE = -I ./meta-ds/single_linklist/include/*.h

CFLAGS = -fPIC

all:
	$(MAKE) -C $(PWD)/meta-ds/single_linklist/
	$(MAKE) -C $(PWD)/meta-ds/double_linklist/
	$(MAKE) -C $(PWD)/meta-ds/double_linklist_opt/
	$(MAKE) -C $(PWD)/meta-ds/stack/

lib : ${SINGLE} ${DOUBLE} ${DOUBLE_OPT} ${STACK}
	${CC} -shared -o libDataStructure.so ${SINGLE} ${DOUBLE} ${DOUBLE_OPT} ${STACK} ${CFLAGS}

clean:
	$(MAKE) -C $(PWD)/meta-ds/single_linklist/ clean
	$(MAKE) -C $(PWD)/meta-ds/double_linklist/ clean
	$(MAKE) -C $(PWD)/meta-ds/double_linklist_opt/ clean
	$(MAKE) -C $(PWD)/meta-ds/stack/ clean
