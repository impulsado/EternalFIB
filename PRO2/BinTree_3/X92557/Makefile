OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

main.exe: main.o sortTree.o
	g++ -o ./main.exe ./main.o ./sortTree.o
	rm *.o

main.o: main.cc
	g++ -c  $(OPCIONS) ./main.cc

sortTree.o: sortTree.cc
	g++ -c  $(OPCIONS) ./sortTree.cc

clean:
	rm *.o