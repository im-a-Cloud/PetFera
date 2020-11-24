#include "anfibio.hpp"
#include "animal.hpp"

anfibio::anfibio(){

}

anfibio::anfibio(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta, string veterinario_responsavel, string tratador_responsavel, string venenoso):animal(nome_especie, nome_batismo, classe, sexo, tipo, risco_extincao, dieta, veterinario_responsavel, tratador_responsavel), venenoso(venenoso) {

}

void anfibio::set_venenoso(string venenoso){
	this->venenoso = venenoso;
}
string anfibio::get_venenoso(){
	return this->venenoso;
}

ostream& anfibio::print(ostream &o) const{
	o << "------------------Dados do animal------------------" <<endl;
	o << " Especie do animal: " << this->nome_especie << endl;
	o << " Nome do animal: " << this->nome_batismo << endl;
	o << " Classe do animal: "<< this-> classe << endl;
	o << " Sexo do animal: " << this->sexo << endl;
	o << " tipo(nativo, exotico, domestico):" << this->tipo << endl;
	o << " corre risco de extinção: " << this->risco_extincao << endl;
  	o << " A dieta do animal consiste em :" <<this->dieta <<endl;
	o << " Venenoso:" << this->venenoso <<endl;
	o << " Veterinário responsável pelo animal: " << this->veterinario_responsavel <<endl;
  	o << " Tratador do animal: " << this-> tratador_responsavel <<endl;
	return o;
}

istream& anfibio::insercao(istream &i){
	i >> nome_especie >> nome_batismo >> classe	 >> sexo >> risco_extincao >> dieta >> veterinario_responsavel >> tratador_responsavel >> venenoso;
	return i;
}

anfibio::~anfibio(){
	
}