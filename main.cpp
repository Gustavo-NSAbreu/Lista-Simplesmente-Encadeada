#include <stdio.h>

struct No{
    int dado;
    struct No *prox;
} *inicio = NULL;


char menu(){
    char op;
    printf("\nEscolha:\n0- FIM\n1- Inserir no inicio da lista:\n2- Inserir no fim da lista:\n3- Buscar na lista:\n4- Trocar numero:\n5- Imprimir:\nOpcao:");
    scanf("%c%*C", &op);
    return op;
}


void insereFim(int x){
    struct No *novo;
    novo = new struct No();
    novo->dado = x;

    if (inicio == NULL) {
        novo->prox = inicio;
        inicio = novo;
    }
    else{
        struct No *aux;
        for (aux = inicio; aux->prox != NULL; aux = aux->prox) {}
        novo->prox = aux->prox;
        aux->prox = novo;
    }
}


void insereInicio(int x){
    struct No *novo;
    novo = new struct No();
    novo->dado = x;
    novo->prox = inicio;
    inicio = novo;
}


void imprime(){
    struct No *aux;
    for(aux = inicio; aux != NULL; aux = aux->prox){
        printf("| %d ", aux->dado);
    }
    printf("|");
}


struct No *busca(int x, int status){

    struct No *aux;
    for (aux = inicio; aux != NULL; aux = aux->prox) {
        char op;
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
            case '5': imprime(); break;
            default :
                if (op != '0')
                    printf ("\nEscolha errada!!!!");
                else
                    printf ("\nFIM");
        }
    }while (op != '0');
    return 0;
}
