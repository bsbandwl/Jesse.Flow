objects= flow.o getImage.o

flow:flow.o getImage.o
	g++ -o flow $(objects) `pkg-config --libs opencv`
getImage.o:getImage.h getImage.cpp
	g++ -c getImage.cpp `pkg-config --cflags opencv`
.PHONY:clean,run
clean:
	rm flow *.o
run:flow
	./flow