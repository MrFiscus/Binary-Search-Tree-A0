CC := g++
INCLUDE_DIRS := .
CFLAGS := -I$(INCLUDE_DIRS)

OBJS := bst.o mainbst.o customErrorClass.o
DEPS := bst.h customErrorClass.h

.PHONY: clean all run

all: bst

bst: $(OBJS)
	$(CC) -o bst.exe $^ $(CFLAGS)

bst.o: bst.cpp bst.h customErrorClass.h
	$(CC) -c -o $@ $(CFLAGS) $<

mainbst.o: mainbst.cpp bst.h customErrorClass.h
	$(CC) -c -o $@ $(CFLAGS) $<

customErrorClass.o: customErrorClass.cpp customErrorClass.h
	$(CC) -c -o $@ $(CFLAGS) $<

run: bst
	.\bst.exe

clean:
	del *.o *.exe
