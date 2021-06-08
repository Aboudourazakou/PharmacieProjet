#ifndef PHARMACIEN_H
#define PHARMACIEN_H
#include<iostream>
using namespace std;
class Pharmacien
{   private:
	int Identifiant;
	string Nom;
	string Prenom;
	string MDP;
	public:
		Pharmacien(int identifiant,string Nom,string Prenom,string MDP){
		
		};
		int getIdentifiant();
		string getNom();
		string getPrenom();
		string getMDP();
		void setIdentifiant(int);
		void setNom(string);
		void setPrenom(string);
		void setMDP(string);
		void vendreMedicament();
		void RechercherMedicament();
		void afficherMedicament();
		void afficherFacture();
		
};

#endif

