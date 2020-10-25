#define disponiveis 13

int i, codigoPedido, qntdPedido;
char tentarNovamente[1];

// Hamburgeria LasBurgers // 
typedef struct {
// Irá conter o menu   
    int produtoId;
    char nomeDoLanche[30];
    float precoDoProduto;
    
} menuDeLanches;

menuDeLanches lasBurgers [disponiveis] = {
    {1, "COMBO: X-BURGER + BATATA", 15.50 }, // 0
    {2, "X-Salada", 9.50 }, // 1 ..
    {3, "Picanha das galaxias + Coca-cola", 20.50 },
    {4, "BigTasty", 14.50 },
    {5, "LaDelicia", 20.50 },
    {6, "X-Suculento", 17.50 },
    {7, "BigMac", 27.50 },
    {8, "lasanha", 27.50 },
    {9, "vegTasty + coca-cola", 17.50 },
    {10, "x-tudo", 37.50 },
    {11, "Big King", 27.50 },
    {12, "goCrazyBurger + batata + mcflurry", 77.50 },
    {13, "oldschool", 47.50 },
};


typedef struct {

 int CartaoId;
 char formatoPagamento[50];
 float setPedido;
 
} menuPagamento;

menuPagamento meiosPagar[3] = {

    {1, "Dinheiro", 0},
    {2, "Cartao (Debito - Credito)", 0},
    {3, "Cheque", 0},

};

typedef struct {

    int formatOfPaying;
    char cartaoValidacao[16];

} paymentValidation;

paymentValidation getUserData[2] = {

    { 0, 0 }
};

typedef struct {

    char userName[50];
    int userAge;

} queue;

queue menuFila;

