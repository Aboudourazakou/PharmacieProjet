#include <iostream>
#include"Facture.h"
#include"Medicament.h"
#include"Pharmacien.h"
#include<fstream>
#include<string.h>
#include <sstream>
#include"Compte.h"
#include"Administrateur.h"
#include <Windows.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

  welcomeGuide(){
  	
   	cout<<endl<<endl<<"\t\t\t BIEVENUE!VEUILLEZ VOUS CONNECTER SVP"<<endl;
   		
  }
 string connexion(int id,string password){
 	  string status="error";
 	  bool trouver=false;
      ifstream file("compte.txt",ios::in);
      if(file.bad()){
      	 cout<<"Erreur d'ouverture fichier"<<endl;
      	 return "error";
	  }
	 
      else{
	  
      string line;
     
    ostringstream userId;
	userId<<id;
        
  while (getline(file,line))
 {  
 
 
   char l[200];//Une chaine de caracteres  pour couper la lignes en attributs
  if(line!="\0") strcpy(l,line.c_str());//On convertit la ligne recue du fichier en chaines de caracteres que nous copions // dans l;
   char *tempon=strtok(l,"/");//Nous decoupons cette chaine a partir des /;
   
   if(!strcmp(tempon,userId.str().c_str())){
   	
  	  tempon=strtok(NULL,"/");
  	  
  	  if(!strcmp(tempon,password.c_str())){
  	  	    trouver=true;
   	  	    tempon=strtok(NULL,"/");
  	  	    return tempon;
 	  	    
	 }
		
   	
   }


  

			 
    } 
    
  
   }
         return status;
      	  file.close();
  }
  
  Pharmacien TrouverPharmacien(int id){
  	
  	ifstream file("Pharmaciens.txt");
  	if(file.bad())cout<<"Erreur d'ouverture de fichiers"<<endl;
  	else{
  		
  		string line;
  		char identifiant[10];
  		
  		while(getline(file,line)){
  			
  				ostringstream userId;
 	            userId<<id;
 	            char l[50];//Une chaine de caracteres  pour couper la lignes en attributs
                strcpy(l,line.c_str());//On convertit la ligne recue du fichier en chaines de caracteres que nous copions // dans l;
                char *tempon=strtok(l,"/");//Nous decoupons cette chaine a partir des /;
	            strcpy(identifiant,tempon);
	            if(strcmp(identifiant,userId.str().c_str())){
	            	
	            	return Pharmacien(id,"Samia","Outnoumar");
	             
				}
 	            
  			
  			
		  }
	  }
  	
  	
  	
  }
 
  Administrateur TrouverAdmin(int id){
  	
  	ifstream file("Pharmaciens.txt");
  	if(file.bad())cout<<"Erreur d'ouverture de fichiers"<<endl;
  	else{
  		
  		string line;
  		char identifiant[10];
  		
  		while(getline(file,line)){
  			
  				ostringstream userId;
 	            userId<<id;
 	            char l[50];//Une chaine de caracteres  pour couper la lignes en attributs
                strcpy(l,line.c_str());//On convertit la ligne recue du fichier en chaines de caracteres que nous copions // dans l;
                char *tempon=strtok(l,"/");//Nous decoupons cette chaine a partir des /;
	            strcpy(identifiant,tempon);
	            if(strcmp(identifiant,userId.str().c_str())){
	            	
	             return Administrateur(id,"Samia","Outnoumar");
	             
				}
 	            
  			
  			
		  }
	  }
  	
  	
  	
  }

