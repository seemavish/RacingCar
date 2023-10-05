CC = g++
CFLAGS = -Wall -g

main.exe: main.o racingCar.o 
	$(CC) $(CFLAGS) -o main.exe main.o racingCar.o 

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp

racingCar.o: racingCar.cpp
	$(CC) $(CFLAGS) -c racingCar.cpp 

clean:
	rm -f *.o main.exe *.gch