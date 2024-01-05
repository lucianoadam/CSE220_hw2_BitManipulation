
CFLAGS = -g -Wall -Wextra -Wshadow -Wdouble-promotion -Wformat=2 -Wundef -DDEBUG


all: integers

integers: integers.o
	gcc -o integers integers.o
	 
integers.o: integers.c
	gcc $(CFLAGS) ${EXTRA_CFLAGS} ${INCD} -c integers.c

clean:
	rm -fr integers

.PHONY: all test