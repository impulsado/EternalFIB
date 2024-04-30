OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

main.exe: main.o sumAtDepthEven.o
	g++ -o main.exe main.o sumAtDepthEven.o
	rm *.o

main.o: main.cc sumAtDepthEven.hh
	g++ -c main.cc $(OPCIONS)

sumAtDepthEven.o: sumAtDepthEven.cc sumAtDepthEven.hh
	g++ -c sumAtDepthEven.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch