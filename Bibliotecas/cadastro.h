#ifndef CADASTRO_H
#define CADASTRO_H


#include <iostream>
#include <string>

using namespace std;

string gerar_nome() {
    int number = (1 + (rand() % 10));
    string name;
    switch (number) {
        case 1:
            name = "Mateus Cavalcanti Martins";
            break;
        case 2:
            name = "Leticia Ribeiro Costa";
            break;
        case 3:
            name = "Chloe Price";
            break;
        case 4:
            name = "Rafael Correia Ferreira";
            break;
        case 5:
            name = "Isabela Pereira";
            break;
        case 6:
            name = "Igor Carvalho";
            break;
        case 7:
            name = "Clara de Souza";
            break;
        case 8:
            name = "Gabriel Melo Oliveira";
            break;
        case 9:
            name = "Rebeca Araujo";
            break;
        case 10:
            name = "Felipe Costa";
            break;
    }
    return name;
}

string gerar_endereco () {
    int number = (1 + (rand() % 10));
    string address;
    switch (number) {
        case 1:
            address = "Rua Augusto Scaraboto, 621";
            break;
        case 2:
            address = "Rua das Violetas, 1223";
            break;
        case 3:
            address = "Rua Cinquenta e Oito, 1438";
            break;
        case 4:
            address = "Rua Benedito Paula dos Santos, 46";
            break;
        case 5:
            address = "Rua Affonso Jose Pessoa, 875";
            break;
        case 6:
            address = "Avenida Nossa Senhora das Gracas, 475";
            break;
        case 7:
            address = "Rua Gildartes Wilson, 1695";
            break;
        case 8:
            address = "Rua Joaquim da Luz, 1069";
            break;
        case 9:
            address = "Rua Henrique Pereira, 1233";
            break;
        case 10:
            address = "Avenida Guilherme Cotching, 1571";
            break;
    }
    return address;
}

string gerar_pedido(float &precoPedidoRandomico) {
    string pedido;
    int numberHamburger = (rand() % 9);
    int numberSnack = (rand() % 4);
    int numberDrink = (rand() % 5);
    switch (numberHamburger) {
        case 0:
            pedido = "DSC Bacon Burger";
            precoPedidoRandomico = 21.90;
            break;
        case 1:
            pedido = "Guerrilha";
            precoPedidoRandomico = 26.90;
            break;
        case 2:
            pedido = "Gorgonzola";
            precoPedidoRandomico = 19.90;
            break;
        case 3:
            pedido = "Gorgonzola stout";
            precoPedidoRandomico = 21.90;
            break;
        case 4:
            pedido = "Classic";
            precoPedidoRandomico = 14.90;
            break;
        case 5:
            pedido = "Double Bacon";
            precoPedidoRandomico = 25.90;
            break;
        case 6:
            pedido = "Cheddar";
            precoPedidoRandomico = 24.90;
            break;
        case 7:
            pedido = "Veggie";
            precoPedidoRandomico = 21.90;
            break;
        case 8:
            pedido = "Kids";
            precoPedidoRandomico = 10.90;
            break;
    }

    switch (numberSnack) {
        case 1:
            pedido = pedido + ", Batata frita + cheddar e bacon";
            precoPedidoRandomico = (precoPedidoRandomico + 15.90);
            break;
        case 2:
            pedido = pedido + ", Batata frita tradicional";
            precoPedidoRandomico = (precoPedidoRandomico + 10.90);
            break;
        case 3:
            pedido = pedido + ", Onion rings";
            precoPedidoRandomico = (precoPedidoRandomico + 12.90);
            break;
        default:
            break;
    }

    switch (numberDrink) {
        case 1:
            pedido = pedido + ", Agua";
            precoPedidoRandomico = (precoPedidoRandomico + 4.00);
            break;
        case 2:
            pedido = pedido + ", Refrigerante";
            precoPedidoRandomico = (precoPedidoRandomico + 5.00);
            break;
        case 3:
            pedido = pedido + ", Suco";
            precoPedidoRandomico = (precoPedidoRandomico + 5.00);
            break;
        case 4:
            pedido = pedido + ", Cerjeva";
            precoPedidoRandomico = (precoPedidoRandomico + 7.90);
            break;
        default:
            break;
    }
    return pedido;
}

#endif //CADASTRO_H