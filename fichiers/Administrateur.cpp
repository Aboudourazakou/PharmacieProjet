#include "Administrateur.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include"Compte.h"
using namespace std;

Administrateur::Administrateur(int id,string n,string p):Pharmacien(id,n,p){
	Identifiant=id;
	Nom=n;
	Prenom=p;
	
}

void Administrateur::creerPharmacien()
{
int Identifiant;
string Nom,Prenom;
cout<<"Entrer l'identifiant:";
cin>>Identifiant;
cout<<"Entrer le nom:";
cin>>Nom;
cout<<"Entrer le prenom:";
cin>>Prenom;
Pharmacien p(Identifiant,Nom,Prenom);
cin>>p;
cout<<"PHARMACIEN CREE AVEC SUCCES"<<endl;
}


string  Administrateur::supprimerPharmacien(string id){
	
	ifstream file("pharmaciens.txt",ios::in);
	ofstream file2("tempon.txt",ios::app);//Fichier  pour copier les anciens valeurs de medicament.txt;
	if(file.bad())cout<<"Erreur d'ouverture fichier"<<endl;
	string line;
	string response="user not found";
	
	while(getline(file,line)){
		
		
	  char l[200];
	  
	  if(line!="\0"){
	  	
      strcpy(l,line.c_str());//On convertit la ligne recue du fichier en chaines de caracteres que nous copions // dans l;
      char *tempon=strtok(l,"/");//Nous decoupons cette chaine a partir des |;
     
     
      
	  if(!strcmp(tempon,id.c_str())){
	     response="success";
	   }
	   
	   else{
	 	 file2<<line<<endl;
	 	 
	     }
       }
		
		
	}
	file.close();
	file2.close();
	remove("pharmaciens.txt");
	file2.close();
	ifstream file3("tempon.txt",ios::in);
	ofstream file4("pharmaciens.txt",ios::app);
	
	while(getline(file3,line)){
		
	 	 if(line!="\0"){
		  file4<<line<<endl;
		 }
	}
	
	 file4.close();
	 file3.close();
	 remove("tempon.txt");
	 
	 return response;
	
	;
	
	
	
	
   
}
void Administrateur::modifierMedicament(string id,Medicament &M){


	ifstream file("medicament.txt",ios::in);
	ofstream file2("tempon.txt",ios::app);//Fichier  pour copier les anciens valeurs de medicament.txt;
	if(file.bad())cout<<"Erreur d'ouverture fichier"<<endl;
	string line;
	bool trouver=false;
	char identifiant[10];
	
	while(getline(file,line)){
		
     char l[200];
     
    if(line!="\0"){
      strcpy(l,line.c_str());//On convertit la ligne recue du fichier en chaines de caracteres que nous copions // dans l;
      char *tempon=strtok(l,"|");//Nous decoupons cette chaine a partir des |;
	  if(!strcmp(tempon,id.c_str())){
	  
	  	trouver=true;
	 	M.code=atoi(tempon);
	 	tempon=strtok(NULL,"|");
	    M.nomc=tempon;
		tempon=strtok(NULL,"|");
        M.DCI=tempon;
        tempon=strtok(NULL,"|");
        M.quantite=atoi(tempon);
        tempon=strtok(NULL,"|");
        M.prix_unite=atof(tempon);
        tempon=strtok(NULL,"|");
        M.dosage=tempon;
        tempon=strtok(NULL,"|");
        M.date_exp=tempon;
        tempon=strtok(NULL,"|");
        M.nbrvente=atoi(tempon);
		
	 	int option;
	 	
	 
		
		int reponse=1;
		
	      string name;
	
		do{ 
		
		 cout<<"Choisissez ce que vous voulez modifer"<<endl<<endl;
	 	cout<<"1-Modifier le nom commun"<<endl;
	 	cout<<"2-Modifier la denomination internationale"<<endl;
	 	cout<<"3-Modifier la quantite"<<endl;
	 	cout<<"4-Modifier le prix par unite"<<endl;
	 	cout<<"5-Modifier la posologie ou le dosage"<<endl;
		cout<<"6-Modifier le nombre de ventes"<<endl;
		cout<<"7-Modifier la date d'expiration'"<<endl;
		cout<<"Entrer votre choix"<<endl;
		cin>>option;
		cin.ignore();
		int qte;
	
		switch(option){
			case 1:cout<<"Entrer le nouveau nom"<<endl;
			  
			    getline(cin,M.nomc);
			    
			break;
			case 2: cout<<"Entrer le Denomination internationale"<<endl;
 				getline(cin,M.DCI);
 				    
 				
			break;
			case 3: cout<<"Entrer la quantite"<<endl;
                    cin>>qte;
                    M.setquantite(M.quantite+qte);
                   
			break;
			case 4:	cout<<"Entrer le prix_unite"<<endl;
                    cin>>M.prix_unite;
                    cin.ignore();
                  
			break;
			case 5: cout<<"Entrer la posologie ou le dosage"<<endl;
                   getline(cin,M.dosage);
                  
			break;
			case 6:cout<<"Entrer le nombre de vente du Medicament:";
                      cin>>M.nbrvente;
                    
			break;
			case 7:cout<<"Entrer la date d'expiration"<<endl;
					getline(cin,M.date_exp);
                 
			break;	
			default:cout<<"Vous n'avez choisi aucune option'";	
		}
		cout<<"Voulez vous modifier autre chose?Si oui taper 1 sinon taper 0"<<endl;
		
		cin>>reponse;
		
		system("cls");
		
	    }while(reponse==1);
	    
	    
	    file2<<M.code<<"|"<<M.nomc<<"|"<<M.DCI<<"|"<<M.quantite<<"|"<<M.prix_unite<<"|"<<M.dosage<<"|"<<M.nbrvente<<endl;
	   
	 }
	 else{
	 	 file2<<line<<endl;
	 	 
	 }	
	   
	
	}
	


   } 
	file.close();

   	if(trouver==true){ 
	
	
	remove("medicament.txt");
	file2.close();
	ifstream file3("tempon.txt",ios::in);
	ofstream file4("medicament.txt",ios::app);
	
	while(getline(file3,line)){
		
	 	 if(line!="\0"){
		  file4<<line<<endl;
		 }
	}
	
	 file4.close();
	 file3.close();
	 remove("tempon.txt");
  }
	if(trouver==false)cout<<"\t\t\t AUCUN PRODUIT NE CORRESPOND A CET IDENTIFIANT"<<endl<<endl;
	
}   

 void Administrateur::ajouterMedicament(Medicament &M){
	
   
	cout<<"Entrer le code du Medicament:"<<endl;
	cin>>M.code;
	cin.ignore();
	cout<<"Entrer le nom commercial du Medicament:"<<endl;
    getline(cin,M.nomc);
	cout<<"Entrer la denomination internationale:"<<endl;
    getline(cin,M.DCI);
    cout<<"Entrer la quantite"<<endl;
    cin>>M.quantite;
    cout<<"Entrer le prix unitaire"<<endl;
    cin>>M.prix_unite;
    cin.ignore();
	cout<<"Entrer le dosage ou la posologie du Medicament:";
    getline(cin,M.dosage);
    cout<<"Entrer la date d'expiration du Medicament: sous forme jj-mois-annee";
    getline(cin,M.date_exp);
    cout<<"Entrer le nombre de vente du Medicament:";
    cin>>M.nbrvente;
    cin>>M;
	
	
}


