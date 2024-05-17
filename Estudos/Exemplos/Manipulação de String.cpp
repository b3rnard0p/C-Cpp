#include<iostream>
#include<string>
using namespace std;

int main(){
	string frase;
	int i;
	cout << "Digite uma frase:";
	getline(cin, frase);
	
	cout << "Foi digitada a frase:" << frase<< endl;
	cout << "A frase possui " << frase.length() << " caracteres\n";
	
	for(i=0;i<frase.length();i++){
		frase[i] = toupper(frase[i]);
	}
	
	cout << "A frase em maiusculo:" << frase << endl;
	
	string outraPalavra;
	cout << "Digite uma palavra para pesquisa\n";
	getline(cin, outraPalavra);
	
	if(frase.find(outraPalavra)){
		cout << outraPalavra << " Foi encontrada na frase\n";
	}
}