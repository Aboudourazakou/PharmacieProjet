#ifndef VENTE_H
#define VENTE_H
#include<iostream>
using namespace std;

class Vente
{
	private:
		
    
	int quantite;
	float prix_unite;
   
	int idFacture;
	int idVendeur;
    string nomc;
    float prixTotal;
	public:
			string dosage;
		Vente(){
		};
	void affiche(){
		cout<<"Bonjour"<<endl;
	}
	Vente(string,int,float,string,int,int,float);
	void ajouterAuPanier();
    bool afficherPanier();
    string reduireLaQuantite(string,string);
	 void supprimerDuPanier(string );
    
    void setNom(string nom){
    	nomc=nom;
	}
	void setQuantite(int q){
		quantite=q;
	}
	void setPrixTotal(float p){
		prixTotal=p;
	}
	
	void setIdFacture(int s){
		idFacture=s;
		
	}
	
	void setIdVendeur(int s){
		idVendeur=s;
	}
	void setdosage(string d){
		dosage=d;
	}

	void setPrixUnite(float p){
		prix_unite=p;
	}

		
	
	//friend void Pharmacien::vendreMedicament(Vente &);
};

#endif


