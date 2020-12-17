#ifndef AVE_EXOTICO_HPP
#define AVE_EXOTICO_HPP

#include "ave.hpp"
#include "silvestre.hpp"
#include "exotico.hpp"

class ave_exotico: public ave, public animal_exotico
{

public:
	ave_exotico();
	ave_exotico(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta, string veterinario_responsavel, string tratador_responsavel, string formato_bico, string cod_ibama, string pais_origem);

	string registro_animal();

	~ave_exotico();
private:
	ostream& print(ostream &o) const;
	istream& insercao(istream &i);
  

};

#endif
