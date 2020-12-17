#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

using namespace std;

class animal
{
protected:
	
	string nome_especie;   // nome da especie do animal, por exemplo lobo, cobra, cachorro e assim por diante
	string nome_batismo; // nome dado para o animal pelos donos,etc.
	string classe; // qual classe do animal (mamifero, ave, etc).
	string sexo; //sexo do animal.
	string tipo; //se ele é um nativo, exotico, domestico.
	string risco_extincao; //se o animal está ou não em risco de extinção; //se ele é perigoso de alguma forma
	string dieta; // oque ele come
	string veterinario_responsavel;
	string tratador_responsavel;

public:
	animal();
	animal(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta, string veterinario_responsavel, string tratador_responsavel); //construtor parametrizado

	//metodos getters e setters
	string get_nome_especie();
	string get_nome_batismo();
	string get_classe();
	string get_sexo();
	string get_tipo();
	string get_risco();
	string get_dieta();
	string get_veterinario_responsavel();
	string get_tratador_responsavel();

	string registro_animal();
  void alterar_animal();
    
	void set_nome_especie(string nome_especie);
	void set_nome_batismo(string nome_batismo);
	void set_classe(string classe);
	void set_sexo(string sexo);
	void set_tipo(string tipo);
	void set_risco(string risco);
	void set_dieta(string dieta);
	void set_veterinario_responsavel(string veterinario_responsavel);
	void set_tratador_responsavel(string tratador_responsavel);



	//sobrecarga dos operadores de extração e insersção
	friend ostream& operator<< (ostream &o, animal const &ani);
	friend istream& operator>> (istream &i, animal &ani);
	
	virtual	~animal(); //

private:
	//metodos para fazer a inserção e o print com os operadores sobrecarregados, virtuais para as classes poderem ter 
	virtual ostream& print(ostream &o) const = 0;
	virtual istream& insercao(istream &i) = 0;
};
#endif
