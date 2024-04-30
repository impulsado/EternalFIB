OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

main.exe: main.o searchInBST.o
	g++ -o main.exe main.o searchInBST.o

main.o: main.cc
	g++ -c main.cc $(OPCIONS)

searchInBST.o: searchInBST.cc searchInBST.hh
	g++ -c searchInBST.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe