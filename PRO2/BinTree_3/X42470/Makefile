OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: program.o BinTreeIOint.o
	g++ -o ./program.exe ./program.o ./BinTreeIOint.o
	rm *.o

program.o: program.cc
	g++ -c  $(OPCIONS) ./program.cc

BinTreeIOint.o: BinTreeIOint.cc
	g++ -c  $(OPCIONS) ./BinTreeIOint.cc

clean:
	rm *.o