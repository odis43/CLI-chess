CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = chess
OBJECTS = AI.o Bishop.o Board.o Chess.o Human.o King.o Knight.o Level1.o Main.o Move.o Observer.o Pawn.o Piece.o Player.o Queen.o Rook.o Subject.o TextDisplay.o Tile.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
