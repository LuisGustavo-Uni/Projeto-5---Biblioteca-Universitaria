#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// ================= LIVROS =================

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

// ================= ALUNOS =================

typedef struct {
    int id;
    char nome[100];
    char curso[100];
    int idade;
    int ativo;
    int totalEmprestimos;
} Aluno;

// ================= EMPRESTIMOS =================

typedef struct {
    int id;
    int idAluno;
    int idLivro;
    char dataEmp[20];
    char dataDev[20];
    int ativo;
    int renovado;
} Emprestimo;

// ================= CATEGORIAS =================

typedef struct {
    int id;
    char nome[50];
    int ativo;
} Categoria;

// ================= VETORES =================

Livro livros[MAX];
Aluno alunos[MAX];
Emprestimo emprestimos[MAX];
Categoria categorias[MAX];

int totalLivros = 0;
int totalAlunos = 0;
int totalEmprestimos = 0;
int totalCategorias = 0;

// ================= PROTOTIPOS =================

int buscarLivro(int id);
int buscarAluno(int id);
int buscarCategoria(int id);

void menuLivros();
void menuAlunos();
void menuEmprestimos();
void menuCategorias();
void relatorios();

// ================= BUSCAS =================

int buscarLivro(int id) {

    for(int i = 0; i < totalLivros; i++) {

        if(livros[i].id == id && livros[i].ativo)
            return i;
    }

    return -1;
}

int buscarAluno(int id) {

    for(int i = 0; i < totalAlunos; i++) {

        if(alunos[i].id == id && alunos[i].ativo)
            return i;
    }

    return -1;
}

int buscarCategoria(int id) {

    for(int i = 0; i < totalCategorias; i++) {

        if(categorias[i].id == id && categorias[i].ativo)
            return i;
    }

    return -1;
}

// ================= LIVROS =================

void cadastrarLivro() {

    if(totalLivros >= MAX) {
        printf("\nLimite de livros atingido.\n");
        return;
    }

    Livro novo;

    novo.id = totalLivros + 1;
    novo.ativo = 1;
    novo.emprestimos = 0;

    printf("\nTitulo: ");
    scanf(" %[^\n]", novo.titulo);

    printf("Autor: ");
    scanf(" %[^\n]", novo.autor);

    printf("Categoria: ");
    scanf(" %[^\n]", novo.categoria);

    printf("Quantidade total: ");
    scanf("%d", &novo.quantidadeTotal);

    novo.quantidadeDisp = novo.quantidadeTotal;

    livros[totalLivros++] = novo;

    printf("\nLivro cadastrado com sucesso!\n");
}

void listarLivros() {

    printf("\n===== LIVROS =====\n");

    for(int i = 0; i < totalLivros; i++) {

        if(livros[i].ativo) {

            printf("\nID: %d", livros[i].id);
            printf("\nTitulo: %s", livros[i].titulo);
            printf("\nAutor: %s", livros[i].autor);
            printf("\nCategoria: %s", livros[i].categoria);
            printf("\nDisponiveis: %d/%d",
                   livros[i].quantidadeDisp,
                   livros[i].quantidadeTotal);
            printf("\n----------------------\n");
        }
    }
}

void buscarLivroNome() {

    char busca[100];
    int encontrou = 0;

    printf("\nDigite titulo, autor ou categoria: ");
    scanf(" %[^\n]", busca);

    for(int i = 0; i < totalLivros; i++) {

        if(!livros[i].ativo)
            continue;

        if(strcmp(livros[i].titulo, busca) == 0 ||
           strcmp(livros[i].autor, busca) == 0 ||
           strcmp(livros[i].categoria, busca) == 0) {

            printf("\nLivro encontrado:");
            printf("\nID: %d", livros[i].id);
            printf("\nTitulo: %s", livros[i].titulo);
            printf("\nAutor: %s", livros[i].autor);
            printf("\nCategoria: %s\n", livros[i].categoria);

            encontrou = 1;
        }
    }

    if(!encontrou)
        printf("\nNenhum livro encontrado.\n");
}

void editarLivro() {

    int id;

    printf("\nDigite o ID do livro: ");
    scanf("%d", &id);

    int pos = buscarLivro(id);

    if(pos == -1) {

        printf("\nLivro nao encontrado.\n");
        return;
    }

    printf("Novo titulo: ");
    scanf(" %[^\n]", livros[pos].titulo);

    printf("Novo autor: ");
    scanf(" %[^\n]", livros[pos].autor);

    printf("Nova categoria: ");
    scanf(" %[^\n]", livros[pos].categoria);

    printf("\nLivro atualizado.\n");
}

