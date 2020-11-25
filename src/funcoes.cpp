#include "funcoes.hpp"
#include <memory>
#include <string>

vector< shared_ptr <animal> > vetor_animais;
vector< shared_ptr <funcionario> > vetor_funcionarios;

string deixar_minusculo(string texto){
    for_each(texto.begin(), texto.end(), [](char &texto_lower){
    texto_lower = ::tolower(texto_lower);
    });
    return texto;
}
//função que recebe uma string qualquer e retorna ela minuscula, para pradonizar os dados
bool checa_veterinario(string nome_vet){
  int contador = 0;
   while(contador < vetor_funcionarios.size()){
      if(nome_vet == vetor_funcionarios[contador]->get_nome_funcionario()){
      return true;
    }
    contador++;	
    }
    cout <<"Não foi encontrado nenhum veterinário com esse nome, tente de novo" <<endl;
    return false;
}
//checa se o veterinario realmente existe no vetor de funcionario

bool checa_tratador(string nome_trat){
  int contador = 0;
   while(contador < vetor_funcionarios.size()){
      if(nome_trat == vetor_funcionarios[contador]->get_nome_funcionario()){
      return true;
    }
    contador++;	
    }
    cout <<"Não foi encontrado nenhum tratador com esse nome, tente de novo" <<endl;
    return false;
}
//identico ao de cima, só que para tratadores
int code_to_num(string code){
  if (code == "vermelho") {
    return 3;
  }
  else if (code == "azul"){
    return 2;
  } 
  else if (code == "verde") {
    return 1;
  }
  else{
    return 0;
  }
}
//uso para fazer uma hierarquia simulado dos niveis de segurança dos tratadores

bool checa_nivel_seguranca(string nome_func, string nivel_nescessario){
  int nivel_nec = code_to_num(nivel_nescessario);
  int contador = 0;
  while(contador < vetor_funcionarios.size()){
    if(nome_func == vetor_funcionarios[contador]->get_nome_funcionario()){
      if(vetor_funcionarios[contador]->get_funcao() != "tratador" ){
        return false;
      }else{
        //tem que ser ref para conversão dinâmica
        //só converte depois de verificar que o funcionario tem a função "tratador"
        //derreferencia o valor a ser convertido
        tratador& t = dynamic_cast<tratador&>(*vetor_funcionarios[contador]);
        int nivel_trat = code_to_num (t.get_nivel_seguranca());
        return (nivel_trat >= nivel_nec);
      }
    }
  }
  //nunca vai chegar aqui, somente para evitar warnings 
  return false;
}

