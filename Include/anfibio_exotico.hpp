#ifndef ANFIBIO_EXOTICO_HPP
#define ANFIBIO_EXOTICO_HPP

#include "anfibio.hpp"
#include "silvestre.hpp"
#include "exotico.hpp"

class anfibio_exotico: public anfibio, public animal_exotico
{

public:
	anfibio_exotico();
	anfibio_exotico(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta, string veterinario_responsavel, string tratador_responsavel, string venenoso, string cod_ibama, string pais_origem);

	~anfibio_exotico();
private:
	ostream& print(ostream &o) const;
	istream& insercao(istream &i);	

};

#endif
