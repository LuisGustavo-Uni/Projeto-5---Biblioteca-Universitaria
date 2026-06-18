# 📚 Sistema de Biblioteca Universitária em C
# Prof Hudson Neves e Silva

## 📖 Sobre o Projeto

Este projeto é um **Sistema de Gerenciamento de Biblioteca Universitária** desenvolvido na linguagem **C**, utilizando estruturas (`struct`), vetores e menus interativos no terminal.

O sistema permite o controle de:

* Livros
* Alunos
* Categorias
* Empréstimos
* Relatórios gerenciais

Todos os dados são armazenados em memória durante a execução do programa.

---

## 🚀 Funcionalidades

### 📚 Módulo de Livros

* Cadastrar livros
* Listar livros cadastrados
* Buscar livro por:

  * Título
  * Autor
  * Categoria
* Editar informações
* Excluir livros

### 👨‍🎓 Módulo de Alunos

* Cadastrar alunos
* Listar alunos
* Buscar aluno por nome
* Editar cadastro
* Excluir aluno

### 🏷️ Módulo de Categorias

* Cadastrar categorias
* Listar categorias
* Editar categorias
* Excluir categorias

### 🔄 Módulo de Empréstimos

* Registrar empréstimos
* Registrar devoluções
* Renovar empréstimos
* Listar empréstimos

### 📊 Relatórios

* Livros mais emprestados
* Livros disponíveis
* Empréstimos ativos
* Quantidade de empréstimos por aluno
* Histórico de empréstimos

---

## 🏗️ Estruturas Utilizadas

### Livro

```c
typedef struct {
    int id;
    char titulo[100];
    char autor[100];
    char categoria[50];
    int quantidadeTotal;
    int quantidadeDisp;
    int emprestimos;
    int ativo;
} Livro;
```

### Aluno

```c
typedef struct {
    int id;
    char nome[100];
    char curso[100];
    int idade;
    int ativo;
    int totalEmprestimos;
} Aluno;
```

### Empréstimo

```c
typedef struct {
    int id;
    int idAluno;
    int idLivro;
    char dataEmp[20];
    char dataDev[20];
    int ativo;
    int renovado;
} Emprestimo;
```

### Categoria

```c
typedef struct {
    int id;
    char nome[50];
    int ativo;
} Categoria;
```

---

## 🗂️ Estrutura do Sistema

```text
Sistema Principal
│
├── Livros
│   ├── Cadastrar
│   ├── Listar
│   ├── Buscar
│   ├── Editar
│   └── Excluir
│
├── Alunos
│   ├── Cadastrar
│   ├── Listar
│   ├── Buscar
│   ├── Editar
│   └── Excluir
│
├── Categorias
│   ├── Cadastrar
│   ├── Listar
│   ├── Editar
│   └── Excluir
│
├── Empréstimos
│   ├── Registrar
│   ├── Devolver
│   ├── Renovar
│   └── Listar
│
└── Relatórios
    ├── Livros mais emprestados
    ├── Livros disponíveis
    ├── Empréstimos ativos
    ├── Alunos e empréstimos
    └── Histórico
```

---

## ⚙️ Como Compilar

Utilizando o GCC:

```bash
gcc biblioteca.c -o biblioteca
```

---

## ▶️ Como Executar

Linux/macOS:

```bash
./biblioteca
```

Windows:

```bash
biblioteca.exe
```

---

## 📋 Exemplo de Menu Principal

```text
==============================
 BIBLIOTECA UNIVERSITARIA
==============================
1 - Livros
2 - Alunos
3 - Emprestimos
4 - Categorias
5 - Relatorios
0 - Sair
```

---

## 🔍 Regras Implementadas

* Cada livro possui quantidade total e quantidade disponível.
* Não é possível realizar empréstimo de livro indisponível.
* Apenas alunos cadastrados podem realizar empréstimos.
* Apenas livros cadastrados podem ser emprestados.
* Um empréstimo pode ser renovado apenas uma vez.
* Ao devolver um livro, a quantidade disponível é atualizada automaticamente.
* Exclusões são lógicas, utilizando o campo `ativo`.

---

## 📚 Conceitos de Programação Utilizados

* Linguagem C
* Structs
* Vetores
* Modularização por funções
* Menus interativos
* Busca sequencial
* Manipulação de strings
* Controle de estoque
* CRUD (Create, Read, Update, Delete)

---

## 🚧 Limitações Atuais

* Os dados não são salvos em arquivos.
* Os registros são armazenados apenas durante a execução.
* Limite máximo de 100 registros por entidade.
* Não há autenticação de usuários.
* A busca é realizada por comparação exata de texto.

---

## 🔮 Melhorias Futuras

* Persistência em arquivos (`.txt` ou `.bin`)
* Integração com banco de dados
* Busca parcial por palavras-chave
* Ordenação de relatórios
* Interface gráfica
* Controle de multas e atrasos
* Sistema de login e permissões

---



