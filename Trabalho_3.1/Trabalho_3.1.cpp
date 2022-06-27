#include <iostream>
using namespace std;

struct Jogador {
	string nome;
	int pontos;
};


void shellSort(Jogador* vet, int size) {
	int i, j;
	string value;

	int h = 1;
	while (h < size) {
		h = 3 * h + 1;
	}
	while (h > 0) {
		for (i = h; i < size; i++) {
			value = vet[i].nome;
			j = i;
			while (j > h - 1 && value <= vet[j - h].nome) {
				vet[j].nome = vet[j - h].nome;
				j = j - h;
			}
			vet[j].nome = value;
		}
		h = h / 3;
	}
	
	
}

void exibirJogadores(Jogador* jogadores, int tam) {
	shellSort(jogadores, tam);
	for (int i = 0; i < 1000; i++)
		cout << jogadores[i].nome << endl;
}

void mergesort(Jogador* vet, int const left, int const right) {
	int i, j, k;
	Jogador* aux;
	if (left < right) {
		i = (left + right) / 2;
		mergesort(vet, left, i);
		mergesort(vet, i + 1, right);
		j = left;
		k = i + 1;
		aux = new Jogador[right - left + 1];
		for (int m = 0; m < right - left + 1; m++) {
			if (j > i)
				aux[m] = vet[k++];
			else if (k > right)
				aux[m] = vet[j++];
			else if (vet[j].pontos > vet[k].pontos)
				aux[m] = vet[j++];
			else
				aux[m] = vet[k++];
		}
		for (int m = 0; m < right - left + 1; m++)
			vet[left + m] = aux[m];
		delete[] aux;
	}
}



void melhoresPontuacoes10( Jogador* jogadores, int tam) {

	mergesort( jogadores, 0, tam - 1);
	for (int i = 0; i < 10; i++)
		cout << jogadores[i].nome << ":" << jogadores[i].pontos <<  endl;
}

void bubbleSort( Jogador* jogadores, int tam) {
	int i, j;
	Jogador aux;
	for (i = 0; i < tam - 1; i++) {
		for (j = 0; j < tam - i - 1; j++) {
			if (jogadores[j].pontos < jogadores[j + 1].pontos || (jogadores[j].pontos == jogadores[j + 1].pontos && jogadores[j].nome > jogadores[j + 1].nome)) {
				aux = jogadores[j];
				jogadores[j] = jogadores[j + 1];
				jogadores[j + 1] = aux;
			}
			
	
		}
	}
}

void melhoresPontuacoes100(Jogador* jogadores, int tam) {

	bubbleSort(jogadores, tam);
	for (int i = 0; i < 100; i++)
	
		cout << jogadores[i].nome << " : " << jogadores[i].pontos << endl;
	
}





int main()
{
	srand(time(NULL));

	string sílabas[75] = { "a", "ti", "si", "cu", "ta", "ca", "tu", "na", "ri", "ma", "mi", "o", "ni", "da", "la", "de", "te", "to"
	, "e", "co", "ru", "fi", "i", "pi", "pa", "bi", "nu", "mu", "ba", "zi", "ga", "es", "se", "sa", "me", "mo", "lo", "no", "pe"
	, "lu", "po", "ar", "dor", "su", "vas", "vi", "le", "ro", "fla", "ne", "va", "fa", "bu", "tri", "so", "do", "bo", "cra", "gu"
	, "gra", "tra", "do", "fo", "pu", "us", "bro", "les", "fo", "fa", "gus", "vo", "go", "fu", "pro", "pre" };

	Jogador jogadores[1000];

	for (int i = 0; i < 1000; i++)
		jogadores[i].pontos = rand() % 501;

	int numSílabas;
	for (int i = 0; i < 1000; i++) {
		numSílabas = rand() % 3;

		jogadores[i].nome = sílabas[rand() % 75] + sílabas[rand() % 75];
		for (int j = 0; j < numSílabas; j++)
			jogadores[i].nome += sílabas[rand() % 75];
	}

	int r = 0;
	while (r != 4) {
		cout << " 1 - Exibir nomes dos jogadores\n 2 - Exibir pontos(top 10)\n 3 - Exibir pontos(top 100)\n 4 - Sair\n\n";
		cin >> r;

		switch (r)
		{
		case 1:
			exibirJogadores(jogadores, 1000);
			break;
		case 2:
			melhoresPontuacoes10(jogadores, 1000);
			break;
		case 3:
			melhoresPontuacoes100(jogadores, 1000);
			break;
		default:
			break;
		}

		if (r == 4)
			break;

		system("pause");
		system("CLS");

	}
}
