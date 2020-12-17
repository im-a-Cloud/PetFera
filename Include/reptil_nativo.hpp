#ifndef REPTIL_NATIVO_HPP
#define REPTIL_NATIVO_HPP

#include "reptil.hpp"
#include "silvestre.hpp"
#include "nativo.hpp"

class reptil_nativo: public reptil, public animal_nativo
{

public:
	reptil_nativo();
	reptil_nativo(string nome_especie,string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta,string veterinario_responsavel, string tratador_responsavel, string venenoso, string tipo_pele, string cod_ibama, string origem, string auto_ibama);

    string registro_animal();

	~reptil_nativo();
private:
	ostream& print(ostream &o) const;
	istream& insercao(istream &i);	

};

#endif
