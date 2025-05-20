/* echo.y */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern int yylex();
extern char *yytext;
extern int yylineno;
void yyerror(const char *s);


%}


%union {
    double dval;
    char  *sval; 
    int    bval; 
}

/* Declaração dos Tokens (vindos do Flex) */
/* Associar o tipo da union <...> aos tokens que carregam valor */
%token <sval> T_IDENTIFIER T_TXT_LITERAL
%token <dval> T_NUM_LITERAL
%token <bval> T_BOOL_LITERAL

/* Tokens que são palavras-chave ou operadores multi-caractere */
%token T_ECHO T_RETURN T_SHOW T_GET T_IF T_OTIF T_OTHER T_LOOP T_TIMES T_BUBBLE T_TRY T_OOPS
%token T_TYPE_TXT T_TYPE_NUM T_TYPE_BOOL T_TYPE_OBJ T_TYPE_LIST T_TYPE_SILENT
%token T_ASSIGN /* << */ T_CONCAT /* ++ */
%token T_EQ T_NEQ T_LT T_GT T_LTE T_GTE /* == != < > <= >= */
%token T_AND T_OR T_NOT /* && \\ ! */

/* Não é estritamente necessário declarar tokens de caracteres únicos se eles forem retornados */
/* diretamente pelo Flex (ex: return '+';), mas é preciso se precisar definir precedência para eles. */

/* Precedência e Associatividade dos Operadores (Menor para Maior) */
%right T_ASSIGN                 /* << (Atribuição) */
%left T_OR                     /* \\ */
%left T_AND                    /* && */
%nonassoc T_EQ T_NEQ           /* == != */
%nonassoc T_LT T_GT T_LTE T_GTE /* < > <= >= */
%left '+' '-' T_CONCAT         /* + - ++ (Usei '+' e '-' direto como tokens) */
%left '*' '/'                  /* * / */
%right T_NOT '!'               /* Negação unária (!) */
%left '.' '[' ']'              /* Acesso a membro e índice (colocando ']' aqui ajuda a resolver shift/reduce com arrays) */
%left '(' ')'                  /* Chamada de função e parênteses */



/* Tipos para Não-Terminais (se eles retornarem valores via $$) */
%type <dval> expressao literal_num // Assumindo expressão retorna double por padrão (simplificado)
%type <sval> tipo_nome literal_txt 
%type <bval> literal_bool
%type <dval> acesso_membro     
%type <dval> acesso_indice
%type <dval> chamada_funcao
%type <dval> lista_literal
%type <dval> objeto_literal


%%
/*** Seção de Regras Gramaticais (com printf de depuração) ***/

/* Regra inicial: um programa é uma sequência de declarações */
programa:
      declaracao_lista
    ;

declaracao_lista:
      /* vazio */
    | declaracao_lista declaracao
        { printf("Linha %d: Declaração reconhecida.\n", yylineno); }
    ;

/* Tipos de declarações possíveis */
declaracao:
      definicao_funcao
    | condicional
    | repeticao
    | escopo_isolado
    | excecao
    | atribuicao ';'
    | reatribuicao ';'      
    | comando_show ';'
    | comando_retorno ';'
    | expressao ';' 
    // | bloco             
    | ';'                  
    ;

/* Definição de tipo (retorna o nome como string para uso posterior) */
tipo_nome: T_TYPE_TXT  /
         | T_TYPE_NUM   
         | T_TYPE_BOOL  
         | T_TYPE_OBJ   
         | T_TYPE_LIST  
         | T_TYPE_SILENT
         ;

/* Atribuição com declaração de tipo */
atribuicao:
      tipo_nome T_IDENTIFIER T_ASSIGN expressao
    ;

/* Reatribuição (sem tipo) */
reatribuicao:
      T_IDENTIFIER T_ASSIGN expressao
    ;

/* Definição de Função */
definicao_funcao:
      T_ECHO tipo_nome T_IDENTIFIER '(' parametros_opt ')' bloco
    ;

