#include "funcionario.hpp"

funcionario::funcionario(){}

funcionario::funcionario(string nome_funcionario, string sexo_funcionario, string funcao, int CPF, int idade, int id_funcionario, string nivel_seguranca): 
nome_funcionario(nome_funcionario), sexo_funcionario(sexo_funcionario), funcao(funcao), CPF(CPF), idade(idade), id_funcionario(id_funcionario),nivel_seguranca(nivel_seguranca){}

void funcionario::set_nome_funcionario(string nome_funcionario){
	this->nome_funcionario = nome_funcionario;
}
void funcionario::set_sexo_funcionario(string sexo_funcionario){
	this->sexo_funcionario = sexo_funcionario;
}
void funcionario::set_funcao(string funcao){
	this->funcao = funcao;
}
void funcionario::set_CPF(int CPF){
	this->CPF = CPF;
}
void funcionario::set_idade(int idade){
	this->idade = idade;
}
void funcionario::set_id_funcionario(int id_funcionario){
	this->id_funcionario = id_funcionario;
}

string funcionario::get_nome_funcionario(){
	return this->nome_funcionario;
}
string funcionario::get_sexo_funcionario(){
	return this->sexo_funcionario;
}
string funcionario::get_funcao(){
	return this->funcao;
}
int funcionario::get_CPF(){
	return this->CPF;
}
int funcionario::get_idade(){
	return this->idade;
}
int funcionario::get_id_funcionario(){
	return this->id_funcionario;
}

string funcionario::get_nivel_seguranca(){
  return "sem nível";
}


ostream& operator<<(ostream &o, funcionario const &func){ 
	return func.print(o);
}

istream& operator>>(istream &i, funcionario &func){ 
	return func.insercao(i);
}

/*
string registro_funcionario(){
	string data_save;
	string separador = ";";
	data_save = nome_funcionario + separador + sexo_funcionario + separador + funcao + separador + to_string(CPF) + separador + to_string(idade) + separador + to_string(id_funcionario);
	return data_save;
}
*/

ostream& funcionario::print(ostream &o) const{
  /*
	o << "-------------------Dados do funcionário-------------------" <<endl;
	o << "O nome do funcionário é: " <<this->nome_funcionario <<endl;
	o << "O sexo do funcionário é: " <<this->sexo_funcionario <<endl;
	o << "O funcionário é: " <<this->funcao <<endl;
	o << "O CPF do funcionário é: " <<this->CPF <<endl;
	o << "A idade do funcionário é: " <<this->idade <<endl;
	o << "O id do funcionário é: " <<this->id_funcionario <<endl;
  */
	return o;

}

istream& funcionario::insercao(istream &i){
	i >> nome_funcionario >> sexo_funcionario >> funcao >> CPF >> idade >> id_funcionario;
	return i;
}
funcionario::~funcionario(){}