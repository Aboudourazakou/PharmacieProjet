#include "Compte.h"
#include<fstream>
#include<iostream>
using namespace std;


string  Compte::sauvegarder(string id){

	int role;
	ofstream file("compte.txt",ios::app);
	
	if(file.bad())cout<<"Erreur d'ouverture fichier"<<endl;//Si le fichier ne s'est pas ouvert;
<<<<<<< HEAD
			cout<<"Donner lui un mot de passe"<<endl;
=======
			cout<<"Entrer son mot de passe"<<endl;
>>>>>>> 4a8c01b7c0e6be20822c309b5efe498eebb0de44
			cin>>password; 
			cout<<"Selectionner le role"<<endl<<endl;
			cout<<"1-Simple utilisateur"<<endl;
			cout<<"2-Administrateur"<<endl;
			cin>>role;
			switch(role){
				case 1:file<<id<<"/"<<password<<"/"<<"user"<<endl;
				break;
				case 2:file<<id<<"/"<<password<<"/"<<"admin"<<endl;
				break;
				default:file<<id<<"/"<<password<<"/"<<"user"<<endl;
		    	}
			
			file.close();
	        return "success";
	
      
}

