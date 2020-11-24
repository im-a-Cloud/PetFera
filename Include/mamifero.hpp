#ifndef MAMIFERO_HPP
#define MAMIFERO_HPP

#include "animal.hpp"

class mamifero: public animal
{
private:
	string cor_pelos;
public:
	mamifero();
	mamifero(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta, string veterinario_responsavel, string tratador_responsavel, string cor_pelos);

  void set_cor_pelos(string cor_pelos);

  string get_cor_pelos();

	~mamifero();
private:
	ostream& print(ostream &o) const;
	istream& insercao(istream &i);
  friend class mamifero_nativo;
  friend class mamifero_exotico;

};
#endif
