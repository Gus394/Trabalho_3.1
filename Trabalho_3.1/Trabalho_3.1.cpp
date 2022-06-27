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

void melhoresPontuacoes10() {

}

void melhoresPontuacoes100() {

}

int main()
{
	srand(time(NULL));
	
	string sílabas[75] = {"a", "ti", "si", "cu", "ta", "ca", "tu", "na", "ri", "ma", "mi", "o", "ni", "da", "la", "de", "te", "to"
	, "e", "co", "ru", "fi", "i", "pi", "pa", "bi", "nu", "mu", "ba", "zi", "ga", "es", "se", "sa", "me", "mo", "lo", "no", "pe"
	, "lu", "po", "ar", "dor", "su", "vas", "vi", "le", "ro", "fla", "ne", "va", "fa", "bu", "tri", "so", "do", "bo", "cra", "gu"
	, "gra", "tra", "do", "fo", "pu", "us", "bro", "les", "fo", "fa", "gus", "vo", "go", "fu", "pro", "pre"};

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
			break;
		case 3:
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
