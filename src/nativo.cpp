#include "nativo.hpp"

animal_nativo::animal_nativo(){}

animal_nativo::animal_nativo(string cod_ibama, string origem, string auto_ibama):animal_silvestre(cod_ibama), origem(origem), auto_ibama(auto_ibama){

}

void animal_nativo::set_origem(string origem){
	this->origem = origem;
}

void animal_nativo::set_auto_ibama(string auto_ibama){
	this->auto_ibama = auto_ibama;
}

string animal_nativo::get_origem(){
	return this->origem;
}

string animal_nativo::get_auto_ibama(){
	return this->auto_ibama;
}

animal_nativo::~animal_nativo(){}