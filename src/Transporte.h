/*
 * Transporte.h
 *
 *  Created on: 24 de jan de 2022
 *      Author: gustavo
 */

#ifndef TRANSPORTE_H_
#define TRANSPORTE_H_

#include "No.h"

class Transporte {
public:
	Transporte();
	Transporte(No** matrizTabular, int tamanho);
	virtual ~Transporte();

	void gerarMatrizes();
	bool estaBalanceado();

	bool metodoCantoNoroeste();

	void imprimirMatriz();
	int getValorZ();


private:
	int linhas;
	int colunas;

	No** matrizTabular;
	int* capacidades;
	int* demandas;
};

#endif /* TRANSPORTE_H_ */
