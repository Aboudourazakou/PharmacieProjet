#include "Pharmacien.h"
#include<fstream>

Pharmacien::Pharmacien(int id,string nom,string prenom,string mdp){
}
int Pharmacien::getIdentifiant(){
	return Identifiant;
};
string Pharmacien::getNom(){
	return Nom;
};
string Pharmacien::getPrenom(){
	return Prenom;
};
string Pharmacien::getMDP(){
	return MDP;
};
void Pharmacien::setIdentifiant(int I){
Identifiant=I;
};
void Pharmacien::setNom(string n){
Nom=n;
};

void Pharmacien::setPrenom(string p){
Prenom=p;
}; 
void Pharmacien::setMDP(string mdp){
MDP=mdp;
};


void Pharmacien::afficher(){
	cout<<"Identifiant: "<<Identifiant<<endl;
	cout<<"Nom: "<<Nom<<endl;
	cout<<"Prenom: "<<Prenom<<endl;
	cout<<"MDP: "<<MDP<<endl;
	
	
};

istream &operator>>(istream &p,Pharmacien&g){
	ofstream file("Pharmaciens.txt",ios::app);
	if(file.bad())cout<<"Erreur d'ouverture fichier"<<endl;
	else{
		file<<g.Identifiant<<"/"<<g.Nom<<"/"<<g.Prenom<<"/"<<g.MDP<<"/"<<endl;
	}
	
	
	
}