void excluirLivro() {

    int id;

    printf("\nID do livro: ");
    scanf("%d", &id);

    int pos = buscarLivro(id);

    if(pos == -1) {

        printf("\nLivro nao encontrado.\n");
        return;
    }

    livros[pos].ativo = 0;

    printf("\nLivro removido.\n");
}

void menuLivros() {

    int op;

    do {

        printf("\n===== MODULO LIVROS =====\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar\n");
        printf("4 - Editar\n");
        printf("5 - Excluir\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");

        scanf("%d", &op);

        switch(op) {

            case 1:
                cadastrarLivro();
                break;

            case 2:
                listarLivros();
                break;

            case 3:
                buscarLivroNome();
                break;

            case 4:
                editarLivro();
                break;

            case 5:
                excluirLivro();
                break;
        }

    } while(op != 0);
}
//
// ================= ALUNOS =================
//

void cadastrarAluno() {

    if(totalAlunos >= MAX) {
        printf("\nLimite de alunos atingido.\n");
        return;
    }

    Aluno novo;

    novo.id = totalAlunos + 1;
    novo.ativo = 1;
    novo.totalEmprestimos = 0;

    printf("\nNome: ");
    scanf(" %[^\n]", novo.nome);

    printf("Curso: ");
    scanf(" %[^\n]", novo.curso);

    printf("Idade: ");
    scanf("%d", &novo.idade);

    alunos[totalAlunos++] = novo;

    printf("\nAluno cadastrado com sucesso!\n");
}

void listarAlunos() {

    printf("\n===== ALUNOS =====\n");

    for(int i = 0; i < totalAlunos; i++) {

        if(alunos[i].ativo) {

            printf("\nID: %d", alunos[i].id);
            printf("\nNome: %s", alunos[i].nome);
            printf("\nCurso: %s", alunos[i].curso);
            printf("\nIdade: %d", alunos[i].idade);
            printf("\nTotal emprestimos: %d",
                   alunos[i].totalEmprestimos);
            printf("\n----------------------\n");
        }
    }
}

void buscarAlunoNome() {

    char nome[100];
    int encontrou = 0;

    printf("\nDigite o nome do aluno: ");
    scanf(" %[^\n]", nome);

    for(int i = 0; i < totalAlunos; i++) {

        if(!alunos[i].ativo)
            continue;

        if(strcmp(alunos[i].nome, nome) == 0) {

            printf("\nAluno encontrado:");
            printf("\nID: %d", alunos[i].id);
            printf("\nNome: %s", alunos[i].nome);
            printf("\nCurso: %s", alunos[i].curso);
            printf("\nIdade: %d\n", alunos[i].idade);

            encontrou = 1;
        }
    }

    if(!encontrou)
        printf("\nAluno nao encontrado.\n");
}

void editarAluno() {

    int id;

    printf("\nDigite o ID do aluno: ");
    scanf("%d", &id);

    int pos = buscarAluno(id);

    if(pos == -1) {

        printf("\nAluno nao encontrado.\n");
        return;
    }

    printf("Novo nome: ");
    scanf(" %[^\n]", alunos[pos].nome);

    printf("Novo curso: ");
    scanf(" %[^\n]", alunos[pos].curso);

    printf("Nova idade: ");
    scanf("%d", &alunos[pos].idade);

    printf("\nAluno atualizado com sucesso.\n");
}

void excluirAluno() {

    int id;

    printf("\nDigite o ID do aluno: ");
    scanf("%d", &id);

    int pos = buscarAluno(id);

    if(pos == -1) {

        printf("\nAluno nao encontrado.\n");
        return;
    }

    alunos[pos].ativo = 0;

    printf("\nAluno removido.\n");
}

void menuAlunos() {

    int op;

    do {

        printf("\n===== MODULO ALUNOS =====\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar\n");
        printf("4 - Editar\n");
        printf("5 - Excluir\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");

        scanf("%d", &op);

        switch(op) {

            case 1:
                cadastrarAluno();
                break;

            case 2:
                listarAlunos();
                break;

            case 3:
                buscarAlunoNome();
                break;

            case 4:
                editarAluno();
                break;

            case 5:
                excluirAluno();
                break;
        }

    } while(op != 0);
}

//
// ================= CATEGORIAS =================
//

