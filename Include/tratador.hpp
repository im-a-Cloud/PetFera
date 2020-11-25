#ifndef TRATADOR_HPP
#define TRATADOR_HPP

#include "funcionario.hpp"

class tratador: public funcionario
{
private:
	string nivel_seguranca;
public:
	tratador();
	tratador(string nome_funcionario, string sexo_funcionario, string funcao, int CPF, int idade, int id_funcionario, string nivel_seguranca);

	void set_nivel_seguranca(string nivel_seguranca);

	string get_nivel_seguranca();

	~tratador();
private:
	virtual ostream& print(ostream &o) const;
	virtual istream& insercao(istream &i);
	
};

#endif
