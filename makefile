main: main.o Ciudadano.o Estudiante.o Maestro.o Quirk.o Emmitter.o Transformation.o Mutant.o LinkedList.o
	g++ main.o Ciudadano.o Estudiante.o Maestro.o Quirk.o Emmitter.o Transformation.o Mutant.o LinkedList.o -o main

main.o: main.cpp Ciudadano.h Estudiante.h Maestro.h Quirk.h Emmitter.h Transformation.h Mutant.h LinkedList.h
	g++ -c main.cpp

LinkedList.o: LinkedList.cpp LinkedList.h Ciudadano.h Quirk.h Emmitter.h Transformation.h Mutant.h
		g++ -c LinkedList.cpp

Ciudadano.o: Ciudadano.cpp Ciudadano.h Quirk.h
	g++ -c Ciudadano.cpp

Estudiante.o: Estudiante.cpp Estudiante.h Ciudadano.h Maestro.h
	g++ -c Estudiante.cpp

Maestro.o: Maestro.cpp Maestro.h Ciudadano.h Estudiante.h LinkedList.h
	g++ -c Maestro.cpp

Quirk.o: Quirk.cpp Quirk.h
	g++ -c Quirk.cpp

Emmitter.o: Emmitter.cpp Emmitter.h Quirk.h
	g++ -c Emmitter.cpp

Transformation.o: Transformation.cpp Transformation.h Quirk.h
	g++ -c Transformation.cpp

Mutant.o: Mutant.cpp Mutant.h Quirk.h
	g++ -c Mutant.cpp

clean:
	rm *.o main
