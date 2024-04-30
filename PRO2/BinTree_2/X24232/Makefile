OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

main.exe: main.o removeAll.o
	g++ -o main.exe main.o removeAll.o
	rm *.o

main.o: main.cc removeAll.hh
	g++ -c main.cc $(OPCIONS)

removeAll.o: removeAll.cc removeAll.hh
	g++ -c removeAll.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch