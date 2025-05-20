
<p align="center">
  <img src="./logo_echo.png" alt="Echo Logo" width="200"/>
</p>

<h1 align="center">Echo Language</h1>
<p align="center">
Uma linguagem desenvolvida por Luigi Lopes com propósito educacional.
</p>

---

## 🚀 Exemplo de Código

```echo
// Echo Test Sample

show << "--- Variable Declarations and Assignments ---";

txt message << "Hello from Echo!";
show << message;

num count << 10;
show << "Initial count: " ++ count;

bool isReady << true;
show << "Is ready: " ++ isReady;

num anotherNumber << count + 5; // Assignment with an expression
show << "Another number: " ++ anotherNumber;

// Reassignments
message << "Updated message.";
show << message;

count << anotherNumber - count;
show << "Updated count: " ++ count;

isReady << false;
show << "Is ready now: " ++ isReady;

show << "\n--- List and Object Assignments ---";

list items << [1, "two", true];
show << "Items list: " ++ items;

obj details << {
  txt id << "item001";
  num value << 100;
};
show << "Details object: " ++ details;

// Accessing and reassigning list/object members
items[1] << "zwei"; // Reassign list element
show << "Updated items list: " ++ items;

details.value << details.value + 50; // Reassign object member
show << "Updated details object: " ++ details;


show << "\n--- Function Example with Assignments ---";

echo num calculate(num a, num b) {
  num intermediateResult << a * 2;
  
  num finalResult << intermediateResult + b;
  >> finalResult;
}

num calcOutput << calculate(count, 5);
show << "Calculation output: " ++ calcOutput;


show << "\n--- User Input ---";

show << "\n Qual seu nome? ";
txt nome << get;
show << "\n Qual sua idade? ";
txt idade << get;

show << "\n Bem vindo, " ++ nome ++ "! você tem: " ++ idade ++ " anos"; 

show << "\n--- End of Sample ---";

```

## 🚀 Output do Exemplo

```
--- Variable Declarations and Assignments ---
Hello from Echo!
Initial count: 10
Is ready: true
Another number: 15
Updated message.
Updated count: 5
Is ready now: false

--- List and Object Assignments ---
Items list: [1, two, true]
Details object: {id: item001; value: 100}
Updated items list: [1, zwei, true]
Updated details object: {id: item001; value: 150}

--- Function Example with Assignments ---
Calculation output: 15

--- User Input ---

 Qual seu nome?
luigi

 Qual sua idade?
21

 Bem vindo, luigi! você tem: 21 anos

--- End of Sample ---
```

---

## 📦 Tipos Suportados

| Tipo     | Significado                 | Exemplo Literal          |
|----------|-----------------------------|--------------------------|
| `txt`    | Texto (String Unicode)      | `"Olá"`, `"\"Escape\""`   |
| `num`    | Número (Ponto Flutuante 64b)| `10`, `-5.5`, `3.14e-2`  |
| `bool`   | Booleano                    | `true`, `false`          |
| `obj`    | Objeto (Mapa Chave-Valor)   | `{ txt k << "v"; }`      |
| `list`   | Lista Ordenada de Valores   | `[1, "a", true]`         |
| `silent` | Tipo de Retorno Vazio       | (N/A - usado em funções) |

**Observações:**
* Strings usam aspas duplas e suportam escapes como `\n`, `\t`, `\\`, `\"`.
* Números seguem o padrão de ponto flutuante de dupla precisão (IEEE 754).

---

## 🧠 Palavras-chave e Literais Reservados

As seguintes palavras são reservadas e não podem ser usadas como identificadores:

* **Tipos:** `txt`, `num`, `bool`, `obj`, `list`, `silent`
* **Controle de Fluxo:** `if`, `otif`, `other`, `loop`, `times`, `>>` (retorno)
* **Definição:** `echo`
* **Escopo:** `bubble`
* **Tratamento de Erro:** `try`, `oops`
* **I/O:** `show`, `get`
* **Literais Booleanos:** `true`, `false`

---

## 🔤 Operadores