parametros_opt:
    | parametros
    ;

parametros:
      parametro
    | parametros ',' parametro
    ;

parametro:
      tipo_nome T_IDENTIFIER
    ;

/* Retorno de Função */
comando_retorno:
      T_RETURN expressao
    ;

/* Condicional If-Otif-Other */
condicional:
      T_IF T_ASSIGN expressao bloco lista_otif other_opt
    ;

lista_otif:
      /* vazio */
    | lista_otif T_OTIF T_ASSIGN expressao bloco
    ;

other_opt:
      /* vazio */
    | T_OTHER bloco
    ;

/* Repetição Loop */
repeticao:
      T_LOOP T_ASSIGN loop_especificador bloco
    ;

loop_especificador:
      T_IDENTIFIER ':' expressao  
    | expressao T_TIMES           
    ;

/* Comando Show */
comando_show:
      T_SHOW T_ASSIGN expressao
    ;

/* Tratamento de Exceção */
excecao:
      T_TRY bloco T_OOPS bloco
        { printf("-> Estrutura TRY-OOPS\n"); }
    ;

/* Escopo Isolado */
escopo_isolado:
      T_BUBBLE bloco
        { printf("-> Estrutura BUBBLE\n"); }
    ;

/* Bloco de Código */
bloco:
      '{' declaracao_lista '}'
        { printf("--> Bloco de código {} finalizado\n"); }
    ;

/* --- Expressões (Simplificado - Resultado assumido como double) --- */
expressao:
      literal_num               { $$ = $1; printf("Expr: Literal Num (%f)\n", $$); }
    | literal_txt               { printf("Expr: Literal Txt (%s)\n", $1); free($1); $$ = 0; } // Libera string, retorna 0
    | literal_bool              { $$ = $1; printf("Expr: Literal Bool (%d)\n", $1); } // Retorna int (convertido para double $$)
    | T_IDENTIFIER              { $$ = 0; printf("Expr: ID (%s)\n", $1); free($1); } // Libera ID, retorna 0
    | T_GET                     { $$ = 0; printf("Expr: GET\n"); } // Retorna 0
    | chamada_funcao            { $$ = $1; printf("Expr: Chamada Função\n"); } // Propaga placeholder
    | acesso_membro             { $$ = $1; printf("Expr: Acesso Membro\n"); } // Propaga placeholder
    | acesso_indice             { $$ = $1; printf("Expr: Acesso Indice\n"); } // Propaga placeholder
    | lista_literal             { $$ = $1; printf("Expr: Lista Literal\n"); } // Propaga placeholder
    | objeto_literal            { $$ = $1; printf("Expr: Objeto Literal\n"); } // Propaga placeholder

    /* Operadores Binários */
    | expressao '+' expressao   { $$ = $1 + $3; printf("Expr: +\n"); }
    | expressao '-' expressao   { $$ = $1 - $3; printf("Expr: -\n"); }
    | expressao '*' expressao   { $$ = $1 * $3; printf("Expr: *\n"); }
    | expressao '/' expressao   { if($3 == 0) { yyerror("Divisão por zero"); $$ = 0; } else { $$ = $1 / $3; } printf("Expr: /\n"); }
    | expressao T_CONCAT expressao { printf("AVISO: Concatenação não implementada\n"); $$ = 0; } // Placeholder
    | expressao T_EQ expressao  { $$ = ($1 == $3); printf("Expr: ==\n"); } // Retorna 0 ou 1.0
    | expressao T_NEQ expressao { $$ = ($1 != $3); printf("Expr: !=\n"); }
    | expressao T_LT expressao  { $$ = ($1 < $3); printf("Expr: <\n"); }
    | expressao T_GT expressao  { $$ = ($1 > $3); printf("Expr: >\n"); }
    | expressao T_LTE expressao { $$ = ($1 <= $3); printf("Expr: <=\n"); }
    | expressao T_GTE expressao { $$ = ($1 >= $3); printf("Expr: >=\n"); }
    | expressao T_AND expressao { $$ = ($1 && $3); printf("Expr: &&\n"); } // Lógica C
    | expressao T_OR expressao  { $$ = ($1 || $3); printf("Expr: \\\\\n"); } // Lógica C

    /* Operadores Unários */
    | T_NOT expressao           { $$ = !$2; printf("Expr: !\n"); } // Lógica C
    /* | '-' expressao %prec UMINUS { $$ = -$2; } */

    /* Parênteses */
    | '(' expressao ')'         { $$ = $2; printf("Expr: ()\n"); } /* Propaga o valor interno */
    ;

