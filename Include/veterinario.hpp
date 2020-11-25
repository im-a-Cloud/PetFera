#ifndef VETERINARIO_HPP
#define VETERINARIO_HPP

#include "funcionario.hpp"

class veterinario : public funcionario
{
private:
	string cod_CRMV;
public:
	veterinario();
	veterinario(string nome_funcionario, string sexo_funcionario, string funcao, int CPF, int idade, int id_funcionario, string cod_CRMV);

	void set_cod_CRMV(string cod_CRMV);

	string get_cod_CRMV();

	~veterinario();
private:
	ostream& print(ostream &o) const;
	istream& insercao(istream &i);
};
#endif