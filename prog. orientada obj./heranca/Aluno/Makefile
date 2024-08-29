# Makefile (Roland Teodorowitsch; 27 out. 2019)

EXECUTAVEL=app
CFLAGS=-c -std=c++11

all:		${EXECUTAVEL}

${EXECUTAVEL}:	Aluno.o AlunoRegular.o AlunoFinanciado.o main.o
		@g++ Aluno.o AlunoRegular.o AlunoFinanciado.o main.o -o ${EXECUTAVEL}

main.o:		main.cpp
		@g++ ${CFLAGS} main.cpp

Aluno.o:	Aluno.cpp Aluno.hpp
		@g++ ${CFLAGS} Aluno.cpp

AlunoRegular.o:	AlunoRegular.cpp AlunoRegular.hpp Aluno.hpp
		@g++ ${CFLAGS} AlunoRegular.cpp

AlunoFinanciado.o:	AlunoFinanciado.cpp AlunoFinanciado.hpp Aluno.hpp
		@g++ ${CFLAGS} AlunoFinanciado.cpp

run:		${EXECUTAVEL}
		@./${EXECUTAVEL}

clean:
		@rm -f Aluno.o AlunoRegular.o AlunoFinanciado.o main.o ${EXECUTAVEL}