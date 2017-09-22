main: main.o Ciudadano.o Quirk.o Emmitter.o Transformation.o Mutant.o
	g++ main.o Ciudadano.o Quirk.o Emmitter.o Transformation.o Mutant.o -o main

main.o: main.cpp Ciudadano.h Quirk.h Emmitter.h Transformation.h Mutant.h
	g++ -c main.cpp

Ciudadano.o: Ciudadano.cpp Ciudadano.h Quirk.h
	g++ -c Ciudadano.cpp

Quirk.o: Quirk.cpp Quirk.h
	g++ -c Quirk.cpp

Emmitter.o: Emmitter.cpp Emmitter.h Quirk.h
	g++ -c Emmitter.cpp

Transformation.o: Transformation.cpp Transformation.h Quirk.h
	g++ -c Transformation.cpp

Mutant.o: Mutant.cpp Mutant.h Quirk.h
	g++ -c Mutant.cpp
