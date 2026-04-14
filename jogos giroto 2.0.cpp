#include <stdio.h>

int main() {

    int i;
    int rodada = 1;

    do {
        printf("\nMENU PRINCIPAL\n");
        printf("1  Pergunta e Resposta\n");
        printf("2  Cobra na Caixa\n");
        printf("3  Gousmas War\n");
        printf("4  Sair\n");
        printf("Escolha: ");
        scanf("%d", &i);
        if (i == 1) {
            int resposta, acertos, jogar;

            do {
                acertos = 0;

                printf("\n1) onde fica o cesupa?\n1-Belem 2-Barcarena 3-Mosqueiro 4-Salinas\n");
                scanf("%d", &resposta);
                if (resposta == 1) { printf("Correto\n"); acertos++; }
                else printf("Errado, Belem\n");

                printf("\n2) 2+2?\n1-3 2-4 3-5 4-6\n");
                scanf("%d", &resposta);
                if (resposta == 2) { printf("Correto\n"); acertos++; }
                else printf("Errado,4\n");

                printf("\n3) quantas copas tem o Brasil?\n1-1 2-5 3-7 4-2\n");
                scanf("%d", &resposta);
                if (resposta == 2) { printf("Correto\n"); acertos++; }
                else printf("Errado, 5\n");

                printf("\n4) qual raiz de 144?\n1-7 2-12 3-17 4-15\n");
                scanf("%d", &resposta);
                if (resposta == 2) { printf("Correto\n"); acertos++; }
                else printf("Errado, 12\n");

                printf("\n5) qual a melhor materia?\n1-calculo 2-logica 3-progamacao 4-algebra\n");
                scanf("%d", &resposta);
                if (resposta == 3) { printf("Correto\n"); acertos++; }
                else printf("Errado, calculo\n");

                printf("\nAcertos: %d\n", acertos);

                printf("\n1-Jogar novamente\n2-Menu\n");
                scanf("%d", &jogar);

            } while (jogar == 1);
        }
        if (i == 2) {

            int jogar;

            do {
                int caixas[5] = {0,0,0,0,0};
                int botao = (rodada % 5) + 1;
                int cobra = ((rodada + 2) % 5) + 1;

                if (cobra == botao) cobra = ((cobra + 1) % 5) + 1;

                rodada++;

                int jogador = 1;
                int escolha;
                int fim = 0;

                printf("\nJogo iniciado\n");

                do {
                    printf("\nJogador %d - escolha (1-5): ", jogador);
                    scanf("%d", &escolha);

                    if (escolha < 1 || escolha > 5 || caixas[escolha-1] == 1) {
                        printf("Escolha invalida\n");
                    } else {
                        caixas[escolha-1] = 1;

                        if (escolha == botao) {
                            printf("Jogador %d achou o botao, venceu\n", jogador);
                            fim = 1;
                        }
                        else if (escolha == cobra) {
                            printf("Jogador %d achou a cobra vc perdeu\n", jogador);
                            fim = 1;
                        }
                        else {
                            printf("vazio\n");
                            if (jogador == 1) jogador = 2;
                            else jogador = 1;
                        }
                    }

                } while (fim == 0);

                printf("\n1-Jogar novamente?\n2-Menu\n");
                scanf("%d", &jogar);

            } while (jogar == 1);
        }

        if (i == 3) {

            int jogar;

            do {
                int j1me = 1, j1md = 1;
                int j2me = 1, j2md = 1;
                int turno = 1;
                int acao, escolha, alvo, valor;
                int fim = 0;

                do {
                    printf("\nJogador %d\n", turno);
                    printf("J1: [%d %d] | J2: [%d %d]\n", j1me, j1md, j2me, j2md);

                    printf("1-Atacar 2-Dividir: ");
                    scanf("%d", &acao);

                    if (acao == 1) {
                        printf("Sua gousma (1 ou 2): ");
                        scanf("%d", &escolha);

                        printf("Alvo (1 ou 2): ");
                        scanf("%d", &alvo);

                        if (turno == 1) {
                            int atc = (escolha == 1 ? j1me : j1md);

                            if (alvo == 1) j2me += atc;
                            else j2md += atc;

                            if (j2me > 5) j2me = 0;
                            if (j2md > 5) j2md = 0;
                        } else {
                            int atc = (escolha == 1 ? j2me : j2md);

                            if (alvo == 1) j1me += atc;
                            else j1md += atc;

                            if (j1me > 5) j1me = 0;
                            if (j1md > 5) j1md = 0;
                        }
                    }

                    if (acao == 2) {
                        printf("Gousma (1 ou 2): ");
                        scanf("%d", &escolha);

                        printf("Valor: ");
                        scanf("%d", &valor);

                        if (turno == 1) {
                            if (escolha == 1 && j1me > valor) {
                                j1me -= valor;
                                j1md += valor;
                            }
                            if (escolha == 2 && j1md > valor) {
                                j1md -= valor;
                                j1me += valor;
                            }
                        } else {
                            if (escolha == 1 && j2me > valor) {
                                j2me -= valor;
                                j2md += valor;
                            }
                            if (escolha == 2 && j2md > valor) {
                                j2md -= valor;
                                j2me += valor;
                            }
                        }
                    }

                    if (j1me == 0 && j1md == 0) {
                        printf("\nJogador 2 venceu\n");
                        fim = 1;
                    }

                    if (j2me == 0 && j2md == 0) {
                        printf("\nJogador 1 venceu\n");
                        fim = 1;
                    }

                    if (turno == 1) turno = 2;
                    else turno = 1;

                } while (fim == 0);

                printf("\n1-Jogar novamente?\n2-Menu\n");
                scanf("%d", &jogar);

            } while (jogar == 1);
        }

    } while (i != 4);

    printf("\nEncerrado.\n");

    return 0;
}