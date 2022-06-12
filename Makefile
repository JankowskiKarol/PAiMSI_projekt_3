
TRGDIR=./
OBJ=./obj
FLAGS= -Wall -pedantic -std=c++14 -iquote inc

__start__: ${TRGDIR}/sortowania
	${TRGDIR}/sortowania

${TRGDIR}/sortowania: ${OBJ} ${OBJ}/main.o ${OBJ}/Game_support.o\
                     ${OBJ}/Options_to_winning.o ${OBJ}/Min-Max.o ${OBJ}/Game_status.o\
					 ${OBJ}/Positions_status.o
	g++ -o ${TRGDIR}/sortowania ${OBJ}/main.o ${OBJ}/Game_support.o\
                     ${OBJ}/Options_to_winning.o ${OBJ}/Min-Max.o ${OBJ}/Game_status.o\
					 ${OBJ}/Positions_status.o
${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/Positions_status.hh inc/Game_status.hh inc/Game_support.hh inc/Options_to_winning.hh inc/Min-Max.hh
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/Min-Max.o: src/Min-Max.cpp inc/Min-Max.hh
	g++ -c ${FLAGS} -o ${OBJ}/Min-Max.o src/Min-Max.cpp

${OBJ}/Positions_status.o: src/Positions_status.cpp inc/Positions_status.hh inc/Min-Max.hh
	g++ -c ${FLAGS} -o ${OBJ}/Positions_status.o src/Positions_status.cpp

${OBJ}/Game_support.o: src/Game_support.cpp inc/Game_support.hh inc/Min-Max.hh 
	g++ -c ${FLAGS} -o ${OBJ}/Game_support.o src/Game_support.cpp

${OBJ}/Game_status.o: src/Game_status.cpp inc/Game_status.hh inc/Positions_status.hh
	g++ -c ${FLAGS} -o ${OBJ}/Game_status.o src/Game_status.cpp

${OBJ}/Options_to_winning.o: src/Options_to_winning.cpp inc/Options_to_winning.hh inc/Min-Max.hh
	g++ -c ${FLAGS} -o ${OBJ}/Options_to_winning.o src/Options_to_winning.cpp


clean:
	rm -f ${TRGDIR}/test_arytm_zesp ${OBJ}/*
