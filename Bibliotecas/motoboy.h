#ifndef MOTOBOY_H
#define MOTOBOY_H

#include <iostream>
using namespace std;


struct TElementoM {
    bool trabalhando;
    int tempo;
    TElementoM* proximo;
};


struct TMotoboy {
    TElementoM* inicio;
};

void inicializa_motoboy (TMotoboy &motoboys) {
    motoboys.inicio = NULL;
}

//=====================================================================================================================================================================

TElementoM* cria_motoboy () {
    TElementoM* novo = new TElementoM;
    novo->trabalhando = true;
    novo->tempo = NULL;
    return novo;
}

//=====================================================================================================================================================================
void inicializa_dia_MB (TMotoboy &motoboys) {
    TElementoM* nav = motoboys.inicio;
    int random = NULL;
    for (int i = 0; i < 10; i++) {
        random = (rand() % 20);
        if (random < 10) {
            nav->trabalhando = true;
            nav = nav->proximo;
        } else {
            nav->trabalhando = false;
            nav = nav->proximo;
        }
    }
}

int retorna_tamanho_motoboy (TMotoboy motoboys) {
    int i = 0;
    for (TElementoM* nav = motoboys.inicio; nav != motoboys.inicio or (i == 0 and motoboys.inicio != NULL); nav = nav->proximo) {
        i++;
    }
    return i;
}

//=====================================================================================================================================================================
void insere_motoboy_fim (TMotoboy &motoboys) {
    TElementoM* novo = cria_motoboy();
    if(motoboys.inicio == NULL) {
        novo->proximo = novo;
        motoboys.inicio = novo;
    } else {
        TElementoM* nav = motoboys.inicio;
        while (nav->proximo != motoboys.inicio) {
            nav = nav->proximo;
        }
        nav->proximo = novo;
        novo->proximo = motoboys.inicio;
    }
}

void insere_motoboy_inicio(TMotoboy &motoboys) {
    TElementoM* novo = cria_motoboy();
    if (motoboys.inicio == NULL) {
        novo->proximo = novo;
        motoboys.inicio = novo;
    } else {
        TElementoM* nav = motoboys.inicio;
        while (nav->proximo != motoboys.inicio) {
            nav = nav->proximo;
        }
        novo->proximo = motoboys.inicio;
        motoboys.inicio = novo;
        nav->proximo = motoboys.inicio;
    }
}

void insere_motoboy_posicao(TMotoboy &motoboys, int posicao) {
    if (posicao < 0) {
        throw "Posicao negativa!";
    } if (posicao == 0) {
        insere_motoboy_inicio(motoboys);
    } else {
        TElementoM* novo = cria_motoboy();
        TElementoM* nav = motoboys.inicio;
        int i = 0;
        while (i < (posicao - 1) and (nav->proximo != motoboys.inicio)) {
            nav = nav->proximo;
            i++;
        }
        if (nav->proximo != motoboys.inicio) {
            novo->proximo = nav->proximo;
            nav->proximo = novo;
        } else {
            if(posicao == retorna_tamanho_motoboy(motoboys)) {
                insere_motoboy_fim(motoboys);
            } else {
                throw "Posicao maior que a lista!";
            }
        }
    }
}

//=====================================================================================================================================================================
void remove_motoboy_fim (TMotoboy &motoboys) {
    if (motoboys.inicio == NULL) {
        throw "Stack Underflow!";
    } else {
        TElementoM* nav = motoboys.inicio;
        TElementoM* navAnt;
        while (nav->proximo != motoboys.inicio) {
            navAnt = nav;
            nav = nav->proximo;
        }
        TElementoM* excluir = nav;
        navAnt->proximo = motoboys.inicio;
        delete excluir;
    }
}

void remove_motoboy_inicio (TMotoboy &motoboys) {
     if (motoboys.inicio == NULL) {
        throw "Stack Underflow!";
    } else {
        TElementoM* nav = motoboys.inicio;
        while (nav->proximo != motoboys.inicio) {
            nav = nav->proximo;
        }
        TElementoM* excluir = motoboys.inicio;
        motoboys.inicio = motoboys.inicio->proximo;
        nav->proximo = motoboys.inicio;
        delete excluir;
    }
}

