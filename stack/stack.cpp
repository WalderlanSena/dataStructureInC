/**
 *  Algoritmo de Estrutura de Dados em C++
 *  Implementação do algoritmo Pilha/Stack
 *  @developer: Walderlan Sena <eu@walderlan.xyz>
 *  @github   : https://github.com/WalderlanSena/dataStructureInC
 *  @version  : v1.0.0
 *  @license  : GPL License v3.0
 */
#include <iostream>
#include <cstdlib>
using namespace std;

//-------- Macros ---------

#define TAM 5               //Tamanho da pilha a ser criada posteriormente

#ifdef WIN32                //Realiza o teste de qual o sistema operacional o software foi compilado
    #define PAUSE 1
    #define CLEAR "cls"
#else
    #define PAUSE 0
    #define CLEAR "clear"
#endif

//-------- Protótipos das funções ----------

void menu (void);           //Imprime menu de opções na tela
void systemSo(void);        //Pausa o console esperando teclar (Funcional para qualquer SO)
bool stack_isEmpty (void);  //Verifica se a pilha está vazia
bool stack_isFull (void);   //Verifica se a pilha está cheia
bool stack_push (int value);//Insere um novo valor na pilha
bool stack_pop (void);      //Deleta um item da pilhas especifica
bool stack_peek (void);     //Imprime a pilhas

//---------- Variáveis Globais ----------
int inicio = 0,
    fim    = TAM - 1,
    top    = -1;

int stack[TAM] = {};

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
    int value = 0;

    while (true) {
        system(CLEAR);    //Limpando o terminal
        cout << "╔═══════════════════════════════════════════════════════╗" << endl;
        cout << "║        Algoritmos de Estrutura de Dados em C++        ║" << endl;
        cout << "║                      PILHA/STACK                      ║" << endl;
        cout << "╚═══════════════════════════════════════════════════════╝" << endl;
        cout << "             contato@mentesvirtuaissena.com              " << endl;
        cout << "                Developer: Walderlan Sena                " << endl << endl;
        cout << "       »»»»»»»»»»»»»»»»»»» MENU «««««««««««««««««««      " << endl << endl;

        cout << " 1  » Inserir novo valor na pilha                         " << endl;
        cout << " 2  » Deletar valor da pilha                              " << endl;
        cout << " 3  » Consultar valores da pilha                          " << endl;
        cout << " 99 » Sair do programa                                    " << endl;
        cout << " >>> ";
            cin >> opcao;   //Capturando opção selecionada pelo usúario
        switch (opcao) {    //Testando qual opção o usúario selecionou
            case 1:
                    cout << " Digite um numero (INT) >>> "; //Orietação a ação do usuario
                        cin >> value;                       //Capturando o valor digitado
                    if (stack_push(value)) {
                        cout << endl<< " » Item incluido com sucesso ! « " << endl << endl;
                        stack_peek();
                        systemSo();
                    } else {
                        cout << " Desculpe ! Pilha cheia..." << endl;
                        systemSo();
                    }//end if
                break;
            case 2:
                if (stack_pop()) {
                    cout << endl<< " » Item excluido com sucesso ! « " << endl << endl;
                    stack_peek();
                    systemSo();
                } else {
                    cout << endl<< " » Pilha vazia, impossivel excluir... « " << endl << endl;
                    systemSo();
                }
                break;
            case 3:
                if (stack_peek()) {
                    stack_peek();
                    systemSo();
                } else {
                    cout << endl<< " » Desculpe, pilha vazia... « " << endl << endl;
                    systemSo();
                }
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

/**
 *  Verifica se a pilha está vazia
 *  @return true se estiver vazia
 *  @return false se não estiver vazia
 */
bool stack_isEmpty ()
{
    if (top == -1)      //Se o topo for igual a -1, pilha está vazia
        return true;    //Return true, pilha com espaço
    else                //Caso não
        return false;   //Return false, pilha cheia
}//end isEmpty

/**
 *  Verifica se a pilha está cheia
 *  @return true se estiver cheia
 *  @return false se não estiver cheia
 */
bool stack_isFull()
{
    if (top == fim)
        return true;    //A pilha está cheia
    else
        return false;   //A pilha não está cheia
}//end isFull

/**
 *  Insere um novo valor na pilha
 */
bool stack_push (int value)
{
    if (stack_isFull()) {
        return false;
    } else {
        top++;
        stack[top] = value;
        return true;       //Pilha vazia impossivel inserir novo item
    }//end if
}//end insert_stack

/**
 *  Deleta um valor da pilha
 */
bool stack_pop ()
{
    if (stack_isEmpty())
        return false;
    else
        top--;
        return true;
}//end delete_stack

/**
 *  Mostra toda a pilha no console
 */
bool stack_peek ()
{
    if (stack_isEmpty()) {
        return false;
    } else {
        for (int i = 0; i <= top; i++)
            cout << " [ " << i << " ] tem o valor => " << stack[i] << endl;
        return true;
    }//end if
}//end search_Stack 
