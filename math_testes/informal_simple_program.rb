# NEXT -- aula 4

DESCRIÇÃO INFORMAL

programa:
  PROGRAM declarações BEGIN comandos END;

declarações:
  DECLARE lista_de_identificadores;

lista_de_identificadores:
  alfanumerico | alfanumerico, lista_de_identificadores

alfanumerico:
  letra, letra_digito | letra, letra_digito, alfanumerico

letra:
  A, B, C, D, E, F, H, I, J, K, L, M, N, O , P, Q, R ,S, T, U, V, X, W, Y, Z,
    a, b, c d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, x, y, w, z

letra_digito:
  letra | digito | letra, letra_digito | digito, letra_digito

digito:
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9

comandos:
 comando  | comando, comandos

comando:
  comando_de_atribuição:
    posição_na_memoria := expressão;

  comando_condicional:
      IF expressão_booleana THEN comandos ELSE comandos; |
      IF expressão_booleana THEN comandos END IF;

  comando_iterativo:
    WHILE condição LOOP comandos END;

posição_na_memoria:
  digitos

digitos:
  digito | digito, digitos

expressão:
  expressão_aritmética:
    digitos | expressão_aritmética operador_aritmético expressão_aritmética
  expressão_booleanas:
    TRUE | FALSE | digitos operador_booleano digitos #NAO VAO PODER FAZER TRUE == FALSE, OPERAÇÃOES COM BOOLEAOS

operados_aritmético:
  + | - | / | * |

operador_booleano:
 || | && | < | <= | == | != | > | >=



# comando de entrada:!
#   INPUT lista_de_posições_de_memória;

# comando de saída:!
#   OUTPUT lista_de_expressões;


# bloco!

# agregados homoeneos -- vetor e matriz !

# função tipada !

#

# DECLARAÇÃO DE VARIAVEL!

# VARIAVEL
  # variáveis_simples:
  # variáveis indexadas (array)
  # agregados homogêneos (vetor/array)
  # agregados heterogêneos (TDA -- objeto)



# COMNETARIO
#   linha de comentário
#   bloco de comentário

# TO THINK
#   regras de escopo
#   palavras reservadas
