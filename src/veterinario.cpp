#include "veterinario.hpp"

veterinario::veterinario(){}

veterinario::veterinario(string nome_funcionario, string sexo_funcionario, string funcao, int CPF, int idade, int id_funcionario, string nivel_seguranca, string cod_CRMV):funcionario(nome_funcionario, sexo_funcionario, funcao, CPF, idade, id_funcionario, nivel_seguranca), cod_CRMV(cod_CRMV){

}

void veterinario::set_cod_CRMV(string cod_CRMV){
	this-> cod_CRMV = cod_CRMV;
}

string veterinario::get_cod_CRMV(){
	return this-> cod_CRMV;
}

string veterinario::registro_funcionario(){
	string data_save;
	string separador = ";";
	data_save = nome_funcionario + separador + sexo_funcionario + separador + funcao + separador + to_string(CPF) + separador + to_string(idade) + separador + to_string(id_funcionario) + separador + nivel_seguranca + separador + cod_CRMV;
	return data_save;
}

string veterinario::get_nivel_seguranca(){
    return "não tem carai";
}

ostream& veterinario::print(ostream &o) const{
	o << "-------------------Dados do funcionário-------------------" <<endl;
	o << "O nome do funcionário é: " <<this->nome_funcionario <<endl;
	o << "O sexo do funcionário é: " <<this->sexo_funcionario <<endl;
	o << "O funcionário é: " <<this->funcao <<endl;
	o << "O CPF do funcionário é: " <<this->CPF <<endl;
	o << "A idade do funcionário é: " <<this->idade <<endl;
	o << "O id do funcionário é: " <<this->id_funcionario <<endl;
	o << "O código CRMV do veterinário é: " << this-> cod_CRMV <<endl;
	return o;
}

istream& veterinario::insercao(istream &i){
	i >> nome_funcionario >> sexo_funcionario >> funcao >> CPF >> idade >> id_funcionario >> cod_CRMV;
	return i;
}
veterinario::~veterinario(){}