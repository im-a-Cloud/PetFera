#include "funcoes.hpp"
#include <memory>
#include <string>
#include <vector>
#include "animal.hpp"
#include "veterinario.hpp"
#include "tratador.hpp"

//Declaração dos vetores de animal e funcionário usando ponteiros inteligentes

vector< shared_ptr <animal> > vetor_animais;
vector< shared_ptr <funcionario> > vetor_funcionarios;

void remover_animal(string classe_animal, string nome_batismo){
    auto i = vetor_animais.begin();
    //loop para percorrer o vetor de animais até achar um animal com classe e nome de batismo correspondente 
    while(i != vetor_animais.end()){
        if((*i)->get_classe() == classe_animal && (*i)->get_nome_batismo() == nome_batismo){
			vetor_animais.erase(i);
            //apaga o animal na posição achada
            cout <<"Animal removido com sucesso" <<endl;
            salvar_animal();
            return;
        }
      i++;
    }
    cout <<"Não achamos nenhuma correspondência" <<endl;
}
void alterar_dados_animal(string nome_especie, string nome_batismo){
    auto i = vetor_animais.begin();
    //loop para percorrer o vetor de animais até achar um animal com nome de especie e nome de batismo correspondente 
    while(i != vetor_animais.end()){
        if((*i)->get_nome_especie() == nome_especie && (*i)->get_nome_batismo() == nome_batismo){
			(*i)->alterar_animal();
            cout <<"Animal alterado com sucesso" <<endl;
            salvar_animal();
            return;
        }
      i++;
    }
    cout <<"Não achamos nenhuma correspondência" <<endl;
}
//função para salvar os funcionários no arquivo que estão no vetor
void salvar_funcionario(){
    cout <<"Salvando Funcionários" <<endl;
    ofstream arquivo_funcionarios;
    arquivo_funcionarios.open("funcionarios.csv");
    string linha_arquivo;
    if(arquivo_funcionarios.bad())
    {
		cerr <<"Falha ao abrir arquivo, tente de novo" <<endl;
		return;
    }
    //cast dinâmico de funcionario para inserir
    int contador = 0;
    while(contador < vetor_funcionarios.size()){
        if(vetor_funcionarios[contador]->get_funcao() == "veterinario"){
            veterinario& t = dynamic_cast<veterinario&>(*vetor_funcionarios[contador]);
            linha_arquivo = t.registro_funcionario();
        }
        if(vetor_funcionarios[contador]->get_funcao() == "tratador"){
            tratador& t = dynamic_cast<tratador&>(*vetor_funcionarios[contador]);
            linha_arquivo = t.registro_funcionario(); 
        }
    //essa parte é para evitar que ficasse um espaço em branco no arquivo que fazia as saídas ficarem estranhas
    if(contador==(vetor_funcionarios.size()-1) ){
    linha_arquivo = linha_arquivo;
    }else{
    linha_arquivo = linha_arquivo + '\n';
    }

    arquivo_funcionarios << linha_arquivo;
	  
    contador++;
    }
    arquivo_funcionarios.close();
}
//identica a anterior só que para animais
void salvar_animal(){
  cout<< "Salvando animais" << endl;

  cout<< vetor_animais.size() << endl;

  ofstream arquivo_animais;
	arquivo_animais.open("./animais_save.csv");
	string linha_arquivo;

	if (arquivo_animais.bad())
	{
		cerr <<"Falha ao abrir arquivo, tente de novo" <<endl;
		return;
	}

  int contador = 0;
  while(contador < vetor_animais.size()){

    cout<<vetor_animais[contador]->get_classe()<<" "<<vetor_animais[contador]->get_tipo();
    if(vetor_animais[contador]->get_classe()=="ave"){
        if(vetor_animais[contador]->get_tipo()== "domestico"){
        ave& t = dynamic_cast<ave&>(*vetor_animais[contador]);
        linha_arquivo = t.registro_animal();
        }
        else if(vetor_animais[contador]->get_tipo()=="nativo"){
        ave_nativo& t = dynamic_cast<ave_nativo&>(*vetor_animais[contador]);
        linha_arquivo = t.registro_animal();
        }
        else if(vetor_animais[contador]->get_tipo()== "exotico"){
        
        ave_exotico& t = dynamic_cast<ave_exotico&>(*vetor_animais[contador]);
        linha_arquivo = t.registro_animal();
        }
    }
    else if(vetor_animais[contador]->get_classe()=="anfibio"){
        if(vetor_animais[contador]->get_tipo()== "domestico"){
        anfibio& t = dynamic_cast<anfibio&>(*vetor_animais[contador]);
        linha_arquivo = t.registro_animal();
        }
        else if(vetor_animais[contador]->get_tipo()=="nativo"){
        anfibio_nativo& t = dynamic_cast<anfibio_nativo&>(*vetor_animais[contador]);
        linha_arquivo = t.registro_animal();
        }
        else if(vetor_animais[contador]->get_tipo()== "exotico"){
        anfibio_exotico& t = dynamic_cast<anfibio_exotico&>(*vetor_animais[contador]);
        linha_arquivo = t.registro_animal();
        }
    }
    else if(vetor_animais[contador]->get_classe()=="mamifero"){
        if(vetor_animais[contador]->get_tipo()== "domestico"){
        mamifero& t = dynamic_cast<mamifero&>(*vetor_animais[contador]);
        linha_arquivo = t.registro_animal();
        }
        else if(vetor_animais[contador]->get_tipo()=="nativo"){
        mamifero_nativo& t = dynamic_cast<mamifero_nativo&>(*vetor_animais[contador]);
        linha_arquivo = t.registro_animal();
        }
        else if(vetor_animais[contador]->get_tipo()== "exotico"){
        mamifero_exotico& t = dynamic_cast<mamifero_exotico&>(*vetor_animais[contador]);
        linha_arquivo = t.registro_animal();
        }
    }
    else if(vetor_animais[contador]->get_classe()=="ave"){
        if(vetor_animais[contador]->get_tipo()== "domestico"){
        ave& t = dynamic_cast<ave&>(*vetor_animais[contador]);
        linha_arquivo = t.registro_animal();
        }
        else if(vetor_animais[contador]->get_tipo()=="nativo"){
        ave_nativo& t = dynamic_cast<ave_nativo&>(*vetor_animais[contador]);
        linha_arquivo = t.registro_animal();
        }
        else if(vetor_animais[contador]->get_tipo()== "exotico"){
        ave_exotico& t = dynamic_cast<ave_exotico&>(*vetor_animais[contador]);
        linha_arquivo = t.registro_animal();
        }
    }
    else if(vetor_animais[contador]->get_classe()=="reptil"){
        if(vetor_animais[contador]->get_tipo()== "domestico"){
        reptil& t = dynamic_cast<reptil&>(*vetor_animais[contador]);
        linha_arquivo = t.registro_animal();
        }
        else if(vetor_animais[contador]->get_tipo()=="nativo"){
        reptil_nativo& t = dynamic_cast<reptil_nativo&>(*vetor_animais[contador]);
        linha_arquivo = t.registro_animal();
        }
        else if(vetor_animais[contador]->get_tipo()== "exotico"){
        reptil_exotico& t = dynamic_cast<reptil_exotico&>(*vetor_animais[contador]);
        linha_arquivo = t.registro_animal();
        }
    }

    if(contador==(vetor_animais.size()-1) ){
      linha_arquivo = linha_arquivo;
    }else{
     linha_arquivo = linha_arquivo + '\n';
    }
    arquivo_animais << linha_arquivo;
	  
    contador++;
	}
  arquivo_animais.close();
}
//carrega/abre o arquivo com os funcionários
void carregar_funcionarios(){
	string::size_type tam;
	string aux;

    
    //abre o arquivo no modo ifstream, ou seja no modo

    ifstream ip("./funcionarios.csv");

    //checa se o arquivo foi aberto com sucesso
    if(!ip.is_open()){
        cout << "erro na leitura" << endl;
        return;
  }

    string nome_funcionario;
	string sexo_funcionario;
	string funcao; 
	int CPF;
	int idade;
	int id_funcionario;

    //enquanto ele conseguir ler ele vai fazer a separação usando ; que é o nosso token
    while(ip.good()){
    getline(ip,nome_funcionario,';');
    getline(ip,sexo_funcionario,';');
    getline(ip,funcao          ,';');

    getline(ip,aux,';');
    CPF = std::stoi(aux,&tam);

    getline(ip,aux,';');
    idade = std::stoi(aux,&tam);

    getline(ip,aux,';');
    id_funcionario = std::stoi(aux,&tam);

    //o \n e para fazer a quebra de linha signifciando que aquele linha é daquele funcionario
    if(funcao == "veterinario"){
      string cod_CRMV;
      getline(ip,cod_CRMV,'\n');
      shared_ptr <funcionario> funcionario_novo = std::make_shared<veterinario>( veterinario(nome_funcionario, sexo_funcionario, funcao, CPF, idade, id_funcionario, cod_CRMV,"não tem") );
      vetor_funcionarios.push_back(funcionario_novo);
    } else if(funcao == "tratador"){
      string nivel_seguranca;
      getline(ip,nivel_seguranca,'\n');
      shared_ptr <funcionario> funcionario_novo = std::make_shared<tratador>( tratador(nome_funcionario, sexo_funcionario, funcao, CPF, idade, id_funcionario, nivel_seguranca) );
      vetor_funcionarios.push_back(funcionario_novo);
    } else {
      cout << "função " + funcao + "não reconhecida \n";
      cout << "escolha \"veterinario\" ou \"tratador\"";
    }
  }
}
//identico ao anterior só que para animais
void carregar_animais(){
	string::size_type tam;
	string aux;

    ifstream ip("./animais_save.csv");

    if(!ip.is_open()){
    cout << "erro na leitura" << endl;
    return;
  }
  	string nome_especie;
	string nome_batismo;
	string classe_animal;
	string sexo;
    string tipo_animal;
	string risco_extincao;
	string dieta;
	string nome_veterinario;
	string nome_tratador;

    while(ip.good()){
        getline(ip,nome_especie,';');
        getline(ip,nome_batismo,';');
        getline(ip,classe_animal,';');
        getline(ip,sexo,';');
        getline(ip,tipo_animal,';');
        getline(ip,risco_extincao,';');
        getline(ip,dieta,';');
        getline(ip,nome_veterinario,';');
        getline(ip,nome_tratador,';');

        if(classe_animal == "anfibio"){
            string venenoso;
            if(tipo_animal == "domestico"){
                getline(ip,venenoso,'\n');
                shared_ptr<animal> animal_novo =std::make_shared<anfibio>(anfibio(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal, risco_extincao, dieta,nome_veterinario, nome_tratador,venenoso));
            
            vetor_animais.push_back(animal_novo);
            }
            else if(tipo_animal == "exotico"){
            string cod_ibama;
            string pais_origem;

            getline(ip,venenoso,';');
            getline(ip,cod_ibama,';');
            getline(ip,pais_origem,'\n');

            shared_ptr <anfibio> anfibio_exo = make_shared<anfibio_exotico>(
            anfibio_exotico(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,risco_extincao, dieta,nome_veterinario, nome_tratador,venenoso, cod_ibama, pais_origem));

            vetor_animais.push_back(anfibio_exo);

            }
            else if(tipo_animal == "nativo"){
            string cod_ibama;
            string origem;
            string auto_ibama;

            getline(ip,venenoso,';');
            getline(ip,cod_ibama,';');
            getline(ip,origem,';');
            getline(ip,auto_ibama,'\n');

            shared_ptr <anfibio> anfibio_nat = make_shared<anfibio_nativo>(
            anfibio_nativo (nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,  risco_extincao, dieta, nome_veterinario, nome_tratador,venenoso, cod_ibama, origem, auto_ibama));

            vetor_animais.push_back(anfibio_nat);
            }
        }
        else if(classe_animal == "ave"){
            string formato_bico;

            if(tipo_animal == "domestico"){
            getline(ip,formato_bico,'\n');
            shared_ptr <ave> ave_domestico = make_shared<ave>(
                        ave(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal, risco_extincao, dieta ,nome_veterinario, nome_tratador,formato_bico));
            

            vetor_animais.push_back(ave_domestico);

            }
            else if(tipo_animal == "exotico"){
            string cod_ibama;
            string pais_origem;

            getline(ip,formato_bico,';');
            getline(ip,cod_ibama,';');
            getline(ip,pais_origem,'\n');

            shared_ptr <ave> ave_exo = make_shared<ave_exotico>(
            ave_exotico(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,risco_extincao, dieta,nome_veterinario, nome_tratador,formato_bico, cod_ibama, pais_origem));
            vetor_animais.push_back(ave_exo);

            }
            else if(tipo_animal == "nativo"){
            string cod_ibama;
            string origem;
            string auto_ibama;

            getline(ip,formato_bico,';');
            getline(ip,cod_ibama,';');
            getline(ip,origem,';');
            getline(ip,auto_ibama,'\n');

            getline(cin, auto_ibama);
            shared_ptr <ave> ave_nat = make_shared<ave_nativo>(
            ave_nativo (nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,  risco_extincao, dieta, nome_veterinario, nome_tratador,formato_bico, cod_ibama, origem, auto_ibama));

            vetor_animais.push_back(ave_nat);
            }
        }
        else if(classe_animal == "mamifero"){
            string cor_pelos;
            if(tipo_animal == "domestico"){
                getline(ip,cor_pelos,'\n');
				shared_ptr <mamifero> mamifero_domestico = make_shared<mamifero>(
							mamifero(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal, risco_extincao, dieta,nome_veterinario, nome_tratador,cor_pelos));

				vetor_animais.push_back(mamifero_domestico);
            }
            else if(tipo_animal == "exotico"){
            string cod_ibama;
            string pais_origem;
            getline(ip,cor_pelos,';');
            getline(ip,cod_ibama,';');
            getline(ip,pais_origem,'\n');

            shared_ptr <mamifero> mamifero_exo = make_shared<mamifero_exotico>(
            mamifero_exotico(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,risco_extincao, dieta,nome_veterinario, nome_tratador,cor_pelos, cod_ibama, pais_origem));

            vetor_animais.push_back(mamifero_exo);
            }
            else if(tipo_animal == "nativo"){
            string cod_ibama;
            string origem;
            string auto_ibama;

            getline(ip,cod_ibama,';');
            getline(ip,origem,';');
            getline(ip,auto_ibama,'\n');

            shared_ptr <mamifero> mamifero_nat = make_shared<mamifero_nativo>(
            mamifero_nativo (nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,  risco_extincao, dieta,nome_veterinario, nome_tratador,cor_pelos, cod_ibama, origem, auto_ibama));

            vetor_animais.push_back(mamifero_nat);
            }
        }
        else if(classe_animal =="reptil"){
            string venenoso;
            string tipo_pele;

            if(tipo_animal == "domestico"){
            getline(ip,venenoso,';');
            getline(ip,tipo_pele,'\n');

            shared_ptr <reptil> reptil_domestico = make_shared<reptil>(
            reptil(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal, risco_extincao, dieta,nome_veterinario, nome_tratador, venenoso, tipo_pele));

            vetor_animais.push_back(reptil_domestico);
            }
            else if(tipo_animal == "exotico"){
            string cod_ibama;
            string pais_origem;
            getline(ip,venenoso,';');
            getline(ip,tipo_pele,';');
            getline(ip,cod_ibama,';');
            getline(ip,pais_origem,'\n');

            shared_ptr <reptil> reptil_domestico = make_shared<reptil>(
            reptil(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal, risco_extincao, dieta,nome_veterinario, nome_tratador, venenoso, tipo_pele));

            vetor_animais.push_back(reptil_domestico);

            }
            else if(tipo_animal == "nativo"){
            string cod_ibama;
            string origem;
            string auto_ibama;

            getline(ip,cod_ibama,';');
            getline(ip,origem,';');
            getline(ip,auto_ibama,'\n');

            shared_ptr <reptil> reptil_nat = make_shared<reptil_nativo>(
            reptil_nativo (nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,  risco_extincao, dieta,nome_veterinario, nome_tratador,venenoso , tipo_pele, cod_ibama, origem, auto_ibama));

            vetor_animais.push_back(reptil_nat);

            }
        }
    }
}

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
      if(nome_vet == vetor_funcionarios[contador]->get_nome_funcionario() && vetor_funcionarios[contador]->get_funcao() =="veterinario" ){
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
      if(nome_trat == vetor_funcionarios[contador]->get_nome_funcionario() && vetor_funcionarios[contador]->get_funcao() =="tratador"){
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
        //tem que ser ref para conversão dinâmica
        //só converte depois de verificar que o funcionario tem a função "tratador"
        //derreferencia o valor a ser convertido
        tratador &t = dynamic_cast<tratador&>( *vetor_funcionarios[contador]);
        int nivel_trat = code_to_num (t.get_nivel_seguranca());
        if (nivel_trat >= nivel_nec){
            return true;
            }
        }
        cout <<"O tratador não é qualificado para lidar com esse animal" <<endl;
        return false;
    }
  //nunca vai chegar aqui, somente para evitar warnings
    cout <<"O tratador não é qualificado para lidar com esse animal" <<endl;
    return false;
}

