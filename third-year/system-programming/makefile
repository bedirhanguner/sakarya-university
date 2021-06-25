CLASSDIR = .
INCLUDE = -I$(CLASSDIR)/libfdr
LIBS = $(CLASSDIR)/libfdr/libfdr.a
CC = gcc
OBJS = $(CLASSDIR)/libfdr/dllist.o $(CLASSDIR)/libfdr/fields.o $(CLASSDIR)/libfdr/jval.o $(CLASSDIR)/libfdr/jrb.o
CFLAGS = -O

EX = libfdr.a	main
all: $(EX) 

cleanall:
	$(MAKE) clean
	rm  -f *.txt .kilit kripto encrypted decrypted

clean:
	rm -f kripto
	rm -f *.o 
	rm -f core $(CLASSDIR)/libfdr/*.o $(CLASSDIR)/libfdr/libfdr.a

run:
	$(MAKE) all
	./kripto -e ornek_metin.txt encrypted
	./kripto -d encrypted decrypted
	$(MAKE) clean

libfdr.a: $(OBJS)
	ar ru $(CLASSDIR)/libfdr/libfdr.a $(OBJS)
	ranlib $(CLASSDIR)/libfdr/libfdr.a 

main: main.o $(LIBS)
	$(CC) $(INCLUDE) -o kripto main.o $(LIBS)

main.o:
	$(CC) $(INCLUDE) -g  -c  main.c

dllist.o:
	$(CC) $(CFLAGS) -c $(CLASSDIR)/libfdr/dllist.c

fields.o:
	$(CC) $(CFLAGS) -c $(CLASSDIR)/libfdr/fields.c

jval.o:
	$(CC) $(CFLAGS) -c $(CLASSDIR)/libfdr/jval.c

jrb.o:
	$(CC) $(CFLAGS) -c $(CLASSDIR)/libfdr/jrb.c
