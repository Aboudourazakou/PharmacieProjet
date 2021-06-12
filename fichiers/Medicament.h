#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <iostream>
#include"Administrateur.h"


using namespace std;




class Medicament
{
protected:
	int code;
    string nomc;
	string DCI;
	int quantite;
	float prix_unite;
	string dosage;
	string date_exp;
	int nbrvente;
public:
 Medicament(){
 };
 Medicament(int,string,string,int,float,string,string,int);
 void afficher();
 void setcode(int);
 void setdate_xp(string);
 void setDCI(string);
 void setdosage(string);
 void setnbrvente(int);
 void setnomc(string);
 void setprix_unite(float);
 void setquantite(int);
 
 int getcode(){
 	return code;
 }
 string getdate(){
 	
 	return date_exp;
 };
 string getDCI(){
 	return DCI;
 };
 string getdosage(){
 	return dosage;
 };
 int getnbrvente(){
 	return nbrvente;
 };
 string getnomc(){
 	return nomc;
 };
 float getprix_unite(){
 	return prix_unite;
 };
 int getquantite();	
	
friend istream &operator>>(istream &,Medicament&);
friend void Administrateur::modifierMedicament(string,Medicament&); 
friend void Administrateur::ajouterMedicament(Medicament &);


	
};
#endif

