from ctypes import CDLL

struct data {
        int data;
};

struct stack_user {
        size_t stack_size;
        int stack_idx;
        struct data *data;
        //struct stack_operation sop;
};

struct stack_user user
 
slibc = './libDataStructure.so'
hlibc = CDLL(slibc)
 
iret = 
print iret
