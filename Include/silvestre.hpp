#ifndef SILVESTRE_HPP
#define SILVESTRE_HPP

#include <string>

using namespace std;
//criação da classe animal_silvestre
class animal_silvestre
{
protected:
	string cod_ibama;
public:
	animal_silvestre();
	animal_silvestre(string cod_ibama);

	void set_cod_ibama(string cod_ibama);

	string get_cod_ibama();

	virtual ~animal_silvestre();
	
};

#endif