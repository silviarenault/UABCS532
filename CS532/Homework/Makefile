CC = gcc
CFLAGS = -Wall -g #replace -g with -O when not debugging
DEPS     = Makefile
OBJS     = silvia_HW02.o
EXECS    = silvia_HW02
 
all:	$(EXECS)
 
%.o:	%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
 
search:	$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
 
clean:
	/bin/rm -i *.o $(EXECS)