#include <stdio.h>
#include <string.h>

#define MAX 100

// ================= LIVROS =================
struct Livro {
    int id;
    char titulo[100];
    char autor[100];
    char categoria[50];
    int quantidadeTotal;
    int quantidadeDisp;
    int emprestimos;
};

// ================= ALUNOS =================
struct Aluno {
    int id;
    char nome[50];
    char curso[50];
    int idade;
    int ativo;
    int totalEmprestimos;
};

// ================= EMPRESTIMOS =================
struct Emprestimo {
    int id;
    int idAluno;
    int idLivro;
    char dataEmp[20];
    char dataDev[20];
    int ativo;
    int renovado;
};

// ================= CATEGORIAS =================
struct Categoria {
    int id;
    char nome[50];
    int ativo;
};

// ================= DADOS GLOBAIS =================
struct Livro livros[MAX];
int totalLivros = 0;

struct Aluno alunos[MAX];
int totalAlunos = 0;

struct Emprestimo emprestimos[MAX];
int totalEmprestimos = 0;

struct Categoria categorias[MAX];
int totalCategorias = 0;

// ================= Funções Auxiliar=================

int buscarLivro(int id) {
    for (int i = 0; i < totalLivros; i++)
        if (livros[i].id == id) return i;
    return -1;
}

int buscarAluno(int id) {
    for (int i = 0; i < totalAlunos; i++)
        if (alunos[i].id == id) return i;
    return -1;
}

// ================= RELATÓRIOS =================
void relatorios() {
    int op;

    do {
        printf("\n===== RELATORIOS =====\n");
        printf("1 - Livros mais emprestados\n");
        printf("2 - Livros disponiveis\n");
        printf("3 - Livros emprestados\n");
        printf("4 - Alunos com mais emprestimos\n");
        printf("5 - Historico emprestimos\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        if (op == 1) {
            for (int i = 0; i < totalLivros; i++) {
                printf("%d - %s (%d)\n",
                       livros[i].id,
                       livros[i].titulo,
                       livros[i].emprestimos);
            }
        }

        else if (op == 2) {
            for (int i = 0; i < totalLivros; i++) {
                if (livros[i].quantidadeDisp > 0)
                    printf("%s - Disp: %d\n",
                           livros[i].titulo,
                           livros[i].quantidadeDisp);
            }
        }

        else if (op == 3) {
            for (int i = 0; i < totalEmprestimos; i++) {
                if (emprestimos[i].ativo)
                    printf("Livro ID %d com aluno ID %d\n",
                           emprestimos[i].idLivro,
                           emprestimos[i].idAluno);
            }
        }

        else if (op == 4) {
            for (int i = 0; i < totalAlunos; i++) {
                printf("%s - %d emprestimos\n",
                       alunos[i].nome,
                       alunos[i].totalEmprestimos);
            }
        }

        else if (op == 5) {
            for (int i = 0; i < totalEmprestimos; i++) {
                printf("Aluno %d - Livro %d - %s\n",
                       emprestimos[i].idAluno,
                       emprestimos[i].idLivro,
                       emprestimos[i].dataEmp);
            }
        }

    } while (op != 0);
}

