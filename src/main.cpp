#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>

    char lanche1[20] = "bigmac1";
    char lanche2[20] = "bigmac2";
    char lanche3[30] = "bigmac3";
    
    float precoLanche1 =  9.50;
    float precoLanche2 =  12.50;
    float precoLanche3 =  16.50;
    
    int quantidadePedidos;
    
    float calcTotal;

void menuLanches() {

       
    printf("Bem Vindo ao Mickey & Donalds\n");
    printf("Esse e o nosso MENU:\n");

    printf("1- %s R$ %f \n", lanche1, precoLanche1);
    printf("2- %s R$ %f\n", lanche2, precoLanche2);
    printf("3- %s R$ %f\n", lanche3, precoLanche3);
}


int main() {
    
    int pedidoDoUsuario;

    menuLanches();
    
    printf("o que gostaria de Comer?");
    scanf("%d", &pedidoDoUsuario);

    
    
    switch (pedidoDoUsuario) {
        case 1:
            printf("Voce escolheu o lanche %s que custa %f\n", lanche1, precoLanche1);
            
            printf("Quantos %s voce gostaria?", lanche1);
            scanf("%d", &quantidadePedidos);

            calcTotal = quantidadePedidos * precoLanche1;

            printf("o total do pedido e %f", calcTotal);
            

        break;
        
        case 2: 
            printf("Voce escolheu o lanche %s que custa %f\n", lanche2, precoLanche2);
            
            printf("Quantos %s voce gostaria", lanche2);
             scanf("%d", &quantidadePedidos);

             calcTotal = quantidadePedidos * precoLanche2;

            printf("o total do pedido e %f", calcTotal);
        break;
         
        case 3:
            printf("Voce escolheu o lanche %s que custa %f\n", lanche3, precoLanche3);
          
            printf("Quantos %s voce gostaria", lanche3);
            scanf("%d", &quantidadePedidos);

            calcTotal = quantidadePedidos * precoLanche3;

            printf("o total do pedido e %f", calcTotal);
        break;
    
    default: 
            printf("Opcao invalida");
        break;
    }
    
    


}