void cadastrar_animal(string tipo_animal, string classe_animal){
  //inicilizando todas as possiveis variaveis nescessárias
	string nome_especie;
	string nome_batismo;
	string classe;
	string sexo;
	string risco_extincao;
  string dieta;
  string nome_veterinario;
  string nome_tratador;

	string cod_ibama;
	string origem;
	string auto_ibama;
	string pais_origem;


	string formato_bico;
	string cor_pelo;
	string venenoso;
	string tipo_pele;

	cout <<"Entre com o nome da especie do animal" <<endl;
  cin.ignore();
	getline(cin, nome_especie); //getline caso seja um nome composto 

	cout <<"Com o nome de batismo do animal" <<endl;
	getline(cin, nome_batismo);

	cout <<"Sexo" <<endl;
	getline(cin, sexo);

	cout <<"O animal corre risco de extinção?" <<endl;
	getline(cin, risco_extincao);

  	cout <<"Qual a dieta do animal(pode ser mais de uma coisa)" <<endl;
  	getline(cin, dieta);

  	cout <<"Entre com o nome do veterinário responsável pelo animal" <<endl;
    getline(cin, nome_veterinario);
    while(checa_veterinario(nome_veterinario) == false){
      getline(cin,nome_veterinario);
    }//checa se o veterinario existe
 
  	cout <<"Agora com o tratador responsável pelo animal" <<endl;
  	getline(cin, nome_tratador);
    while(checa_tratador(nome_tratador) == false){
      getline(cin,nome_tratador);
    }//checa se o tratador existe

  	if (tipo_animal == "anfibio")
  	{
	  cout <<"O animal é venenoso?" <<endl;
		getline(cin, venenoso);
    if(venenoso == "sim"){
      if(checa_nivel_seguranca(nome_tratador,"vermelho")){
        if (classe_animal == "domestico")
			{
				shared_ptr <anfibio> anfibio_domestico = make_shared<anfibio>(
							anfibio(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal, risco_extincao, dieta,nome_veterinario, nome_tratador,venenoso));

				vetor_animais.push_back(anfibio_domestico);
			}
			else if (classe_animal == "nativo")
			{
				cout <<"Codigo do animal no ibama" <<endl;

				getline(cin, cod_ibama);

				cout <<"Local de origem do animal no territorio brasileiro" <<endl;

				getline(cin, origem);

				cout <<"Autorização do IBAMA" <<endl;

				getline(cin, auto_ibama);
				shared_ptr <anfibio> anfibio_nat = make_shared<anfibio_nativo>(
		        anfibio_nativo (nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,  risco_extincao, dieta, nome_veterinario, nome_tratador,venenoso, cod_ibama, origem, auto_ibama));

				vetor_animais.push_back(anfibio_nat);
			}
			else if (classe_animal == "exotico")
			{
				cout <<"Codigo do animal no ibama" <<endl;

				getline(cin, cod_ibama);

				cout <<"País de origem do animal" <<endl;

				getline(cin, pais_origem);
				shared_ptr <anfibio> anfibio_exo = make_shared<anfibio_exotico>(
		        anfibio_exotico(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,risco_extincao, dieta,nome_veterinario, nome_tratador,venenoso, cod_ibama, pais_origem));
				vetor_animais.push_back(anfibio_exo);
			}
  	}
    else{
      cout <<"o tratador não é qualificado para tratar esse o animal" <<endl;
    }

  }
      if(venenoso == "não" || venenoso=="nao"){
        if(checa_nivel_seguranca(nome_tratador, "azul")){
          if (classe_animal == "domestico")
			{
				shared_ptr <anfibio> anfibio_domestico = make_shared<anfibio>(
							anfibio(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal, risco_extincao, dieta,nome_veterinario, nome_tratador,venenoso));

				vetor_animais.push_back(anfibio_domestico);
			}
			else if (classe_animal == "nativo")
			{
				cout <<"Codigo do animal no ibama" <<endl;

				getline(cin, cod_ibama);

				cout <<"Local de origem do animal no territorio brasileiro" <<endl;

				getline(cin, origem);

				cout <<"Autorização do IBAMA" <<endl;

				getline(cin, auto_ibama);
				shared_ptr <anfibio> anfibio_nat = make_shared<anfibio_nativo>(
		        anfibio_nativo (nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,  risco_extincao, dieta, nome_veterinario, nome_tratador,venenoso, cod_ibama, origem, auto_ibama));

				vetor_animais.push_back(anfibio_nat);
			}
			else if (classe_animal == "exotico")
			{
				cout <<"Codigo do animal no ibama" <<endl;

				getline(cin, cod_ibama);

				cout <<"País de origem do animal" <<endl;

				getline(cin, pais_origem);
				shared_ptr <anfibio> anfibio_exo = make_shared<anfibio_exotico>(
		        anfibio_exotico(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,risco_extincao, dieta,nome_veterinario, nome_tratador,venenoso, cod_ibama, pais_origem));
				vetor_animais.push_back(anfibio_exo);
        }
			}else{
        cout <<"O tratador não é qualificado para cuidar desse animal" <<endl;
        }
      }
  	}
  	else if (tipo_animal == "ave")
  	{
    cout <<"Qual o formato do bico?" <<endl;
		getline(cin, formato_bico);
		if (classe_animal == "domestico")
			{
				shared_ptr <ave> ave_domestico = make_shared<ave>(
							ave(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal, risco_extincao, dieta ,nome_veterinario, nome_tratador,formato_bico));

				vetor_animais.push_back(ave_domestico);
			}
			else if (classe_animal == "nativo")
			{
				cout <<"Codigo do animal no ibama" <<endl;

				getline(cin, cod_ibama);

				cout <<"Local de origem do animal no territorio brasileiro" <<endl;

				getline(cin, origem);

				cout <<"Autorização do IBAMA" <<endl;

				getline(cin, auto_ibama);
				shared_ptr <ave> ave_nat = make_shared<ave_nativo>(
		        ave_nativo (nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,  risco_extincao, dieta, nome_veterinario, nome_tratador,formato_bico, cod_ibama, origem, auto_ibama));

				vetor_animais.push_back(ave_nat);
			}
			else if (classe_animal == "exotico")
			{
				cout <<"Codigo do animal no ibama" <<endl;

				getline(cin, cod_ibama);

				cout <<"País de origem do animal" <<endl;

				getline(cin, pais_origem);
				shared_ptr <ave> ave_exo = make_shared<ave_exotico>(
		        ave_exotico(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,risco_extincao, dieta,nome_veterinario, nome_tratador,formato_bico, cod_ibama, pais_origem));
				vetor_animais.push_back(ave_exo);
			}
  	}
  	else if (tipo_animal == "mamifero")
  	{
    if(checa_nivel_seguranca(nome_tratador, "azul")){
	  cout <<"Quais são as cores do pelo do animal?" <<endl;
		getline(cin, cor_pelo);
		if (classe_animal == "domestico")
			{
				shared_ptr <mamifero> mamifero_domestico = make_shared<mamifero>(
							mamifero(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal, risco_extincao, dieta,nome_veterinario, nome_tratador,cor_pelo));

				vetor_animais.push_back(mamifero_domestico);
			}
			else if (classe_animal == "nativo")
			{
				cout <<"Codigo do animal no ibama" <<endl;

				getline(cin, cod_ibama);

				cout <<"Local de origem do animal no territorio brasileiro" <<endl;

				getline(cin, origem);

				cout <<"Autorização do IBAMA" <<endl;

				getline(cin, auto_ibama);
				shared_ptr <mamifero> mamifero_nat = make_shared<mamifero_nativo>(
		        mamifero_nativo (nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,  risco_extincao, dieta,nome_veterinario, nome_tratador,cor_pelo, cod_ibama, origem, auto_ibama));

				vetor_animais.push_back(mamifero_nat);
			}
			else if (classe_animal == "exotico")
			{
				cout <<"Codigo do animal no ibama" <<endl;

				getline(cin, cod_ibama);

				cout <<"País de origem do animal" <<endl;

				getline(cin, pais_origem);
				shared_ptr <mamifero> mamifero_exo = make_shared<mamifero_exotico>(
		        mamifero_exotico(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,risco_extincao, dieta,nome_veterinario, nome_tratador,cor_pelo, cod_ibama, pais_origem));
				vetor_animais.push_back(mamifero_exo);
        }
        else{
          cout <<"O tratador não é qualificado para cuidar desse animal" <<endl;
          }
        }
			}
			else if (tipo_animal == "reptil")
			{
        if(venenoso == "sim"){
          if(checa_nivel_seguranca(nome_tratador,"vermelho")){
				cout <<"O animal é venenoso?" <<endl;
				getline(cin, venenoso);

				cout <<"Como é a pele do animal?(Placas, Escamas, Carapaça)" <<endl;
				getline(cin, venenoso);
				if (classe_animal == "domestico")
				{
					shared_ptr <reptil> reptil_domestico = make_shared<reptil>(
								reptil(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal, risco_extincao, dieta,nome_veterinario, nome_tratador, venenoso, tipo_pele));

					vetor_animais.push_back(reptil_domestico);
				}
				else if (classe_animal == "nativo")
				{
					cout <<"Codigo do animal no ibama" <<endl;

					getline(cin, cod_ibama);

					cout <<"Local de origem do animal no territorio brasileiro" <<endl;

					getline(cin, origem);

					cout <<"Autorização do IBAMA" <<endl;

					getline(cin, auto_ibama);
					shared_ptr <reptil> reptil_nat = make_shared<reptil_nativo>(
			        reptil_nativo (nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,  risco_extincao, dieta,nome_veterinario, nome_tratador,venenoso , tipo_pele, cod_ibama, origem, auto_ibama));

					vetor_animais.push_back(reptil_nat);
				}
				else if (classe_animal == "exotico")
				{
					cout <<"Codigo do animal no ibama" <<endl;

					getline(cin, cod_ibama);

					cout <<"País de origem do animal" <<endl;

					getline(cin, pais_origem);
					shared_ptr <reptil> reptil_exo = make_shared<reptil_exotico>(
			        reptil_exotico(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,risco_extincao, dieta,nome_veterinario, nome_tratador,venenoso, tipo_pele, cod_ibama, pais_origem));
					vetor_animais.push_back(reptil_exo);
            }
          }
				}else{
          cout <<"O tratador não é qualificado para cuidar desse animal" <<endl;
        }
        if(venenoso == "não" || venenoso=="nao"){
        if(checa_nivel_seguranca(nome_tratador, "azul")){
				cout <<"Como é a pele do animal?(Placas, Escamas, Carapaça)" <<endl;
				getline(cin, venenoso);
				if (classe_animal == "domestico")
				{
					shared_ptr <reptil> reptil_domestico = make_shared<reptil>(
								reptil(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal, risco_extincao, dieta,nome_veterinario, nome_tratador, venenoso, tipo_pele));

					vetor_animais.push_back(reptil_domestico);
				}
				else if (classe_animal == "nativo")
				{
					cout <<"Codigo do animal no ibama" <<endl;

					getline(cin, cod_ibama);

					cout <<"Local de origem do animal no territorio brasileiro" <<endl;

					getline(cin, origem);

					cout <<"Autorização do IBAMA" <<endl;

					getline(cin, auto_ibama);
					shared_ptr <reptil> reptil_nat = make_shared<reptil_nativo>(
			        reptil_nativo (nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,  risco_extincao, dieta,nome_veterinario, nome_tratador,venenoso , tipo_pele, cod_ibama, origem, auto_ibama));

					vetor_animais.push_back(reptil_nat);
				}
				else if (classe_animal == "exotico")
				{
					cout <<"Codigo do animal no ibama" <<endl;

					getline(cin, cod_ibama);

					cout <<"País de origem do animal" <<endl;

					getline(cin, pais_origem);
					shared_ptr <reptil> reptil_exo = make_shared<reptil_exotico>(
			        reptil_exotico(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,risco_extincao, dieta,nome_veterinario, nome_tratador,venenoso, tipo_pele, cod_ibama, pais_origem));
					vetor_animais.push_back(reptil_exo);
              }
            }
          }
        }
  	cout <<"Animal cadastrado com sucesso" <<endl;
}
void cadastrar_funcionario(string funcao_funcionario){
	string nome_funcionario;
	string sexo_funcionario;
	string funcao;
	int CPF;
	int idade;
	int id_funcionario;

	string cod_CRMV;
	string nivel_seguranca;

	funcao = funcao_funcionario;

	cout <<"Entre com o nome do novo funcionário" <<endl;
  cin.ignore();
	getline(cin, nome_funcionario);

	cout <<"Qual o sexo do novo funcionário?" <<endl;
	getline(cin, sexo_funcionario);

	cout <<"Qual o CPF do novo funcionário?" <<endl;
	cin>>CPF;

	cout <<"Qual a idade do novo funcionário?" <<endl;
	cin>> idade;

	cout <<"Agora dê um id para o funcionário" <<endl;
	cin >> id_funcionario;

	if (funcao_funcionario == "veterinario")
	{
		cout <<"Entre com o código do Conselho Regional de Medicina Veterinária(CRMV) do novo veterinário" <<endl;

    //SE DER BUG É ISSO
    cin.ignore();

		getline(cin, cod_CRMV);

		shared_ptr <funcionario> veterinario_novo = make_shared<veterinario>(veterinario(nome_funcionario, sexo_funcionario, funcao_funcionario, CPF, idade, id_funcionario, cod_CRMV));
		vetor_funcionarios.push_back(veterinario_novo);
	}
	else if (funcao_funcionario == "tratador")
	{
		cout <<"Entre com o nível de manejo que o novo tratador possuí: Azul(Para anfíbios, aves, mamíferos e répteis),Verde(Apenas aves),Vermelho(para os que tem experiência em manejo de animais perigosos ou venenosos)" <<endl;

    //SE DER BUG É ISSO
    cin.ignore();
    cin >> nivel_seguranca;
    nivel_seguranca = deixar_minusculo(nivel_seguranca);
    while(nivel_seguranca != "azul" && nivel_seguranca !="verde" && nivel_seguranca != "vermelho"){
    cout <<"entrada inválida tente de novo" << endl;
    cin >> nivel_seguranca;
    }
    
		shared_ptr <funcionario> tratador_novo = make_shared<tratador>(tratador(nome_funcionario, sexo_funcionario, funcao_funcionario, CPF, idade, id_funcionario, nivel_seguranca));
		vetor_funcionarios.push_back(tratador_novo);
	}
	cout <<"Funcionário cadastrado com sucesso" <<endl;
}
//entra com o tipo do animal e lista todos desse tipo
void listar_animais_por_tipo(string tipo_animal){
	int posicao = 0;
	while(posicao < vetor_animais.size()){
		if (vetor_animais[posicao]->get_tipo() == tipo_animal)
		{
			cout << *vetor_animais[posicao] <<endl;
			posicao++;
		}
	}
}
//lista todos os funcionarios 
void mostrar_funcionarios(){
	int posicao = 0;
	while(posicao < vetor_funcionarios.size()){
			cout << *vetor_funcionarios[posicao] <<endl;
			posicao++;	
	}
}