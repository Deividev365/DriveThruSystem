#define disponiveis 8

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
    {1, "X-BURGER", 7.50 }, // 0
    {2, "X-Salada", 9.50 }, // 1 ..
    {3, "Coca-cola", 5.50 },
    {4, "BigTasty", 14.50 },
    {5, "LaDelicia", 20.50 },
    {6, "X-Suculento", 17.50 },
    {7, "BigMac", 37.50 },
    {8, "lasanha", 57.50 },
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