| Categoria        | Operadores                    | Associatividade | Nível Precedência (Exemplo) |
|------------------|-------------------------------|-----------------|-----------------------------|
| Acesso Membro    | `.`                           | Esquerda        | Mais Alta                   |
| Acesso Índice    | `[]`                          | Esquerda        | Mais Alta                   |
| Chamada Função   | `()`                          | Esquerda        | Mais Alta                   |
| Negação          | `!`                           | Direita (prefix)| Alta                        |
| Multiplicativos  | `*`, `/`                      | Esquerda        | Média-Alta                  |
| Aditivos         | `+`, `-`                      | Esquerda        | Média                       |
| Concatenação     | `++`                          | Esquerda        | Média                       |
| Relacionais      | `<`, `>`, `<=`, `>=`           | Esquerda        | Média-Baixa                 |
| Igualdade        | `==`, `!=`                    | Esquerda        | Baixa                       |
| E Lógico         | `&&`                          | Esquerda        | Mais Baixa                  |
| OU Lógico        | `\\`                          | Esquerda        | Mais Baixa                  |
| Atribuição       | `<<`                          | Direita         | Mínima                      |

**Observações:**
* `<<`: Usado para atribuição (`var << val`), mas também na sintaxe de `if << cond`, `loop << spec`, `show << val`. O parser diferencia pelo contexto gramatical.
* `\\`: Operador OU lógico (equivalente a `||` em outras linguagens). Use duas barras invertidas na EBNF/Flex/Bison para escapar.
* `()`: Usado para agrupamento de expressões e chamadas de função.
* A precedência exata e associatividade devem ser implementadas no parser (Bison) para garantir a ordem correta de avaliação das expressões.

---

## ✍️ Comentário

* **Linha Única:** Começam com `//` e vão até o final da linha.
    ```echo
    // Isto é um comentário
    num x << 10; // Comentário após o código
    ```

---

## 🧩 Blocos, Escopo e Parsing

* **Blocos `{}`:** Usados para agrupar múltiplas declarações em estruturas como `if`, `other`, `loop`, `echo`, `bubble`, `try`, `oops`. Também usados na definição literal de `obj`. O parser distingue o uso baseado no contexto gramatical (ex: após `if << expr` espera-se um bloco; após `obj nome <<` espera-se um literal de objeto).
* **Escopo Léxico:** Variáveis declaradas dentro de um bloco (`{...}`, corpo de função, `bubble`) são locais a esse bloco e seus sub-blocos. `bubble` cria um escopo completamente isolado, sem acesso a variáveis externas (a menos que passadas como parâmetros, se aplicável a funções futuras).
* **Ponto e Vírgula `;`:** Termina a maioria das declarações (atribuições, reatribuições, retornos, show, chamadas de função como declaração).

---

## 📚 EBNF (Gramática Formal - Estendida)

<details>
<summary>Clique para expandir</summary>

