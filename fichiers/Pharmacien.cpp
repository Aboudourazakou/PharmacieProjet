#include "Pharmacien.h"
#include<fstream>
#include<string.h>
#include"Medicament.h"
#include"Vente.h"
#include <Windows.h>
#include<conio.h>
#include<time.h>
#include<string>
#include <sstream>
#include"Facture.h"


Pharmacien::Pharmacien(int id,string nom,string prenom){
	Identifiant=id;
	Nom=nom;
	Prenom=prenom;
}
int Pharmacien::getIdentifiant(){
	return Identifiant;
};
//string Pharmacien::getNom(){
//	return Nom;
//};
string Pharmacien::getPrenom(){
	return Prenom;
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



void Pharmacien::afficher(){
	cout<<"Identifiant: "<<Identifiant<<endl;
	cout<<"Nom: "<<Nom<<endl;
	cout<<"Prenom: "<<Prenom<<endl;
	
	
	
};

istream &operator>>(istream &p,Pharmacien&g){
	ofstream file("Pharmaciens.txt",ios::app);
	if(file.bad())cout<<"Erreur d'ouverture fichier"<<endl;
	else{
		file<<g.Identifiant<<"/"<<g.Nom<<"/"<<g.Prenom<<endl;
	}
	
	
	
}



void Pharmacien::afficherListeMedicament(){
	ifstream file("medicament.txt",ios::in);
	if(file.bad()){
		cout<<"Erreur d'ouverture de fichier'"<<endl;
		
	}
	else{
		string  line;
		cout<<"code"<<"|"<<"nomc"<<"|"<<"DCI "<<"|"<<"quantite"<<"|"<<"prix_unite"
		<<"|"<<"Posologie"<<"|"<<"date_exp"<<"|"<<"nbrvente"<<endl<<endl;
		while(getline(file,line)){
		
		  char ligne[200];//On cree une variable tempon
		  strcpy(ligne,line.c_str());//On convertit line en char et on lui affecte a tempon
	      char *tempon=strtok(ligne,"|");
		  cout<<tempon<<"\t\t";
		  tempon=strtok(NULL,"|");
		  cout<<tempon<<"\t\t";
		  tempon=strtok(NULL,"|");
		  cout<<tempon<<"\t\t";
		  tempon=strtok(NULL,"|");
		  cout<<tempon<<"\t\t";
		  tempon=strtok(NULL,"|");
		  cout<<tempon<<"\t\t";
		  tempon=strtok(NULL,"|");
		  cout<<tempon<<"\t\t";
		  tempon=strtok(NULL,"|");
		  cout<<tempon<<"\t\t";
		  tempon=strtok(NULL,"|");
		  cout<<tempon<<endl;
		}
		
	}
	file.close();
}

string Pharmacien::RechercherMedicament(string query){
	
	   ifstream file("medicament.txt",ios::in);
	   string line;
	  
	   
	   
	   while(getline(file,line)){
	   	
	   	 char ligne[200];//On cree une variable tempon
		  strcpy(ligne,line.c_str());//On convertit line en char et on lui affecte a tempon
	      char *tempon=strtok(ligne,"|");
	      
	      if(!strcmp(tempon,query.c_str())){
	      	return line;
		  }
		   tempon=strtok(NULL,"|");
		  if(!strcmp(tempon,query.c_str())){
		  	return line;
		  	
		  }
	   	
	   	
	   }
	   
	   return "not found";
	
}

void Pharmacien::vendreMedicament(){
	
	ifstream file("medicament.txt",ios::in);

	string line;
    string choix="1";
    string query,response;
    int quantite;
    
    string nomc;
	int quantity;
	float prix;
	string dosage;
	string dateVente;
	int idFacture;
	int idVendeur;
	Vente v;
   
    do{
		system("cls");
		cout<<endl<<"\t\t\t VENTE DES MEDICAMENTS"<<endl<<endl;
    	cout<<"Entrer l'identifiant le nom  commercial du medicament a vendre"<<endl;
    	cin>>query;
    	response=Pharmacien::RechercherMedicament(query);
    	
    	if(response=="not found")cout<<"Ce medicament n'est pas disponible"<<endl;
    	
    	else{
    		
		  char ligne[200];//On cree une variable tempon
		  strcpy(ligne,response.c_str());//On convertit line en char et on lui affecte a tempon
	      char *tempon=strtok(ligne,"|");
		  tempon=strtok(NULL,"|");
		  v.setNom(tempon);
		  tempon=strtok(NULL,"|");
		  tempon=strtok(NULL,"|");
	      quantity=atoi(tempon);
		  tempon=strtok(NULL,"|");
		  prix=atof(tempon);
		  v.setPrixUnite(prix);
		  tempon=strtok(NULL,"|");
		   //v.dosage=tempon;
   	      tempon=strtok(NULL,"|");
           tempon=strtok(NULL,"|");
	       idFacture= 54545;
	       v.setIdFacture(idFacture);
		   v.setIdVendeur(this->Identifiant);
		 	 
		   
		 
		  
		   
		  cout<<"Entrer la quantite a vendre"<<endl;
		  cin>>quantite;
		     v.setQuantite(quantite);
		     v.setPrixTotal(quantite*prix);
	
		   
		  if(quantity<quantite)cout<<"Le stock est insuffisant  pour cette vente.Stock disponible "<<quantity<<endl;
		  else{
		  	  v.ajouterAuPanier();
		  	
		  
		      }
		}
		cout<<"Taper 1 pour continuer la vente ou 0 pour terminer"<<endl;
	
		
	   cin>>choix;
    	
	} while(choix=="1");
	cout<<endl<<endl<<"Taper pour voir le contenu du panier"<<endl;
	
	getch();
	system("cls");//Effacer la console;
	cout<<endl<<endl<<"\t\t\tVOICI LE CONTENU DE VOTRE PANIER"<<endl;
    bool found=	v.afficherPanier();

     cout<<endl<<endl<<"Taper pour continuer le processuss"<<endl<<endl;
     getch();

 if(found==true){ 
 
	Facture f(idFacture,this->Identifiant,this->Nom,"20-303");
	
	int s,cancel;
	string nom;
	int c=1;
	string q,n;
	bool res=false;
	 
	 do{
 
     system("cls");
	cout<<endl<<endl<<"\t\t\tVEUILLEZ CHOISIR UNE OPTION"<<endl<<endl;
	cout<<"1-CONFIRMER LA VENTE"<<endl;
	cout<<"2-SUPPRIMER UN MEDICAMENT DU PANIER"<<endl;
	cout<<"3-REDUIRE LA QUANTIE"<<endl;
	cout<<"4-ANNULER TOUTE LA VENTE"<<endl;
	cout<<"5-AFFICHER LA FACTURE"<<endl;
	cout<<"Entrer votre choix"<<endl;
	
	cin>>s;
	  switch(s){
	 	
	 	case 1:if(res==false){
	 		f.GenererFacture();
	 		 res=true;
		    }
		    else{
		    	cout<<"VOUS AVEZ DEJA CONFIRME LA VENTE"<<endl;
			}
		    	
	 	break;
	 	case 2:
	
	      if(res==false){
	      	
	      	     cout<<"Entrer le nom du medicament a supprimer"<<endl;
	      		 cin>>nom;
		       v.supprimerDuPanier(nom);
		  }
		  
		 else cout<<"Suppression impossible car vous avez deja valide"<<endl;
	 	  break;
	 	case 3:if(res==false){
	 		cout<<"REDUIRE LA QUANTITE"<<endl;
	 	   cout<<"Entrer la quantite a reduire"<<endl;
	 	    getline(cin,q);
	 	    cin>>q;
	 	    cin.ignore();
	 	   cout<<"Entrer le nom du medicament"<<endl;
	 	   getline(cin,n);
	 	 
	 	    response=v.reduireLaQuantite(n,q);
	 	    if(response=="echec")cout<<"Operation echouee"<<endl;
	 	    else if(response=="negatif")cout<<"Operation impossible car la quantite a reduire est superieure a la quantite disponible"<<endl;
	 	    else if(response=="success")cout<<"Quantite reduite avec succes"<<endl;
			
		 }
		 else{
		 	cout<<"Aucune reduction possible,car la vente est deja validee"<<endl;
		   }
		   
		    break;
	 	case 4:
	 		if(res==false){
	 			cout<<"Voulez vous vraiment annuler la vente? Taper 1 si OUI et 0 si non"<<endl;
	 	     cin>>cancel;
	 	     if(cancel==1){
	 	     	remove("panier.txt");
	 	     	cout<<"Vente annuler avec success"<<endl;
	 	     	c=3;
			  }
	 	     
			 }
			 else{
			 	cout<<"Vous avez deja validee la vente"<<endl;
			 }
	 	   break;
	 	case 5:if(res==false)cout<<"Aucune facture disponible  pour le moment.Valider d'abord la vente'"<<endl;
	 			else f.afficherFacture("54545");
	 	break;

	
	 } 
	  cout<<endl<<endl<<"Taper 1  pour continuer le processus de vente ou 0 pour quitter definitivement"<<endl;
	 cin>>c;
 } while(c==1);
	
}
	
	
  
	
	


}

void Pharmacien::voirTotalVentes(string role){
	
     ifstream file("facture.txt",ios::in);
	 ifstream file2("vente.txt");
	   float sommeTotal=0;
	 if(file.bad() || file2.bad()){
	 	cout<<"Erreur d'ouverture fichier"<<endl;
	

	 }

	 else{
	 	cout<<endl<<"DESIGNATION "<<"VENDEUR  "<<"QUANTITE  "<<"PrixTotal  "<<"Date   "<<endl<<endl;
	 	
	 		 string line,line2,nom,date,idF;
	 		 
	 	 while(getline(file,line)){
	 	 	
	 	 	char N[200];
	 	 	strcpy(N,line.c_str());
	 	 	char *tempon=strtok(N,"|");
	 	 	    idF=tempon;
	 	 	 	tempon=strtok(NULL,"|");
	 	 		tempon=strtok(NULL,"|");
	 	 	    nom=tempon;
	 	 		tempon=strtok(NULL,"|");
	 	 	    date=tempon;
	 	 	  
	 	 	    
	 	 	    while(getline(file2,line2)){
	 	 	    	if(line2!="\0"){ 
				
	 	 	    	char L[200];
	 	 	    	strcpy(L,line2.c_str());
	 	 	    	char *neutre=strtok(L,"|");
	 	 	    	if(!strcmp(neutre,idF.c_str())){
	 	 	    	
	 	 	    	     tempon=strtok(NULL,"|");
					      string designation=tempon;
					     tempon=strtok(NULL,"|");
					     string quantite=tempon;
					     tempon=strtok(NULL,"|");
					     string prixUnite=tempon;
					     tempon=strtok(NULL,"|");
					     string dosage=tempon;
					     tempon=strtok(NULL,"|");
					     tempon=strtok(NULL,"|");
					     float prixTotal=atof(tempon);
					     sommeTotal+=prixTotal;
					     cout<<designation<<"     "<<nom<<"  "<<quantite<<"   "<<prixTotal<<"   "<<date<<endl;
					 }
					   		
	 	 	    		
					}
				  }
				 
				  
				  file.close();
				  file2.close();
	 	 	    
	 	 		
			  }
	 	 	
	 	 	
          
		  }
	 	
	   }
	





