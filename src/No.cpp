/*
 * No.cpp
 *
 *  Created on: 24 de jan de 2022
 *      Author: gustavo
 */

#include "No.h"
#include <cstdlib>

No::No() {
	// TODO Auto-generated constructor stub
	this->custoUnitario = 0;
	this->variavel_descisao = NULL;
}

No::No(int custoUnitario) {
	// TODO Auto-generated constructor stub
	this->custoUnitario = custoUnitario;
	this->variavel_descisao = NULL;
}

No::~No() {
	// TODO Auto-generated destructor stub
}

int No::getCustoUnitario() const {
	return custoUnitario;
}

void No::setCustoUnitario(int custoUnitario) {
	this->custoUnitario = custoUnitario;
}

int No::getVariavelDescisao() const {
	return variavel_descisao;
}

void No::setVariavelDescisao(int variavelDescisao) {
	variavel_descisao = variavelDescisao;
}

