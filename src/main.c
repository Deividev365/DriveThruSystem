#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

#define disponiveis 9
int i;
int codigoPedido;
int qntdPedido;
float setPedidoAcumulator = 0;

int formaDePagamento;

char tentarNovamente[1];

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

menuPagamento pegarValorTotal;

menuPagamento meiosPagar[3] = {
    {1, "Dinheiro"},
    {2, "Cartao (Debito - Credito)"},
    {3, "Cheque"},

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
            
            printf("%d- %s %f\n", lasBurgers[i].produtoId, lasBurgers[i].nomeDoLanche, lasBurgers[i].precoDoProduto);
        }
    }

    void pedidoUsuario() {
     
        pegarValorTotal.setPedido = 0;
        printf("Para fazer o pedido e SIMPLES\n");
        
        printf("Digite o codigo referente ao que voce quer comprar:");
        scanf("%d", &codigoPedido);

        printf("\nQuantos voce gostaria?:");
        scanf("%d", &qntdPedido);



        pegarValorTotal.setPedido = lasBurgers[codigoPedido].precoDoProduto * qntdPedido;
         //setPedidoAcumulator = setPedidoAcumulator + setPedido;
   
 
    }

    void writePaymentFormats() {
         FILE *pont_arq; // CRIAMOS O PONTEIRO

        pont_arq = fopen ("PAGAMENTOS.DAT.txt","w"); // - W = Escrever arquivo //

        if(pont_arq == NULL) printf("Algum erro aconteceu");


        printf("Arquivo escrito!");

        
        for(i = 0; i < 3; i++) {

        fwrite(&meiosPagar[i], 2, sizeof(menuDeLanches), pont_arq);

/*         writeFile("%d - %s - %f", meiosPagar[i].CartaoId, meiosPagar[i].formatoPagamento, setPedido, pont_arq);
 */        }
    }



    void formaPagamento() {
        
        printf("Valor total do seu %s e: %f\n", lasBurgers[codigoPedido].nomeDoLanche, setPedido);


/*         printf("\nBEM VINDO AO MENU PAGAMENTO :)\n");
 */     printf("\nEssas sao as formas de pagamento :)\n");

        inicioPagamento:
        for(i = 0; i < 3; i++) {
            printf("\n%d - %s", meiosPagar[i].CartaoId, meiosPagar[i].formatoPagamento);
        }

        printf("\nSelecione a melhor forma de pagar: ");
        scanf("%d", &formaDePagamento);

        

        switch (formaDePagamento) {

        case 1:
            printf("Voce escolheu: Dinheiro");
            writePaymentFormats();

        break;

        case 2:
            //metodoCartao();
        break;

        case 3:
            //metodoCheque();
        break;

        default:
            printf("Essa forma de paagmento é INVALIDA");
            
            fflush(stdin);

            printf("\nGostaria de tentar novamente? [s/n]");
            gets(tentarNovamente);
            
            fflush(stdin);

            // ARRUMAR ISSO // 
            if(tentarNovamente == "s" || tentarNovamente == "S") {
                goto inicioPagamento;

            } else {
                printf("Tchau!");
            }

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


/* 
  
        printf("2-%s R$%f\n", lanchesDisponiveis.lanche2, lanchesDisponiveis.precoLanche2);
        printf("3-%s R$%f\n", lanchesDisponiveis.lanche3, lanchesDisponiveis.precoLanche3); */
    


    /* float order(float price) {

        int qntdPedidos;
        float setCalc;

        printf("Quantos Lanches você gostaria?: ");
        scanf("%d", &qntdPedidos);
        
         setCalc = qntdPedidos * price;
        
        printf("Obrigado por comprar :). O total à pagar e: %f", setCalc);

        return setCalc;
    }
                                                


    void pedidoUsuario() {

        int pedidoDoUsuario;

        printf("o que gostaria de Comer?");
        scanf("%d", &pedidoDoUsuario);


    
        switch (pedidoDoUsuario) {
            case 1:
               order();
            break;
            
            case 2: 
                order();


            break;
            
            case 3:
                order();
                

            break;
        
        default: 
                printf("Opcao invalida");
                // voltar menu //
            break;
        }
    }
    
    
    int main(void) {

            printf("Bem Vindo ao Mickey & Donalds\n");
            printf("Esse e o nosso MENU:\n");

            writeFile();

            menuLanches();

            pedidoUsuario();

        }


     
   /*  int quantidadePedidos;
    
    float calcTotal;

 */







    
    /* int pedidoDoUsuario;

    menuLanches();
    
    */
    
    





 