void Administrateur::supprimerFacture(){
    
}
void Administrateur::afficherPharmaciens(){
	ifstream file("Pharmaciens.txt",ios::in);
	if(file.bad()){
		cout<<"Erreur d'ouverture de fichier"<<endl;
		
	}
	else{
		string  line;
		cout<<endl<<"Identifiant\t"<<"Nom\t\t"<<"Prenom\t"<<endl<<endl;
		while(getline(file,line)){
			
		  char ligne[200];//On cree une variable tempon
		  strcpy(ligne,line.c_str());//On convertit line en char et on lui affecte a tempon
	      char *tempon=strtok(ligne,"/");
		  cout<<tempon<<"\t\t";
		  tempon=strtok(NULL,"/");
		  cout<<tempon<<"\t\t";
		  tempon=strtok(NULL,"/");
		  cout<<tempon<<endl;
		  	  
		}
		
	}
	file.close();
    
}

bool Administrateur::supprimerMedicament(string nom){
	
	ifstream file("medicament.txt",ios::in);
	ofstream file2("tempon.txt",ios::app);//Fichier  pour copier les anciens valeurs de medicament.txt;
	if(file.bad())cout<<"Erreur d'ouverture fichier"<<endl;
	string line;
	bool trouver=false;
	
	while(getline(file,line)){
		
		
	  char l[200];
	  
	  if(line!="\0"){
	  	
      strcpy(l,line.c_str());//On convertit la ligne recue du fichier en chaines de caracteres que nous copions // dans l;
      char *tempon=strtok(l,"|");//Nous decoupons cette chaine a partir des |;
      tempon=strtok(NULL,"|");
     
     
      
	  if(!strcmp(tempon,nom.c_str())){
	     trouver=true;
	   }
	   
	   else{
	 	 file2<<line<<endl;
	 	 
	     }
       }
		
		
	}
	file.close();
	file2.close();
	remove("medicament.txt");
	file2.close();
	ifstream file3("tempon.txt",ios::in);
	ofstream file4("medicament.txt",ios::app);
	
	while(getline(file3,line)){
		
	 	 if(line!="\0"){
		  file4<<line<<endl;
		 }
	}
	
	 file4.close();
	 file3.close();
	 remove("tempon.txt");
	 
	 return trouver;
	
	
	
}

