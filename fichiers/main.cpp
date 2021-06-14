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
#include"Vente.h"
#include<conio.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void c(int a)
{
    SetConsoleTextAttribute(hConsole, a); /**Cette fonction me permet de choisir des couleurs d affichage**/
}
void message(){
	 c(14);cout<<"Taper une touche  pour continuer  "<<endl;c(15);
      getch();
	  system("cls");
}

  welcomeGuide(){
  	c(2);//Responsable de la couleur verte du texte ci dessous
   	cout<<endl<<endl<<"\t\t\t BIEVENUE!VEUILLEZ VOUS CONNECTER SVP"<<endl;c(15);//c(15) change la couleur des autres textes en blancs;   		
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
  		   string nom,prenom;
  		
  		while(getline(file,line)){
  			
  				ostringstream userId;
 	            userId<<id;
 	            char l[50];//Une chaine de caracteres  pour couper la lignes en attributs
                strcpy(l,line.c_str());//On convertit la ligne recue du fichier en chaines de caracteres que nous copions // dans l;
                char *tempon=strtok(l,"/");//Nous decoupons cette chaine a partir des /;
	            strcpy(identifiant,tempon);
	            if(!strcmp(identifiant,userId.str().c_str())){
	            	
	             tempon=strtok(NULL,"/");
	             nom=tempon;
	             tempon=strtok(NULL,"/");
	             prenom=tempon;
	             cout<<nom<<endl;
	             return Pharmacien(id,nom,prenom);
	             
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
  			   
  			   string nom,prenom;
  			   
  				ostringstream userId;
 	            userId<<id;
 	            char l[200];//Une chaine de caracteres  pour couper la lignes en attributs
                strcpy(l,line.c_str());//On convertit la ligne recue du fichier en chaines de caracteres que nous copions // dans l;
                char *tempon=strtok(l,"/");//Nous decoupons cette chaine a partir des /;
	            strcpy(identifiant,tempon);
	            if(!strcmp(identifiant,userId.str().c_str())){
	             tempon=strtok(NULL,"/");
	              nom=tempon;
	             tempon=strtok(NULL,"/");
	             prenom=tempon;
	             return Administrateur(id,nom,prenom);
	             
				}
 	            
  			
  			
		  }
	  }
  	
  	
  	
  }
  
  Medicament convertStringToMedicamentObject(string response){
  	    
  	     Medicament M;
  	      char ligne[200];//On cree une variable tempon
		  strcpy(ligne,response.c_str());//On convertit line en char et on lui affecte a tempon
	      char *tempon=strtok(ligne,"|");
		  M.setcode(atoi(tempon));
		  tempon=strtok(NULL,"|");
		   M.setnomc(tempon);
		  tempon=strtok(NULL,"|");
		   M.setDCI(tempon);
		  tempon=strtok(NULL,"|");
		  M.setquantite(atoi(tempon));
		  tempon=strtok(NULL,"|");
		   M.setprix_unite(atof(tempon));
		  tempon=strtok(NULL,"|");
		  M.setdosage(tempon);
		  tempon=strtok(NULL,"|");
		  M.setdate_xp(tempon);
		  tempon=strtok(NULL,"|");
		  M.setnbrvente(atoi(tempon));
		  
  	      return M;
  	
  }

int main(int argc, char** argv) {
	
	int identifiant;
	string password;
	string query;

	
	welcomeGuide();
	
	cout<<"Entrer votre identifiant"<<endl;
	cin>>identifiant;
	cout<<"Entrer votre mot de passe"<<endl;
	cin>>password;
    
    string status=connexion(identifiant,password);
    
  
    
    if(status=="error")	{
    	c(4);cout<<"Erreur d'authentification!"<<endl;c(15);
	}
    
    else{
    	
    	 if(status=="admin"){
    	  int reponse=1;
    	 Medicament M;

    	 Vente v;

    	 Pharmacien p;
    	 string id;
    	 string nomPharmacien;
    	 string response;
    	 string password;
    	 string nomMedicament;
    	 Administrateur admin=TrouverAdmin(identifiant);
    	 system("cls");//Effacer la console;
    	 c(2); cout<<endl<<"\t\t\t VOUS ETES CONNECTER EN TANT QUE ADMINISTRATEUR";c(15);
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
    	  cout<<"9-Voir la liste des medicaments"<<endl;
    	  cout<<"10-Voir total des ventes"<<endl;
    	  cout<<"11-Rechercher un medicament par nom commercial ou par identifiant"<<endl;
    	  cout<<"12-Vendre les medicaments "<<endl;
    	  cout<<"13-Voir liste des factures "<<endl;
    	  cout<<"14-DECONNEXION"<<endl<<endl;
    	  cout<<"ENTRER L'OPTION DE VOTRE CHOIX'"<<endl;
    	  int option;
    	  cin>>option;
    	  system("cls");//Effacer la console;
    	  switch(option){
    	  	
    	  	case 1:cout<<endl<<"\t\t\tCREATION PHARMACIEN"<<endl<<endl;
    	  	        admin.creerPharmacien();
    	  	       break;
    	  	case 2:cout<<endl<<"\t\t\tSUPPRESSION PHARMACIEN"<<endl<<endl;
    	  			cout<<"Entrer l'identifiant du pharmacien a supprimer"<<endl;
    	  			cin>>id;
    	  			response=admin.supprimerPharmacien(id);
    	  			if(response=="user not found"){
    	  				c(4);cout<<"Aucun pharmacien ne correspond a cet identifiant "<<endl;
    	  				message();
					  }
    	  			else if(response=="success"){
    	  				c(2);cout<<"OPERATION EFFECTUEE AVEC SUCCES"<<endl;
    	  				message();
					  }
    	  			break;
    	  	case 3:cout<<endl<<"\t\t\tCREATION COMPTE"<<endl<<endl;
    	  	        cout<<"Entrer l'id du pharmacien"<<endl;
    	  	        cin>>id;
    	  	         response=admin.creerCompte(id);
    	  			if(response=="success"){ 
					  
					   c(2); cout<<"\t\t\t OPERATION EFFECTUE AVEC SUCCES"<<endl;
					   message();
				}
    	  			else if(response=="existe deja"){
    	  				  c(4); cout<<"\t\t\t UN COMPTE AU MEME IDENTIFIANT EXISTE DEJA"<<endl;
					       message();
					  }
    	  			else if(response=="id non correspondant"){
    	  				  c(4); cout<<"\t\t\t CET IDENTIFIANT NE CORRESPOND A AUCUN PHARMACIEN"<<endl;
					     message();
					  }
    	  			break;
    	  	case 4:cout<<"Entrer l'identifiant"<<endl;
    	  	
    	  	        cin>>id;
    	  	        cout<<"Entrer le mot de passe"<<endl;
    	  	        cin>>password;
    	  	        response=admin.supprimerCompte(id,password);
    	  	        if(response=="success"){
    	  	        	c(2); cout<<"\t\t\t OPERATION EFFECTUE AVEC SUCCES"<<endl;
    	  	        	message();
					  }
					else if(response=="user not found"){
						c(4);cout<<"\t\t\t OPERATION N'A PAS ABOUTI.ENTREZ LES BONNES VALEURS"<<endl;
						message();
					}
    	  	        
    	  			break;
    	  	case 5:cout<<endl<<"\t\t\t CREATION MEDICAMENT"<<endl<<endl;
    	  			admin.ajouterMedicament(M);
    	  			message();
    	  			break;
    	  	case 6:cout<<endl<<"\t\t\t MODIFICATION MEDICAMENT"<<endl<<endl;
    	  			cout<<"Entrer l'identifiant du medicament a modifier"<<endl;
    	  			cin>>id;
    	  		   admin.modifierMedicament(id,M);
    	  		   message();
    	  			break;
    	  	case 7:cout<<endl<<"\t\t\t SUPPRESSION D'UN MEDICAMENT'"<<endl<<endl;
    	  	       cout<<"Entrer le nom du medicament a supprimer"<<endl;
					cin>>nomMedicament;
    	  	        if(admin.supprimerMedicament(nomMedicament)){
    	  	        	c(2);cout<<endl<<"Supprime avec succes"<<endl;
    	  	        	message();
					  }
					  else{
					  	 c(4);cout<<endl<<"Aucune suppression n'a eu lieu.Entrer les infos corrects"<<endl;
					  	 message();
					  }
    	  			break;
    	  	case 8:cout<<endl<<"\t\t\t LISTE DES PHARMACIENS"<<endl<<endl;
    	  	        admin.afficherPharmaciens();
    	  	        message();
    	  			break;
    	  	case 9:cout<<endl<<"\t\t\t LISTE DES MEDICAMENTS"<<endl<<endl;
    	            admin.afficherListeMedicament();
    	            message();
    	    		break;
    	  	
    	 
    	  	
    	  
    	    case 10: cout<<endl<<"\t\t\t TOTAL DES VENTES"<<endl<<endl;
    	    	    admin.voirTotalVentes("admin");
    	    	    message();
    	           break;
    	    case 11:cout<<endl<<"\t\t\t RECHERCHE DES MEDICAMENTS"<<endl<<endl;
    	  	        cout<<"Entrer l'identifiant ou le nom commercial du medicament a rechercher"<<endl;
    	  	        cin>>query;
    	  	        response=admin.RechercherMedicament(query);
    	  	        if(response=="not found")cout<<"AUCUN MEDICAMENT DISPONIBLE"<<endl;
    	  	        else {
    	  	        	  cout<<"Ce medicmanent existe et voici ces informations"<<endl;
    	  	        	  M=convertStringToMedicamentObject(response);
    	  	        	   message();
    	  	        	  M.afficher();
    	  	        	  message();
    	  	        	 
					  }
    	  			break;
    	    case 12:cout<<endl<<"\t\t\t VENTE  DES MEDICAMENTS"<<endl<<endl;
    	            admin.vendreMedicament();
    	            message();
    	    		break;
    	    case 13:cout<<endl<<"\t\t\t LISTE DES FACTURES"<<endl<<endl;
    	            admin.afficherToutesFacture("admin");
    	            message();
    	    		break;
    	 	case 14:cout<<endl<<endl<<"\t\tDECONNECTE AVEC SUCCES"<<endl;
    	  			reponse=2;//Deconnecte;
    	  			break;
    	  	default:cout<<endl<<endl<<"\t\tDECONNECTE AVEC SUCCES"<<endl;
    	  			reponse=2;//Deconnecte;
    	  
    	  			
    	  
		        }
		 
		 
         }while(reponse==1);
         
		 }
		 else if(status=="user"){
		 	Pharmacien pharmacien=TrouverPharmacien(identifiant);
		 
		 	 int reponse=1;
		 	 system("cls");//Effacer la console;
    	    	 c(2); cout<<endl<<"\t\t\t VOUS ETES CONNECTER EN TANT QUE PHARMACIEN";c(15);
    	     cout<<endl<<endl<<"\t\t\tVeuillez choisir ce que vous voulez faire!"<<endl<<endl;
    	       do{
		  
    	  cout<<"1-Voir la liste des ventes"<<endl;
    	  cout<<"2-Voir la liste des medicaments"<<endl;
    	  cout<<"3-Vendre des medicaments"<<endl;
    	  cout<<"4-Afficher les factures"<<endl<<endl;
    	  cout<<endl<<"ENTRER L'OPTION DE VOTRE CHOIX'"<<endl;
    	  int option;
    	  cin>>option;
    	 
    	  system("cls");//Effacer la console;
    	  switch(option){
    	  	
    	  	case 1:cout<<endl<<"\t\t\t LISTE DES VENTES"<<endl<<endl;
    	  	        pharmacien.voirTotalVentes("user");
    	  	           message();
    	  	       break;
    	  	case 2:cout<<endl<<"\t\t\t LISTE DES MEDICAMENTS"<<endl<<endl;
    	  	        pharmacien.afficherListeMedicament();
    	  	           message();
    	  			break;
    	  	case 3:cout<<endl<<"\t\t\t VENTE DES MEDICAMENTS"<<endl<<endl;
    	  	        pharmacien.vendreMedicament();
    	  	           message();
    	  			break;
    	  	case 4:cout<<endl<<"\t\t\t FACTURES"<<endl<<endl;
    	  	        pharmacien.afficherToutesFacture("user");
    	  	        message();
    	  			break;
    	  	case 5:cout<<endl<<endl<<"\t\tDECONNECTE AVEC SUCCES"<<endl;
    	  			reponse=2;//Deconnecte;
    	  			break;
    	  	default:cout<<endl<<endl<<"\t\tDECONNECTE AVEC SUCCES"<<endl;
    	  			reponse=2;//Deconnecte;
    	     
		  }
		 
		 
         }while(reponse==1);
        }
		}
    
	
	
	

	
}

