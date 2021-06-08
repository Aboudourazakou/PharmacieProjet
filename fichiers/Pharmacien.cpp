#include "Pharmacien.h"
#include<fstream>
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
string Pharmacien::getrole(){
	return role;
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
void Pharmacien::setrole(string R){
role=R;
};
void Pharmacien::afficher(){
	cout<<"Identifiant: "<<Identifiant<<endl;
	cout<<"Nom: "<<Nom<<endl;
	cout<<"Prenom: "<<Prenom<<endl;
	cout<<"MDP: "<<MDP<<endl;
	cout<<"Role: "<<role<<endl;
	
};
istream &operator>>(istream &p,Pharmacien&g){
	ofstream file("Pharmaciens.txt",ios::app);
	if(file.bad())cout<<"Erreur d'ouverture fichier"<<endl;
	else{
		file<<g.Identifiant<<"/"<<g.Nom<<"/"<<g.Prenom<<"/"<<g.MDP<<"/"<<g.role<<endl;
	}
	
	
	
}
 

