OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

main.exe: main.o SumBelowAtEvenDepth.o
	g++ -o ./main.exe ./main.o ./SumBelowAtEvenDepth.o
	rm *.o

main.o: main.cc
	g++ -c  $(OPCIONS) ./main.cc

SumBelowAtEvenDepth.o: SumBelowAtEvenDepth.cc
	g++ -c  $(OPCIONS) ./SumBelowAtEvenDepth.cc

clean:
	rm *.o