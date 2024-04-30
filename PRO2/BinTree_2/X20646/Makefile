OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o ParInt.o BinTreeIOParInt.o
	g++ -o program.exe program.o ParInt.o BinTreeIOParInt.o
	rm *.o

program.o: program.cc ParInt.hh BinTreeIOParInt.hh BinTree.hh
	g++ -c program.cc $(OPCIONS)

ParInt.o: ParInt.cc ParInt.hh
	g++ -c ParInt.cc $(OPCIONS)

BinTreeIOParInt.o: BinTreeIOParInt.cc BinTree.hh BinTreeIOParInt.hh ParInt.hh
	g++ -c BinTreeIOParInt.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
