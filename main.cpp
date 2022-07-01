#include <stdio.h>
#include <cstring>

struct No{
    int dado;
    struct No *prox;
} *inicio = nullptr;
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

    if (inicio == nullptr) {
        novo->prox = inicio;
        inicio = novo;
    }
    else{
        No *aux;
        for (aux = inicio; aux->prox != nullptr; aux = aux->prox) {}
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
    if(inicio != nullptr){
        struct No *aux;
        for(aux = inicio; aux != nullptr; aux = aux->prox){
            printf("| %d ", aux->dado);
        }
        printf("|");
    } else
        printf("Lista vazia!!");
}

No *buscaSemPrint(int x){
    No *aux;
    for (aux = inicio; aux != nullptr; aux = aux->prox) {
        if (x == aux->dado)return aux;
    }
    return nullptr;
}

No *buscaComPrint(int x){

    No *aux = buscaSemPrint(x);
    if (aux != nullptr){
        printf("O numero %d esta no endereco %p.", x, aux);
        return aux;
    }
    printf("Nao encontrado!!");return nullptr;
}


int alterar(int num){
    struct No *aux = buscaSemPrint(num);
    if(aux == nullptr) {
        printf("Nao encontrado!!");
        return 0;
    }
    printf("Digite o numero desejado para inserir na lista:");
    scanf ("%d%*C", &aux->dado);
    printf("Feito!!");
    return 0;

}


int excluirElemento(int x) {

    if(inicio->dado == x){
        No *aux = inicio;
        inicio = inicio->prox;
        memset(aux, 0, sizeof(No));
    }
    else{
        No *aux1; // anterior ao excluido
        No *aux2 = buscaSemPrint(x); // a ser excluido

        if(aux2 == nullptr) {
            printf("Nao encontrado!!");
            return 0;
        }

        for (aux1 = inicio; aux1->prox != aux2; aux1 = aux1->prox) {}
        aux1->prox = aux2->prox;
        memset(aux2, 0, sizeof(No));
    }
    return 0;
}

int excluirLista() {
    if(inicio != nullptr){
        No *aux;
        No *apagar = inicio;
        for(aux = inicio->prox; aux != nullptr; aux = aux->prox){
            excluirElemento(apagar->dado);
            apagar = aux;
        }
        excluirElemento(apagar->dado);
        return 0;
    }
    printf("Lista vazia!!");
    return 0;
}


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
                if(inicio!=nullptr) {
                    printf("Digite um numero para buscar na lista:");
                    scanf("%d%*C", &num);
                    buscaComPrint(num);
                    break;
                }printf("Lista vazia.");break;
            case '4':
                if(inicio != nullptr) {
                    int num;
                    printf("Qual numero da lista deseja substituir?\n");
                    scanf("%d%*C", &num);
                    alterar(num);break;
                }printf("Lista vazia!!");break;
            case '5':
                imprime();
                if (inicio == nullptr)break;
                int x;
                printf("\nDigite o elemento que deseja excluir:");
                scanf("%d%*C", &x);
                excluirElemento(x);break;
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
