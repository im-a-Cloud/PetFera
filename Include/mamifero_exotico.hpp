#ifndef MAMIFERO_EXOTICO_HPP
#define MAMIFERO_EXOTICO_HPP

#include "mamifero.hpp"
#include "silvestre.hpp"
#include "exotico.hpp"

class mamifero_exotico: public mamifero, public animal_exotico
{

public:
	mamifero_exotico();
	mamifero_exotico(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta,string veterinario_responsavel, string tratador_responsavel, string formato_bico, string cod_ibama, string pais_origem);

	~mamifero_exotico();
private:
	ostream& print(ostream &o) const;
	istream& insercao(istream &i);	

};

#endif