string Administrateur::creerCompte(string id){
	
 
    bool existDeja=false;
	ifstream file("compte.txt",ios::in);
	ifstream file2("pharmaciens.txt",ios::in);
	string line;
	string line2;
	string response="id non correspondant";
	
	string password;
	 int role;
	 Compte compte;
	
	
	while(getline(file2,line)){//On verifie si cet id appartient au mois  a un pharmacien
		char l[200];
	    if(line!="\0"){
	    strcpy(l,line.c_str());
		char *tempon=strtok(l,"/");
		if(!strcmp(tempon,id.c_str())){
			
		   while(getline(file,line2)){//On verfiie si un compte ne possede pas cet identifiant deja
		   	char s[200];
		   	if(line2!="\0"){
		   		strcpy(s,line2.c_str());
		   		char *neutre=strtok(s,"/");
		   		 if(!strcmp(neutre,id.c_str())){
		   		 	 existDeja=true;
		   		 	return response= "existe deja";
		   		 
					}
			   }
		   }
		   file.close();
		   file2.close();
		  return compte.sauvegarder(id);
		  break;
		}
		}
	}
	
	file.close();
	file2.close();
	return response;
	
}

string Administrateur::supprimerCompte(string id,string password){
	
	ifstream file("compte.txt",ios::in);
	ofstream file2("tempon.txt",ios::app);
	string line;
	string response="user not found";
	 while(getline(file,line)){//On verfiie si un compte ne possede pas cet identifiant deja

		   	char s[200];
		   	if(line!="\0"){
		   		strcpy(s,line.c_str());
		   		char *neutre=strtok(s,"/");
		   		 if(!strcmp(neutre,id.c_str())){//On verfie d'abord l'id
		   		    neutre=strtok(NULL,"/");
		   		    
		   		     if(!strcmp(neutre,password.c_str())){//Puis on verfiie le mot de passe
		   		     	
		   		     	response="success";
		   		       //Aucune instruction de recopie,l'essentiel c'est d'eviter la recopie de l'ancien fichier
		               }
		               else{
		               	 file2<<line<<endl;//Si le mot de passe ne convient pas,alors on recopie simplement l'utilisateur dans le fichier tempon;
					   }
		   		
		   		 
					}
				else{
						 file2<<line<<endl;
			     	}
			   }
		   }
		   file.close();
		   remove("compte.txt");
		   file2.close();
		   
		   ifstream file3("tempon.txt",ios::in);
		   ofstream file4("compte.txt",ios::app);
		   string line2;
		   
		   while(getline(file3,line2)){
		   	
		   	   if(line2!="\0"){
		   	   	   file4<<line2<<endl;
				  }
			
		    }
		    
		    file4.close();
		    file3.close();
		    remove("tempon.txt");
		    
		    return response;
		   
	
	
	
}


