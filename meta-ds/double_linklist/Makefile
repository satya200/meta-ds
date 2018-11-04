.DEFAULT_GOAL := debug
# constants
MKDIR = mkdir -p
COPY = cp -r

LIB_DIR = ${libdir}
BIN_DIR = ${bindir}
ETC_DIR = ${sysconfdir}
INCLUDE_DIR = ${includedir}

LOCAL_IFLAGS = -I./include/ 
LOCAL_CFLAGS = -fPIC -Wall -Werror ${LOCAL_IFLAGS}
LOCAL_LFLAGS = 

TARGET = double_linklist

# objects
objs = src/main.o src/double_ll.o

%.o: %.c
	$(CC) -c $< -o $@ $(LOCAL_CFLAGS) ${GLOBAL_IFLAGS}

${TARGET}:${objs}
	${CC} $^ -o $@  ${LOCAL_LFLAGS} ${GLOBAL_LFLAGS}


.PHONY: install clean

#install: 
#	$(MKDIR) ${DESTDIR}${BIN_DIR}
#	$(MKDIR) ${DESTDIR}${ETC_DIR}
#	$(COPY) ${TARGET} ${DESTDIR}${BIN_DIR}
#	$(MKDIR) ${DESTDIR}${INCLUDE_DIR}
#	$(COPY) ./include/* ${DESTDIR}${INCLUDE_DIR}

clean:
	$(RM) ${objs} 
	$(RM) ${TARGET}

debug: LOCAL_CFLAGS += -g -DDEBUG 
debug: LOCAL_LFLAGS += -g -DDEBUG 
debug: ${TARGET}

all: ${TARGET}

