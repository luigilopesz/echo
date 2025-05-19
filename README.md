
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
// Exemplo de comentário de linha única


// Leitura de input e declaração
txt nome << get;
num idade << 27;

// Declaração de lista e objeto
list nomes << ["Luigi", "Abate", "Marcelo"];
obj pessoa << {
   txt nome << "Visitante";
   num idade << 0;
   bool ativo << false;
};

// Atribuição e acesso a membros/índices (Sintaxe Exemplo!)
pessoa.nome << nome; // Acessando membro de obj
pessoa.idade << idade + 1;
show << "Primeiro nome na lista: " ++ nomes[0]; // Acessando índice de list e concatenação

// Definição de função
echo bool maior(num idade) {
   if << idade >= 18 {
      >> true;
   } other {
      >> false;
   }
}

// Condicional e chamada de função
if << maior(pessoa.idade) {
   show << pessoa.nome ++ " é maior de idade.";
} other {
   show << pessoa.nome ++ " é menor de idade.";
}

// Loop 'times'
loop << 3 times {
  show << "Loop simples";
}

// Loop 'for-each'
loop << n : nomes {
  show << "Nome: " ++ n;
}

// Escopo isolado
bubble {
   txt temp << "isolado";
   show << temp; // 'temp' só existe aqui
}

// Tratamento de erro (básico)
try {
  num resultado << 10 / 0; // Potencial erro
} oops {
  show << "Opa! Algo deu errado.";
}
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

## ✍️ Comentários

* **Linha Única:** Começam com `//` e vão até o final da linha.
    ```echo
    // Isto é um comentário
    num x << 10; // Comentário após o código
    ```
* **Múltiplas Linhas:** (Opcional - Definir se suportado) Começam com `/*` e terminam com `*/`.
    ```echo
    /*
     Isto é um
     comentário de múltiplas
     linhas.
    */
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
