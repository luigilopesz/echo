/* echo.l */
%{
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <stddef.h> // Define size_t e NULL
#include "echo.tab.h" 

extern YYSTYPE yylval; 
%}


DIGITO    [0-9]
LETRA     [a-zA-Z_]
ID        {LETRA}({LETRA}|{DIGITO})*
NUMERO    {DIGITO}+(\.{DIGITO}+)?([eE][+-]?{DIGITO}+)?

STRING    \"([^"\\\\]|\\.)*\"


%option noyywrap warn
%option yylineno


%x COMMENT

%%


<INITIAL>"/*"  { BEGIN(COMMENT);  }
<COMMENT>"*/"  { BEGIN(INITIAL);  }
<COMMENT>.     {  }
<COMMENT>\n    {  }


[ \t\r]+      { /* Ignora */ }


"//".* { /* Ignora */ }


\n            { /* Nenhuma ação necessária */ }



"echo"        { return T_ECHO; }
">>"          { return T_RETURN; }
"show"        { return T_SHOW; }
"get"         { return T_GET; }
"if"          { return T_IF; }
"otif"        { return T_OTIF; }
"other"       { return T_OTHER; }
"loop"        { return T_LOOP; }
"times"       { return T_TIMES; }
"bubble"      { return T_BUBBLE; }
"try"         { return T_TRY; }
"oops"        { return T_OOPS; }
"true"        { yylval.bval = 1; return T_BOOL_LITERAL; }
"false"       { yylval.bval = 0; return T_BOOL_LITERAL; }


"txt"         { return T_TYPE_TXT; }
"num"         { return T_TYPE_NUM; }
"bool"        { return T_TYPE_BOOL; }
"obj"         { return T_TYPE_OBJ; }
"list"        { return T_TYPE_LIST; }
"silent"      { return T_TYPE_SILENT; }


"<<"          { return T_ASSIGN; }
"++"          { return T_CONCAT; }
"=="          { return T_EQ; }
"!="          { return T_NEQ; }
"<="          { return T_LTE; }
">="          { return T_GTE; }
"&&"          { return T_AND; }
"\\\\"        { return T_OR; } 
"<"           { return T_LT; }
">"           { return T_GT; }
"+"           { return '+'; } 
"-"           { return '-'; }
"*"           { return '*'; }
"/"           { return '/'; }
"!"           { return '!'; }
"."           { return '.'; }
";"           { return ';'; }
","           { return ','; }
":"           { return ':'; }
"("           { return '('; }
")"           { return ')'; }
"{"           { return '{'; }
"}"           { return '}'; }
"["           { return '['; }
"]"           { return ']'; }



{NUMERO}      { yylval.dval = atof(yytext); return T_NUM_LITERAL; }

{STRING}      {
                
                yylval.sval = strdup(yytext + 1);
                if (yylval.sval) {
                    yylval.sval[strlen(yylval.sval) - 1] = '\0'; // Remove a aspa final
                    
                } else {
                    fprintf(stderr, "Erro: Falha ao alocar memória para string na linha %d.\n", yylineno);
                    exit(1);
                }
                return T_TXT_LITERAL;
              }


{ID}          { yylval.sval = strdup(yytext); return T_IDENTIFIER; }


.             { fprintf(stderr, "Erro Léxico na linha %d: Caractere inesperado '%s'\n", yylineno, yytext); }

%%
