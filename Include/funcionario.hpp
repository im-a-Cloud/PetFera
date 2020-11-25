#ifndef FUNCIONARO_HPP
#define FUNCIONARO_HPP

#include <string>
#include <iostream>

using namespace std;

class funcionario
{
protected:
	string nome_funcionario;
	string sexo_funcionario;
	string funcao; //se ele é um veterinário ou um tratador;
	int CPF;
	int idade;
	int id_funcionario;
public:
	funcionario();
	funcionario(string nome_funcionario, string sexo_funcionario, string funcao, int CPF, int idade, int id_funcionario);

	void set_nome_funcionario(string nome_funcionario);
	void set_sexo_funcionario(string sexo_funcionario);
	void set_funcao(string funcao);
	void set_CPF(int CPF);
	void set_idade(int idade);
	void set_id_funcionario(int id_funcionario);
  
  string get_nivel_seguranca();
  
	string get_nome_funcionario();
	string get_sexo_funcionario();
	string get_funcao();
	int get_CPF();
	int get_idade();
	int get_id_funcionario();

	friend ostream& operator<< (ostream &o, funcionario const &func);
	friend istream& operator>> (istream &i, funcionario &func);
	
	virtual	~funcionario();

private:
	//metodos para fazer a inserção e o print com os operadores sobrecarregados
	virtual ostream& print(ostream &o) const = 0;
	virtual istream& insercao(istream &i) = 0;

	friend class veterinario;
	friend class tratador;
};

#endif