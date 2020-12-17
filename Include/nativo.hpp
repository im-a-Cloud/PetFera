#ifndef NATIVO_HPP
#define NATIVO_HPP

#include "silvestre.hpp"
//exotico herda de animal_silvestre o cod_ibama e tem como atributo o pais de origem do animal, que é uma string e o codigo de autorização do ibama
class animal_nativo : public animal_silvestre
{
protected:
	string origem; //de que parte do Brasil o animal é
	string auto_ibama;	//codigo de autorização do ibama
public:
	animal_nativo();
	animal_nativo(string cod_ibama, string origem, string auto_ibama);

	string get_origem();
	string get_auto_ibama();

	void set_origem(string origem);
	void set_auto_ibama(string auto_ibama);

	virtual ~animal_nativo();
	
};

#endif