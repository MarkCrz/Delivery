#include <iostream>

#include "D:\Estruturas de Dados\Bibliotecas\lista_estatica.h"
#include "Bibliotecas\cardapio.h"
#include "Bibliotecas\cadastro.h"
#include "Bibliotecas\pedidos.h"
#include "Bibliotecas\motoboy.h"

#include <string>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

using namespace std;


int main () {

    TLista<string, 20> cardapioNomes;
    TLista<string, 20> cardapioDescricoes;
    TLista<float, 20> cardapioPrecos;

    string nome;
    string endereco;
    string itemsRandomico;
    float precoPedidoRandomico = NULL;

    TPedido<string> pedidosAndamento;
    TPedido<string> pedidosConcluidos;
    TElementoPe<string>* pedidoGerado;

    TMotoboy motoboys;
    TElementoM* motoboyAtual;

    srand((unsigned)time(NULL));

    inicializa_lista(cardapioNomes);
    inicializa_lista(cardapioDescricoes);
    inicializa_lista(cardapioPrecos);

    inicializa_pedido(pedidosAndamento);
    inicializa_pedido(pedidosConcluidos);

    inicializa_motoboy(motoboys);
    for (int i = 0; i < 5; i++) {
        insere_motoboy_fim(motoboys);
    }
    inicializa_dia_MB(motoboys);
    motoboyAtual = motoboys.inicio;
    int l = 0;
    int j = 0;

    try {
        cria_cardapio_nome(cardapioNomes);
        cria_cardapio_descricao(cardapioDescricoes);
        cria_cardapio_preco(cardapioPrecos);

        cout << "=================================================================" << endl;
        cout << "CARDAPIO:" << endl;
        imprime_lista(cardapioNomes, cardapioDescricoes, cardapioPrecos);
        cout << "=================================================================" << endl;
        cout << "LANCHONETE ABERTA!!!" << endl;
        for (int i = 0; i <= 30; i++) {
            if (motoboys.inicio != NULL) {
                conta_entrega(motoboys);
            }
            if (pedidosAndamento.inicio != NULL) {
                conta_preparo(pedidosAndamento);
                if (pedidosAndamento.inicio->tempo == 0) {
                    if (verifica_motoboy(motoboys, motoboyAtual) == true) {
                        pedidoGerado = obter_pedido(pedidosAndamento, 0);
                        remove_pedido_inicio (pedidosAndamento);
                        insere_pedido_fim(pedidosConcluidos, pedidoGerado);
                        cout << "Pedido concluido!!" << endl
                             << "Pedido: " << pedidoGerado << "\tJ: " << j << endl
                             << "Preco: " << pedidoGerado->preco << endl
                             << "Tempo de Entrega: " << 7 << " min" << endl << endl;
                        j++;
                    } else {
                        cout << "Nao ha motoboy disponivel!" << endl;
                    }
                }
            } 
            if ((i % 2 == 0) and (i != 0)) {
                nome = gerar_nome();
                endereco = gerar_endereco();
                itemsRandomico = gerar_pedido(precoPedidoRandomico);
                pedidoGerado = cria_pedido(nome, endereco, itemsRandomico, precoPedidoRandomico);
                pedidoGerado->tempo = define_tempo(pedidosAndamento);
                insere_pedido_fim(pedidosAndamento, pedidoGerado);
                cout << "Pedido confirmado!!" << endl
                     << "Pedido: " << pedidoGerado << "\tL: " << l << endl
                     << "Preco: " << pedidoGerado->preco << endl
                     << "Tempo de Preparo: " << pedidoGerado->tempo << " min" << endl
                     << "Tempo de Entrega: " << 7 << " min" << endl << endl;
                precoPedidoRandomico = NULL;
                l++;
           }
           if ((rand() % 100) < 10) {
               insere_motoboy_fim(motoboys);
           }
        }

        int tempoRestante = tempo_restante(pedidosAndamento);
        cout << "=================================================================" << endl;
        cout << "FINALIZANDO PEDIDOS" << endl;
        for (int i = 0; i < tempoRestante; i++) {
            if (motoboys.inicio != NULL) {
                conta_entrega(motoboys);
            }
            if (pedidosAndamento.inicio != NULL) {
                conta_preparo(pedidosAndamento);
                if (pedidosAndamento.inicio->tempo == 0) {
                    if (verifica_motoboy(motoboys, motoboyAtual) == true) {
                        pedidoGerado = obter_pedido(pedidosAndamento, 0);
                        remove_pedido_inicio (pedidosAndamento);
                        insere_pedido_fim(pedidosConcluidos, pedidoGerado);
                        cout << "Pedido concluido!!" << endl
                             << "Pedido: " << pedidoGerado << "\tJ: " << j << endl
                             << "Preco: " << pedidoGerado->preco << endl
                             << "Tempo de Entrega: " << 7 << " min" << endl << endl;
                        j++;
                    } else {
                        cout << "Nao ha motoboy disponivel!" << endl;
                    }
                }
            } 
        }
        
        cout << "=================================================================" << endl;
        cout << "LISTA DE MOTOBOYS" << endl;
        lista_motoboy(motoboys);
        cout << "=================================================================" << endl;
        cout << "PEDIDOS CONCLUIDOS:" << endl;
        imprime_inicio_Pe(pedidosConcluidos);
        cout << "=================================================================" << endl;
        cout << "O CAIXA RENDEU: " << fechamento_caixa(pedidosConcluidos) << " R$" << endl;
        while (pedidosConcluidos.inicio != NULL) {
            remove_pedido_inicio(pedidosConcluidos);
        }
        delete pedidoGerado;
    }
    catch(const char* err) {
        cout << "ERRO: " << err << endl;
    }
    

    return 0;
}