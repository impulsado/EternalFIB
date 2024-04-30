OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

main.exe: main.o maximumTree.o
	g++ -o main.exe main.o maximumTree.o

main.o: main.cc
	g++ -c main.cc $(OPCIONS)

maximumTree.o: maximumTree.cc maximumTree.hh
	g++ -c maximumTree.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe