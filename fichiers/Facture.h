#ifndef FACTURE_H
#define FACTURE_H
#include<iostream>
using namespace std;

class Facture
{
	private:
		
		int idFacture;
		string nomVendeur;
		int idVendeur;
		string date;
		
	public:
	Facture(int id,int idV,string nom,string d){
		
		idFacture=id;
		nomVendeur=nom;
		idVendeur=idV;
		date=d;
		
		
	}
	
	void GenererFacture();
	void afficherFacture(string id);
};

#endif
