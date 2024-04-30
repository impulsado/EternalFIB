OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

main.exe: main.o evaluate.o
	g++ -o main.exe main.o evaluate.o
	rm *.o

main.o: main.cc evaluate.hh
	g++ -c main.cc $(OPCIONS)

evaluate.o: evaluate.cc evaluate.hh
	g++ -c evaluate.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch