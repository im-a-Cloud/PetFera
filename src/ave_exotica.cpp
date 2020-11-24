#include "ave_exotica.hpp"

ave_exotico::ave_exotico(){

}

ave_exotico::ave_exotico(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta, string veterinario_responsavel, string tratador_responsavel, string formato_bico, string cod_ibama, string pais_origem):ave(nome_especie, nome_batismo, classe, sexo, tipo, risco_extincao, dieta, veterinario_responsavel, tratador_responsavel, formato_bico), animal_exotico(cod_ibama, pais_origem) {

}

ostream& ave_exotico::print(ostream &o)const {
	o << "------------------Dados do animal------------------" <<endl;
	o << " Especie do animal: " << this->nome_especie << endl;
	o << " Nome do animal: " << this->nome_batismo << endl;
	o << " Classe do animal: "<< this-> classe << endl;
	o << " Sexo do animal: " << this->sexo << endl;
	o << " Tipo(exotico, exotico, domestico):" << this->tipo << endl;
	o << " Corre risco de extinção: " << this->risco_extincao << endl;
 	o << " A dieta do animal consiste em :" <<this->dieta <<endl;
	o << " Formato do bico da ave: " << this->formato_bico <<endl;
	o << " Veterinário responsável pelo animal: " << this->veterinario_responsavel <<endl;
  	o << " Tratador do animal: " << this-> tratador_responsavel <<endl;
	o << " Codigo do IBAMA : " << this->cod_ibama <<endl;
	o << " País de origem :" <<this->pais_origem <<endl;
	return o;
}

istream& ave_exotico::insercao(istream &i){
	i >>nome_especie >> nome_batismo >> classe >> sexo >> tipo >> risco_extincao >> dieta >> veterinario_responsavel >> tratador_responsavel >> formato_bico >> cod_ibama>> pais_origem;
	return i;
}

ave_exotico::~ave_exotico(){
	
}