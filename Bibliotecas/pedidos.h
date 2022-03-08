#ifndef PEDIDOS_H
#define PEDIDOS_H

#include <iostream>

using namespace std;

template <class T>
struct TElementoPe {
    T nome;
    T endereco;
    T item;
    float preco;
    int tempo;
    TElementoPe<T>* proximo;
    TElementoPe<T>* anterior;
};

template <class T>
struct TPedido {
    TElementoPe<T>* inicio;
    TElementoPe<T>* fim;
};

template <class T>
void inicializa_pedido (TPedido<T> &pedidos) {
    pedidos.inicio = NULL;
    pedidos.fim = NULL;
}

//=====================================================================================================================================================================
template <class T>
TElementoPe<T>* cria_pedido (T name, T address, T order, float price) {
    TElementoPe<T>* novo = new TElementoPe<T>;
    novo->nome = name;
    novo->endereco = address;
    novo->item = order;
    novo->preco = price;
    novo->tempo = 5;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

//=====================================================================================================================================================================
template <class T>
void insere_pedido_fim (TPedido<T> &pedidos, TElementoPe<T>* novo) {
    if ((pedidos.inicio == NULL) and (pedidos.fim == NULL)) {
        pedidos.inicio = new TElementoPe<T>;
        pedidos.fim = new TElementoPe<T>;
        pedidos.inicio = novo;
        pedidos.fim = novo;
    } else {
        pedidos.fim->proximo = novo;
        novo->anterior = pedidos.fim;
        pedidos.fim = novo;
    }
}

template <class T>
void insere_pedido_inicio (TPedido<T> &pedidos, TElementoPe<T>* novo) {
    if ((pedidos.inicio == NULL) and (pedidos.fim == NULL)) {
        pedidos.inicio = new TElementoPe<T>;
        pedidos.fim = new TElementoPe<T>;
        pedidos.inicio = novo;
        pedidos.fim = novo;
    } else {
        novo->proximo = pedidos.inicio;
        pedidos.inicio->anterior = novo;
        pedidos.inicio = novo;
    }
}

template <class T>
void insere_pedido_posicao (TPedido<T> &pedidos, TElementoPe<T>* novo, int posicao) {
    if (posicao < 0) {
        throw "Posicao negativa!";
    } if (posicao == 0) {
        insere_pedido_inicio(pedidos, novo);
    } else {
        TElementoPe<T>* nav = pedidos.inicio;
        int i = 0;
        while ((i < posicao - 1) and (nav->proximo != NULL)) {
            nav = nav->proximo;
        } 
        if (nav->proximo != NULL) {
            novo->anterior = nav;
            novo->proximo = nav->proximo;
            nav->proximo = novo;
            novo->proximo->anterior = novo;
        } else {
            if(posicao == retorna_tamanho_Pe(pedidos)) {
                insere_pedido_fim(pedidos, novo);
            } else {
                throw "Posicao maior que a lista!";
            }
        }
    }
}

//=====================================================================================================================================================================
template <class T>
TElementoPe<T>* remove_pedido_inicio (TPedido<T> &pedidos) {
    if ((pedidos.inicio == NULL) and (pedidos.fim == NULL)) {
        throw "Stack Underflow!";
    } else {
        TElementoPe<T>* excluir = pedidos.inicio;
        pedidos.inicio = excluir->proximo;
        if (retorna_tamanho_Pe(pedidos) != 0) {
            pedidos.inicio->anterior = NULL;
        } else {
            pedidos.fim = NULL;
        }
        delete excluir;
    }
}

template <class T>
void remove_pedido_fim (TPedido<T> &pedidos) {
    if ((pedidos.inicio == NULL) and (pedidos.fim == NULL)) {
        throw "Stack Underflow!";
    } else {
        TElementoPe<T>* excluir = pedidos.fim;
        pedidos.fim = pedidos.fim->anterior;
        if (retorna_tamanho_Pe(pedidos != 0)) {
            pedidos.fim->proximo = NULL;
        } else {
            pedidos.inicio = NULL;
        }
        delete excluir;
    }
}

template <class T>
void remove_pedido_posicao (TPedido<T> &pedidos, int posicao) {
    if ((pedidos.inicio == NULL) and (pedidos.fim == NULL)) {
        throw "Stack Underflow!";
    } if (posicao < 0) {
            throw "Posicao negativa!";
    } else {
        if (posicao == 0) {
            remove_pedido_inicio(pedidos);
        } else {
            TElementoPe<T>* nav = pedidos.inicio;
            int i = 0;
            while ((i < posicao - 1) and (nav->proximo != NULL)) {
                nav = nav->proximo;
            }
            if (nav != NULL) {
                TElementoPe<T>* excluir = nav->proximo;
                nav->proximo = excluir->proximo;
                excluir->proximo->anterior = nav;
            } else {
                throw "Posicao maior que a lista!";
            }
        }
    }
}

//=====================================================================================================================================================================
template <class T>
bool busca_pedido (TPedido<T> pedidos, TElementoPe<T> info) {
    for (TElementoPe<T>* nav = pedidos.inicio; nav != NULL; nav = nav->proximo) {
        if ((nav->nome == info->nome) and (nav->endereco == info->endereco) and (nav->item == info->item) and (nav->preco == info->preco)) {
            return true;
        }
    }
    return false;
}

template <class T>
int obter_indice_pedido (TPedido<T> pedidos, TElementoPe<T> info) {
    if (busca_pedido(pedidos, info) == true) {
        int i = 0;
        for (TElementoPe<T>* nav = pedidos.inicio; nav != NULL; nav = nav->proximo) {
            if ((nav->nome == info->nome) and (nav->endereco == info->endereco) and (nav->item == info->item) and (nav->preco == info->preco)) {
            return i;
            }
            i++;
        }
    } else {
        throw "O pedido nao pertence a lista!";
    }
}

template <class T>
TElementoPe<T>* obter_pedido (TPedido<T> pedidos, int posicao) {
    if ((pedidos.inicio == NULL) and (pedidos.fim == NULL)) {
        throw "Stack Underflow!";
    } if (posicao < 0) {
        throw "Posicao negativa!";
    } else {
        int i = 0;
        for (TElementoPe<T>* nav = pedidos.inicio; nav != NULL; nav = nav->proximo) {
            if (i == posicao) {
                TElementoPe<T>* retirar = cria_pedido(nav->nome, nav->endereco, nav->item, nav->preco);
                retirar->tempo = 0;
                return retirar;
            }
            i++;
        }
        throw "Posicao maior que a lista";
    }
}

//=====================================================================================================================================================================
template <class T>
int define_tempo (TPedido<T> &pedidos) {
    int emPreparo = 0;
    int tempoEsperado = 5;
    for (TElementoPe<T>* nav = pedidos.fim; nav != NULL; nav = nav->anterior) {
        emPreparo++;
    }

    if (emPreparo < 3) {
        tempoEsperado = tempoEsperado + 0;
    } else {
        tempoEsperado = tempoEsperado + pedidos.inicio->tempo;
    }
    return tempoEsperado;
}

template <class T>
int retorna_tamanho_Pe (TPedido<T> pedidos) {
    int i = 0;
    for(TElementoPe<T>* nav = pedidos.inicio; nav != NULL; nav = nav->proximo) {
        i++;
    }
    return i;
}

template <class T>
void conta_preparo (TPedido<T> &pedidos) {
    for (TElementoPe<T>* nav = pedidos.inicio; nav != NULL; nav = nav->proximo) {
        if(nav->tempo != 0) {
            nav->tempo = nav->tempo - 1;
        }
    }
}

//=====================================================================================================================================================================
template <class T>
int tempo_restante (TPedido<T> pedidos) {
    int tempoRestante = 0;
    for(TElementoPe<T>* nav = pedidos.inicio; nav != NULL; nav = nav->proximo) {
        tempoRestante = tempoRestante + nav->tempo;
    }
    return tempoRestante;
}

//=====================================================================================================================================================================
template <class T>
double fechamento_caixa (TPedido<T> pedidos) {
    double valorInicio = 0.0f;
    double valorFinal = 0.0f;
    for(TElementoPe<T>* nav = pedidos.inicio; nav != NULL; nav = nav->proximo) {
        valorInicio = valorInicio + nav->preco;
    }
    for (TElementoPe<T>* nav = pedidos.fim; nav != NULL; nav = nav->anterior) {
        valorFinal = valorFinal + nav->preco;
    }
    if(valorFinal == valorInicio) {
        return valorInicio;
    } else {
        cout << valorInicio << " | " << valorFinal << endl;
        throw "O CAIXA ESTA ERRADO!!";
    }
}

//=====================================================================================================================================================================
template <class T>
void imprime_inicio_Pe (TPedido<T> pedidos) {
    cout << "Imprime pedidos do inicio-fim!" << endl;
    cout << "Comeca em: " << pedidos.inicio << endl;
    cout << "Termina em: " << pedidos.fim << endl;
    int posicao = 0;
    for(TElementoPe<T>* nav = pedidos.inicio; nav != NULL; nav = nav->proximo) {
        cout << "Elemento[" << posicao++ << "]: " << "nome: " << nav->nome << endl
                                                  << "endereco: " << nav->endereco << endl
                                                  << "pedido: " << nav->item << endl
                                                  << "preco: " << nav->preco << endl
                                                  << "tempo: " << nav->tempo << endl
                                                  << " - &: " << nav 
                                                  << " - anterior: " 
                                                  << nav->anterior 
                                                  << " - proximo: " << nav->proximo << endl;
    }
}

template <class T>
void imprime_fim_Pe (TPedido<T> pedidos) {
    cout << "Imprime pedidos do fim-inicio!" << endl;
    cout << "Comeca em: " << pedidos.fim << endl;
    cout << "Termina em: " << pedidos.inicio << endl;
    int posicao = (retorna_tamanho_Pe(pedidos) - 1);
    for(TElementoPe<T>* nav = pedidos.fim; nav != NULL; nav = nav->anterior) {
        cout << "Elemento[" << posicao-- << "]:" << "nome: " << nav->nome << endl
                                                  << "endereco: " << nav->endereco << endl
                                                  << "pedido: " << nav->item << endl
                                                  << "preco: " << nav->preco << endl
                                                  << "tempo: " << nav->tempo << endl
                                                  << " - &: " << nav 
                                                  << " - anterior: " 
                                                  << nav->anterior 
                                                  << " - proximo: " << nav->proximo << endl;
    }
}

#endif