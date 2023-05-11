run: main.o
	g++ -o main main.o
	./main

main.o: main.cpp avl.h functions.h
	g++ -c main.cpp
	

clean: 
	rm *.o main