```ebnf
programa         = { declaracao } ;

declaracao       = definicao_funcao
                 | condicional
                 | repeticao
                 | escopo_isolado
                 | excecao
                 | atribuicao ';'
                 | reatribuicao ';'
                 | expressao ';'  (* Chamada de função ou outra expressão usada como declaração *)
                 | comando_show ';'
                 | comando_retorno ';'
                 | bloco          (* Bloco pode ser uma declaração válida em alguns contextos? *)
                 | ';'            (* Declaração vazia *)
                 ;

bloco            = '{' , { declaracao } , '}' ;

tipo             = 'txt' | 'num' | 'bool' | 'obj' | 'list' | 'silent' ;

atribuicao       = tipo , identificador , '<<' , expressao ; (* Semicolon vem na regra 'declaracao' *)

reatribuicao     = identificador , '<<' , expressao ; (* Semicolon vem na regra 'declaracao' *)

definicao_funcao = 'echo' , tipo , identificador , '(' , [ parametros ] , ')' , bloco ;

parametros       = parametro , { ',' , parametro } ;
parametro        = tipo , identificador ;

comando_retorno  = '>>' , expressao ; (* Semicolon vem na regra 'declaracao' *)

condicional      = 'if' , '<<' , expressao , bloco ,
                   { 'otif' , '<<' , expressao , bloco } ,
                   [ 'other' , bloco ] ;

repeticao        = 'loop' , '<<' , loop_especificador , bloco ;
loop_especificador = ( identificador , ':' , expressao )   (* for-each: loop << item : minhaLista *)
                 | ( expressao , 'times' )             (* times: loop << 5 times ou loop << varNum times *)
                 ;

comando_show     = 'show' , '<<' , expressao ; (* Semicolon vem na regra 'declaracao' *)

comando_get      = 'get' ; (* Usado como 'fator' dentro de 'expressao' *)

excecao          = 'try' , bloco , 'oops' , bloco ;

escopo_isolado   = 'bubble' , bloco ;

(* --- Definição de Expressão (Simplificada - Precedência implícita) --- *)

expressao        = atribuicao_expr     (* Atribuição como expressão, se suportado *)
                 | expressao_logica
                 ;

(* Simplificação: Assumindo que a atribuição tem a menor precedência *)
atribuicao_expr  = identificador , '<<' , expressao
                 | acesso_membro , '<<' , expressao
                 | acesso_indice , '<<' , expressao
                 ;

expressao_logica = expressao_logica , ('&&' | '\\') , expressao_igualdade (* Duas barras para EBNF literal *)
                 | expressao_igualdade
                 ;

expressao_igualdade = expressao_igualdade , ('==' | '!=') , expressao_relacional
                  | expressao_relacional
                  ;

expressao_relacional = expressao_relacional , ('<' | '>' | '<=' | '>=') , expressao_aditiva
                   | expressao_aditiva
                   ;

expressao_aditiva = expressao_aditiva , ('+' | '-' | '++') , expressao_multiplicativa
                  | expressao_multiplicativa
                  ;

expressao_multiplicativa = expressao_multiplicativa , ('*' | '/') , expressao_unaria
                       | expressao_unaria
                       ;

expressao_unaria = ('!') , expressao_unaria  (* Negação prefixa *)
                 | '+' , expressao_unaria  (* + unário, se suportado *)
                 | '-' , expressao_unaria  (* - unário, se suportado *)
                 | fator_primario
                 ;

fator_primario   = literal
                 | identificador
                 | comando_get
                 | acesso_membro
                 | acesso_indice
                 | chamada_funcao
                 | '(' , expressao , ')'
                 ;

literal          = literal_num | literal_txt | literal_bool | literal_obj | literal_list ;
literal_num      = numero_inteiro | numero_decimal ; (* Definido por regex no Flex *)
literal_txt      = '"' , { caractere } , '"' ; (* Definido por regex no Flex *)
literal_bool     = 'true' | 'false' ;
literal_obj      = '{' , [ lista_membros_obj ] , '}' ;
literal_list     = '[' , [ lista_elementos_list ] , ']' ;

lista_membros_obj = atribuicao , { ';' , atribuicao } , [ ';' ] ; (* Atribuições dentro do obj *)

lista_elementos_list = expressao , { ',' , expressao } ;

acesso_membro    = fator_primario , '.' , identificador ; (* obj.membro *)

acesso_indice    = fator_primario , '[' , expressao , ']' ; (* lista[indice] *)

chamada_funcao   = identificador , '(' , [ lista_argumentos ] , ')' ; (* func(arg1, arg2) *)

lista_argumentos = expressao , { ',' , expressao } ;

identificador    = letra , { letra | digito } ; (* Definido por regex no Flex *)
letra            = 'a'..'z' | 'A'..'Z' | '_' ;
digito           = '0'..'9' ;
```
*Nota: A EBNF de expressão acima é uma representação para ilustrar a estrutura. A implementação real no Bison usará as diretivas `%left`, `%right`, `%nonassoc` para definir a precedência e associatividade corretamente.*
</details>

---

## 📚 Biblioteca Padrão (Embutida)

A linguagem Echo fornece algumas funções básicas embutidas:

* **`show << expressao;`**: Imprime a representação textual do valor da `expressao` na saída padrão.
* **`get`**: Lê uma linha de texto da entrada padrão e a retorna como um valor `txt`. É usada como uma expressão.

---

## 👨‍💻 Autor

Desenvolvida por **Luigi Lopes** com propósito educacional.

---
