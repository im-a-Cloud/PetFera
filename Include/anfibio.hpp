#ifndef ANFIBIO_HPP
#define ANFIBIO_HPP

#include "animal.hpp"

class anfibio: public animal
{
private:
	string venenoso;
public:
	anfibio();
	anfibio(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta, string veterinario_responsavel, string tratador_responsavel, string venenoso);

	void set_venenoso(string venenoso);
	string get_venenoso();

	~anfibio();
private:
	ostream& print(ostream &o) const;
	istream& insercao(istream &i);
 	friend class anfibio_exotico;
  	friend class anfibio_nativo;
};

#endif
