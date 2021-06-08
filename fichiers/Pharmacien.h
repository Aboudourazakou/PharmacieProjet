
#ifndef PHARMACIEN_H
#define PHARMACIEN_H
#include<iostream>
#include <fstream>
using namespace std;
class Pharmacien
{   private:
	int Identifiant;
	string Nom;
	string Prenom;
	string MDP;
	
	public:
		Pharmacien(int,string,string,string);
		int getIdentifiant();
		string getNom();
		string getPrenom();
		string getMDP();
		void setIdentifiant(int);
		void setNom(string);
		void setPrenom(string);
		void setMDP(string);
		void setrole(string);
		void afficher();
		friend istream &operator>>(istream &,Pharmacien&);
		//void vendreMedicament();
       //void RechercherMedicament();
      //void afficherMedicament();
     //void afficherFacture();
		
};

#endif

