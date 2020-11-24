#include "exotico.hpp"

animal_exotico::animal_exotico(){}

animal_exotico::animal_exotico(string cod_ibama, string pais_origem):animal_silvestre(cod_ibama), pais_origem(pais_origem){

}
void animal_exotico::set_pais_origem(string pais_origem){
	this->pais_origem = pais_origem;
}

string animal_exotico::get_pais_origem(){
	return this->pais_origem;
}
animal_exotico::~animal_exotico(){}