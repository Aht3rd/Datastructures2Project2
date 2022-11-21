CXXFLAGS = -g -Wall -std=c++11 -Werror=return-type -Werror=uninitialized
CXX = g++

OBJECTS = main.o customer.o queue.o analytics.o heap.o

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o main $(OBJECTS)

main.o: main.cpp heap.hpp
customer.o: customer.cpp customer.hpp
queue.o: queue.cpp queue.hpp customer.cpp
analytics.o: analytics.cpp analytics.hpp
heap.o: heap.cpp heap.hpp customer.hpp queue.hpp analytics.hpp

.PHONY : clean
clean: 
	rm main $(OBJECTS) 
