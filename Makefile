CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -MMD
EXEC = transcribe
OBJECTS = transcribe.o keys.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${DEPENDS} ${OBJECTS} ${EXEC}
