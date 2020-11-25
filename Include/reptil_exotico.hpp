#ifndef REPTIL_EXOTICO_HPP
#define REPTIL_EXOTICO_HPP

#include "reptil.hpp"
#include "silvestre.hpp"
#include "exotico.hpp"

class reptil_exotico: public reptil, public animal_exotico
{

public:
	reptil_exotico();
	reptil_exotico(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta,string veterinario_responsavel, string tratador_responsavel, string venenoso, string tipo_pele, string cod_ibama, string pais_origem);

	~reptil_exotico();
private:
	ostream& print(ostream &o) const;
	istream& insercao(istream &i);	

};

#endif
