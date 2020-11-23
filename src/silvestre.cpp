#include "silvestre.hpp"

animal_silvestre::animal_silvestre(){}

animal_silvestre::animal_silvestre(string cod_ibama): cod_ibama(cod_ibama){

}
void animal_silvestre::set_cod_ibama(string cod_ibama){
	this->cod_ibama=cod_ibama;
}
string animal_silvestre::get_cod_ibama(){
	return this->cod_ibama;
}

animal_silvestre::~animal_silvestre(){}