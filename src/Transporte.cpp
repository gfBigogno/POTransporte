/*
 * Transporte.cpp
 *
 *  Created on: 24 de jan de 2022
 *      Author: gustavo
 */

#include "Transporte.h"

#include <cstdlib>
#include <iostream>

Transporte::Transporte() {
	this->matrizTabular = NULL;
	this->capacidades = NULL;
	this->demandas = NULL;
	this->colunas = -1;
	this->linhas = -1;
}

bool Transporte::estaBalanceado() {
	int somaCapaciadade = 0;
	int somaDemanda = 0;

	for (int i = 0; i < this->linhas; ++i)
		somaCapaciadade += this->capacidades[i];

	for (int i = 0; i < this->colunas; ++i)
		somaDemanda += this->demandas[i];

	if (somaCapaciadade == somaDemanda)
		return true;
	else
		return false;
}

void Transporte::gerarMatrizes() {
	this->linhas = 3;
	this->colunas = 3;

	this->matrizTabular = new No*[linhas];
	for (int i = 0; i < linhas; ++i)
		this->matrizTabular[i] = new No[colunas];

	matrizTabular[0][0] = No(12);
	matrizTabular[0][1] = No(22);
	matrizTabular[0][2] = No(30);

	matrizTabular[1][0] = No(18);
	matrizTabular[1][1] = No(24);
	matrizTabular[1][2] = No(32);

	matrizTabular[2][0] = No(22);
	matrizTabular[2][1] = No(15);
	matrizTabular[2][2] = No(34);

	this->capacidades = new int[this->linhas];

	capacidades[0] = 100;
	capacidades[1] = 140;
	capacidades[2] = 160;

	this->demandas = new int[this->colunas];

	demandas[0] = 120;
	demandas[1] = 130;
	demandas[2] = 150;
}

bool Transporte::metodoCantoNoroeste() {
	if (!this->estaBalanceado())
		return false;

	int varDescisao = 0;
	bool tipo;
	for (int i = 0; i < this->linhas; ++i) {
		for (int j = 0; j < this->colunas; ++j) {

			if (matrizTabular[i][j].getVariavelDescisao() == -999)
				continue;

			if (capacidades[i] >= demandas[j]) {
				varDescisao = demandas[j];
				tipo = true;
			} else {
				varDescisao = capacidades[i];
				tipo = false;
			}

			capacidades[i] = capacidades[i] - varDescisao;
			demandas[j] = demandas[j] - varDescisao;
			matrizTabular[i][j].setVariavelDescisao(varDescisao);

			if (!tipo) {
				for (int k = j + 1; k < this->colunas; ++k) {
					matrizTabular[i][k].setVariavelDescisao(-999);
				}
			} else {
				for (int k = i + 1; k < this->colunas; ++k) {
					matrizTabular[k][j].setVariavelDescisao(-999);
				}
			}
		}
	}

	return true;
}

void Transporte::imprimirMatriz() {
	for (int i = 0; i < this->linhas; ++i) {
		for (int j = 0; j < this->colunas; ++j) {
			std::cout << "(" << matrizTabular[i][j].getCustoUnitario() << ";"
					<< matrizTabular[i][j].getVariavelDescisao() << ")       ";
		}
		std::cout << "\n";
	}
}

int Transporte::getValorZ() {

	int soma = 0;
	for (int i = 0; i < this->linhas; ++i) {
		for (int j = 0; j < this->colunas; ++j) {
			if(matrizTabular[i][j].getVariavelDescisao() != -999)
				soma += (matrizTabular[i][j].getCustoUnitario() * matrizTabular[i][j].getVariavelDescisao());
		}
	}

	return soma;
}

Transporte::~Transporte() {
	// TODO Auto-generated destructor stub
}

