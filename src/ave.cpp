#include "ave.hpp"

ave::ave(){}

ave::ave(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao,string dieta, string veterinario_responsavel, string tratador_responsavel, string formato_bico):animal(nome_especie, nome_batismo, classe, sexo, tipo, risco_extincao, dieta, veterinario_responsavel, tratador_responsavel), formato_bico(formato_bico){

}

void ave::set_formato_bico(string formato_bico){
	this->formato_bico = formato_bico;
}
string ave::get_formato_bico(){
	return this->formato_bico;
}

ostream& ave::print(ostream &o) const{
	o << "------------------Dados do animal------------------" <<endl;
	o << " Especie do animal: " << this->nome_especie << endl;
	o << " Nome do animal: " << this->nome_batismo << endl;
	o << " Classe do animal: "<< this-> classe << endl;
	o << " Sexo do animal: " << this->sexo << endl;
	o << " tipo(nativo, exotico, domestico):" << this->tipo << endl;
	o << " corre risco de extinção: " << this->risco_extincao << endl;
  	o << " A dieta do animal consiste em :" <<this->dieta <<endl;
	o << " Formato do bico da ave: " << this->formato_bico <<endl;
	o << " Veterinário responsável pelo animal: " << this->veterinario_responsavel <<endl;
  	o << " Tratador do animal: " << this-> tratador_responsavel <<endl;
	return o;
}

istream& ave::insercao(istream &i){
	i >> nome_especie >> nome_batismo >> classe	 >> sexo >> risco_extincao >> dieta >> veterinario_responsavel >> tratador_responsavel >> formato_bico;
	return i;
}

ave::~ave(){}
