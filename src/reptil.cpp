#include "reptil.hpp"

reptil::reptil(){}

reptil::reptil(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao,string dieta,string veterinario_responsavel, string tratador_responsavel, string venenoso, string tipo_pele):animal(nome_especie, nome_batismo, classe, sexo, tipo, risco_extincao, dieta, veterinario_responsavel, tratador_responsavel), venenoso(venenoso), tipo_pele(tipo_pele){

}

void reptil::set_venenoso(string venenoso){
	this->venenoso = venenoso;
}
void reptil::set_tipo_pele(string tipo_pele){
	this->tipo_pele = tipo_pele;
}
string reptil::get_venenoso(){
	return this->venenoso;
}
string reptil::get_tipo_pele(){
	return this->tipo_pele;
}

string reptil::registro_reptil(){
	string data_save;
	string separador = ";";
	data_save = nome_especie + separador + nome_batismo + separador + classe + separador + sexo + separador + tipo + separador+ risco_extincao + separador + dieta + separador + veterinario_responsavel + separador + tratador_responsavel + separador + venenoso + separador + tipo_pele;
	return data_save;
}

ostream& reptil::print(ostream &o) const{
	o << "------------------Dados do animal------------------" <<endl;
	o << " Especie do animal: " << this->nome_especie << endl;
	o << " Nome do animal: " << this->nome_batismo << endl;
	o << " Classe do animal: "<< this-> classe << endl;
	o << " Sexo do animal: " << this->sexo << endl;
	o << " tipo(nativo, exotico, domestico):" << this->tipo << endl;
	o << " corre risco de extinção: " << this->risco_extincao << endl;
  	o << " A dieta do animal consiste em :" <<this->dieta <<endl;
	o << " Veterinário responsável pelo animal: " << this->veterinario_responsavel <<endl;
  	o << " Tratador do animal: " << this-> tratador_responsavel <<endl;
	o << " O animal é venenoso?: " << this->venenoso <<endl;
	o << " O tipo de pele dele é:" <<this->tipo_pele <<endl;	
	return o;
}

istream& reptil::insercao(istream &i){
	i >> nome_especie >> nome_batismo >> classe	 >> sexo >> risco_extincao >> dieta >> veterinario_responsavel >> tratador_responsavel >> venenoso >> tipo_pele;
	return i;
}

reptil::~reptil(){}
