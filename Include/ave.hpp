#ifndef AVE_HPP
#define AVE_HPP

#include "animal.hpp"

class ave : public animal
{
private:
  string formato_bico;
public:
	ave();
	ave(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao,string dieta, string veterinario_responsavel, string tratador_responsavel, string formato_bico);

  void set_formato_bico(string formato_bico);

  string get_formato_bico();

	~ave();
private:
	ostream& print(ostream &o) const;
	istream& insercao(istream &i);
  friend class ave_nativo;
  friend class ave_exotico;
};
#endif