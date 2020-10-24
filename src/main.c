#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <time.h>


void delay(int number_of_seconds)  { 
	// Converting time into milli_seconds 
	int milli_seconds = 1000 * number_of_seconds; 

	// Storing start time 
	clock_t start_time = clock(); 

	// looping till required time is not achieved 
	while (clock() < start_time + milli_seconds); 
} 


#define ANSI_COLOR_GREEN "\033[1;32m" // DINHEIRO
#define ANSI_COLOR_PURPLE "\033[1;32m" // DINHEIRO
#define ANSI_COLOR_BLUE "\033[1;34m" // CHEQUE

#define disponiveis 8
int i;
int codigoPedido;
int qntdPedido;
float setPedidoAcumulator = 0;


char tentarNovamente[1];


int setCartaoValidacao = 0;


typedef struct {

    int formatOfPaying;
    char cartaoValidacao[16];


} paymentValidation;

paymentValidation getUserData[2] = {
    { 0, 0 }
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


typedef struct {

    char userName[50];
    int userAge;

} queue;







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

queue menuFila;
queue filaPadrao;
queue filaMaiorIdade;



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
            
            printf("%d- %s R$%.2f\n", lasBurgers[i].produtoId, lasBurgers[i].nomeDoLanche, lasBurgers[i].precoDoProduto);
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
        
        printf("Valor total do seu %s e: %.2f\n", lasBurgers[codigoPedido].nomeDoLanche, meiosPagar->setPedido);

 
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
            printf("\n%d- %s %.2f\n", meiosPagar[i].CartaoId, meiosPagar[i].formatoPagamento, meiosPagar->setPedido);
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


    void cartaoMetodo() {
        // %2.f %.2f
        printf("\nVoce escolheu cartao!: ");
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



                    



            // registrar em um arquvios CARTOES.DAT quando passar a validação do cartão // 

            //cartaoId  // cartaoUsuario ex(1111********4444); // mascarar entre 5 e 12 //
            //

            //printf("numero cartao: %d", setCartaoValidacao);
    }

    dinheiroMetodo() {

        float userMoneypayment;
        float change;

        //printf(ANSI_COLOR_GREEN "\n dinheiro!");

        printf("\nTotal a pagar: %.2f", meiosPagar->setPedido);

        printf("\n\nPague aqui: (Digite o preco do lanche em R$): ");
        scanf("%f", &userMoneypayment);

        if(userMoneypayment < meiosPagar->setPedido) {

            printf("\nerro no pagamento! Digite o valor corretamente! ");

        } else if( userMoneypayment > meiosPagar->setPedido) {

            change = userMoneypayment - meiosPagar->setPedido;
            printf("\nO seu troco e: %.2f, Obrigado por comprar!", change);

        }
        
        filaDeEspera();
    }

    metodoCheque() {


       /*  printf("Aqui voce paga com cheque");
        printf  ("Cheque emetido por..:");
        scanf ("%c", &nome);
	    printf("Pague por este cheque na quantia de: %.2f", meiosPagar->setPedido);    
     */
    
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


    void filaDeEspera() {

        int idPreferencial = rand() % 10;

        int idNormal = rand() % 20;

        printf("\nBem vindo a FILA DE ESPERA do LAburge :)");

        printf("\nPara entrar na FILA DE ESPERA e preciso preencher um cadastro: ");

        printf("\nDigite o seu nome: ");
        scanf("%s", &menuFila.userName);

        fflush(stdin);

        printf("Digite a sua idade: ");
        scanf("%d", &menuFila.userAge);



        if(menuFila.userAge > 60) {
            //filaMaiorIdade

            printf("Bem vindo a fila preferencial, %s, a sua senha e: %d", menuFila.userName, idPreferencial);

            for(i = 0; i < idPreferencial; i++) {
                delay(2);
                printf("\nAguarde...", i + 1);
            }

            printf("\nObrigado por comprar! Recebemos o seu pedido, %s", menuFila.userName);
            printf("\nLogo o seu %s chegará na sua casa!", lasBurgers[codigoPedido].nomeDoLanche);

        } else {
                
            printf("Bem vindo a fila de espera, %s a sua senha e %d, AGUARDE O NUMERO %d SER CHAMADO", menuFila.userName, idNormal, idPreferencial);   
            
            printf("\n Aguarde...");
            for(i = 0; i < idNormal; i++) {
                delay(1);
                printf("\n Aguarde...", i + 1);
            }

            printf("\nObrigado por comprar! Recebemos o seu pedido, %s", menuFila.userName);
            printf("\nLogo o seu %s chegará na sua casa!", lasBurgers[codigoPedido].nomeDoLanche);
        }

        
        entregaPedido();


    }



    void entregaPedido() {

        
 
        switch (getUserData->formatOfPaying) {
        case 1:
            system("COLOR 2");
            printf("\n\nO pedido ja foi pago com %s ", meiosPagar[getUserData->formatOfPaying].formatoPagamento); // DINHEIRO // 
            break;

        case 2:
            system("COLOR 5");
            printf("\n\nO pedido ja foi pago com %s", meiosPagar[getUserData->formatOfPaying].formatoPagamento); // CARTAO OU DEBITO //
            break;

        
        case 3:
            system("COLOR 1");
            printf("\n\nO pedido ja foi pago com %s", meiosPagar[getUserData->formatOfPaying].formatoPagamento); // CHEQUE // 
            break;
        
        default:
            break;
        }
        // Pedido foi pago com (cartao) 
    }


    


    int main(void) {

        printf("===Bem Vindo ao Mickey & Donalds===\n");
        printf("Esse e o nosso MENU\n");

        writeFile();
        exibirMenu();
        pedidoUsuario();
        formaPagamento();
    }