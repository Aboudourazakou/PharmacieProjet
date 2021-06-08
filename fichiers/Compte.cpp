#include "Compte.h"
#include<fstream>
#include<iostream>
using namespace std;


bool Compte::createCompte(int id,string password,string role){

	
	ofstream file("comptes.txt",ios::app);
	if(file.bad())cout<<"Erreur d'ouverture fichier"<<endl;//Si le fichier ne s'est pas ouvert;
	else{
		
		bool utilisateurExiste=false;
		bool compteExiste=false;
		//On verifie si l'identifiant existe vraiment dans le dossier pharmaciens;
		 
		
		//On verifie si le compte pour le meme identifiant n'existe pas encore;
		file<<id<<"|"<<password<<"|"<<role<<endl;
	}
	
	
	 return true;
}
