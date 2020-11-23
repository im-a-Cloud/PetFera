#include "animal.hpp"

animal::animal(){}

animal::animal(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta, string veterinario_responsavel, string tratador_responsavel):nome_especie(nome_especie),nome_batismo(nome_batismo),  classe(classe), sexo(sexo), tipo(tipo), risco_extincao(risco_extincao), dieta(dieta), veterinario_responsavel(veterinario_responsavel), tratador_responsavel(tratador_responsavel) {

}

void animal::set_nome_especie(string nome_especie){
	this->nome_especie = nome_especie;
}

void animal::set_nome_batismo(string nome_batismo){
	this->nome_batismo = nome_batismo;
}

void animal::set_classe(string classe){
	this->classe = classe;
}
void animal::set_sexo(string sexo){
	this->sexo =sexo;
}
void animal::set_tipo(string tipo){
	this->tipo = tipo;
}
void animal::set_risco(string risco_extincao){
	this->risco_extincao = risco_extincao;
}
void animal::set_dieta(string dieta){
  this->dieta = dieta;
}
void animal::set_veterinario_responsavel(string veterinario_responsavel){
	this->veterinario_responsavel = veterinario_responsavel;	
}
void animal::set_tratador_responsavel(string tratador_responsavel){
	this->tratador_responsavel = tratador_responsavel;
}
string animal::get_nome_especie(){
	return this->nome_especie;
}
string animal::get_nome_batismo(){
	return this->nome_batismo;
}
string animal::get_classe(){
	return this->classe;
}
string animal::get_sexo(){
	return this->sexo;
}
string animal::get_tipo(){
	return this->tipo;
}
string animal::get_dieta(){
  return this->dieta;
}
string animal::get_veterinario_responsavel(){
	return this->veterinario_responsavel;
}
string animal::get_tratador_responsavel(){
	return this->tratador_responsavel;
}
ostream& operator<<(ostream &o, animal const &ani){ 
	return ani.print(o);
}
istream& operator>>(istream &i, animal &ani){ 
	return ani.insercao(i);
}
ostream& animal::print(ostream &o) const{
	o << "------------------Dados do animal------------------" <<endl;
	o << " Especie do animal: " << this->nome_especie << endl;
	o << " Nome do animal: " << this->nome_batismo << endl;
	o << " Classe do animal: "<< this-> classe << endl;
	o << " Sexo do animal: " << this->sexo << endl;
	o << " Tipo(nativo, exotico, domestico):" << this->tipo << endl;
	o << " Corre risco de extinção: " << this->risco_extincao << endl;
  	o << " A dieta do animal consiste em :" <<this->dieta <<endl;
  	o << " Veterinário repsonsável pelo animal: " << this->veterinario_responsavel <<endl;
  	o << " Tratador do animal: " << this-> tratador_responsavel <<endl;
	return o;
}

istream& animal::insercao(istream &i){
	i >>nome_especie >> nome_batismo >> classe >> sexo >> tipo >> risco_extincao >> dieta >> veterinario_responsavel >> tratador_responsavel;
	return i;
}
animal::~animal(){

}