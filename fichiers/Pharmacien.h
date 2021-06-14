
#ifndef PHARMACIEN_H
#define PHARMACIEN_H
#include<iostream>
#include <fstream>
using namespace std;

class Vente;
class Pharmacien
{  

 protected:
	int Identifiant;
	string Nom;
	string Prenom;
	
	
	public:
		Pharmacien(){
		};
		Pharmacien(int,string,string);
		int getIdentifiant();
		string getPrenom();
		string getMDP();
		void setIdentifiant(int);
		void setNom(string);
		void setPrenom(string);
		void setMDP(string);
		void setrole(string);
		void afficher();
		friend istream &operator>>(istream &,Pharmacien&);
		void afficherListeMedicament();
		string RechercherMedicament(string query);
		void vendreMedicament();
		void voirTotalVentes(string);
        void afficherToutesFacture(string role);
		
};

#endif
