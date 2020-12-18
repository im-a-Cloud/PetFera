# Compiler
CC = g++

INC = ./Include
SRC = ./src
OBJ = ./build
BIN = ./bin

CPPFLAGS = -O0 -Wall -pedantic -std=c++11 -I$(INC)
OBJECTS = $(OBJ)/anfibio.o $(OBJ)/anfibio_exotico.o $(OBJ)/anfibio_nativo.o $(OBJ)/animal.o $(OBJ)/ave.o $(OBJ)/ave_exotica.o  $(OBJ)/ave_nativa.o $(OBJ)/exotico.o $(OBJ)/funcionario.o $(OBJ)/funcoes.o $(OBJ)/mamifero.o $(OBJ)/mamifero_exotico.o $(OBJ)/mamifero_nativo.o $(OBJ)/nativo.o $(OBJ)/reptil.o $(OBJ)/reptil_exotico.o $(OBJ)/reptil_nativo.o $(OBJ)/silvestre.o $(OBJ)/tratador.o $(OBJ)/veterinario.o $(OBJ)/main.o 
PROG = $(BIN)/petfera

all: $(OBJECTS) $(BIN)/petfera
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJECTS)

$(OBJ)/anfibio.o: $(INC)/anfibio.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/anfibio.cpp -o $@

$(OBJ)/anfibio_exotico.o: $(INC)/anfibio_exotico.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/anfibio_exotico.cpp -o $@

$(OBJ)/anfibio_nativo.o: $(INC)/anfibio_nativo.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/anfibio_nativo.cpp -o $@

$(OBJ)/animal.o: $(INC)/animal.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/animal.cpp -o $@

$(OBJ)/ave.o: $(INC)/ave.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/ave.cpp -o $@

$(OBJ)/ave_exotica.o: $(INC)/ave_exotica.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/ave_exotica.cpp -o $@

$(OBJ)/ave_nativa.o: $(INC)/ave_nativa.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/ave_nativa.cpp -o $@

$(OBJ)/exotico.o: $(INC)/exotico.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/exotico.cpp -o $@

$(OBJ)/funcionario.o: $(INC)/funcionario.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/funcionario.cpp -o $@

$(OBJ)/funcoes.o: $(INC)/funcoes.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/funcoes.cpp -o $@

$(OBJ)/mamifero.o: $(INC)/mamifero.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/mamifero.cpp -o $@

$(OBJ)/mamifero_exotico.o: $(INC)/mamifero_exotico.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/mamifero_exotico.cpp -o $@

$(OBJ)/mamifero_nativo.o: $(INC)/mamifero_nativo.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/mamifero_nativo.cpp -o $@

$(OBJ)/nativo.o: $(INC)/nativo.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/nativo.cpp -o $@

$(OBJ)/reptil.o: $(INC)/reptil.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/reptil.cpp -o $@

$(OBJ)/reptil_nativo.o: $(INC)/reptil_nativo.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/reptil_nativo.cpp -o $@

$(OBJ)/reptil_exotico.o: $(INC)/reptil_exotico.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/reptil_exotico.cpp -o $@

$(OBJ)/silvestre.o: $(INC)/silvestre.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/silvestre.cpp -o $@

$(OBJ)/tratador.o: $(INC)/tratador.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/tratador.cpp -o $@

$(OBJ)/veterinario.o: $(INC)/veterinario.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/veterinario.cpp -o $@

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@	

$(BIN)/petfera: $(OBJ)/main.o
	$(CC) $(CPPFLAGS) $(OBJECTS) -o $@

clean:
	rm -f $(PROG) $(OBJECTS) 
