#include <iostream>

#include <cstdlib>

using namespace std;

typedef struct cliente{
    string nome;
    string cpf;
} Cliente;

typedef struct node{
    Cliente cliente;
    struct node* prox;
} Node;

typedef struct lista{
    int tam;
    Node* prim;
    Node* ult;
} ListaCabeca;

ListaCabeca* criarListaVazia(){
    ListaCabeca* cabeca = (ListaCabeca *) malloc(sizeof(ListaCabeca));
    cabeca->tam = 0;
    cabeca->prim = NULL;
    cabeca->ult = NULL;
    return cabeca;
}

bool inserirElemento(string nome, string cpf, int pos, ListaCabeca* lista){
    if(pos > lista->tam || pos < 0)
        return false;

    Node* novo = (Node *) malloc(sizeof(Node));
    (novo->cliente).nome = nome;
    (novo->cliente).cpf = cpf;

    if(lista->tam == 0){
        novo->prox = novo;
        lista->prim = lista->ult = novo;
    }
    else if(pos == 0){
        novo->prox = lista->prim;
        lista->prim = novo;
        lista->ult->prox = novo;
    }
    else{
        Node *aux = lista->prim;
        for(int i = 1; i < pos; ++i){
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;

        if(pos == lista->tam)
            lista->ult = novo;
    }
    ++lista->tam;

    return true;
}

Cliente remover(int pos, ListaCabeca* lista){
    if(lista->tam == 0 || pos < 0 || pos >= lista->tam){
        Cliente nulo = {"", 0};
        return nulo;
    }

    Node* remov;

    if(lista->tam == 1){
        remov = lista->prim;
        lista->prim = lista->ult = NULL;
    }
    else if(pos == 0){
        remov = lista->prim;
        lista->prim = lista->prim->prox;
        lista->ult->prox = lista->prim;
    }
    else{
        Node* aux = lista->prim;
        for(int i = 1; i < pos; ++i)
            aux = aux->prox;

        remov = aux->prox;
        aux->prox = aux->prox->prox;
        if(pos == (lista->tam) - 1)
            lista->ult = aux;
    }

    Cliente cliente = {remov->cliente.nome, remov->cliente.cpf};
    free(remov);

    --lista->tam;

    return cliente;
}

int buscar(Cliente cliente, ListaCabeca* lista){
    int pos = -1;

    if(lista->tam != 0){

        int cont = 0;

        Node* node = lista->prim;

        do{
            if(node->cliente.nome == cliente.nome && node->cliente.cpf == cliente.cpf){
                pos = cont;
                break;
            }
            node = node->prox;
            ++cont;
        } while(node != lista->prim);
    }

    return pos;
}

void imprimirLista(ListaCabeca* lista){

    cout << "--------------------------------------------------------" << endl;

    if(lista->tam == 0){
        cout << "Lista Vazia" << endl;
    }
    else{
        cout << "Tamanho da lista: " << lista->tam << endl;

        Node* node = lista->prim;

        do{
            cout << endl;
            cout << "Nome: " << node->cliente.nome << endl;
            cout << "CPF : " << node->cliente.cpf  << endl;

            node = node->prox;
        } while(node != lista->prim);
    }

    cout << "--------------------------------------------------------" << endl;
}

void deletarLista(ListaCabeca* lista){
    if(lista->tam != 0){
        Node* node = lista->prim;
        Node* aux;
        do{
            aux = node;
            node = node->prox;
            free(aux);
        } while(node != lista->prim);
    }

    free(lista);
}

int main(){

    //TESTANDO FUNÇÕES

    cout << "*Criando e imprimindo Lista Circular Vazia\n" << endl;

    ListaCabeca* lista = criarListaVazia();
    imprimirLista(lista);

    cout << "\n*Inserindo Cliente Carlos Maia na posicao 0.\n" << endl;

    inserirElemento("Carlos Maia", "12345678945", 0, lista);
    imprimirLista(lista);

    cout << "\n*Inserindo Cliente Joao Passos na posicao 0.\n" << endl;

    inserirElemento("Joao Passos", "26485960463", 0, lista);
    imprimirLista(lista);

    cout << "\n*Inserindo Cliente Fernando Bezerra na posicao 2.\n" << endl;

    inserirElemento("Fernando Bezerra", "25365702484", 2, lista);
    imprimirLista(lista);

    cout << "\n*Inserindo Cliente Lucio Almeida na posicao 1.\n" << endl;

    inserirElemento("Lucio Almeida", "03425714263", 1, lista);
    imprimirLista(lista);

    cout << "\n*Removendo cliente na posicao 1 da Lista Circular.\n" << endl;

    Cliente remov = remover(1, lista);
    imprimirLista(lista);

    cout << "\n*Cliente removido:\n" << endl;
    cout << "Nome: " << remov.nome << endl;
    cout << "CPF : " << remov.cpf  << endl;

    cout << "\n*Removendo cliente na posicao 0 da Lista Circular.\n" << endl;

    remov = remover(0, lista);
    imprimirLista(lista);

    cout << "\n*Cliente removido:\n" << endl;
    cout << "Nome: " << remov.nome << endl;
    cout << "CPF : " << remov.cpf  << endl;

    cout << "\n*Buscando Clientes:" << endl;

    Cliente carlos = {"Carlos Maia", "12345678945"};
    Cliente fernando = {"Fernando Bezerra", "25365702484"};
    Cliente joao = {"Joao Passos", "26485960463"};

    int pos = buscar(carlos, lista);
    if(pos != -1) cout << "\nCliente Carlos Maia na posicao " << pos << "." << endl;
    else          cout << "\nCliente Carlos Maia nao encontrado." << endl;

    pos = buscar(fernando, lista);
    if(pos != -1) cout << "\nCliente Fernando Bezerra na posicao " << pos << "." << endl;
    else          cout << "\nCliente Fernando Bezerra nao encontrado." << endl;

    pos = buscar(joao, lista);
    if(pos != -1) cout << "\nCliente Joao Passos na posicao " << pos << "." << endl;
    else          cout << "\nCliente Joao Passos nao encontrado." << endl;

    cout << "\n*Deletando Lista. Desalocando todos os nodes e a cabeca." << endl;

    deletarLista(lista);

    return 0;
}
