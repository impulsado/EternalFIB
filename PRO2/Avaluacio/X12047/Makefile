OPTIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

main.exe: main.o numberOfLeaves.o
	g++ -o ./main.exe ./main.o ./numberOfLeaves.o
	rm *.o

main.o: main.cc
	g++ -c $(OPTIONS) ./main.cc

numberOfLeaves.o: numberOfLeaves.cc
	g++ -c $(OPTIONS) ./numberOfLeaves.cc