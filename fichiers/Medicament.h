#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <iostream>
#include"Administrateur.h"


using namespace std;




class Medicament
{
private:
	int code;
    string nomc;
	string DCI;
	int quantite;
	float prix_unite;
	string dosage;
	string date_exp;
	int nbrvente;
public:
 void afficher();
 void setcode(int);
 void setdate_xp(string);
 void setDCI(string);
 void setdosage(float);
 void setnbrvente(int);
 void setnomc(string);
 void setprix_unite(float);
 void setquantite(int);
 string getdate_xp();
 string getDCI();
 float getdosage();
 int getnbrvente();
 string getnomc();
 float getprix_unite();
 int getquantite();	
	
friend istream &operator>>(istream &,Medicament&);
friend void Administrateur::modifierMedicament(string,Medicament&); 
friend void Administrateur::ajouterMedicament(Medicament &);


	
};
#endif

