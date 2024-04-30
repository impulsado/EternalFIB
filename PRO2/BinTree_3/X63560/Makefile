OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

main.exe: main.o treeOfSums.o
	g++ -o ./main.exe ./main.o ./treeOfSums.o
	rm *.o

main.o: main.cc
	g++ -c  $(OPCIONS) ./main.cc

treeOfSums.o: treeOfSums.cc
	g++ -c  $(OPCIONS) ./treeOfSums.cc

clean:
	rm *.o