all: libds lltest stacktest qtest

libds: gentype.h linkedlist.h linkedlist.c stack.h stack.c queue.h queue.c
	gcc -c linkedlist.c queue.c stack.c
	ar rcs lib/libds.a linkedlist.o queue.o stack.o
	rm *.o
	
lltest: libds ll-tests.c
	gcc ll-tests.c -Llib -lds -o lltest

stacktest: lib/libds.a stack-tests.c
	gcc stack-tests.c -Llib -lds -o stacktest

qtest: lib/libds.a queue-tests.c
	gcc queue-tests.c -Llib -lds -o qtest

clean:
	@rm -f *.o lltest stacktest qtest

cleanall: clean
	@rm -f lib/libds.a