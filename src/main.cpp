#include "funcoes.hpp"

using namespace std;

int main()
{
  int opcao;
  string tipo_func;
  string tipo_animal;
  string classe_animal;
  cout <<"BEM VINDO AO PET FERA" <<endl;
  cout <<"Qual operação você deseja fazer?" <<endl;
  cout <<"1 - Registrar um novo funcionário" <<endl;
  cout <<"2 - Registrar um novo animal" <<endl;
  cout <<"3 - Listar os animais por tipo" <<endl;
  cout <<"4 - Listar os funcionários" <<endl;
  cout <<"0 - Sair do programa" <<endl;
  cin >> opcao;
  while(opcao != 0){
  switch (opcao){
  case 1:{
    cout <<"Diga qual o tipo do funcionário(Veterinário ou Tratador)" <<endl;
    cin >> tipo_func;
    tipo_func = deixar_minusculo(tipo_func);
    while(tipo_func != "tratador" && tipo_func !="veterinario"){
    cout <<"entrada inválida tente de novo" << endl;
    cin >> tipo_func;
    tipo_func = deixar_minusculo(tipo_func);
    }
    cadastrar_funcionario(tipo_func);
    cout << checa_nivel_seguranca(tipo_func, "vermelho") <<endl;
    cout <<"deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
    cin >>opcao;
    break;
    }
  case 2:{
    cout <<"Entre com o tipo do animal(ave, mamifero, anfibio, reptil)" <<endl;
    cin >> tipo_animal;
    tipo_animal = deixar_minusculo(tipo_animal);
    while(tipo_animal != "ave" && tipo_animal !="reptil" && tipo_animal != "anfibio" && tipo_animal != "mamifero"){
    cout <<"entrada inválida tente de novo" << endl;
    cin >> tipo_animal;
    tipo_animal = deixar_minusculo(tipo_animal);

  }
    cout <<"Agora entre com a classe do animal(doméstico, nativo, exótico)" <<endl;
    cin >> classe_animal;
    classe_animal = deixar_minusculo(classe_animal);
    while(classe_animal != "domestico" && classe_animal !="nativo" && classe_animal != "exotico"){
    cout <<"entrada inválida tente de novo" << endl;
    cin >> classe_animal;
    classe_animal = deixar_minusculo(classe_animal);
    }
    cadastrar_animal(tipo_animal, classe_animal);
    cout <<"deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
    cin >>opcao;
    break;
  }
  case 3:{
    cout <<"Entre com o tipo de animal que você deseja imprimir" <<endl;
    cin >> tipo_animal;
    tipo_animal = deixar_minusculo(tipo_animal);
    while(tipo_animal != "ave" && tipo_animal !="reptil" && tipo_animal != "anfibio" && tipo_animal != "mamifero"){
    cout <<"entrada inválida tente de novo" << endl;
    cin >> tipo_animal;
    }
    listar_animais_por_tipo(tipo_animal);
        cout <<"deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
    cin >>opcao;
    break;
  }
  case 4:{
    mostrar_funcionarios();
    cout <<"deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
    cin >>opcao;
    break;
  }
  case 0:{
    cout <<"fechando programa...";
    return 0;
  }
  default:{
    cout <<"Entrada inválida, tente de novo" <<endl;
    break;
      }
    }
  }
	return 0;
}