void cadastrarCategoria() {

    if(totalCategorias >= MAX) {
        printf("\nLimite de categorias atingido.\n");
        return;
    }

    Categoria nova;

    nova.id = totalCategorias + 1;
    nova.ativo = 1;

    printf("\nNome da categoria: ");
    scanf(" %[^\n]", nova.nome);

    categorias[totalCategorias++] = nova;

    printf("\nCategoria cadastrada com sucesso.\n");
}

void listarCategorias() {

    printf("\n===== CATEGORIAS =====\n");

    for(int i = 0; i < totalCategorias; i++) {

        if(categorias[i].ativo) {

            printf("%d - %s\n",
                   categorias[i].id,
                   categorias[i].nome);
        }
    }
}

void editarCategoria() {

    int id;

    printf("\nID da categoria: ");
    scanf("%d", &id);

    int pos = buscarCategoria(id);

    if(pos == -1) {

        printf("\nCategoria nao encontrada.\n");
        return;
    }

    printf("Novo nome: ");
    scanf(" %[^\n]", categorias[pos].nome);

    printf("\nCategoria atualizada.\n");
}

void excluirCategoria() {

    int id;

    printf("\nID da categoria: ");
    scanf("%d", &id);

    int pos = buscarCategoria(id);

    if(pos == -1) {

        printf("\nCategoria nao encontrada.\n");
        return;
    }

    categorias[pos].ativo = 0;

    printf("\nCategoria removida.\n");
}

void menuCategorias() {

    int op;

    do {

        printf("\n===== MODULO CATEGORIAS =====\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Editar\n");
        printf("4 - Excluir\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");

        scanf("%d", &op);

        switch(op) {

            case 1:
                cadastrarCategoria();
                break;

            case 2:
                listarCategorias();
                break;

            case 3:
                editarCategoria();
                break;

            case 4:
                excluirCategoria();
                break;
        }

    } while(op != 0);
}
//
// ================= EMPRESTIMOS =================
//

void registrarEmprestimo() {

    if(totalEmprestimos >= MAX) {
        printf("\nLimite de emprestimos atingido.\n");
        return;
    }

    int idAluno, idLivro;

    printf("\nID do aluno: ");
    scanf("%d", &idAluno);

    int posAluno = buscarAluno(idAluno);

    if(posAluno == -1) {
        printf("\nAluno nao encontrado.\n");
        return;
    }

    printf("ID do livro: ");
    scanf("%d", &idLivro);

    int posLivro = buscarLivro(idLivro);

    if(posLivro == -1) {
        printf("\nLivro nao encontrado.\n");
        return;
    }

    if(livros[posLivro].quantidadeDisp <= 0) {
        printf("\nLivro indisponivel.\n");
        return;
    }

    Emprestimo novo;

    novo.id = totalEmprestimos + 1;
    novo.idAluno = idAluno;
    novo.idLivro = idLivro;
    novo.ativo = 1;
    novo.renovado = 0;

    printf("Data do emprestimo: ");
    scanf(" %[^\n]", novo.dataEmp);

    strcpy(novo.dataDev, "-");

    livros[posLivro].quantidadeDisp--;
    livros[posLivro].emprestimos++;

    alunos[posAluno].totalEmprestimos++;

    emprestimos[totalEmprestimos++] = novo;

    printf("\nEmprestimo registrado com sucesso.\n");
}

void devolverLivro() {

    int idEmp;

    printf("\nID do emprestimo: ");
    scanf("%d", &idEmp);

    for(int i = 0; i < totalEmprestimos; i++) {

        if(emprestimos[i].id == idEmp &&
           emprestimos[i].ativo) {

            emprestimos[i].ativo = 0;

            printf("Data devolucao: ");
            scanf(" %[^\n]", emprestimos[i].dataDev);

            int posLivro =
                buscarLivro(emprestimos[i].idLivro);

            if(posLivro != -1)
                livros[posLivro].quantidadeDisp++;

            printf("\nLivro devolvido.\n");
            return;
        }
    }

    printf("\nEmprestimo nao encontrado.\n");
}

void renovarEmprestimo() {

    int idEmp;

    printf("\nID do emprestimo: ");
    scanf("%d", &idEmp);

    for(int i = 0; i < totalEmprestimos; i++) {

        if(emprestimos[i].id == idEmp &&
           emprestimos[i].ativo) {

            if(emprestimos[i].renovado) {

                printf("\nEmprestimo ja renovado.\n");
                return;
            }

            emprestimos[i].renovado = 1;

            printf("\nEmprestimo renovado.\n");
            return;
        }
    }

    printf("\nEmprestimo nao encontrado.\n");
}

