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
		Pharmacien(){
		};
		int getIdentifiant();
		string getNom();
		string getPrenom();
		string getMDP();
		void setIdentifiant(int);
		void setNom(string);
		void setPrenom(string);
		void setMDP(string);
		
};

#endif