int main(int argc, char** argv) {
	
	int identifiant;
	string password;
	
	welcomeGuide();
	
	cout<<"Entrer votre identifiant"<<endl;
	cin>>identifiant;
	cout<<"Entrer votre mot de passe"<<endl;
	cin>>password;
    
    string status=connexion(identifiant,password);
    
  
    
    if(status=="error")cout<<"Erreur d'authentification!"<<endl;
    else{
    	
    	 if(status=="admin"){
    	  int reponse;
    	 Medicament M;
    	 string id;
    	 Administrateur admin=TrouverAdmin(identifiant);
    	 system("cls");//Effacer la console;
    	  cout<<endl<<"\t\t\t VOUS ETES CONNECTER EN TANT QUE ADMINISTRATEUR";
    	  cout<<endl<<endl<<"\t\t\tVeuillez choisir ce que vous voulez faire!"<<endl<<endl;
    	  do{
    	  cout<<"1-Creer un pharmacien"<<endl;
    	  cout<<"2-Supprimer un pharmacien"<<endl;
    	  cout<<"3-Creer un compte"<<endl;
    	  cout<<"4-Supprimer un compte"<<endl;
    	  cout<<"5-Ajouter un medicament"<<endl;
    	  cout<<"6-Modifier un medicament"<<endl;
    	  cout<<"7-Supprimer  un medicament"<<endl;
    	  cout<<"8-Voir la liste des pharmaciens"<<endl;
    	  cout<<"9-Voir la liste des ventes"<<endl;
    	  cout<<"10-Voir la liste des medicaments"<<endl;
    	  cout<<"11-Voir total des ventes"<<endl;
    	  cout<<"ENTRER L'OPTION DE VOTRE CHOIX'"<<endl;
    	  int option;
    	  cin>>option;
    	  system("cls");//Effacer la console;
    	  switch(option){
    	  	
    	  	case 1:cout<<endl<<"\t\t\tCREATION PHARMACIEN"<<endl<<endl;
    	  	       break;
    	  	case 2:cout<<"Creer produit"<<endl;
    	  			break;
    	  	case 6:cout<<endl<<"\t\t\t MODIFICATION MEDICAMENT"<<endl<<endl;
    	  			cout<<"Entrer l'identifiant du medicament a modifier"<<endl;
    	  			cin>>id;
    	  		   admin.modifierMedicament(id,M);
    	  			break;
    	  	case 7:cout<<endl<<"\t\t\t SUPPRESSION D'UN MEDICAMENT'"<<endl<<endl;
    	  			break;
    	  	case 8:cout<<endl<<"\t\t\t LISTE DES PHARMACIENS"<<endl<<endl;
    	  			break;
    	  	
    	  	case 9:cout<<endl<<"\t\t\t LISTE DES VENTES"<<endl<<endl;
    	  			break;
    	  	
    	    case 10:cout<<endl<<"\t\t\t LISTE DES MEDICAMENTS"<<endl<<endl;
    	            admin.afficherListeMedicament();
    	    		break;
    	    default:cout<<"VOUS N'AVEZ CHOISI AUCUNE OPTION"<<endl;
    	  
    	  			
    	  
		        }
		 
		  cout<<"Appuyer 1 pour continuez ou un autre chiffre  pour vous deconnecter"<<endl;
		  cin>>reponse;
         }while(reponse==1);
         
		 }
		 else if(status=="user"){
		 	Pharmacien pharmacien=TrouverPharmacien(identifiant);
		 	 int reponse;
		 	 system("cls");//Effacer la console;
    	     cout<<endl<<"\t\t\t VOUS ETES CONNECTER EN TANT QUE PHARMACIEN";
    	     cout<<endl<<endl<<"\t\t\tVeuillez choisir ce que vous voulez faire!"<<endl<<endl;
    	       do{
		  
    	  cout<<"1-Voir la liste des ventes"<<endl;
    	  cout<<"2-Voir la liste des medicaments"<<endl;
    	  cout<<"3-Voir total des ventes"<<endl;
    	  cout<<endl<<"ENTRER L'OPTION DE VOTRE CHOIX'"<<endl;
    	  int option;
    	  cin>>option;
    	  system("cls");//Effacer la console;
    	  switch(option){
    	  	
    	  	case 1:cout<<endl<<"\t\t\t LISTE DES VENTES"<<endl<<endl;
    	  	       break;
    	  	case 2:cout<<endl<<"\t\t\t LISTE DES MEDICAMENTS"<<endl<<endl;
    	  			break;
    	  	default:cout<<"Aucune option choisie"<<endl;
    	  			break;
		  }
		 
		  cout<<"Appuyer 1 pour continuez ou un autre chiffre  pour vous deconnecter"<<endl;		  
		  cin>>reponse;
         }while(reponse==1);
        		 }
				 	}
    
	
	
	

	
}

