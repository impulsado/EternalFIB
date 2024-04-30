OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

main.exe: main.o numLeftRight.o
	g++ -o main.exe main.o numLeftRight.o
	rm *.o

main.o: main.cc numLeftRight.hh
	g++ -c main.cc $(OPCIONS)

numLeftRight.o: numLeftRight.cc numLeftRight.hh
	g++ -c numLeftRight.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch