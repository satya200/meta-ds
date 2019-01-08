.DEFAULT_GOAL := debug
# constants
MKDIR = mkdir -p
COPY = cp -r


LOCAL_IFLAGS = -I./include/ 
LOCAL_CFLAGS = -fPIC -Wall -Werror -lDataStructure ${LOCAL_IFLAGS}
LOCAL_LFLAGS = 

TARGET = bst

# objects
objs = src/app.o src/bst.o

%.o: %.c
	$(CC) -c $< -o $@ $(LOCAL_CFLAGS) ${GLOBAL_IFLAGS} -lDataStructure

${TARGET}:${objs}
	${CC} $^ -o $@  ${LOCAL_LFLAGS} ${GLOBAL_LFLAGS} -lDataStructure


.PHONY: install clean

clean:
	$(RM) ${objs} 
	$(RM) ${TARGET}

debug: LOCAL_CFLAGS += -g -DDEBUG 
debug: LOCAL_LFLAGS += -g -DDEBUG 
debug: ${TARGET}

all: ${TARGET}

