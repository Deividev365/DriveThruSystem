#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

#define disponiveis 8
int i;
int codigoPedido;
int qntdPedido;
float setPedidoAcumulator = 0;


char tentarNovamente[1];


int setCartaoValidacao = 0;


typedef struct {

    int formatOfPaying;
    int cartaoValidacao[16];

} paymentValidation;

paymentValidation getUserData[2] = {
    {0, 0}
};

// Hamburgeria LasBurgers // 
typedef struct {
// Irá conter o menu   
    int produtoId;
    char nomeDoLanche[30];
    float precoDoProduto;
    
} menuDeLanches;

typedef struct {

 int CartaoId;
 char formatoPagamento[50];
 float setPedido;
 

} menuPagamento;



menuPagamento meiosPagar[4] = {
    {1, "Dinheiro", 0, 0},
    {2, "Cartao (Debito - Credito)", 0, 0},
    {3, "Cheque", 0, 0},

};


menuDeLanches lasBurgers [disponiveis] = {
    {1, "X-BURGER", 7.50 }, // 0
    {2, "X-Salada", 9.50 }, // 1 ..
    {3, "Coca-cola", 5.50 },
    {4, "BigTasty", 14.50 },
    {5, "LaDelicia", 20.50 },
    {6, "X-Suculento", 17.50 },
    {7, "BigMac", 37.50 },
    {8, "lasanha", 57.50 },
}; 


// escrever arquivos do meu menu de lanches
    void writeFile() {

        FILE *pont_arq; // CRIAMOS O PONTEIRO

        pont_arq = fopen ("PRODUTOS.DAT.txt","w"); // - W = Escrever arquivo //

        if(pont_arq == NULL) printf("Algum erro aconteceu");


        printf("Arquivo escrito!");

        
        for(i = 0; i < disponiveis; i++) {

        fwrite(&lasBurgers[i], 1, sizeof(menuDeLanches), pont_arq);
        
        }

    }

    void exibirMenu() {

        FILE *pont_arq; // CRIAMO O PONTEIRO

        pont_arq = fopen ("PRODUTOS.DAT.txt","r"); // irá ler o arquivo produtos.dat já criado

        if(pont_arq == NULL) printf("Algum erro aconteceu");

        if(lasBurgers->produtoId == 1) { // validacao para quebrar uma linha no primeiro item do menu
                printf("\n");
        } 

        for(i = 0; i < disponiveis; i++) {
            
            fread(&lasBurgers[i], 1, sizeof(menuDeLanches), pont_arq);
            
            printf("%d- %s R$%1.f\n", lasBurgers[i].produtoId, lasBurgers[i].nomeDoLanche, lasBurgers[i].precoDoProduto);
        }
    }

    void pedidoUsuario() {
     

        printf("Para fazer o pedido e SIMPLES\n");
        
        printf("Digite o codigo referente ao que voce quer comprar: ");
        scanf("%d", &codigoPedido);
        codigoPedido--;

        printf("\nQuantos voce gostaria?:");
        scanf("%d", &qntdPedido);



        meiosPagar->setPedido = lasBurgers[codigoPedido].precoDoProduto * qntdPedido;
         //setPedidoAcumulator = setPedidoAcumulator + setPedido;
        
        printf("Valor total do seu %s e: %f\n", lasBurgers[codigoPedido].nomeDoLanche, meiosPagar->setPedido);

 
    }

    void writePaymentFormats() {
         FILE *pont_arq; // CRIAMOS O PONTEIRO

        pont_arq = fopen ("PAGAMENTOS.DAT.txt","w"); // - W = Escrever arquivo //

        if(pont_arq == NULL) printf("Algum erro aconteceu");


        printf("Arquivo escrito!");

        
        for(i = 0; i < 3; i++) {

            fwrite(&meiosPagar[i], 1, sizeof(menuPagamento), pont_arq);
       }
    }

    void readPaymentFormats() {

        FILE *pont_arq; // CRIAMOS O PONTEIRO

        pont_arq = fopen ("PAGAMENTOS.DAT.txt","r"); // - r = Escrever arquivo //

        if(pont_arq == NULL) printf("Algum erro aconteceu");


        printf("Arquivo lido!");

        
        for(i = 0; i < 3; i++) {

            fwrite(&meiosPagar[i], 1, sizeof(menuPagamento), pont_arq);
            printf("\n%d- %s %f\n", meiosPagar[i].CartaoId, meiosPagar[i].formatoPagamento, meiosPagar->setPedido);
       }
    }


    void cartoesData() {
        FILE *pont_arq; // CRIAMOS O PONTEIRO

        pont_arq = fopen ("CARTOES.DAT.txt","w"); // - W = Escrever arquivo //

        if(pont_arq == NULL) printf("Algum erro aconteceu");


        printf("Arquivo escrito!");

        
            // cartaoID e cartaoValidacao

            // lasBurgers[codigoPedido].nomeDoLanche, meiosPagar->setPedido
            fwrite(&getUserData, 1, sizeof(paymentValidation), pont_arq);
       
    }

    void cartoesDataShow() {
        FILE *pont_arq; // CRIAMOS O PONTEIRO

        pont_arq = fopen ("CARTOES.DAT.txt","r"); // - W = Escrever arquivo //

        if(pont_arq == NULL) printf("Algum erro aconteceu");


        printf("Arquivo escrito!");

        
            // cartaoID e cartaoValidacao
        fread(&getUserData, 1, sizeof(paymentValidation), pont_arq);

            printf("\n%d - ", getUserData->formatOfPaying);

            for(i = 0; i < 16; i++) {
                printf("%d", getUserData[i].cartaoValidacao);
            }

    }


    void cartaoMetodo() {
        printf("\nVoce escolheu cartao!: ");
            secaoPagar:
            printf("\nDigite o numero do seu cartao (exatos 16 digitos): ");
            //scanf("%d", &getUserData->cartaoValidacao);


                for(i = 0; i < 16; i++ ) {
                    getUserData->cartaoValidacao[i] = getch();
                    putchar('*');
                
                }
            
            



             /* if( getUserData->cartaoValidacao >= 16 || getUserData->cartaoValidacao <= 16) {
                printf("Cartão Invalido");

                goto secaoPagar;
            } */


            fflush(stdin);
            cartoesData();
            cartoesDataShow();



            // registrar em um arquvios CARTOES.DAT quando passar a validação do cartão // 

            //cartaoId  // cartaoUsuario ex(1111********4444); // mascarar entre 5 e 12 //
            //

            //printf("numero cartao: %d", setCartaoValidacao);
    }

    dinheiroMetodo() {
        printf("\nObrigado por comprar! :) Ficamos felizes pela preferencia");

            //filaDeEspera();
    }

    metodoCheque() {
        printf("Aqui voce paga com cheque");
    }

    metodoDefault() {
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


    void formaPagamento() {
        
/*         printf("\nBEM VINDO AO MENU PAGAMENTO :)\n");
 */     printf("\nEssas sao as formas de pagamento :)\n");

        inicioPagamento:
        writePaymentFormats();
        readPaymentFormats();
        /* for(i = 0; i < 3; i++) {
            printf("\n%d - %s", meiosPagar[i].CartaoId, meiosPagar[i].formatoPagamento);
        } */

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


    int main(void) {

        printf("===Bem Vindo ao Mickey & Donalds===\n");
        printf("Esse e o nosso MENU\n");

        writeFile();
        exibirMenu();
        pedidoUsuario();
        formaPagamento();
    }