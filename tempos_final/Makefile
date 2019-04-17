CC= gcc -Wall
LIBS = -lm
INCLUDES = -I ./

MAIN = ejecutable
SRCS = main.c matrizcuadradadinamica.c
DEPS = matrizcuadradadinamica.h
OBJS = $(SRCS:.c=.o)
	
$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS) $(LIBS)
%.o: %.c
	$(CC) -c $< $(INCLUDES)

cleanall: clean
	rm -f $(MAIN)
clean:
	rm -f *.o *~