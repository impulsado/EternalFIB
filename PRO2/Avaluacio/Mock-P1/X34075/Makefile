OPTIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

main.exe: main.o treeOfEvaluations.o
	g++ -o ./main.exe ./main.o ./treeOfEvaluations.o
	rm *.o

main.o: main.cc
	g++ -c $(OPTIONS) ./main.cc

treeOfEvaluations.o: treeOfEvaluations.cc
	g++ -c $(OPTIONS) ./treeOfEvaluations.cc