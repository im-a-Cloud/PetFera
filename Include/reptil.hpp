#ifndef REPTIL_HPP
#define REPTIL_HPP

#include "animal.hpp"

class reptil: public animal
{
private:
	string venenoso;
	string tipo_pele;
public:
	reptil();
	reptil(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta,string veterinario_responsavel, string tratador_responsavel, string venenoso, string tipo_pele);

	void set_venenoso(string venenoso);
	void set_tipo_pele(string tipo_pele);

	string get_venenoso();
	string get_tipo_pele();

	~reptil();
private:
	ostream& print(ostream &o) const;
	istream& insercao(istream &i);
  friend class reptil_exotico;
  friend class reptil_nativo;
//declarando reptil_exotico e reptil_nativo como friends para poder acessar as funcções deles;
};
#endif
