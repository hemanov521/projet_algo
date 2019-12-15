#makefile du projet d'informatique P17 S5

CC = gcc
CFLAGS = -c -lm -Wall -g
LD = gcc
LDFLAGS = 
RM = rm
RMFLAGS = -rf

.PHONY: clean deepclean

menu: Menu.o FoncCoord.o FoncReponse.o FunctionTCP.o
	$(LD) $(LDFLAGS) $^ -o $@

#Menu.o: Menu.c declaration.h
Menu.o: Menu.c #FoncCoord.h FoncReponse.h FunctionTCP.h
	$(CC) $(CFLAGS) $<

FoncCoord.o: FoncCoord.c FoncCoord.h
	$(CC) $(CFLAGS) $<

FoncReponse.o: FoncReponse.c FoncReponse.h
	$(CC) $(CFLAGS) $<

FunctionTCP.o: FunctionTCP.c FunctionTCP.h
	$(CC) $(CFLAGS) $<

clean:
	$(RM) $(RMFLAGS) *.o

deepclean: clean
	$(RM) $(RMFLAGS) menu