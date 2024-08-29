CFLAGS = -c -std=c++11 

EXECUTAVEL1 = app1
EXECUTAVEL2 = app2
EXECUTAVEL3 = app3

all : ${EXECUTAVEL1} ${EXECUTAVEL2} ${EXECUTAVEL3}

${EXECUTAVEL1}: app1.o Aplicacao.o Filme.o Cinema.o Endereco.o Programacao.o 
					@g++ app1.o Aplicacao.o Filme.o Cinema.o Endereco.o Programacao.o -o ${EXECUTAVEL1}

${EXECUTAVEL2}: app2.o Aplicacao.o Filme.o Cinema.o Endereco.o Programacao.o 
					@g++ app2.o Aplicacao.o Filme.o Cinema.o Endereco.o Programacao.o -o ${EXECUTAVEL2}

${EXECUTAVEL3}: app3.o Aplicacao.o Filme.o Cinema.o Endereco.o Programacao.o 
					@g++ app3.o Aplicacao.o Filme.o Cinema.o Endereco.o Programacao.o -o ${EXECUTAVEL3}

app1.o:  app1.cpp Aplicacao.hpp
		  	@g++ ${CFLAGS} app1.cpp

app2.o:  app2.cpp Aplicacao.hpp
		  	@g++ ${CFLAGS} app2.cpp

app3.o:  app3.cpp Aplicacao.hpp
		  	@g++ ${CFLAGS} app3.cpp

Aplicacao.o: 	Aplicacao.cpp Aplicacao.hpp Filme.hpp Cinema.hpp Programacao.hpp
					@g++ ${CFLAGS} Aplicacao.cpp

Programacao.o: 	Programacao.cpp Programacao.hpp Cinema.hpp Filme.hpp
					@g++ ${CFLAGS} Programacao.cpp

Filme.o: 	Filme.cpp Filme.hpp
				@g++ ${CFLAGS} Filme.cpp

Cinema.o: 	Cinema.cpp Cinema.hpp Endereco.hpp
				@g++ ${CFLAGS} Cinema.cpp

Endereco.o: 	Endereco.cpp Endereco.hpp
					@g++ ${CFLAGS} Endereco.cpp

run: 	all

clean: 
		@rm -f filmes.txt.out cinemas.txt.out Aplicacao.o Filme.o Cinema.o Endereco.o Programacao.o app1.o app2.o app3.o ${EXECUTAVEL1} ${EXECUTAVEL2} ${EXECUTAVEL3}