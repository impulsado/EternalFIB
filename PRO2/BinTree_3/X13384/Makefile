OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

main.exe: main.o treeOfHeights.o
	g++ -o ./main.exe ./main.o ./treeOfHeights.o
	rm *.o

main.o: main.cc
	g++ -c  $(OPCIONS) ./main.cc

treeOfHeights.o: treeOfHeights.cc
	g++ -c  $(OPCIONS) ./treeOfHeights.cc

clean:
	rm *.o