main.o: main.cpp staff_mamagement.cpp staff_mamagement.h
	g++ -c main.cpp

staff_mamagement.o: staff_mamagement.cpp staff_mamagement.h
	g++ -c staff_mamagement.cpp

main: main.o staff_mamagement.o
	g++ main.o staff_mamagement.o -o main

clean:
	rm main staff_mamagement.o main.o

.PHONY: clean