void remove_motoboy_posicao (TMotoboy &motoboys, int posicao) {
    if (motoboys.inicio == NULL) {
        throw "Stack Undeflow!";
    } if (posicao < 0) {
        throw "Posicao negativa!";
    } else {
        if (posicao == 0) {
            remove_motoboy_inicio(motoboys);
        } else {
            TElementoM* nav = motoboys.inicio;
            int i = 0;
            while (i < (posicao - 1) and (nav->proximo != motoboys.inicio)) {
                nav = nav->proximo;
                i++;
            }
            if (nav->proximo != motoboys.inicio) {
                TElementoM* excluir = nav->proximo;
                nav->proximo = excluir->proximo;
                delete excluir;
            } else {
                throw "Posicao maior que a lista!";
            }
        }
    }
}

//=====================================================================================================================================================================
bool pertece_motoboy (TMotoboy motoboys, TElementoM info) {
    int i = 0;
    for (TElementoM* nav = motoboys.inicio; nav != motoboys.inicio or (i == 0 and motoboys.inicio != NULL); nav = nav->proximo) {
        if ((nav->trabalhando == info.trabalhando) and (nav->tempo == info.tempo)) {
            return true;
        }
        i++;
    }
    return false;
}

int obter_indice_motoboy (TMotoboy motoboys, TElementoM info) {
    if (pertece_motoboy(motoboys, info) == true) {
        int i = 0;
        for (TElementoM* nav = motoboys.inicio; nav != motoboys.inicio or (i == 0 and motoboys.inicio != NULL); nav = nav->proximo) {
            if ((nav->trabalhando == info.trabalhando) and (nav->tempo == info.tempo)) {
                return i;
            }
        i++;
        }
    }
}

TElementoM* obter_motoboy (TMotoboy motoboys, int posicao) {
    if (motoboys.inicio == NULL) {
        throw "Stack Underflow!";
    } if (posicao < 0) {
        throw "Posicao negativa!";
    } else {
        int i = 0;
        for (TElementoM* nav = motoboys.inicio; nav != motoboys.inicio or (i == 0 and motoboys.inicio != NULL); nav = nav->proximo) {
            if (i == posicao) {
                return nav;
            }
            i++;
        }
        throw "Posicao maior que a lista!";
    }
}
//=====================================================================================================================================================================
bool verifica_motoboy (TMotoboy &motoboys, TElementoM* motoboyAtual) {
    if (motoboys.inicio == NULL) {
        throw "Lista nao inicializada";
    } else {
        int i = 0;
        for (TElementoM* nav = motoboyAtual; nav != motoboyAtual or (i == 0 and motoboyAtual != NULL); nav = nav->proximo) {
            i++;
            if ((nav->tempo == NULL) and (nav->trabalhando == true)) {
                nav->tempo = 7;
                cout << "O motoboy: " << nav << " saiu para entrega!" << endl;
                motoboyAtual = nav->proximo;
                return 1;
            }
        }
        return 0;
    }
}

//=====================================================================================================================================================================
void conta_entrega (TMotoboy &motoboys) {
    int i = 0;
    for (TElementoM* nav = motoboys.inicio; nav != motoboys.inicio or (i == 0 and motoboys.inicio != NULL); nav = nav->proximo) {
        if (nav->tempo != 0) {
            nav->tempo = (nav->tempo - 1);
        }
        i++;
    }
}

//=====================================================================================================================================================================
void lista_motoboy (TMotoboy motoboys) {
    int i = 0;
    cout << "Inicio da lista: " << motoboys.inicio << endl;
    for (TElementoM* nav = motoboys.inicio; nav != motoboys.inicio or (i == 0 and motoboys.inicio != NULL); nav = nav->proximo) {
        cout << "Item[" << i++ << "]: " << "Trabalhando: " << nav->trabalhando << endl 
                                        << "Entrega: " << nav->tempo << endl
                                        << " - addr: " << nav << " - prox: " << nav->proximo << endl;
    }
}

#endif //MOTOBOY_H