/* Literais */
literal_num: T_NUM_LITERAL      { $$ = $1; };
literal_txt: T_TXT_LITERAL      { $$ = $1; }; // Retorna char*
literal_bool: T_BOOL_LITERAL   { $$ = $1; }; // Retorna int

/* Acesso a Membro */
acesso_membro: expressao '.' T_IDENTIFIER
               {
                   printf("--> Acesso Membro: %s\n", $3);
                   free($3); // Libera ID do membro
                   $$ = 0; // Valor temporário
               }
               ;

/* Acesso a Índice */
acesso_indice: expressao '[' expressao ']'
               {
                   printf("--> Acesso Indice (valor indice: %f)\n", $3); // $3 é double aqui
                   $$ = 0; // Valor temporário
               }
               ;

/* Chamada de Função */
chamada_funcao: T_IDENTIFIER '(' argumentos_opt ')'
               {
                   printf("--> Chamada Func: %s()\n", $1);
                   free($1); // Libera ID da função
                   $$ = 0; // Valor temporário (retorno da função)
               }
               ;

argumentos_opt: /* vazio */ | argumento_lista ;
argumento_lista: expressao | argumento_lista ',' expressao ;

/* Lista Literal */
lista_literal: '[' elementos_lista_opt ']' { printf("--> Lista Literal\n"); $$ = 0; } ;
elementos_lista_opt: /* vazio */ | elemento_lista ;
elemento_lista: expressao | elemento_lista ',' expressao ;

/* Objeto Literal */
objeto_literal: '{' declaracao_lista '}' { printf("--> Objeto Literal\n"); $$ = 0; } ;


%%
/*** Seção de Código C Adicional ***/

int main(int argc, char **argv) {
    // yydebug = 1; // Habilita modo de debug do Bison via código

    FILE *inputFile = stdin;
    // yyin é global e usado pelo Flex
    extern FILE *yyin;

    if (argc > 1) {
        inputFile = fopen(argv[1], "r");
        if (!inputFile) {
            perror(argv[1]); // Reporta erro se não puder abrir o arquivo
            return 1;
        }
        yyin = inputFile; // Aponta yyin para o arquivo aberto
    } else {
       // Se nenhum arquivo for dado, Flex usará stdin por padrão (yyin já é stdin)
       printf("Lendo da entrada padrão (Ctrl+D para EOF em Linux/WSL, Ctrl+Z em Windows)...\n");
    }

    printf("Iniciando análise...\n"); // Mensagem inicial
    if (yyparse() == 0) { // Inicia a análise. yyparse chama yylex() automaticamente.
        printf("\nAnálise Sintática concluída com sucesso!\n"); // Mensagem de sucesso
    } else {
        printf("\nAnálise Sintática falhou.\n"); // Mensagem de falha
    }

    if (inputFile != stdin) {
        fclose(inputFile); // Fecha o arquivo se ele foi aberto
    }

    return 0;
}

// Função de erro sintático (obrigatória)
void yyerror(const char *s) {
    // Imprime a mensagem de erro, linha e o texto onde ocorreu (se disponível)
    fprintf(stderr, "Erro de Sintaxe na linha %d perto de '%s': %s\n", yylineno, yytext ? yytext : "", s);
    // exit(1); // Pode comentar/remover para que o Bison tente continuar (se possível)
}