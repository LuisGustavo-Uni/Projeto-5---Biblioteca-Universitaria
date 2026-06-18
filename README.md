# Projeto-5---Biblioteca-Universitaria
# Sistema de Biblioteca Universitária

## Descrição

Este projeto consiste em um sistema de gerenciamento de biblioteca universitária desenvolvido na linguagem **C**. O programa funciona através do terminal e permite o controle de livros, alunos, empréstimos, categorias e geração de relatórios.

O objetivo do sistema é auxiliar no gerenciamento básico de uma biblioteca acadêmica, possibilitando o cadastro e acompanhamento das operações realizadas.

---

## Funcionalidades

### Módulo de Livros

* Cadastrar livros;
* Listar livros cadastrados;
* Buscar livros por:

  * título;
  * autor;
  * categoria;
* Editar informações de um livro;
* Excluir livros (indisponibilizando sua quantidade).

### Módulo de Alunos

* Cadastrar alunos;
* Listar alunos ativos;
* Buscar alunos;
* Editar informações;
* Excluir alunos logicamente.

### Módulo de Empréstimos

* Registrar empréstimos;
* Registrar devoluções;
* Renovar empréstimos;
* Listar todos os empréstimos realizados.

### Módulo de Categorias

* Cadastrar categorias;
* Listar categorias ativas.

### Relatórios

* Livros mais emprestados;
* Livros disponíveis;
* Livros atualmente emprestados;
* Alunos com maior quantidade de empréstimos;
* Histórico de empréstimos realizados.

---

## Estruturas Utilizadas

O sistema utiliza estruturas (`struct`) para representar os dados:

### Livro

```c
struct Livro {
    int id;
    char titulo[100];
    char autor[100];
    char categoria[50];
    int quantidadeTotal;
    int quantidadeDisp;
    int emprestimos;
};
```

### Aluno

```c
struct Aluno {
    int id;
    char nome[50];
    char curso[50];
    int idade;
    int ativo;
    int totalEmprestimos;
};
```

### Empréstimo

```c
struct Emprestimo {
    int id;
    int idAluno;
    int idLivro;
    char dataEmp[20];
    char dataDev[20];
    int ativo;
    int renovado;
};
```

### Categoria

```c
struct Categoria {
    int id;
    char nome[50];
    int ativo;
};
```

---

## Tecnologias Utilizadas

* Linguagem C;
* Biblioteca padrão:

  * `stdio.h`
  * `string.h`

---

## Como Compilar

Utilize o compilador GCC:

```bash
gcc biblioteca.c -o biblioteca
```

---

## Como Executar

Após a compilação:

### Linux / macOS

```bash
./biblioteca
```

### Windows

```bash
biblioteca.exe
```

---

## Estrutura do Sistema

```
Sistema Biblioteca
│
├── Módulo de Livros
├── Módulo de Alunos
├── Módulo de Empréstimos
├── Módulo de Categorias
└── Relatórios
```

---

## Limitações da Versão Atual

* Os dados são armazenados apenas em memória;
* Não há persistência em arquivos ou banco de dados;
* O sistema suporta até 100 registros de cada estrutura;
* Alguns recursos podem ser aprimorados, como:

  * validação de entradas;
  * busca parcial por texto;
  * ordenação dos relatórios;
  * exclusão lógica de livros;
  * atualização automática da quantidade disponível na devolução.

---

## Melhorias Futuras

* Persistência dos dados em arquivos;
* Utilização de banco de dados;
* Interface gráfica;
* Controle de multas e atrasos;
* Relatórios ordenados automaticamente;
* Sistema de autenticação de usuários.

---

## Autor

Projeto desenvolvido como atividade acadêmica para a disciplina de Programação em Linguagem C.
