#ifndef EXOTICO_HPP
#define EXOTICO_HPP

#include "silvestre.hpp"
//exotico herda de animal_silvestre o cod_ibama e tem como atributo o pais de origem do animal, que é uma string 
class animal_exotico: public animal_silvestre
{
protected:
	string pais_origem; //país de origem do animal
  
public:
	animal_exotico();
	animal_exotico(string cod_ibama, string pais_origem);

	void set_pais_origem(string pais_origem);

	string get_pais_origem();

	virtual ~animal_exotico();
	
};

#endif