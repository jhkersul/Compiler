# NEXT -- aula 4 ou 5

#NAO VAO PODER FAZER TRUE == FALSE, OPERACAOES COM BOOLEAOS

DESCRICAO INFORMAL

programa = [declaracoes] "BEGIN" { comando } "END" .

declaracoes = "DECLARE" lista_de_identificadores ";" .

lista_de_identificadores =  { alfanumerico } .

alfanumerico = letra { letra_digito } .

letra = "A" | "B" | "C" | "D" | "E" | "F" | "H" | "I" | "J" | "K" | "L" | "M" | "N" | "O" | "P" | "Q" | "R" | "S" | "T" | "U" | "V" | "X" | "W" | "Y" | "Z" | "a" | "b" | "c" | "d" | "e" | "f" | "g" | "h" | "i" | "j" | "k" | "l" | "m" | "n" | "o" | "p" | "q" | "r" | "s" | "t"   | "u" | "v" | "x" | "y" | "w" | "z" .

letra_digito = letra | digito .

digito = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" .

comando = comando_de_atribuicao | comando_condicional | comando_iterativo ";" .

comando_de_atribuicao = posicao_na_memoria "=" expressao .

comando_condicional = "IF" expressao_booleana "THEN" { comando } "ELSE" { comando } |  "IF" expressao_booleana "THEN" { comando } "ENDIF" .

comando_iterativo = "WHILE" condicao "LOOP" { comando } "END" .

posicao_na_memoria = { digito } .

expressao = expressao_aritmetica | expressao_booleana .

expressao_aritmetica = { digito } | expressao_aritmetica operador_aritmetico expressao_aritmetica .

expressao_booleana = "TRUE" | "FALSE" | digitos operador_booleano digitos .

operados_aritmetico = "+" | "-" | "/" | "*" .

operador_booleano = "||" | "&&" | "<" | "<=" | "==" | "!=" | ">" | ">=" .
