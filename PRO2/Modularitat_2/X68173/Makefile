main.exe: program.o Estudiant.o Cjt_estudiants.o
	p2++ -o ./main.exe ./program.o ./Estudiant.o ./Cjt_estudiants.o
	rm *.o

program.o: program.cc Estudiant.hh Cjt_estudiants.hh
	p2++ -c program.cc

Estudiant.o: Estudiant.cc Estudiant.hh
	p2++ -c Estudiant.cc

Cjt_estudiants.o: Cjt_estudiants.cc Cjt_estudiants.hh
	p2++ -c Cjt_estudiants.cc