OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

main.exe: main.o treeOfSizes.o
	g++ -o ./main.exe ./main.o ./treeOfSizes.o
	rm *.o

main.o: main.cc
	g++ -c  $(OPCIONS) ./main.cc

treeOfSizes.o: treeOfSizes.cc
	g++ -c  $(OPCIONS) ./treeOfSizes.cc

clean:
	rm *.o