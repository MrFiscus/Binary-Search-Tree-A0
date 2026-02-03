CC := g++
INCLUDE_DIRS := .
CFLAGS := -I$(INCLUDE_DIRS)

OBJS := bst.o mainbst.o
DEPS := bst.h

.PHONY: clean all run

all: bst

clean:
	del $(OBJS) bst.exe

bst.o: bst.cpp $(DEPS)
	$(CC) -c -o $@ $(CFLAGS) $<

mainbst.o: mainbst.cpp $(DEPS)
	$(CC) -c -o $@ $(CFLAGS) $<

bst: $(OBJS)
	$(CC) -o bst.exe $^ $(CFLAGS)

run: bst
	.\bst.exe
