#ifndef FUNCOES_HPP
#define FUNCOES_HPP

#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

#include "animal.hpp"

#include "anfibio.hpp"
#include "anfibio_nativo.hpp"
#include "anfibio_exotico.hpp"

#include "ave.hpp"
#include "ave_nativa.hpp"
#include "ave_exotica.hpp"

#include "mamifero.hpp"
#include "mamifero_exotico.hpp"
#include "mamifero_nativo.hpp"

#include "reptil.hpp"
#include "reptil_nativo.hpp"
#include "reptil_exotico.hpp"

#include "silvestre.hpp"
#include "nativo.hpp"
#include "exotico.hpp"

#include "funcionario.hpp"
#include "veterinario.hpp"
#include "tratador.hpp"

using namespace std;


void cadastrar_animal(string classe_animal, string tipo_animal);
void alterar_dados_animal(string classe_animal, string nome_batismo);
void remover_animal(string nome_animal, string nome_batismo);
void listar_animais_por_classe(string classe_animal);

void cadastrar_funcionario(string funcao_funcionario);
void mostrar_funcionarios();

bool checa_veterinario(string nome_vet);
bool checa_tratador(string nome_trat);
bool checa_nivel_seguranca(string nome_trat, string nivel_nescessario);

void carregar_animais();
void carregar_funcionarios();

void salvar_funcionario();

void salvar_animal(); //debug

void menu();

void menu_opcoes();

string converte_num_para_classe_animal(int opcao);

string converte_num_para_tipo_animal(int opcao);

string deixar_minusculo(string texto);

int code_to_num(string code);

void listar_animais_por_tratador(string nome_tratador);

void listar_todos_animais();

#endif