// ================= MENU =================
int main() {

    int op;

    do {
        printf("\n===== BIBLIOTECA UNIVERSITARIA =====\n");
        printf("1-Modulo de Livros\n");
        printf("2-Modulo de Alunos\n");
        printf("3-Modulo de Emprestimos\n");
        printf("4-Modulo de Categorias\n");
        printf("5-Relatorios\n");
        printf("6-Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        // ================= LIVROS =================
        if (op == 1) {
            int o;

            do {
                printf("\n==== Livros ====\n");
                printf("\n1-Cadastrar\n");
                printf("2-Listar\n");
                printf("3-Buscar\n");
                printf("4-Editar\n");
                printf("5-Excluir\n");
                printf("6-Sair\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &o);

                if (o == 1) {
                    livros[totalLivros].id = totalLivros + 1;

                    printf("Titulo: ");
                    scanf(" %[^\n]", livros[totalLivros].titulo);

                    printf("Autor: ");
                    scanf(" %[^\n]", livros[totalLivros].autor);

                    printf("Categoria: ");
                    scanf(" %[^\n]", livros[totalLivros].categoria);

                    printf("Quantidade: ");
                    scanf("%d", &livros[totalLivros].quantidadeTotal);

                    livros[totalLivros].quantidadeDisp = livros[totalLivros].quantidadeTotal;
                    livros[totalLivros].emprestimos = 0;

                    totalLivros++;
                }

                else if (o == 2) {
                    for (int i = 0; i < totalLivros; i++)
                        printf("%d - %s - %s - %d\n",
                               livros[i].id,
                               livros[i].titulo,
                               livros[i].autor,
                               livros[i].quantidadeDisp);
                }

                else if (o == 3) {
                    char busca[100];
                    scanf(" %[^\n]", busca);

                    for (int i = 0; i < totalLivros; i++) {
                        if (strcmp(livros[i].titulo, busca) == 0 ||
                            strcmp(livros[i].autor, busca) == 0 ||
                            strcmp(livros[i].categoria, busca) == 0) {

                            printf("Encontrado: %s\n", livros[i].titulo);
                        }
                    }
                }

                else if (o == 4) {
                    int id;
                    scanf("%d", &id);

                    int i = buscarLivro(id);

                    if (i != -1) {
                        printf("Novo titulo: ");
                        scanf(" %[^\n]", livros[i].titulo);
                    }
                }

                else if (o == 5) {
                    int id;
                    scanf("%d", &id);

                    int i = buscarLivro(id);
                    if (i != -1) livros[i].quantidadeDisp = 0;
                }

            } while (o != 0);
        }

        // ================= ALUNOS =================
        else if (op == 2) {

            int o;

            do {
                printf("\n==== ALUNOS ====\n");
                printf("\n1-Cadastrar");
                printf("\n2-Listar\n");
                printf("3-Buscar\n");
                printf("4-Editar\n");
                printf("5-Excluir\n");
                printf("6-Sair\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &o);

                if (o == 1) {
                    alunos[totalAlunos].id = totalAlunos + 1;
                    alunos[totalAlunos].ativo = 1;
                    alunos[totalAlunos].totalEmprestimos = 0;

                    scanf(" %[^\n]", alunos[totalAlunos].nome);
                    scanf(" %[^\n]", alunos[totalAlunos].curso);
                    scanf("%d", &alunos[totalAlunos].idade);

                    totalAlunos++;
                }

                else if (o == 2) {
                    for (int i = 0; i < totalAlunos; i++)
                        if (alunos[i].ativo)
                            printf("%d - %s\n", alunos[i].id, alunos[i].nome);
                }

            } while (o != 0);
        }

        // ================= EMPRESTIMOS =================
        else if (op == 3) {

            int o;

            do {
                printf("\n==== EMPRESTIMOS ====\n");
                printf("1-Registrar\n");
                printf("2-Devolucao\n");
                printf("3-Renovar\n");
                printf("4-Listar\n");
                printf("5 -Sair\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &o);

                if (o == 1) {
                    emprestimos[totalEmprestimos].id = totalEmprestimos + 1;
                    emprestimos[totalEmprestimos].ativo = 1;
                    emprestimos[totalEmprestimos].renovado = 0;

                    scanf("%d", &emprestimos[totalEmprestimos].idAluno);
                    scanf("%d", &emprestimos[totalEmprestimos].idLivro);
                    scanf(" %[^\n]", emprestimos[totalEmprestimos].dataEmp);

                    int li = buscarLivro(emprestimos[totalEmprestimos].idLivro);
                    if (li != -1) livros[li].quantidadeDisp--;

                    int al = buscarAluno(emprestimos[totalEmprestimos].idAluno);
                    if (al != -1) alunos[al].totalEmprestimos++;

                    totalEmprestimos++;
                }

                else if (o == 2) {
                    int id;
                    scanf("%d", &id);

                    for (int i = 0; i < totalEmprestimos; i++) {
                        if (emprestimos[i].id == id)
                            emprestimos[i].ativo = 0;
                    }
                }

                else if (o == 3) {
                    int id;
                    scanf("%d", &id);

                    for (int i = 0; i < totalEmprestimos; i++) {
                        if (emprestimos[i].id == id)
                            emprestimos[i].renovado = 1;
                    }
                }

                else if (o == 4) {
                    for (int i = 0; i < totalEmprestimos; i++)
                        printf("%d - Livro %d - Aluno %d\n",
                               emprestimos[i].id,
                               emprestimos[i].idLivro,
                               emprestimos[i].idAluno);
                }

            } while (o != 0);
        }

        // ================= CATEGORIAS =================
        else if (op == 4) {

            int o;

            do {
                printf("\n ==== CATEGORIAS ====\n");
                printf("1-Cadastrar\n");
                printf("2-Listar\n");
                printf("3 -Sair\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &o);

                if (o == 1) {
                    categorias[totalCategorias].id = totalCategorias + 1;
                    categorias[totalCategorias].ativo = 1;

                    scanf(" %[^\n]", categorias[totalCategorias].nome);
                    totalCategorias++;
                }

                else if (o == 2) {
                    for (int i = 0; i < totalCategorias; i++)
                        if (categorias[i].ativo)
                            printf("%d - %s\n",
                                   categorias[i].id,
                                   categorias[i].nome);
                }

            } while (o != 0);
        }

        else if (op == 5) {
            relatorios();
        }

    } while (op != 0);

    return 0;
}
