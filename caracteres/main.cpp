#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int capacidade;
    char *dados;
    int primeiro;
    int ultimo;
    int nItens;
} fila;

void criarFila( fila *f, int c ) {

    f->capacidade = c; //quantos itens vai ter
    f->dados = (char*) malloc (f->capacidade * sizeof(char)); //aloca memoria dinamicamente
    f->primeiro = 0; //indice do primeiro elemento da fila
    f->ultimo = -1; //indice do ultimo elemento da fila
    f->nItens = 0; // numero de itens da fila

}

void inserir(fila *f, char v) {

    if(f->ultimo == f->capacidade-1)
        f->ultimo = -1;

    f->ultimo++;
    f->dados[f->ultimo] = v; // incrementa ultimo e insere
    f->nItens++; // mais um item inserido

}

int remover( fila *f ) { // pega o item do come�o da fila

    int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro

    if(f->primeiro == f->capacidade)
        f->primeiro = 0;

    f->nItens--;  // um item retirado
    return temp;

}

int estaVazia( fila *f ) { // retorna verdadeiro se a fila est� vazia

    return (f->nItens==0);

}

int estaCheia( fila *f ) { // retorna verdadeiro se a fila est� cheia

    return (f->nItens == f->capacidade);
}

void mostrarFila(fila *f){

    int cont, i;

    for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){

        printf("%s\t",f->dados[i++]);

        if (i == f->capacidade)
            i=0;

    }
    printf("\n\n");

}

int main () {

    int opcao, capa;
    char *valor;
    fila umaFila;

    // cria a fila
    printf("\nCapacidade da fila? ");
    scanf("%d",&capa);
    criarFila(&umaFila, capa);

    // apresenta menu
    while( true ){

        printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nOpcao ");
        scanf("%d", &opcao);

        switch(opcao){

            case 0: exit(0);

            case 1: // insere elemento
                if (estaCheia(&umaFila)){

                    printf("\nFila Cheia!!!\n\n");

                }
                else {

                    printf("\nValor do elemento a ser inserido? ");
                    scanf(" %s", &valor);
                    int flag = 0;
                    int j=0;
                    for(int i = 0; valor[i]!='/0';i++)
                    if((valor[i] >= 'a' && valor[i] <= 'z') || (valor[i] >= 'A' && valor[i] <= 'Z') ){
                        flag++;
                    }
                    j++;

                    if(flag == j){
                       inserir(umaFila,*valor);
                    }
                    else{
                        printf("moio");
                    }


                        printf("Não é letra");


                }

                break;

            case 2: // remove elemento
                if (estaVazia(&umaFila)){

                    printf("\nFila vazia!!!\n\n");

                }
                else {

                    valor = remover(&umaFila);
                    printf("\n%1f removido com sucesso\n\n", valor) ;

                }
                break;

            case 3: // mostrar fila
                if (estaVazia(&umaFila)){

                    printf("\nFila vazia!!!\n\n");

                }
                else {

                    printf("\nConteudo da fila => ");
                    mostrarFila(&umaFila);

                }
                break;

            default:
                printf("\nOpcao Invalida\n\n");

        }
    }
}

