#ifndef MAMIFERO_NATIVO_HPP
#define MAMIFERO_NATIVO_HPP

#include "mamifero.hpp"
#include "silvestre.hpp"
#include "nativo.hpp"

class mamifero_nativo: public mamifero, public animal_nativo
{

public:
	mamifero_nativo();
	mamifero_nativo(string nome_especie,string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta,string veterinario_responsavel, string tratador_responsavel, string cor_pelos, string cod_ibama, string origem, string auto_ibama);

	string registro_animal();

	~mamifero_nativo();
private:
	ostream& print(ostream &o) const;
	istream& insercao(istream &i);	

};

#endif
