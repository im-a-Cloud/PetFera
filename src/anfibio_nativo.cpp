#include "anfibio_nativo.hpp"

anfibio_nativo::anfibio_nativo(){

}

anfibio_nativo::anfibio_nativo(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta, string veterinario_responsavel, string tratador_responsavel, string venenoso, string cod_ibama, string origem, string auto_ibama):anfibio(nome_especie, nome_batismo, classe, sexo, tipo, risco_extincao, dieta, veterinario_responsavel, tratador_responsavel, venenoso), animal_nativo(cod_ibama, origem, auto_ibama) {

}

string anfibio_nativo::registro_animal(){
	string data_save;
	string separador = ";";
	data_save = nome_especie + separador + nome_batismo + separador + classe + separador + sexo + separador + tipo + separador + risco_extincao + separador + dieta + separador + veterinario_responsavel + separador + tratador_responsavel + separador + venenoso + separador + cod_ibama +separador + origem+ separador + auto_ibama;
	return data_save;
}

ostream& anfibio_nativo::print(ostream &o)const {
	o << "------------------Dados do animal------------------" <<endl;
	o << " Especie do animal: " << this->nome_especie << endl;
	o << " Nome do animal: " << this->nome_batismo << endl;
	o << " Classe do animal: "<< this-> classe << endl;
	o << " Sexo do animal: " << this->sexo << endl;
	o << " Tipo(nativo, exotico, domestico):" << this->tipo << endl;
	o << " Corre risco de extinção: " << this->risco_extincao << endl;
 	o << " A dieta do animal consiste em :" <<this->dieta <<endl;
	o << " Venenoso:" << this->venenoso <<endl;
	o << " Veterinário responsável pelo animal: " << this->veterinario_responsavel <<endl;
  	o << " Tratador do animal: " << this-> tratador_responsavel <<endl;
	o << " Codigo IBAMA : " << this->cod_ibama <<endl;
	o << " Origem :" <<this->origem <<endl;
	o << " Autorização IBAMA: " << this->auto_ibama <<endl;
	return o;
}

istream& anfibio_nativo::insercao(istream &i){
	i >> nome_especie >> nome_batismo >> classe >> sexo >> tipo >> risco_extincao>> dieta >> veterinario_responsavel >> tratador_responsavel >> venenoso >> cod_ibama >> origem >> auto_ibama;
	return i;
}

anfibio_nativo::~anfibio_nativo(){
	
}