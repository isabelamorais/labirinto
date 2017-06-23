/*
Projeto e An�lise de Algoritmos I
Programa: Labirinto
*/

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

bool livre(char *lab,int w, int h, int l, int c){
	int posicao = l*w+c;
	if(lab[posicao]!=' '||l==h||c==w||l<0||c<0)
		return 0;
	return 1;
}

void caminho(char *lab, int w, int h, int l, int c, int saida){
	int posicao = l*w+c;
	if(posicao==saida){
		lab[posicao]='*';
		return;
	}
	if(livre(lab,w,h,l,c)){
		lab[posicao]='-';
	
		caminho(lab,w,h,l,c+1,saida);
		if(lab[saida]=='*'){	
			lab[posicao]='*';
			return;
		}
		caminho(lab,w,h,l+1,c,saida);
		if(lab[saida]=='*'){	
			lab[posicao]='*';
			return;
		}
		caminho(lab,w,h,l,c-1,saida);
		if(lab[saida]=='*'){	
			lab[posicao]='*';
			return;
		}
		caminho(lab,w,h,l-1,c,saida);
		if(lab[saida]=='*'){	
			lab[posicao]='*';
			return;
		}
		lab[posicao]=' ';
	}
}

int main(int argc, char *argv[]){
	int testes, h, w, s;
	int entrada[2], saida[2];
	std::ifstream arquivo;
	std::string linha;
	
	arquivo.open(argv[1],ios::in);

	cout<<"Testes: ";
	getline(arquivo,linha);
	stringstream convert(linha);
	convert>>testes;
	cout<<testes;
	
	while(testes!=0){
		cout<<"\nAltura: ";
		getline(arquivo,linha);
		stringstream altura(linha);
		altura>>h;
		cout<<h;
		
		cout<<"\nLargura: ";
		getline(arquivo,linha);
		stringstream largura(linha);
		largura>>w;
		cout<<w;
		
		char labirinto[h*w];
		
		cout<<"\n\nLabirinto:";
		for(int i=0;i<h;i++){
			getline(arquivo,linha);
			for(int j=0;j<w;j++)
				labirinto[(i*w)+j]=linha.at(j);
		}
		for(int i=0;i<h*w;i++){
			if(i%w==0)
				cout<<"\n";
			cout<<labirinto[i];
		}
		
		cout<<"\n\nComeco: ";
		getline(arquivo,linha);
		stringstream entrada0(linha);
		entrada0>>entrada[0];
		getline(arquivo,linha);
		stringstream entrada1(linha);
		entrada1>>entrada[1];
		cout<<entrada[0]<<" "<<entrada[1];
		
		cout<<"\nSaida: ";
		getline(arquivo,linha);
		getline(arquivo,linha);
		stringstream saida0(linha);
		saida0>>saida[0];
		getline(arquivo,linha);
		stringstream saida1(linha);
		saida1>>saida[1];
		cout<<saida[0]<<" "<<saida[1];
		
		s=(saida[1]*w)+saida[0];
		caminho(labirinto,w,h,entrada[1],entrada[0],s);
		
		cout<<"\n\nSolucao:";
		for(int i=0;i<h*w;i++){
			if(i%w==0)
				cout<<"\n";
			cout<<labirinto[i];
		}
		
		if(labirinto[s]!='*')
			cout<<"\nNao foi possivel encontrar o Minotauro\n";
		cout<<"\n";
		testes--;
	}
	arquivo.close();
}
