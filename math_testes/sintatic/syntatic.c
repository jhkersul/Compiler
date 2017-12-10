#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "syntatic-transitions.c"
//#include "definition.c"

int main()
{
  // typedef struct {
  //   char tipo[40];
  //   char complemento[40];
  // } Token_type;
  //
  // Token_type tokens[10];
  //
  // for(int i=0; i<10; i++) {
  //     strcpy(tokens[i].tipo, "NULL");
  //     strcpy(tokens[i].complemento, "NULL");
  // }

  char current_state[5];
  char token_type[40];
  char token_complement[40];
  char stack[40];

  //teste
  strcpy(token_type, "declaracoes");
  strcpy(token_complement, "NULL");
  strcpy(current_state, "A0");

  //check if transiction exists
  getNextState(current_state, token_type, token_complement, stack);

  //printf("%s\n", nextState );


  //if exists, check if is consume token or call another machine

  //if machine, empilha e entra na maquina


}




//Gravar todos os tokens na váriavel
//Começar na máquina principal (programa)
//Ler tokens (tipo e valor e retornar
//Conforme os tokes, consumir token ou chamar as submáquinas (máquina de declaracoes por exemplo) (empilhando a
//máquina na pilha)  e chamar a funcao semantico_tbd imprimindo TODO
//ir pra outra submáquina, executa-la e voltar e se necessário empilhar mais submáquinas
//voltar pra máquina anterior desempilhando a si mesma
//depois q acabou aceita  aporra toda


// Implementação:
// Cada transição do analisador sintático (consumindo tokens ou empilhando/desempilhando submáquinas) deve estar mapeada à
// chamada de uma função void   semantico_tbd que imprime "TODO\n". Encare esta função como um trigger das transições do APE;
// A saída do analisador sintático, neste momento, será uma sequência de "TODO"s impressos no console conforme as transições
// do APE ocorrem;
// Implemente um autômato similar ao que foi implementado no Analisador Léxico, mas com a habilidade de empilhar/desempilhar
// outros autômatos (este será o Autômato de Pilha Estruturado).
