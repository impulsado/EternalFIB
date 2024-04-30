OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

main.exe: main.o evaluate.o utils.o
	g++ -o main.exe main.o evaluate.o utils.o

main.o: main.cc
	g++ -c main.cc $(OPCIONS)

evaluate.o: evaluate.cc evaluate.hh
	g++ -c evaluate.cc $(OPCIONS)

utils.o: utils.cc utils.hh
	g++ -c utils.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe