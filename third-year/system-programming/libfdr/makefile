CFLAGS = -O

all: libfdr.a

OBJS = dllist.o fields.o jval.o jrb.o

libfdr.a: $(OBJS)
	ar ru libfdr.a $(OBJS)
	ranlib libfdr.a 

clean:
	rm -f core *.o libfdr.a

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $*.c

