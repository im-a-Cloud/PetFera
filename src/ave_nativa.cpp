#include "ave_nativa.hpp"

ave_nativo::ave_nativo(){

}

ave_nativo::ave_nativo(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta, string veterinario_responsavel, string tratador_responsavel, string formato_bico, string cod_ibama, string origem, string auto_ibama):ave(nome_especie, nome_batismo, classe, sexo, tipo, risco_extincao, dieta, veterinario_responsavel, tratador_responsavel, formato_bico), animal_nativo(cod_ibama, origem, auto_ibama) {

}


ostream& ave_nativo::print(ostream &o)const {
	o << "------------------Dados do animal------------------" <<endl;
	o << " Especie do animal: " << this->nome_especie << endl;
	o << " Nome do animal: " << this->nome_batismo << endl;
	o << " Classe do animal: "<< this-> classe << endl;
	o << " Sexo do animal: " << this->sexo << endl;
	o << " Tipo(nativo, exotico, domestico):" << this->tipo << endl;
	o << " Corre risco de extinção: " << this->risco_extincao << endl;
 	o << " A dieta do animal consiste em :" <<this->dieta <<endl;
	o << " Formato do bico da ave: " << this->formato_bico <<endl;
	o << " Veterinário responsável pelo animal: " << this->veterinario_responsavel <<endl;
  	o << " Tratador do animal: " << this-> tratador_responsavel <<endl;
	o << " Codigo IBAMA : " << this->cod_ibama <<endl;
	o << " Origem :" <<this->origem <<endl;
	o << " Autorização IBAMA: " << this->auto_ibama <<endl;
	return o;
}

istream& ave_nativo::insercao(istream &i){
	i >> nome_especie >> nome_batismo >> classe >> sexo >> tipo >> risco_extincao>> dieta >> veterinario_responsavel >> tratador_responsavel >>  formato_bico >> cod_ibama >> origem >> auto_ibama;
	return i;
}

ave_nativo::~ave_nativo(){
	
}