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
	string role;
	public:
		Pharmacien(){
		};
		int getIdentifiant();
		string getNom();
		string getPrenom();
		string getMDP();
		string getrole();
		void setIdentifiant(int);
		void setNom(string);
		void setPrenom(string);
		void setMDP(string);
		void setrole(string);
		void afficher();
		friend istream &operator>>(istream &,Pharmacien&);
		
};

#endif
