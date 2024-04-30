OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

main.exe: main.o sumOfTree.o
	g++ -o main.exe main.o sumOfTree.o

main.o: main.cc
	g++ -c main.cc $(OPCIONS)

sumOfTree.o: sumOfTree.cc sumOfTree.hh
	g++ -c sumOfTree.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe