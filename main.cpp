#include <stdio.h>
#include <cstdlib>

struct No{
    int dado;
    struct No *prox;
} *inicio = NULL;
typedef struct No No;

char menu(){
    char op;
    printf("\nEscolha:\n0- FIM\n1- Inserir no inicio da lista:\n2- Inserir no fim da lista:\n3- Buscar na lista:\n4- Trocar numero:\n5- Ecluir elemento:\n6- Excluir Lista:\n7- Imprimir:\nOpcao:");
    scanf("%c%*C", &op);
    return op;
}


void insereFim(int x){
    No *novo;
    novo = new struct No();
    novo->dado = x;

    if (inicio == NULL) {
        novo->prox = inicio;
        inicio = novo;
    }
    else{
        No *aux;
        for (aux = inicio; aux->prox != NULL; aux = aux->prox) {}
        novo->prox = aux->prox;
        aux->prox = novo;
    }
}


void insereInicio(int x){
    No *novo;
    novo = new struct No();
    novo->dado = x;
    novo->prox = inicio;
    inicio = novo;
}


void imprime(){
    if(inicio != NULL){
        struct No *aux;
        for(aux = inicio; aux != NULL; aux = aux->prox){
            printf("| %d ", aux->dado);
        }
        printf("|");
    } else
        printf("Lista vazia!!");
}


struct No *busca(int x, int status){

    No *aux;
    for (aux = inicio; aux != NULL; aux = aux->prox) {
        if(x == aux->dado){
            if (status == 1){
                printf("O numero %d esta no endereco %p.", x, aux);
                return nullptr;
            }
            else
                return aux;
        }
    }
    printf("Nao encontrado!!");
    return nullptr;
}


void alterar(){
    int num;
    printf("Qual numero da lista deseja substituir?\n");
    scanf ("%d%*C", &num);
    struct No *aux = busca(num, 0);
    printf("Digite o numero desejado para inserir na lista:");
    scanf ("%d%*C", &aux->dado);
    printf("Feito!!");

}


int excluirElemento() {
    imprime();
    if (inicio == NULL)return 1;

    int x;
    printf("\nDigite o elemento que deseja excluir:");
    scanf("%d%*C", &x);

    if(inicio->dado == x){
        No *aux = inicio;
        inicio = inicio->prox;
        free(aux);
    }
    else{
        No *aux1; // anterior ao excluido
        No *aux2 = busca(x, 0); // a ser excluido
        if(aux2 == nullptr)
            return 1;
        No *aux3; // posterior ao excluido
        aux3 = aux2->prox;
        for (aux1 = inicio; aux1->prox != aux2; aux1 = aux1->prox) {}
        aux1->prox = aux3;
        free(aux2);
    }
    return 0;
}

void excluirLista();


int main(){
    char op;
    int  num;
    do{
        op = menu();
        switch (op){
            case '1':
                printf("Digite um numero para inserir na lista:");
                scanf ("%d%*C", &num);
                insereInicio(num);
                break;
            case '2':
                printf("Digite um numero para inserir na lista:");
                scanf ("%d%*C", &num);
                insereFim(num);
                break;
            case '3':
                if(inicio!=NULL) {
                    printf("Digite um numero para buscar na lista:");
                    scanf("%d%*C", &num);
                    busca(num, 1);break;
                }else {
                    printf("Lista vazia.");
                    break;
                }
            case '4': alterar();break;
            case '5': excluirElemento();break;
            case '6': excluirLista();break;
            case '7': imprime(); break;
            default :
                if (op != '0')
                    printf ("\nEscolha errada!!!!");
                else
                    printf ("\nFIM");
        }
    }while (op != '0');
    return 0;
}
