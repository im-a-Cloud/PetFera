#include "mamifero_nativo.hpp"

mamifero_nativo::mamifero_nativo(){

}

mamifero_nativo::mamifero_nativo(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta,string veterinario_responsavel, string tratador_responsavel, string cor_pelos, string cod_ibama, string origem, string auto_ibama):mamifero(nome_especie, nome_batismo, classe, sexo, tipo, risco_extincao, dieta, veterinario_responsavel, tratador_responsavel, cor_pelos), animal_nativo(cod_ibama, origem, auto_ibama) {

}

ostream& mamifero_nativo::print(ostream &o)const {
	o << "------------------Dados do animal------------------" <<endl;
	o << " Especie do animal: " << this->nome_especie << endl;
	o << " Nome do animal: " << this->nome_batismo << endl;
	o << " Classe do animal: "<< this-> classe << endl;
	o << " Sexo do animal: " << this->sexo << endl;
	o << " Tipo(nativo, exotico, domestico):" << this->tipo << endl;
	o << " Corre risco de extinção: " << this->risco_extincao << endl;
 	o << " A dieta do animal consiste em :" <<this->dieta <<endl;
	o << " A cor do pelo é: " << this->cor_pelos <<endl;
	o << " Codigo IBAMA : " << this->cod_ibama <<endl;
	o << " Veterinário responsável pelo animal: " << this->veterinario_responsavel <<endl;
  	o << " Tratador do animal: " << this-> tratador_responsavel <<endl;
	o << " Origem :" <<this->origem <<endl;
	o << " Autorização IBAMA: " << this->auto_ibama <<endl;
	return o;
}

istream& mamifero_nativo::insercao(istream &i){
	i >> nome_especie >> nome_batismo >> classe >> sexo >> tipo >> risco_extincao>> dieta >> veterinario_responsavel >> tratador_responsavel >> cor_pelos >> cod_ibama >> origem >> auto_ibama;
	return i;
}

mamifero_nativo::~mamifero_nativo(){
	
}