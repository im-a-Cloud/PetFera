#ifndef ANFIBIO_NATIVO_HPP
#define ANFIBIO_NATIVO_HPP

#include "anfibio.hpp"
#include "silvestre.hpp"
#include "nativo.hpp"

class anfibio_nativo: public anfibio, public animal_nativo
{

public:
	anfibio_nativo();
	anfibio_nativo(string nome_especie,string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta, string veterinario_responsavel, string tratador_responsavel, string venenoso, string cod_ibama, string origem, string auto_ibama);

	~anfibio_nativo();
private:
	ostream& print(ostream &o) const;
	istream& insercao(istream &i);	

};

#endif