void cadastrar_animal(string classe_animal, string tipo_animal){
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
  	if (classe_animal == "anfibio")
  	{
	cout <<"O animal é venenoso?" <<endl;
	getline(cin, venenoso);
    if(venenoso == "sim"){
      if(checa_nivel_seguranca(nome_tratador,"vermelho")== true){
        if (tipo_animal == "domestico")
			{
				shared_ptr <anfibio> anfibio_domestico = make_shared<anfibio>(
							anfibio(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal, risco_extincao, dieta,nome_veterinario, nome_tratador,venenoso));

				vetor_animais.push_back(anfibio_domestico);
			}
			if (tipo_animal == "nativo")
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
			if (tipo_animal == "exotico")
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
    }
      if(venenoso == "não" || venenoso=="nao"){
        if(checa_nivel_seguranca(nome_tratador, "azul") == true){
          if (tipo_animal == "domestico")
			{
				shared_ptr <anfibio> anfibio_domestico = make_shared<anfibio>(
							anfibio(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal, risco_extincao, dieta,nome_veterinario, nome_tratador,venenoso));

				vetor_animais.push_back(anfibio_domestico);
			}
			if (tipo_animal == "nativo")
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
			if (tipo_animal == "exotico")
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
  	if (classe_animal == "ave")
  	{
    cout <<"Qual o formato do bico?" <<endl;
	getline(cin, formato_bico);
		if (tipo_animal == "domestico")
			{
				shared_ptr <ave> ave_domestico = make_shared<ave>(
							ave(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal, risco_extincao, dieta ,nome_veterinario, nome_tratador,formato_bico));

				vetor_animais.push_back(ave_domestico);
			}
		if (tipo_animal == "nativo")
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
		if (tipo_animal == "exotico")
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
  	if (classe_animal == "mamifero")
  	{
    if(checa_nivel_seguranca(nome_tratador, "azul") == true){
	  cout <<"Quais são as cores do pelo do animal?" <<endl;
		getline(cin, cor_pelo);
		if (tipo_animal == "domestico")
			{
				shared_ptr <mamifero> mamifero_domestico = make_shared<mamifero>(
							mamifero(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal, risco_extincao, dieta,nome_veterinario, nome_tratador,cor_pelo));

				vetor_animais.push_back(mamifero_domestico);
			}
			if (tipo_animal == "nativo")
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
			if (tipo_animal == "exotico")
			{
				cout <<"Codigo do animal no ibama" <<endl;

				getline(cin, cod_ibama);

				cout <<"País de origem do animal" <<endl;

				getline(cin, pais_origem);
				shared_ptr <mamifero> mamifero_exo = make_shared<mamifero_exotico>(
		        mamifero_exotico(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal,risco_extincao, dieta,nome_veterinario, nome_tratador,cor_pelo, cod_ibama, pais_origem));
				vetor_animais.push_back(mamifero_exo);
        }
        }
        }
        else if (classe_animal == "reptil")
        {
        if(venenoso == "sim"){
          if(checa_nivel_seguranca(nome_tratador,"vermelho") == true){
				cout <<"O animal é venenoso?" <<endl;
				getline(cin, venenoso);

				cout <<"Como é a pele do animal?(Placas, Escamas, Carapaça)" <<endl;
				getline(cin, venenoso);
				if (tipo_animal == "domestico")
				{
					shared_ptr <reptil> reptil_domestico = make_shared<reptil>(
								reptil(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal, risco_extincao, dieta,nome_veterinario, nome_tratador, venenoso, tipo_pele));

					vetor_animais.push_back(reptil_domestico);
				}
				if (tipo_animal == "nativo")
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
				if (tipo_animal == "exotico")
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
        if(venenoso == "não" || venenoso=="nao"){
        if(checa_nivel_seguranca(nome_tratador, "azul") == true){
				cout <<"Como é a pele do animal?(Placas, Escamas, Carapaça)" <<endl;
				getline(cin, venenoso);
				if (tipo_animal == "domestico")
				{
					shared_ptr <reptil> reptil_domestico = make_shared<reptil>(
								reptil(nome_especie, nome_batismo, classe_animal, sexo, tipo_animal, risco_extincao, dieta,nome_veterinario, nome_tratador, venenoso, tipo_pele));

					vetor_animais.push_back(reptil_domestico);
				}
				if (tipo_animal == "nativo")
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
				if (tipo_animal == "exotico")
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
    salvar_animal();
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

		shared_ptr <funcionario> veterinario_novo = make_shared<veterinario>(veterinario(nome_funcionario, sexo_funcionario, funcao_funcionario, CPF, idade, id_funcionario, cod_CRMV,"não tem"));
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
    cout <<"Entrada inválida tente de novo" << endl;
    cin >> nivel_seguranca;
    }
    
		shared_ptr <funcionario> tratador_novo = make_shared<tratador>(tratador(nome_funcionario, sexo_funcionario, funcao_funcionario, CPF, idade, id_funcionario, nivel_seguranca));
		vetor_funcionarios.push_back(tratador_novo);
	}
	cout <<"Funcionário cadastrado com sucesso" <<endl;
    salvar_funcionario();
}
//entra com o tipo do animal e lista todos desse tipo
void listar_animais_por_classe(string classe_animal){
	int posicao = 0;
	while(posicao < vetor_animais.size()){
		if (vetor_animais[posicao]->get_classe() == classe_animal)
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
//função simples para mostrar as opções, para evitar repetição de código
void menu_opcoes(){
    cout <<"1 - Registrar um novo funcionário" <<endl;
    cout <<"2 - Registrar um novo animal" <<endl;
    cout <<"3 - Listar os animais por tipo" <<endl;
    cout <<"4 - Listar os funcionários" <<endl;
    cout <<"5 - Remover um animal" <<endl;
    cout <<"6 - Alterar os dados de um animal" <<endl;
    cout <<"7 - Listar os animais sob responsabildiade de um tratador" <<endl;
    cout <<"8 - Listar todos os animais" <<endl;
    cout <<"0 - Sair do programa" <<endl;
}
//auto-explicativo
void listar_animais_por_tratador(string nome_tratador){
	int posicao = 0;
	while(posicao < vetor_animais.size()){
		if (vetor_animais[posicao]->get_tratador_responsavel() == nome_tratador)
		{
			cout << *vetor_animais[posicao] <<endl;
			posicao++;
		}
	}
}
//auto-explicativo
void listar_todos_animais(){
	int posicao = 0;
	while(posicao < vetor_animais.size()){
		{
			cout << *vetor_animais[posicao] <<endl;
			posicao++;
		}
	}
}
//auto-explicativo
string converte_num_para_classe_animal(int opcao){
    string classe_animal;
    if(opcao == 1){
        classe_animal = "ave";
    }
    if(opcao == 2){
        classe_animal = "mamifero";
    }
    if(opcao == 3){
        classe_animal = "anfibio";
    }
    if(opcao == 4){
        classe_animal = "reptil";
    }
    return classe_animal;
}
//auto-explicativo
string converte_num_para_tipo_animal(int opcao){
    string tipo_animal;
    if(opcao == 1){
        tipo_animal = "domestico";
    }
    if(opcao == 2){
        tipo_animal = "nativo";
    }
    if(opcao == 3){
        tipo_animal = "exotico";
    }
    return tipo_animal;
}
//função para ser a implementação do menu
void menu(){
  int opcao;
  int tipo_func;
  int tipo_animal;
  int classe_animal;
  string classe;
  string tipo;
  string nome_batismo;
  string especie_animal;
  string nome_tratador;
  //declaração dos atributos que talevz sejam usados durante as funções, os int's são para fazer conversão e deixar o codigo mais prático
  cout <<"BEM VINDO AO PET FERA" <<endl;
  cout <<"Qual operação você deseja fazer?" <<endl;
  menu_opcoes();
  //switch case com while padrão, caso o usuário deseja fazer mais de uma operação
  cin >> opcao;
  while(opcao != 0){
  switch (opcao){
  case 1:{
    cout <<"Diga qual o tipo do funcionário 1 para Veterinário ou 2 para Tratador" <<endl;
    cin >> tipo_func;
    while(tipo_func != 1 && tipo_func != 2){
    cout <<"Entrada inválida tente de novo" << endl;
    cin >> tipo_func;
    }
    if(tipo_func == 1){
        cadastrar_funcionario("veterinario");
    }
    else if(tipo_func == 2){
        cadastrar_funcionario("tratador");
    }
    cout <<"Deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
    menu_opcoes();
    cin >>opcao;
    break;
    }
  case 2:{
    cout <<"Entre com a classe do animal 1 para Ave, 2 para Mamífero, 3 para Anfibio e 4 para reptíl" <<endl;
    cin >> classe_animal;
    while(classe_animal != 1 && classe_animal != 2 && classe_animal != 3 && classe_animal != 4){
    cout <<"Entrada inválida tente de novo" << endl;
    cin >> classe_animal;
  }
    cout <<"Agora entre com o tipo do animal 1 para Doméstico, 2 para Nativo e 3 para Exótico" <<endl;
    cin >> tipo_animal;
    while(tipo_animal != 1 && tipo_animal != 2 && tipo_animal != 3){
    cout <<"Entrada inválida tente de novo" << endl;
    cin >> tipo_animal;
    }
    classe = converte_num_para_classe_animal(classe_animal);
    tipo = converte_num_para_tipo_animal(tipo_animal);
    cadastrar_animal(classe, tipo);
    cout <<"Deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
    menu_opcoes();
    cin >>opcao;
    break;
  }
  case 3:{
    cout <<"Entre com a classe de animal que você deseja imprimir 1 para Ave, 2 para Mamífero, 3 para Anfibio e 4 para reptíl" <<endl;
    cin >> classe_animal;
    while(classe_animal != 1 && classe_animal != 2 && classe_animal != 3 && classe_animal != 4){
    cout <<"Entrada inválida tente de novo" << endl;
    cin >> classe_animal;
    }
    classe = converte_num_para_classe_animal(classe_animal);
    listar_animais_por_classe(classe);
    cout <<"Deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
    menu_opcoes();
    cin >>opcao;
    break;
  }
  case 4:{
    mostrar_funcionarios();
    cout <<"Deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
    menu_opcoes();
    cin >>opcao;
    break;
  }
  case 5:{
        cout <<"Entre com a classe do animal e do nome de batismo a ser removido" <<endl;
        cout <<"1 para Ave, 2 para Mamífero, 3 para Anfibio e 4 para reptíl" <<endl;
        cin>>classe_animal;
        while(classe_animal != 1 && classe_animal != 2 && classe_animal != 3 && classe_animal != 4){
        cout <<"Entrada inválida tente de novo" << endl;
        cin >> classe_animal;
        }
        classe = converte_num_para_classe_animal(classe_animal);
        cout <<"Agora com o nome de batismo dele"<<endl;
        cin.ignore();
        getline(cin, nome_batismo);
        cout <<nome_batismo <<endl;
        remover_animal(classe, nome_batismo);
        cout <<"Deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
        menu_opcoes();
        cin >>opcao;
        break;
  }
  case 6:{
        cout <<"Entre com o nome da especie do animal e com o nome de batismo dele, para alterarmos os dados dele" <<endl;
        cout <<"Nome especie:" <<endl;
        cin.ignore();
        getline(cin, especie_animal);
        cout <<"Nome batismo:" <<endl;
        getline(cin, nome_batismo);
        alterar_dados_animal(especie_animal, nome_batismo);
        cout <<"Deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
        menu_opcoes();
        cin.ignore();
        cin >>opcao;
        break;
  }
  case 7:{
        cout <<"Entre com o nome do tratador"<<endl;
        cin.ignore();
        getline(cin, nome_tratador);
        cout <<"Listando animais sob cuidados de um tratador"<<endl;
        listar_animais_por_tratador(nome_tratador);
        cout <<"Deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
        menu_opcoes();
        cin >>opcao;
        break;
  }
  case 8:{
        cout <<"Listando todos os animais" <<endl;
        listar_todos_animais();
        cout <<"Deseja fazer mais uma operação? entre com um dos números passados antes" <<endl;
        menu_opcoes();
        cin >>opcao;
        break;
  }
  case 0:{
    cout <<"Fechando programa...";
    break;
  }
  default:{
    cout <<"Entrada inválida, tente de novo" <<endl;
    break;
      }
    }
  }
}