OPTIONS = "-D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers"

main.exe: execute.o main.o
	g++ -o ./main.exe ./main.o ./execute.o $(OPTIONS)
	rm *.o

main.o:
	g++ -c ./main.cc $(OPTIONS)

execute.o:
	g++ -c ./execute.cc $(OPTIONS)

clean:
	rm *.exe
	rm *.o