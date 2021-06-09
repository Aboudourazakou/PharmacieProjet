#include "Administrateur.h"
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

Administrateur::Administrateur(int id,string n,string p):Pharmacien(id,n,p){
	Identifiant=id;
	Nom=n;
	Prenom=p;
	
}

//void Administrateur::creerPharmacien(){
// Administrateur  p;
//cout<<"Entrer l'identifiant:";
//cin>>p.Identifiant;
//cout<<"Entrer le nom:";
//cin>>p.Nom;
//cout<<"Entrer le prenom:";
//cin>>p.Prenom;
//cin>>p;
//}
void Administrateur::supprimerPharmacien(){
   
}
void Administrateur::modifierMedicament(string id,Medicament &M){

	
	ifstream file("medicament.txt",ios::in);
	ofstream file2("tempon.txt",ios::app);//Fichier  pour copier les anciens valeurs de medicament.txt;
	if(file.bad())cout<<"Erreur d'ouverture fichier"<<endl;
	string line;
	bool trouver=false;
	char identifiant[10];
	while(getline(file,line)){
		
	 char nomc[20];
	 char DCI[20];
	 char quantite[6];
	 char prix_unite[6];
	 char nbrvente[6];
	 char dosage[100];
	 char date_exp[10];
	 char l[200];//Une chaine de caracteres  pour couper la lignes en attributs
       strcpy(l,line.c_str());//On convertit la ligne recue du fichier en chaines de caracteres que nous copions // dans l;
       char *tempon=strtok(l,"|");//Nous decoupons cette chaine a partir des |;
	  if(!strcmp(tempon,id.c_str())){
	 	
	 	tempon=strtok(NULL,"|");
		strcpy(nomc,tempon); 
		tempon=strtok(NULL,"|");
		strcpy(DCI,tempon);
		tempon=strtok(NULL,"|");
		strcpy(quantite,tempon); 
		tempon=strtok(NULL,"|");
		strcpy(prix_unite,tempon);
		tempon=strtok(NULL,"|");
		strcpy(dosage,tempon);
		tempon=strtok(NULL,"|");
		strcpy(date_exp,tempon);
		tempon=strtok(NULL,"|");
		strcpy(nbrvente,tempon);
		
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
		switch(option){
			case 1:cout<<"Entrer le nouveau nom"<<endl;
			  
			       getline(cin,M.nomc);
				
			break;
			case 2: cout<<"Entrer le Denomination internationale"<<endl;
 				    cin>>M.DCI;
 				    
 					//strcpy(DCI,"");
			break;
			case 3: cout<<"Entrer la quantite"<<endl;
                    cin>>M.quantite;
                    strcpy(quantite,"");
			break;
			case 4:	cout<<"Entrer le prix_unite"<<endl;
                    cin>>M.prix_unite;
                    strcpy(prix_unite,"");
			break;
			case 5: cout<<"Entrer la posologie ou le dosage"<<endl;
                    cin>>M.dosage;
                    strcpy(dosage,"");
			break;
			case 6:cout<<"Entrer le nombre de vente du Medicament:";
                      cin>>M.nbrvente;
                      	strcpy(nbrvente,"");
			break;
			case 7:cout<<"Entrer la date d'expiration"<<endl;
                  cin>>M.date_exp;
			break;	
			default:cout<<"Vous n'avez choisi aucune option'";	
		}
		cout<<"Voulez vous modifier autre chose?Si oui taper 1 sinon taper 0"<<endl;
		cin>>reponse;
		system("cls");
		
	    }while(reponse==1);
	    
	   // M.afficher();
	 }
	 else{
	 	 file2<<line<<endl;
	 	 
	 }	
	   
	
	}
	

}
 void Administrateur::ajouterMedicament(Medicament &M){
	
   
	cout<<"Entrer le code du Medicament:"<<endl;
	cout<<"Entrer le nom commercial du Medicament:"<<endl;
	M.setnomc("Paracetamol");
	cout<<"Le nom est bien sur:  "<<M.nomc;
	cin>>M;
//	M.setDCI("antibiotic");
//	cout<<"Entrer la quantite du Medicament:";
//	M.setquantite(15);
//	cout<<"Entrer le prix par unite du Medicament:";
//	M.setprix_unite(80.76);
//	cout<<"Entrer le dosage du Medicament:";
//	M.setdosage(1.5);
//	cout<<"Entrer la date d'expiration du Medicament:";
//	cout<<"Entrer le nombre de vente du Medicament:";
//	M.setnbrvente(5);
//	
	
	
}

void Administrateur::supprimerMedicament(){
    
}
void Administrateur::ModifierMedicament(){
    
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


