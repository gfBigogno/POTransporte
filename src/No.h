/*
 * No.h
 *
 *  Created on: 24 de jan de 2022
 *      Author: gustavo
 */

#ifndef NO_H_
#define NO_H_

class No {
public:
	No();
	No(int custoUnitario);

	virtual ~No();

	int getCustoUnitario() const;
	void setCustoUnitario(int custoUnitario);
	int getVariavelDescisao() const;
	void setVariavelDescisao(int variavelDescisao);

private:
	int custoUnitario;
	int variavel_descisao;
};

#endif /* NO_H_ */
