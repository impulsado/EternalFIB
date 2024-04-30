OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

main.exe: main.o treeOfSumsOfAncestors.o
	g++ -o main.exe main.o treeOfSumsOfAncestors.o
	rm *.o

main.o: main.cc treeOfSumsOfAncestors.hh BinTree.hh
	g++ -c main.cc $(OPCIONS)

treeOfSumsOfAncestors.o: treeOfSumsOfAncestors.cc BinTree.hh treeOfSumsOfAncestors.hh
	g++ -c treeOfSumsOfAncestors.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
