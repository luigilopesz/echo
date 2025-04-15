<p align="center">
  <img src="./logo_echo.png" alt="Echo Logo" width="200"/>
</p>

<h1 align="center">Echo Language</h1>
<p align="center">
  Uma linguagem minimalista, tipada e moderna criada por <strong>Luigi Lopes</strong>.
</p>

---

## ✨ Visão Geral

**Echo** é uma linguagem de programação autoral com foco em:

- Sintaxe limpa
- Blocos visuais com `<<` e `>>`
- Tipagem explícita e simples
- Escopos isolados com `bubble`
- Funções com `echo`
- Controle visual de fluxo com `otif` e `other`
- Blocos e objetos diferenciados por contexto no parser

---

## 🚀 Exemplo de Código

```echo
txt nome << get;
num idade << 27;

echo bool maior(num idade) {
   if << idade > 18 {
      >> true;
   } other {
      >> false;
   }
}

if << maior(idade) {
   show << "Maior de idade";
} other {
   show << "Menor de idade";
}

bubble {
   txt temp << "isolado";
   show << temp;
}

obj pessoa << {
   txt nome << "Luigi";
   num idade << 27;
   bool ativo << true;
};
```

---

## 📦 Tipos suportados

| Tipo     | Significado                 |
|----------|-----------------------------|
| `txt`    | Texto (string)              |
| `num`    | Número (int/float)          |
| `bool`   | Booleano (`true`, `false`)  |
| `obj`    | Objeto                      |
| `list`   | Lista de valores            |
| `silent` | Função sem retorno (`void`) |

---

## 🧠 Palavras-chave

- **`echo`**: definição de função  
- **`>>`**: retorno de função  
- **`show << ...;`**: imprimir algo  
- **`get`**: ler input do usuário  
- **`if << condicao { ... }`**: condicional  
- **`otif << ...`**, **`other`**: encadeamento  
- **`loop << item : lista { ... }`**: iteração  
- **`bubble { ... }`**: escopo isolado  
- **`try { ... } oops { ... }`**: tratamento de erro

---

## 🔤 Operadores suportados

| Categoria   | Operadores                    |
|-------------|-------------------------------|
| Aritméticos | `+`, `-`, `*`, `/`            |
| Concatenação | `++`                          |
| Relacionais | `==`, `!=`, `<`, `>`, `<=`, `>=` |
| Booleanos   | `&&`, `||`, `!`               |

---

## 🧩 Blocos e Parsing

- O `{}` representa **blocos de código ou objetos**, dependendo do contexto.
- O parser mantém um estado `@context` que define como interpretar o `{}`.
- Exemplo:
  - `if << cond { ... }` → bloco
  - `obj pessoa << { ... }` → objeto
  - `x << { ... }` → objeto anônimo

---

## 📚 EBNF simplificada

<details>
<summary>Clique para expandir</summary>

```ebnf
programa         = { declaração } ;
declaração       = bloco | definicao_funcao | condicional | repeticao | escopo_isolado |
                   excecao | atribuicao | reatribuicao | chamada_funcao | comando_show | ";" ;
bloco            = "{" , { declaração } , "}" ;
tipo             = "txt" | "num" | "bool" | "obj" | "list" | "silent" ;
atribuicao       = tipo , identificador , "<<" , expressao , ";" ;
reatribuicao     = identificador , "<<" , expressao , ";" ;
definicao_funcao = "echo" , tipo , identificador , "(" , [ parametros ] , ")" , bloco ;
retorno          = ">>" , expressao , ";" ;
condicional      = "if" , "<<" , expressao , bloco ,
                   { "otif" , "<<" , expressao , bloco } ,
                   [ "other" , bloco ] ;
repeticao        = "loop" , "<<" , ( identificador , ":" , identificador | numero , "times" ) , bloco ;
comando_show     = "show" , "<<" , expressao , ";" ;
comando_get      = "get" ;  // usado como expressão
excecao          = "try" , bloco , "oops" , bloco ;
escopo_isolado   = "bubble" , bloco ;
expressao        = ... // ver versão completa
objeto           = "{" , { atribuicao } , "}" ;
lista            = "[" , [ expressao , { "," , expressao } ] , "]" ;
```

</details>

---

## 👨‍💻 Autor

Desenvolvida por **Luigi Lopes** com propósito educacional, artístico e como experimento de linguagem visual e sintática.

---

## 🖼️ Logo

A logo foi criada com base em um estilo limpo e geométrico, com as letras **E-C-H-O** integradas em um círculo branco.

> Para usá-la no seu repositório, renomeie o arquivo da logo como `logo_echo.png` e adicione-o ao seu projeto.