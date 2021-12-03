echo_test: main.o Echo.o WaveFileManager.o 
	g++ -o echo_test main.o Echo.o WaveFileManager.o
	
main.o: main.cpp
	g++ -c main.cpp
	
Echo.o: Echo.cpp Echo.h
	g++ -c Echo.cpp Echo.h
	
WaveFileManager.o: WaveFileManager.cpp WaveFileManager.h
	g++ -c WaveFileManager.cpp WaveFileManager.h
	
make clean:
	rm *.o echo_test
