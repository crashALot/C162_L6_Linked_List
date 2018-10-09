#target: dependencies
#	rule to build

# Work cited: https://askubuntu.com/questions/433943/how-to-clean-executable-using-make-clean
# 	      https://www.cs.bu.edu/teaching/cpp/writing-makefiles/

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g
CXXFLAGS += -Wall 
#CXXFLAGS += -O3
#CXXFLAGS += -pedantic-errors
#LDFLAGS = -lboost_date_time

OBJS = circularList.o listMenu.o mainCircular.o menuValidate.o
SRCS = circularList.cpp listMenu.cpp mainCircular.cpp menuValidate.cpp
HEADERS = circularList.hpp listMenu.hpp menuValidate.hpp
list: ${OBJS}
	${CXX} ${CXXFLAGS} -o list circularList.o listMenu.o mainCircular.o menuValidate.o
mainCircular.o: mainCircular.cpp ${HEADERS}
	${CXX} ${CXXFLAGS} -c circularList.cpp listMenu.cpp mainCircular.cpp menuValidate.cpp

clean: ${OBJS}
	-rm *.o ${OBJS} list
