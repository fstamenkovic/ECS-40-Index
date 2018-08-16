p8.out: main.o pager.o indexpager.o
	g++ -g -Wall -ansi -o p8.out main.o pager.o indexpager.o

main.o: main.cpp indexpager.h pager.h
	g++ -ansi -Wall -c main.cpp

pager.o: pager.cpp pager.h indexpager.h
	g++ -ansi -Wall -c pager.cpp

indexpager: indexpager.cpp indexpager.h pager.h
	g++ -ansi -Wall -c indexpager.cpp

clean:
	rm -f p8.out main.o pager.o indexpager.o
