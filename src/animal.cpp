#include "animal.hpp"
#include "funcoes.hpp"

animal::animal(){}
//implementação do contrutor parametrizado
animal::animal(string nome_especie, string nome_batismo, string classe, string sexo, string tipo, string risco_extincao, string dieta, string veterinario_responsavel, string tratador_responsavel):nome_especie(nome_especie),nome_batismo(nome_batismo),  classe(classe), sexo(sexo), tipo(tipo), risco_extincao(risco_extincao), dieta(dieta), veterinario_responsavel(veterinario_responsavel), tratador_responsavel(tratador_responsavel) {

}
//implementação dos sets
void animal::set_nome_especie(string nome_especie){
	this->nome_especie = nome_especie;
}

void animal::set_nome_batismo(string nome_batismo){
	this->nome_batismo = nome_batismo;
}

void animal::set_classe(string classe){
	this->classe = classe;
}
void animal::set_sexo(string sexo){
	this->sexo =sexo;
}
void animal::set_tipo(string tipo){
	this->tipo = tipo;
}
void animal::set_risco(string risco_extincao){
	this->risco_extincao = risco_extincao;
}
void animal::set_dieta(string dieta){
  this->dieta = dieta;
}
void animal::set_veterinario_responsavel(string veterinario_responsavel){
	this->veterinario_responsavel = veterinario_responsavel;	
}
void animal::set_tratador_responsavel(string tratador_responsavel){
	this->tratador_responsavel = tratador_responsavel;
}
//implementação dos gets
string animal::get_nome_especie(){
	return this->nome_especie;
}
string animal::get_nome_batismo(){
	return this->nome_batismo;
}
string animal::get_classe(){
	return this->classe;
}
string animal::get_sexo(){
	return this->sexo;
}
string animal::get_tipo(){
	return this->tipo;
}
string animal::get_dieta(){
  return this->dieta;
}
string animal::get_veterinario_responsavel(){
	return this->veterinario_responsavel;
}
string animal::get_tratador_responsavel(){
	return this->tratador_responsavel;
}
//implementação da sobrecarga do operador << (extração)
ostream& operator<<(ostream &o, animal const &ani){ 
	return ani.print(o);
}
istream& operator>>(istream &i, animal &ani){ 
	return ani.insercao(i);
}
string animal::registro_animal(){
	string data_save;
	string separador = ";";
	data_save = nome_especie + separador + nome_batismo + separador + classe + separador + sexo + separador + tipo + separador + dieta + separador + veterinario_responsavel + separador + tratador_responsavel;
	return data_save;
}
//função para alterar animal, fizemos na classe base pois teoricamente não seria possivel "tirar o veneno de um animal venenoso e assim por diante"
void animal::alterar_animal(){
    string nome_especie;
	string nome_batismo; // nome dado para o animal pelos donos,etc.
	string sexo; //sexo do animal.
	string risco_extincao; //se o animal está ou não em risco de extinção; //se ele é perigoso de alguma forma
	string dieta; // oque ele come
	string veterinario_responsavel;
	string tratador_responsavel;

    int opcao;

    cout <<"Qual atributo do animal você deseja alterar?"<<endl;
    cout <<"1- Nome da espécie"<<endl;
    cout <<"2- Nome de batismo"<<endl;
    cout <<"3- O sexo do animal"<<endl;
    cout <<"4- O risco de extinção do animal"<<endl;
    cout <<"5- A dieta do animal"<<endl;
    cout <<"6- Veterinário responsável"<<endl;
    cout <<"7- Tratador responsável"<<endl;
    cout <<"0- Finalizar" <<endl;
    while(opcao !=0){
        cin >> opcao;
        switch(opcao){
            case 1:{
                cout <<"Entre com o novo nome de especie do animal" <<endl;
                cin.ignore();
                getline(cin,nome_especie);
                set_nome_especie(nome_especie);
                cout <<"Deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
                cin >> opcao;
                break;
            }
            case 2:{
                cout <<"Entre com o novo nome do animal" <<endl;
                cin.ignore();
                getline(cin, nome_batismo);
                set_nome_batismo(nome_batismo);
                cout <<"Deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
                cin >> opcao;
                break;
            }
            case 3:{
                cout <<"Entre com o novo sexo" <<endl;
                cin.ignore();
                getline(cin, sexo);
                set_sexo(sexo);
                cout <<"Deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
                cin >> opcao;
                break;
            }
            case 4:{
                cout <<"Entre com o novo risco de extinção" <<endl;
                cin.ignore();
                getline(cin, risco_extincao);
                set_risco(risco_extincao);
                cout <<"Deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
                cin >> opcao;
                break;
            }
            case 5:{
                cout <<"Entre com a nova dieta do animal" <<endl;
                cin.ignore();
                getline(cin,dieta);
                set_dieta(dieta);
                cout <<"Deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
                cin >> opcao;
                break;
            }
            case 6:{
                cout <<"Entre com o novo veterinário responsável" <<endl;
                cin.ignore();
                getline(cin,veterinario_responsavel);
                checa_veterinario(veterinario_responsavel);
                set_veterinario_responsavel(veterinario_responsavel);
                cout <<"Deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
                cin >> opcao;
                break;
            }
            case 7:{
                cout <<"Entre com o novo tratador responsável" <<endl;
                cin.ignore();
                getline(cin, tratador_responsavel);
                checa_tratador(tratador_responsavel);
                set_tratador_responsavel(tratador_responsavel);
                cout <<"Deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
                cin >> opcao;
                break;
            }
            case 0:{
                cout <<"Saindo da função de alterar" <<endl;
                break;
            }
            default:{
                cout <<"Erro na entrada" <<endl;
                break;
            }
        }
    }
    salvar_animal();
}
//implementação do metodo print para imprimirr os animais
ostream& animal::print(ostream &o) const{
	o << "------------------Dados do animal------------------" <<endl;
	o << " Especie do animal: " << this->nome_especie << endl;
	o << " Nome do animal: " << this->nome_batismo << endl;
	o << " Classe do animal: "<< this-> classe << endl;
	o << " Sexo do animal: " << this->sexo << endl;
	o << " Tipo(nativo, exotico, domestico):" << this->tipo << endl;
	o << " Corre risco de extinção: " << this->risco_extincao << endl;
  	o << " A dieta do animal consiste em :" <<this->dieta <<endl;
  	o << " Veterinário repsonsável pelo animal: " << this->veterinario_responsavel <<endl;
  	o << " Tratador do animal: " << this-> tratador_responsavel <<endl;
	return o;
}
//metodo de sobrecarga de inserção
istream& animal::insercao(istream &i){
	i >>nome_especie >> nome_batismo >> classe >> sexo >> tipo >> risco_extincao >> dieta >> veterinario_responsavel >> tratador_responsavel;
	return i;
}
animal::~animal(){

}