OPTIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

main.exe: main.o evaluate.o
	g++ -o ./main.exe ./main.o ./evaluate.o
	rm *.o

main.o: main.cc
	g++ -c $(OPTIONS) ./main.cc

evaluate.o: evaluate.cc
	g++ -c $(OPTIONS) ./evaluate.cc