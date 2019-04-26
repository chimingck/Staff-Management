main.o: main.cpp staff_management.cpp staff_management.h
	g++ -c main.cpp

staff_mamagement.o: staff_management.cpp staff_management.h
	g++ -c staff_management.cpp

main: main.o staff_management.o
	g++ main.o staff_management.o -o main

clean:
	rm main staff_management.o main.o

.PHONY: clean