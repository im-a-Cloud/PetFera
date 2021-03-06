#include "anfibio_exotico.hpp"

anfibio_exotico::anfibio_exotico(){

}

anfibio_exotico::anfibio_exotico(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta, string veterinario_responsavel, string tratador_responsavel, string venenoso, string cod_ibama, string pais_origem):anfibio(nome_especie, nome_batismo, classe, sexo, tipo, risco_extincao, dieta, veterinario_responsavel, tratador_responsavel, venenoso), animal_exotico(cod_ibama, pais_origem) {

}
//função para registrar um animal, no caso um anfibio exotico, com separadores para inserir no arquivo, todas as outras classes de animal tem isso e de forma semelhante, apenas com seus atributos unicos
string anfibio_exotico::registro_animal(){
	string data_save;
	string separador = ";";
	data_save = nome_especie + separador + nome_batismo + separador + classe + separador + sexo + separador + tipo + separador + risco_extincao + separador +  dieta + separador + veterinario_responsavel + separador + tratador_responsavel + separador + venenoso + separador + cod_ibama + separador + pais_origem;
	return data_save;
}

ostream& anfibio_exotico::print(ostream &o)const {
	o << "------------------Dados do animal------------------" <<endl;
	o << " Especie do animal: " << this->nome_especie << endl;
	o << " Nome do animal: " << this->nome_batismo << endl;
	o << " Classe do animal: "<< this->classe << endl;
	o << " Sexo do animal: " << this->sexo << endl;
	o << " Tipo(nativo, exotico, domestico):" << this->tipo << endl;
	o << " Corre risco de extinção: " << this->risco_extincao << endl;
   	o << " A dieta do animal consiste em :" <<this->dieta <<endl;
	o << " Venenoso:" << this->venenoso <<endl;
	o << " Veterinário responsável pelo animal: " << this->veterinario_responsavel <<endl;
  	o << " Tratador do animal: " << this-> tratador_responsavel <<endl;
	o << " Codigo do IBAMA : " << this->cod_ibama <<endl;
	o << " País de origem :" <<this->pais_origem <<endl;
	return o;
}

istream& anfibio_exotico::insercao(istream &i){
	i >>nome_especie >> nome_batismo >> classe >> sexo >> tipo >> risco_extincao >> dieta >> veterinario_responsavel >> tratador_responsavel >> venenoso >>cod_ibama>> pais_origem;
	return i;
}

anfibio_exotico::~anfibio_exotico(){
	
}