void listarEmprestimos() {

    printf("\n===== EMPRESTIMOS =====\n");

    for(int i = 0; i < totalEmprestimos; i++) {

        printf("\nID: %d", emprestimos[i].id);
        printf("\nAluno: %d", emprestimos[i].idAluno);
        printf("\nLivro: %d", emprestimos[i].idLivro);
        printf("\nData Emp.: %s", emprestimos[i].dataEmp);
        printf("\nData Dev.: %s", emprestimos[i].dataDev);
        printf("\nAtivo: %s",
               emprestimos[i].ativo ? "SIM" : "NAO");
        printf("\nRenovado: %s",
               emprestimos[i].renovado ? "SIM" : "NAO");
        printf("\n----------------------\n");
    }
}

void menuEmprestimos() {

    int op;

    do {

        printf("\n===== MODULO EMPRESTIMOS =====\n");
        printf("1 - Registrar\n");
        printf("2 - Devolucao\n");
        printf("3 - Renovar\n");
        printf("4 - Listar\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");

        scanf("%d", &op);

        switch(op) {

            case 1:
                registrarEmprestimo();
                break;

            case 2:
                devolverLivro();
                break;

            case 3:
                renovarEmprestimo();
                break;

            case 4:
                listarEmprestimos();
                break;
        }

    } while(op != 0);
}

//
// ================= RELATORIOS =================
//

void relatorios() {

    int op;

    do {

        printf("\n===== RELATORIOS =====\n");
        printf("1 - Livros mais emprestados\n");
        printf("2 - Livros disponiveis\n");
        printf("3 - Emprestimos ativos\n");
        printf("4 - Alunos e emprestimos\n");
        printf("5 - Historico de emprestimos\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");

        scanf("%d", &op);

        switch(op) {

            case 1:

                printf("\n===== LIVROS MAIS EMPRESTADOS =====\n");

                for(int i = 0; i < totalLivros; i++) {

                    if(livros[i].ativo) {

                        printf("%s - %d emprestimos\n",
                               livros[i].titulo,
                               livros[i].emprestimos);
                    }
                }

                break;

            case 2:

                printf("\n===== LIVROS DISPONIVEIS =====\n");

                for(int i = 0; i < totalLivros; i++) {

                    if(livros[i].ativo &&
                       livros[i].quantidadeDisp > 0) {

                        printf("%s (%d disponiveis)\n",
                               livros[i].titulo,
                               livros[i].quantidadeDisp);
                    }
                }

                break;

            case 3:

                printf("\n===== EMPRESTIMOS ATIVOS =====\n");

                for(int i = 0; i < totalEmprestimos; i++) {

                    if(emprestimos[i].ativo) {

                        printf("Emprestimo %d | Livro %d | Aluno %d\n",
                               emprestimos[i].id,
                               emprestimos[i].idLivro,
                               emprestimos[i].idAluno);
                    }
                }

                break;

            case 4:

                printf("\n===== ALUNOS =====\n");

                for(int i = 0; i < totalAlunos; i++) {

                    if(alunos[i].ativo) {

                        printf("%s - %d emprestimos\n",
                               alunos[i].nome,
                               alunos[i].totalEmprestimos);
                    }
                }

                break;

            case 5:

                printf("\n===== HISTORICO =====\n");

                for(int i = 0; i < totalEmprestimos; i++) {

                    printf("Aluno %d | Livro %d | %s\n",
                           emprestimos[i].idAluno,
                           emprestimos[i].idLivro,
                           emprestimos[i].dataEmp);
                }

                break;
        }

    } while(op != 0);
}

//
// ================= MAIN =================
//

int main() {

    int op;

    do {

        printf("\n==============================\n");
        printf(" BIBLIOTECA UNIVERSITARIA\n");
        printf("==============================\n");
        printf("1 - Livros\n");
        printf("2 - Alunos\n");
        printf("3 - Emprestimos\n");
        printf("4 - Categorias\n");
        printf("5 - Relatorios\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        scanf("%d", &op);

        switch(op) {

            case 1:
                menuLivros();
                break;

            case 2:
                menuAlunos();
                break;

            case 3:
                menuEmprestimos();
                break;

            case 4:
                menuCategorias();
                break;

            case 5:
                relatorios();
                break;

            case 0:
                printf("\nEncerrando sistema...\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
        }

    } while(op != 0);

    return 0;
}
