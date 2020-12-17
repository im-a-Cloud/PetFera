#include "mamifero.hpp"

mamifero::mamifero(){}

mamifero::mamifero(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao,string dieta,string veterinario_responsavel, string tratador_responsavel, string cor_pelos):animal(nome_especie, nome_batismo, classe, sexo, tipo, risco_extincao, dieta, veterinario_responsavel, tratador_responsavel), cor_pelos(cor_pelos){

}

void mamifero::set_cor_pelos(string cor_pelos){
	this->cor_pelos = cor_pelos;
}
string mamifero::get_cor_pelos(){
	return this->cor_pelos;
}

string mamifero::registro_animal(){
	string data_save;
	string separador = ";";
	data_save = nome_especie + separador + nome_batismo + separador + classe + separador + sexo + separador + tipo + separador + risco_extincao + separador + dieta + separador + veterinario_responsavel + separador + tratador_responsavel + separador + cor_pelos;
	return data_save;
}

ostream& mamifero::print(ostream &o) const{
	o << "------------------Dados do animal------------------" <<endl;
	o << " Especie do animal: " << this->nome_especie << endl;
	o << " Nome do animal: " << this->nome_batismo << endl;
	o << " Classe do animal: "<< this-> classe << endl;
	o << " Sexo do animal: " << this->sexo << endl;
	o << " tipo(nativo, exotico, domestico):" << this->tipo << endl;
	o << " corre risco de extinção: " << this->risco_extincao << endl;
  	o << " A dieta do animal consiste em :" <<this->dieta <<endl;
	o << " A cor do pelo é: " << this->cor_pelos <<endl;
	o << " Veterinário responsável pelo animal: " << this->veterinario_responsavel <<endl;
  	o << " Tratador do animal: " << this-> tratador_responsavel <<endl;
	return o;
}

istream& mamifero::insercao(istream &i){
	i >> nome_especie >> nome_batismo >> classe	 >> sexo >> risco_extincao >> dieta >> veterinario_responsavel >> tratador_responsavel >> cor_pelos;
	return i;
}

mamifero::~mamifero(){}
