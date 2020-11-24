#ifndef AVE_NATIVA_HPP
#define AVE_NATIVA_HPP

#include "ave.hpp"
#include "silvestre.hpp"
#include "nativo.hpp"

class ave_nativo: public ave, public animal_nativo
{

public:
	ave_nativo();
	ave_nativo(string nome_especie,string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta, string veterinario_responsavel, string tratador_responsavel, string formato_bico, string cod_ibama, string origem, string auto_ibama);

	~ave_nativo();
private:
	ostream& print(ostream &o) const;
	istream& insercao(istream &i);	

};

#endif
