#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "delay.c"

#include "tipagens.c"



// escrever arquivos do meu menu de lanches
    void writeFile(void) {

        FILE *pont_arq; // CRIAMOS O PONTEIRO

        pont_arq = fopen ("PRODUTOS.DAT.txt","w"); // - W = Escrever arquivo //

        if(pont_arq == NULL) printf("Algum erro aconteceu");


        printf("\nProdutos presentes na nossa base de dados :)");

        
        for(i = 0; i < disponiveis; i++) {

        fwrite(&lasBurgers[i], 1, sizeof(menuDeLanches), pont_arq);
        
        }

    }

    void exibirMenu(void) {

        FILE *pont_arq; // CRIAMO O PONTEIRO

        pont_arq = fopen ("PRODUTOS.DAT.txt","r"); // irá ler o arquivo produtos.dat já criado

        if(pont_arq == NULL) printf("Algum erro aconteceu");

        if(lasBurgers->produtoId == 1) { // validacao para quebrar uma linha no primeiro item do menu
                printf("\n");
        } 

        for(i = 0; i < disponiveis; i++) {
            
            fread(&lasBurgers[i], 1, sizeof(menuDeLanches), pont_arq);
            
            printf("%d- %s R$%.2f\n", lasBurgers[i].produtoId, lasBurgers[i].nomeDoLanche, lasBurgers[i].precoDoProduto);
        }
    }

    void pedidoUsuario(void) {
     
        printf("\nPara fazer o pedido e SIMPLES\n");
        
        printf("\nDigite o codigo referente ao que voce quer comprar: ");
        scanf("%d", &codigoPedido);
        codigoPedido--;

        printf("\nQuantos %s voce gostaria?: ", lasBurgers[codigoPedido].nomeDoLanche);
        scanf("%d", &qntdPedido);


        meiosPagar->setPedido = lasBurgers[codigoPedido].precoDoProduto * qntdPedido;

        printf("\n\n********************************");
        printf("\nValor total do seu %s e: %.2f\n", lasBurgers[codigoPedido].nomeDoLanche, meiosPagar->setPedido);
        printf("\n**********************************");
 
    }

    void writePaymentFormats(void) {
         FILE *pont_arq; // CRIAMOS O PONTEIRO

        pont_arq = fopen ("PAGAMENTOS.DAT.txt","w"); // - W = Escrever arquivo //

        if(pont_arq == NULL) printf("Algum erro aconteceu");


        //printf("\nDados foram escritos!");

        
        for(i = 0; i < 3; i++) {

            fwrite(&meiosPagar[i], 1, sizeof(menuPagamento), pont_arq);
       }
    }

    void readPaymentFormats(void) {

        FILE *pont_arq; // CRIAMOS O PONTEIRO

        pont_arq = fopen ("PAGAMENTOS.DAT.txt","r"); // - r = Escrever arquivo //

        if(pont_arq == NULL) printf("Algum erro aconteceu");


        //printf("Dados Registrados");

        
        for(i = 0; i < 3; i++) {

            fwrite(&meiosPagar[i], 1, sizeof(menuPagamento), pont_arq);
            printf("\n%d- %s %.2f\n", meiosPagar[i].CartaoId, meiosPagar[i].formatoPagamento, meiosPagar->setPedido);
       }
    }


    void cartoesData(void) {
        FILE *pont_arq; // CRIAMOS O PONTEIRO

        pont_arq = fopen ("CARTOES.DAT.txt","w"); // - W = Escrever arquivo //

        if(pont_arq == NULL) printf("Algum erro aconteceu");


        //printf("Dados foram escritos!");

        
            // cartaoID e cartaoValidacao

            // lasBurgers[codigoPedido].nomeDoLanche, meiosPagar->setPedido
            fwrite(&getUserData, 1, sizeof(paymentValidation), pont_arq);
       
    }

    void cartoesDataShow(void) {
        FILE *pont_arq; // CRIAMOS O PONTEIRO

        pont_arq = fopen ("CARTOES.DAT.txt","r"); // - W = Escrever arquivo //

        if(pont_arq == NULL) printf("Algum erro aconteceu");


        //printf("Dados foram Registrados");

        
            // cartaoID e cartaoValidacao
        fread(&getUserData, 1, sizeof(paymentValidation), pont_arq);

            printf("\n%d - ", getUserData->formatOfPaying);
            
            for(i = 0; i < 4; i++) {
                    printf("%c", getUserData->cartaoValidacao[i]);
            }
            
            for(i = 5; i < 16; i++) {

                if(i > 4 && i < 12) {
                    
                    putchar('*');
                
                } else {
                    
                    printf("%c", getUserData->cartaoValidacao[i]);
                    
                }
            }
    }


    void cartaoMetodo(void) {
        
        filaDeEspera();

        printf("\nPague com o seu cartao(debito ou credito)");
            secaoPagar:
            printf("\nDigite o numero do seu cartao (exatos 16 digitos): ");
            
            for(i = 0; i < 16; i++) {
				getUserData->cartaoValidacao[i] = getch();
            	fflush(stdin);
            	printf("%c", getUserData->cartaoValidacao[i]);
            }
                // validacao se for > 16 || < 16 digitos.
            /* if(getUserData->cartaoValidacao[i] != 16) {
                printf("Erro!");
                return (0);
            } */

        fflush(stdin);

        cartoesData();

        cartoesDataShow();

        entregaPedido();

    }

    void dinheiroMetodo(void) {

        filaDeEspera();

        float userMoneypayment, change;


        printf("\nTotal a pagar: %.2f", meiosPagar->setPedido);
        
        pagueAqui:
        printf("\n\nPague aqui: (Digite o preco do lanche em R$): ");
        scanf("%f", &userMoneypayment);

        if(userMoneypayment < meiosPagar->setPedido) {

            printf("\nerro no pagamento! Digite o valor corretamente! ");
            goto pagueAqui;

        } else if( userMoneypayment > meiosPagar->setPedido) {

            change = userMoneypayment - meiosPagar->setPedido;
            printf("\nO seu troco e: %.2f, Obrigado por comprar!", change);

        }
        
        entregaPedido();
    }


    void metodoCheque(void) {

        filaDeEspera();
        fflush(stdin);

        char userName[50];

        printf("\nAqui voce paga com cheque");
	    printf("\nPague por este cheque na quantia de: %.2f", meiosPagar->setPedido);    
        
        fflush(stdin);

        printf("\nDigite o seu nome completo: ");
        gets(userName);

        fflush(stdin);

        entregaPedido();

    }

    void metodoDefault(void) {
        printf("Essa forma de paagmento é INVALIDA");
            
            fflush(stdin);

            printf("\nGostaria de tentar novamente? [s/n]");
            gets(tentarNovamente);
            
            fflush(stdin);

            // ARRUMAR ISSO // 
            if(tentarNovamente == "s" || tentarNovamente == "S") {
                formaPagamento();

            } else {
                printf("Tchau!");
            }
    }


    void formaPagamento(void) {
        

        printf("\nEssas sao as formas de pagamento :)\n");

        inicioPagamento:
        writePaymentFormats();
        readPaymentFormats();
    
        printf("\nSelecione a melhor forma de pagar: ");
        scanf("%d", &getUserData->formatOfPaying);

        
        fflush(stdin);

        switch (getUserData->formatOfPaying) {

        case 1: // DINHEIRO
            dinheiroMetodo();
            break;

        case 2: // CARTÃO DEBITO OU CREDITO // 
            cartaoMetodo();
            break;

        case 3: // CHEQUE //
            metodoCheque();
            break;

        default: // default // 
            metodoDefault();
            break;
        }
    }


    void filaDeEspera(void) {

        int idPreferencial = rand() % 10;

        int idNormal = rand() % 20;

        printf("\n\n********************************************");
        printf("\nBem vindo a FILA DE ESPERA dos LasBurgers");
        printf("\n**********************************************");

        printf("\n\nPara entrar na FILA DE ESPERA e preciso fazer um cadastro simples: ");

        printf("\nDigite o seu primeiro nome: ");
        scanf("%s", &menuFila.userName);

        fflush(stdin);

        printf("\nDigite a sua idade: ");
        scanf("%d", &menuFila.userAge);



        if( menuFila.userAge > 60 ) {
            //filaMaiorIdade
            printf("Bem vindo a fila preferencial, %s, a sua senha e: %d", menuFila.userName, idPreferencial);

            for(i = 0; i < idPreferencial; i++) {
                delay(2);
                printf("\nAguarde...", i + 1);
            }

            printf("\nRecebemos o seu pedido, %s", menuFila.userName);
            printf("\nLogo o seu %s chegará na sua casa!", lasBurgers[codigoPedido].nomeDoLanche);

        } else {
                
            printf("\nBem vindo a fila de espera, %s a sua senha e %d, AGUARDE O NUMERO %d SER CHAMADO", menuFila.userName, idNormal, idPreferencial);   
            
            for(i = 0; i < idNormal; i++) {
                delay(1);
                printf("\n Aguarde...", i + 1);
            }

            printf("\n\nRecebemos o seu pedido, %s\n", menuFila.userName);
            printf("\nLogo o seu %s chegará na sua casa!\n", lasBurgers[codigoPedido].nomeDoLanche);
        }

    }



    void entregaPedido(void) {


        switch (getUserData->formatOfPaying) {

        case 1:
        
            system("COLOR 2");
            printf("\nVOCE PAGOU COM"); // DINHEIRO // 
            printf(" dinheiro!");
            break;

        case 2:

            system("COLOR 05");
            printf("\nVOCE PAGOU COM ");
            printf("CARTAO :)"); // CARTAO OU DEBITO //
            break;

        
        case 3:

            system("COLOR 01");
            printf("\nVOCE PAGOU COM");
            printf(" CHEQUE"); // CHEQUE // 
            break;
        
        default:

            printf("Indisponível");
            break;

        }
    }

    int main(void) {
        printf("*********************************");
        printf("\nBem Vindo ao LasBurgers :p\n");
        printf("\n*********************************");

        printf("\nEsse e o nosso MENU.\n\n");

        writeFile();
        exibirMenu();
        pedidoUsuario();
        formaPagamento();
    }
