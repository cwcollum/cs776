ga: geneticAlg.o util.o population.o individual.o
	g++ -o ga geneticAlg.o util.o population.o individual.o -g
util.o: util.cpp util.h
	g++ -c util.cpp -g
geneticAlgorithm.o: geneticAlg.cpp
	g++ -c geneticAlg.cpp -g
population.o: population.cpp population.h
	g++ -c population.cpp -g
individual.o: individual.cpp individual.h
	g++ -c individual.cpp -g
clean:
	rm *.o ga