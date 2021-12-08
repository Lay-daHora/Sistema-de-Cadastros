#include <stdio.h>
#include <stdlib.h>
#include <string.h>           //bibliotecas utilizadas no programa
#include <locale.h>
#include <stddef.h>

int opcao = 0;

int Login(char usuario[20] , char senha[9]) {    //essa função define a condição para login;
  FILE *arquivo;                                //Se estiver dentro do arquivo de usuários, o acesso é autorizado;
  arquivo = fopen("listaDeLogins.txt" , "r");
  char nome[30];
  char login[9];
  int result = 1;

  while(fscanf(arquivo , "%s %s" , nome , login) != EOF) {
    if(strcmp(usuario , nome) == 0 && strcmp(senha , login) == 0)
      result = 0;
  }

  return result;

}

#define MAX 90

typedef struct {     //essa struct guarda as variaveis que vamos utilizar em diversas funções;
  char nome[MAX];    //usando este comando podemos utilizar as informações a qualquer momento;
  char cpf[MAX];
  char telefone[MAX];
  char endereco[MAX];
  char bairro[MAX];
  char num[MAX];
  char cep[MAX];
  char nascimento[MAX];
  char email[MAX];
  char diagnostico[MAX];
  char comorbidade[MAX];
  char qualComorbidade[MAX];

} Paciente;


void registroPaciente(FILE *listagemPacientes , Paciente p){  //Este void representa a ação de guardar as informações dentro do arquivo de pacientes;
                                                              //Ele imprime os valores digitados dentro do arquivo ListaDePacientes;
  setlocale(LC_ALL, "");

  fprintf(listagemPacientes , "\t Nome: %s \t" , p.nome);
  fprintf(listagemPacientes , "CPF: %s \t" , p.cpf);
  fprintf(listagemPacientes , "Telefone: %s \t" , p.telefone);
  fprintf(listagemPacientes , "Endereço: %s \t" , p.endereco);
  fprintf(listagemPacientes , "Bairro: %s \t" , p.bairro);
  fprintf(listagemPacientes , "Nº: %s \t" , p.num);
  fprintf(listagemPacientes , "CEP: %s \t" , p.cep);
  fprintf(listagemPacientes , "Data de nascimento: %s \t" , p.nascimento);
  fprintf(listagemPacientes , "Email: %s \t" , p.email);
  fprintf(listagemPacientes , "Data do diagnóstico: %s \t" , p.diagnostico);
  fprintf(listagemPacientes , "Possui comorbidades: %s \t" , p.comorbidade);
  fprintf(listagemPacientes , "Comorbidades relatadas: %s \n \n" , p.qualComorbidade);

}

int idadePaciente(char nascimento[MAX] , char dataDeRegistro[MAX]){  //esta função coleta o valor digitado em 'data de nascimento' e 'data de registro';
  char *pDia , *pMes , *pAno;                                        //depois ela transforma o valor da string em int(inteiro);
  char *pDiaReg , *pMesReg , *pAnoReg;                               //isso permite que a função 'if' calcule a idade e decida o destino das informações;

  char dia[3] , mes[3] ,  ano[5];
  char dia2[3] , mes2[3] ,  ano2[5];

  char buffer1[MAX] , buffer2[MAX];

  strcpy(buffer1 , "\0");
  strcpy(buffer2 , "\0");

  strncpy(buffer1 , nascimento , 10);
  strncpy(buffer2 , dataDeRegistro , 10);

  pDia = strtok(buffer1 , "/");
  pMes = strtok(NULL , "/");
  pAno = strtok(NULL , "/");

  pDiaReg = strtok(buffer2 , "/");
  pMesReg = strtok(NULL , "/");
  pAnoReg = strtok(NULL , "/");

  strncpy(dia , pDia , sizeof(dia));
  strncpy(mes , pMes , sizeof(mes));
  strncpy(ano , pAno , sizeof(ano));

  strncpy(dia2 , pDiaReg , sizeof(dia2));
  strncpy(mes2 , pMesReg , sizeof(mes2));
  strncpy(ano2 , pAnoReg , sizeof(ano2));

  dia[2] = '\0';
  mes[2] = '\0';
  ano[4] = '\0';

  dia2[2] = '\0';
  mes2[2] = '\0';
  ano2[4] = '\0';

  int iDia = atoi(dia);
  int iMes = atoi(mes);
  int iAno = atoi(ano);

  int iDia2 = atoi(dia2);
  int iMes2 = atoi(mes2);
  int iAno2 = atoi(ano2);

  int idade;

  if((iDia <= iDia2 && iMes == iMes2) || (iMes < iMes2) ){
    idade = iAno2 - iAno;

  }else{
    idade = (iAno2 - iAno) - 1;
    }

  return idade;
}

void CadastroPaciente(){  //essa função é dividida em partes, tudo dentro dela é exibido durante o processo de cadastramento;

    setlocale(LC_ALL, "");  //essas linhas definem o destino das informações;
    FILE *listagemPacientes;    //manda armazenarem as respostas dentro do arquivo 'ListaDePacientes';
    listagemPacientes = fopen("listaDePacientes.txt" , "a");

    Paciente p;


      char nomeCompleto[MAX];
      char cpf1[MAX];
      char tel[MAX];
      char enderecoRua[MAX];
      char enderecoBairro[MAX];
      char enderecoNum[MAX];      //essas variáveis são associadas aos campos de resposta, para guardarem o que o usuário digitar;
      char enderecoCep[MAX];      //posteriormente seus valores são associados à struct vista no início;
      char nasc[MAX];
      char dataDeRegistro[MAX];
      char eemail[MAX];
      char datadiagnostico[MAX];
      char temcomorbidade[MAX];
      char tipoDeComorbidade[MAX];
      char opcao2[MAX] = "Nenhuma";


      printf("\n \n Insira a data de cadastramento: ");   //perguntas feitas ao usuário;
      fgets(dataDeRegistro, MAX, stdin);

      printf("Nome completo: ");
      fgets(nomeCompleto, MAX, stdin);

      printf("CPF: ");
      fgets(cpf1, MAX, stdin);

      printf("Telefone(com ddd estadual): ");
      fgets(tel, MAX, stdin);

      printf("Endereço (Rua): ");
      fgets(enderecoRua, MAX, stdin);
      printf("Bairro: ");
      fgets(enderecoBairro, MAX, stdin);
      printf("Num: ");
      fgets(enderecoNum, MAX, stdin);
      printf("CEP: ");
      fgets(enderecoCep, MAX, stdin);

      printf("Data de nascimento: ");
      fgets(nasc, MAX, stdin);

      printf("Email: ");
      fgets(eemail, MAX, stdin);

      printf("Data do diagnóstico: ");
      fgets(datadiagnostico, MAX, stdin);

      printf("O paciente possui alguma comorbidade (Sim ou Nao): ");
      fgets(temcomorbidade, MAX, stdin);

      idadePaciente(nasc , dataDeRegistro);


      //A função 'if' a seguir utiliza o calculo feito em outra função para determinar para onde o processo caminhará;
      //Se a idade for maior que 65 ou se possuir comorbidades, seus dados serão salvos também em outro arquivo;
      //Caso contrario, o processo é encerrado;

        if(strcmp(temcomorbidade, "Sim")== 1 || idadePaciente(nasc, dataDeRegistro) >= 65) {
            printf("Quais as comorbidades do paciente? (Responda 'Nenhuma' caso a resposta anterior seja 'não'): ");
            fgets(tipoDeComorbidade, MAX, stdin);
            strcpy(p.qualComorbidade , tipoDeComorbidade);


            FILE *listagemGrupoDeRisco = fopen("PacientesDoGrupoDeRisco.txt", "a");
            fprintf(listagemGrupoDeRisco , "\t Nome: %s \t" , nomeCompleto);
            fprintf(listagemGrupoDeRisco , "Comorbidades relatadas: %s \t", tipoDeComorbidade);
            fprintf(listagemGrupoDeRisco , "Idade: %d anos \t" , idadePaciente(nasc, dataDeRegistro));
            fprintf(listagemGrupoDeRisco , "CEP: %s \n \n \n" , enderecoCep);

        }else if (strcmp(temcomorbidade, "Nao") == 1 && idadePaciente(nasc, dataDeRegistro) < 65) {
            tipoDeComorbidade[MAX] = "Nenhuma";
            strcpy(p.qualComorbidade , opcao2);
        }


      strcpy(p.nome , nomeCompleto);  //Aqui é onde associados os valores das Char's aos valores no struct;
      strcpy(p.cpf , cpf1);           //O 'strcpy' copia o valor de uma variável para outra;
      strcpy(p.telefone , tel);
      strcpy(p.endereco , enderecoRua);
      strcpy(p.bairro , enderecoBairro);
      strcpy(p.num , enderecoNum);
      strcpy(p.cep , enderecoCep);
      strcpy(p.nascimento, nasc);
      strcpy(p.email , eemail);
      strcpy(p.diagnostico , datadiagnostico);
      strcpy(p.comorbidade , temcomorbidade);


      registroPaciente(listagemPacientes , p);

      fclose(listagemPacientes);
}


void MostrarMenu(){ //Aqui é onde definimos o menu principal do programa, onde o usuário decide qual função irá chamar;

    system("cls");
    printf("\n \t REGISTRAMED19 \n");
    printf("\n \t \t****************************** \n");
    printf("\t \t******BEM VINDO, USUÁRIO****** \n");
    printf("\t \t****************************** \n \n \n");

    printf("\t 1) - CADASTRO DE NOVO PACIENTE\n"); //opções para o usuário;
    printf("\t 2) - SAIR DO SISTEMA\n\n");
    printf("\t DIGITE A OPÇÃO DESEJADA: ");
    scanf("%d", &opcao);

    getchar();

    switch (opcao) {

        case 1 :
            system("cls");  //se a opção escolhida for 1, ele roda a função CadastroPaciente e depois finaliza o cadastro;
            CadastroPaciente();
            printf("\n \n \t Cadastro efetuado com sucesso! \n \n");
            system("PAUSE");
            break;

        case 2 :
            system("cls"); //Caso contrario o programa se encerra;
            printf("\n \t Obrigado por usar REGISTRAMED19, até a próxima! \n \n");
            system("PAUSE");
            exit(0);
        }
}


int main(){ //no main é onde está a principal parte do código, ele se inicia aqui;

    setlocale(LC_ALL, "");

    char nome[20];
    char senha[9];
    int login_efetuado = 0;


    while(!login_efetuado){  //Enquanto o login não for efeituado, o programa pedirá o usuário e a senha.

        printf("\n \t ****************************************\n");
        printf("\t *SISTEMA DE CADASTRAMENTO PARA COVID-19*\n");
        printf("\t ****************************************\n \n");
        printf("\t Nome de usuário: ");
        scanf("%s" , nome);
        printf("\n \t Senha: ");
        scanf("%s", senha);
            if(Login(nome , senha) == 0){
                printf("\n \n \t Acesso Liberado! \n \n");
                system("PAUSE");
                login_efetuado = 1; //quando o login for correto, ele muda de valor, entrando na função while;
            }else{
                printf("\n \n \t Usuario não encontrado!\n \n");
                system("PAUSE");
                system("cls");  //usuário errado, ele voltará a pedir essa informação;
            }
    }


    while(login_efetuado == 1) {  //quando o login for efetuado, ele chamará a função MostrarMenu;
        MostrarMenu();            //dentro da função MostrarMenu, chamamos todas as outras;
    }

        getchar();

    return 0;

}