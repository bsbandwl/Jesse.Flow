objects= flow.o getImage.o

flow:$(objects)
	g++ -o flow $(objects) `pkg-config --libs opencv` -g
getImage.o:getImage.h getImage.cpp 
	g++ -c getImage.cpp `pkg-config --cflags opencv` -g
flow.o:flow.cpp flow.h
	g++ -c flow.cpp -g
.PHONY:clean,run
clean:
	rm flow *.o
run:flow
	./flow