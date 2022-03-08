#ifndef CARDAPIO_H
#define CARDAPIO_H
#include "D:\Estruturas de Dados\Bibliotecas\lista_estatica.h"

#include <iostream>

using namespace std;

template <class T, int MAX>
void cria_cardapio_nome (TLista<T, MAX> &lista) {
    if (lista.quantidade == 0) {
        TElementos<T> temp;
        temp.dado = "DSC Bacon Burger";
        lista.dados[0] = temp;
        temp.dado = "Guerrilha";
        lista.dados[1] = temp;
        temp.dado = "Gorgonzola";
        lista.dados[2] = temp;
        temp.dado = "Gorgonzola stout";
        lista.dados[3] = temp;
        temp.dado = "Classic";
        lista.dados[4] = temp;
        temp.dado = "Double Bacon";
        lista.dados[5] = temp;
        temp.dado = "Cheddar";
        lista.dados[6] = temp;
        temp.dado = "Veggie";
        lista.dados[7] = temp;
        temp.dado = "Kids";
        lista.dados[8] = temp;

        temp.dado = "Batata frita + cheddar e bacon";
        lista.dados[9] = temp;
        temp.dado = "Batata frita tradicional";
        lista.dados[10] = temp;
        temp.dado = "Onion rings";
        lista.dados[11] = temp;

        temp.dado = "Agua";
        lista.dados[12] = temp;
        temp.dado = "Refrigerante";
        lista.dados[13] = temp;
        temp.dado = "Suco";
        lista.dados[14] = temp;
        temp.dado = "Cerveja";
        lista.dados[15] = temp;
        lista.quantidade = 16;
    } else {
        throw "Cardapio ja existente!";
    }
}

template <class T, int MAX>
void cria_cardapio_descricao (TLista<T, MAX> &lista) {
    if (lista.quantidade == 0) {
        TElementos<T> temp;
        temp.dado = "Lanche composto por 02 Smash Burgers de 80gr, 4 fatias de cheddar Polenghi, muito bacon e molho especial no pao de brioche";
        lista.dados[0] = temp;
        temp.dado = "Hamburguer artesanal 100% costela angus defumada (180gr), bacon caramelizado levemente picante, queijo brie, alface, tomate e cebola roxa no pao cervejinha com gergelim preto.";
        lista.dados[1] = temp;
        temp.dado = "Hamburguer artesanal de carnes nobres (180gr), queijo gorgonzola cremoso, alface, tomate e cebola roxa no pao com gergelim.";
        lista.dados[2] = temp;
        temp.dado = "Hamburguer artesanal de carnes nobres (180gr), queijo gorgonzola em pedaços, cebola caramelizada na cerveja stout no pao australiano.";
        lista.dados[3] = temp;
        temp.dado = "Hamburguer artesanal de carnes nobres (120gr), queijo mussarela, alface e tomate no pao com gergelim.";
        lista.dados[4] = temp;
        temp.dado = "Hamburguer artesanal de carnes nobres (180gr), double bacon crispy, molho barbecue, queijo mussarela, alface e tomate no pao com gergelim.";
        lista.dados[5] = temp;
        temp.dado = "Hamburguer artesanal de carnes nobres (180gr), queijo cheddar cremoso, bacon crispy, farofa de torresmo e cebola roxa no pao australiano.";
        lista.dados[6] = temp;
        temp.dado = "Hamburguer vegetariano (grao de bico, proteína de soja, aveia e cogumelo shitake), queijo gorgonzola, molho de mostarda e mel, nozes quebradas, alface, tomate e cebola roxa no pao australiano.";
        lista.dados[7] = temp;
        temp.dado = "Hamburguer artesanal de carnes nobres (120gr) e queijo mussarela no pao kids.";
        lista.dados[8] = temp;

        temp.dado = "Porcao de 350gr de Batata Frita com Cheddar Cremoso e Bacon Crispy";
        lista.dados[9] = temp;
        temp.dado = "Porcao de 350gr de Batata Frita";
        lista.dados[10] = temp;
        temp.dado = "Aneis de cebola empanados.";
        lista.dados[11] = temp;

        temp.dado = "Agua mineral com ou sem gas, 500ml";
        lista.dados[12] = temp;
        temp.dado = "Lata 350ml, qualquer marca";
        lista.dados[13] = temp;
        temp.dado = "Nataral. Sabores: uva, laranja, acerola e abacaxi";
        lista.dados[14] = temp;
        temp.dado = "Cerveja long neck, 330ml";
        lista.dados[15] = temp;
        lista.quantidade = 16;
    } else {
        throw "Cardapio ja existente!";
    }
}

template <class T, int MAX>
void cria_cardapio_preco (TLista<T, MAX> &lista) {
    if (lista.quantidade == 0) {
        TElementos<T> temp;
        temp.dado = 21.90;
        lista.dados[0] = temp;
        temp.dado = 26.90;
        lista.dados[1] = temp;
        temp.dado = 19.90;
        lista.dados[2] = temp;
        temp.dado = 21.90;
        lista.dados[3] = temp;
        temp.dado = 14.90;
        lista.dados[4] = temp;
        temp.dado = 25.90;
        lista.dados[5] = temp;
        temp.dado = 24.90;
        lista.dados[6] = temp;
        temp.dado = 21.90;
        lista.dados[7] = temp;
        temp.dado = 10.90;
        lista.dados[8] = temp;

        temp.dado = 15.90;
        lista.dados[9] = temp;
        temp.dado = 10.90;
        lista.dados[10] = temp;
        temp.dado = 12.90;
        lista.dados[11] = temp;

        temp.dado = 4.00;
        lista.dados[12] = temp;
        temp.dado = 5.00;
        lista.dados[13] = temp;
        lista.dados[14] = temp;
        temp.dado = 7.90;
        lista.dados[15] = temp;
        lista.quantidade = 16;
    } else {
        throw "Cardapio ja existente!";
    }
}


#endif // CARDAPIO_H