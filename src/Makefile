OBJS= uimain.o tokenizer.o history.o





CFLAGS=-g -O3



all: uimain



uimain:$(OBJS)

	cc -o uimain $(CFLAGS) $(OBJS)







$(OBJS): tokenizer.h history.h



clean:

	rm -f *.o uimain



run:uimain

	./uimain
