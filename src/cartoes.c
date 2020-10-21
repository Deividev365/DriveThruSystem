typedef struct {

    int formatOfPaying;
    char cartaoValidacao[16];
    //char senha[6];

} paymentValidation;

paymentValidation getUserData[2] = {
    { 0, 0 }
};


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
            
            /* for(i = 0; i < 5; i++) {
                getUserData->cartaoValidacao[i] = getch();
                putchar('*');
            }*/
            // tenho que exibir isso em tela pro usuario, só que nao ocnsigo
            printf("%c", getUserData->cartaoValidacao[i]);
    }


    void cartaoMetodo() {

        printf("\nVoce escolheu cartao!: ");
            secaoPagar:
            printf("\nDigite o numero do seu cartao (exatos 16 digitos): ");

                for(i = 0; i < 16; i++) {
                  getUserData->cartaoValidacao[i] = getch();
                  printf("%c", getUserData->cartaoValidacao[i]);


                  if(i > 4 && i < 13) {
                    getUserData->cartaoValidacao[i] = getch();
                    putchar('*');
                  }
                }

                //printf("senha cartao: %s", result);


                 /* for(i = 0; i < 16; i++ ) {
                    getUserData->cartaoValidacao[i] = getch();
                    fflush(stdin);
                    printf("%c", getUserData->cartaoValidacao[i]);
                    

                    if(i > 5) {
                        getUserData->cartaoValidacao[i] = getch();
                        //fflush(stdin);
                        putchar('*');
                    }
                } */

                //printf("%d", getUserData->cartaoValidacao[i]);

                    fflush(stdin);
                    cartoesData();
                    cartoesDataShow();



            // registrar em um arquvios CARTOES.DAT quando passar a validação do cartão // 

            //cartaoId  // cartaoUsuario ex(1111********4444); // mascarar entre 5 e 12 //
            //

            //printf("numero cartao: %d", setCartaoValidacao);
    }
