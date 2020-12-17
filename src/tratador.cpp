#include "tratador.hpp"

tratador::tratador(){}

tratador::tratador(string nome_funcionario, string sexo_funcionario, string funcao, int CPF, int idade, int id_funcionario, string nivel_seguranca):funcionario(nome_funcionario, sexo_funcionario, funcao, CPF, idade, id_funcionario, nivel_seguranca){

}

void tratador::set_nivel_seguranca(string nivel_seguranca){
	this-> nivel_seguranca = nivel_seguranca;
}

string tratador::get_nivel_seguranca(){
	return this-> nivel_seguranca;
}

string tratador::registro_funcionario(){
	string data_save;
	string separador = ";";
	data_save = nome_funcionario + separador + sexo_funcionario + separador + funcao + separador + to_string(CPF) + separador + to_string(idade) + separador + to_string(id_funcionario) +  separador + nivel_seguranca;
	return data_save;
}

ostream& tratador::print(ostream &o) const{
	o << "-------------------Dados do funcionário-------------------" <<endl;
	o << "O nome do funcionário é: " <<this->nome_funcionario <<endl;
	o << "O sexo do funcionário é: " <<this->sexo_funcionario <<endl;
	o << "O funcionário é: " <<this->funcao <<endl;
	o << "O CPF do funcionário é: " <<this->CPF <<endl;
	o << "A idade do funcionário é: " <<this->idade <<endl;
	o << "O id do funcionário é: " <<this->id_funcionario <<endl;
	o << "O nível de segurança do funcionário é: "<< this-> nivel_seguranca <<endl;
	return o;
}

istream& tratador::insercao(istream &i){
	i >> nome_funcionario >> sexo_funcionario >> funcao >> CPF >> idade >> id_funcionario >> nivel_seguranca;
	return i;
}
tratador::~tratador(){}