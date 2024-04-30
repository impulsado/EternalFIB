OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

main.exe: main.o reverseTree.o
	g++ -o main.exe main.o reverseTree.o

main.o: main.cc
	g++ -c main.cc $(OPCIONS)

reverseTree.o: reverseTree.cc reverseTree.hh
	g++ -c reverseTree.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe