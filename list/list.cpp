/**
 *  Algoritmo de Estrutura de Dados em C++
 *  Implementação do algoritmo Lista/List
 *  @developer: Walderlan Sena <eu@walderlan.xyz>
 *  @github   : https://github.com/WalderlanSena/dataStructureInC
 *  @version  : v1.0.0
 *  @license  : GPL License v3.0
 */
#include <iostream>
#include <cstdlib>
using namespace std;

//-------- Macros ---------

#define TAM 5               //Tamanho da lista a ser criada posteriormente

#ifdef WIN32                //Realiza o teste de qual o sistema operacional o software foi compilado
    #define PAUSE 1
    #define CLEAR "cls"
#else
    #define PAUSE 0
    #define CLEAR "clear"
#endif

//-------- Protótipos das funções ----------

void menu (void);                           //Imprime menu de opções na tela
void systemSo(void);                        //Pausa o console esperando teclar (Funcional para qualquer SO)
bool list_isEmpty (void);                   //Verifica se a lista está vazia
bool list_isFull (void);                    //Verifica se a lista está cheia
bool list_push (int position, int value);   //Insere um novo item na lista
bool list_pop (int position);               //Exclui um item da lista
bool list_modify (int position, int value); //Modifica um valor da lista
bool list_speek (void);                     //Consuta valores da lista

//---------- Variáveis Globais ----------

int list[TAM] = {};

//---------- Inicio Método main ----------

int main ()
{
    menu ();
    return 0;
}//end main

//-------- Implemetação das funções ----------

/**
 *  Menu onde são apresentadas as funcionalidades do software
 */
void menu ()
{
    int opcao = 0;
    int value = 0,
        position;

    while (true) {
        system(CLEAR);    //Limpando o terminal
        cout << "╔═══════════════════════════════════════════════════════╗" << endl;
        cout << "║        Algoritmos de Estrutura de Dados em C++        ║" << endl;
        cout << "║                      LISTA/LIST                       ║" << endl;
        cout << "╚═══════════════════════════════════════════════════════╝" << endl;
        cout << "             contato@mentesvirtuaissena.com              " << endl;
        cout << "                Developer: Walderlan Sena                " << endl << endl;
        cout << "       »»»»»»»»»»»»»»»»»»» MENU «««««««««««««««««««      " << endl << endl;

        cout << " 1  » Inserir novo valor na lista                         " << endl;
        cout << " 2  » Deletar valor da lista                              " << endl;
        cout << " 3  » Consultar valores da lista                          " << endl;
        cout << " 4  » Modificar valores da lista                          " << endl;
        cout << " 99 » Sair do programa                                    " << endl;
        cout << " >>> ";
            cin >> opcao;   //Capturando opção selecionada pelo usúario
        switch (opcao) {    //Testando qual opção o usúario selecionou
            case 1:
                
                cout << " Digite a posicao que deseja inserir >>> ";
                    cin >> position;
                
                if (position > TAM - 1) {
                    cout << " >>> Desculpe ! Essa posicao nao existe na lista <<<" << endl;
                    systemSo();
                } else if (list[position] > 0) {
                    cout << " >>> Desculpe ! Essa posicao ja contem um valor armazenado <<<" << endl;
                    list_speek();
                    cout << endl << " >>> Utilize a opcao 4 para modificar <<< " << endl;
                    systemSo();
                    continue;
                }

                cout << " Digite o valor que deseja inserir na posicao >>> ";
                    cin >> value;
                if (value == 0) {
                    cout << " >>> Desculpe ! Nao e possivel inserir valores menores que 1 <<<" << endl;
                    systemSo();
                } else {
                    if (list_push(position, value)) {
                        cout << endl << " >>> Item incluido com sucesso <<< " << endl;
                        list_speek();
                        cout << endl;
                        systemSo();
                    } else {
                        cout << " >>> Erro: A lista ja esta cheia <<< " << endl;
                        systemSo();
                    }//end if list_push
                }//end if
                break;
            case 2:
                cout << " Digite a posicao que deseja excluir >>> ";
                    cin >> position;
                if (list_pop(position)) {
                    cout << " >>> Item excluido com sucesso <<< " << endl;
                    systemSo();
                } else {
                    cout << endl << " >>> Erro: A posicao informada, ja se encontra vazia <<< " << endl;
                    list_speek();
                    cout << endl;
                    systemSo();
                }
                break;
            case 3:
                list_speek();
                cout << endl;
                systemSo();
                break;
            case 4:
                cout << " Digite a posicao que deseja alterar >>> ";
                    cin >> position;
                if (position > TAM -1) {
                    cout << " >> Erro: A posicao nao existe na lista <<< " << endl;
                    systemSo();
                    continue;
                } else {
                    cout << " Digite o valor que sera adicionado na substituicao >>> ";
                        cin >> value;
                    if (value <= 0) {
                        cout << " >>> Erro: Nao e permitido valoes menores que 1" << endl;
                        systemSo();
                        continue;
                    } else {
                        if (list_modify(position, value)) {
                            cout << endl << " >>> Item alterado com sucesso ! <<<" << endl;
                            list_speek();
                            cout << endl;
                            systemSo();
                        } else {
                            cout << endl << " >>> Erro: Nao foi possivel alterar posicao ja esta vazia <<<" << endl;
                            cout << " >>> Dica: Utilize o metodo de insercao da opcao 1 " << endl;
                            systemSo();
                            continue;
                        }//end if
                    }//end if
                }//end if
                break;
            case 99:
                cout << "By!  :) " << endl;
                exit(0);      //Sai do programa e retorno 0 para o sistema operacional
            default:
                cout << "Desculpe, opcao invalida..." << endl;
                exit(0);      //Sai do programa e retorna 0 para o sistema operacional
        }//end switch
    }//end while
}//end menu

/**
 *  Pausa o console e espera o usúario teclar alguma tecla para continuar
 */
void systemSo ()
{
    if (PAUSE != 1)
        system("read -p \"\nPressione enter para continuar...\" saindo");
    else
        system("pause");
}//end systemSo

bool list_isEmpty ()
{
    for (int i = 0; i <= TAM - 1; i++) {
        if (list[i] == 0)
            return true;                //Se encontrar uma posição vazia, a lista está vazia
    }
    return false;                       //Caso não encontre, lista não está vazia 
}//end list_isEmpty

bool list_isFull ()
{
    for (int i = 0; i <= TAM - 1; i++)
        if (list[i] <= 0)
            return false;               //Se a pilha n
    return true;
}//end list_isFull

bool list_push (int position, int value)
{
    if (list_isFull())
        return false;
    else
        list[position] = value;
        return true;
}//end list_push

bool list_pop (int position)
{
    if (list[position] <= 0) {
        return false;
    } else {
        list[position] = 0;
        return true;
    }
}//end list_pop

bool list_modify (int position, int value)
{
    if (list[position] != 0) {
        list[position] = value;
        return true;
    } else {
        return false;
    }
}//end list_modify

bool list_speek ()
{
    cout << endl;
    for (int i = 0; i <= TAM - 1; i++) {
        cout << " " << "[" << i << "] => " << list[i] << "\t";
    }
}//end list_speek