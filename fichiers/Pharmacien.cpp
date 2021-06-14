#include "Pharmacien.h"
#include<fstream>
#include<string.h>
#include"Medicament.h"
#include"Vente.h"
#include <Windows.h>
#include<conio.h>
#include<string>
#include <sstream>
#include"Facture.h"
#include <cstdlib>
#include <ctime>


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
	time_t idF;
    idF = time (NULL);
    idFacture=idF-1623614360;//Pour reduire la valeur de Id facture qui doit etre un int;
   
    do{
		system("cls");
		cout<<endl<<"\t\t\t VENTE DES MEDICAMENTS"<<endl<<endl;
    	cout<<"Entrer l'identifiant ou le nom  commercial du medicament a vendre"<<endl;
    	cin>>query;
    	response=Pharmacien::RechercherMedicament(query);
    	
    	if(response=="not found")cout<<endl<<endl<<"\t\t\tCe medicament n'est pas disponible"<<endl<<endl;
    	
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
	       v.setIdFacture(idFacture);
		   v.setIdVendeur(this->Identifiant);
		 	 
		   
		 
		  
		   
		  cout<<"Entrer la quantite a vendre"<<endl;
		  cin>>quantite;
		     v.setQuantite(quantite);
		     v.setPrixTotal(quantite*prix);
	
		   
		  if(quantity<quantite)cout<<endl<<endl<<"\t\t\tLe stock est insuffisant  pour cette vente.Stock disponible "<<quantity<<endl;
		  else{
		  	  v.ajouterAuPanier();
		  	
		  
		      }
		}
		cout<<"\t\t Taper 1 pour continuer la vente ou 0 pour terminer"<<endl;
	
		
	   cin>>choix;
    	
	} while(choix=="1");
	
	file.close();//We close the file,because sell is finished
	ifstream file2("panier.txt",ios::app);//We open this file, in order to be able to reduce each produit qty in the file medicament
	system("cls");
	string nom;
	string qte;
	char *tempon;
	string line2;
	
	
	cout<<endl<<endl<<"Taper pour voir le contenu du panier"<<endl;
	
	getch();
	system("cls");//Effacer la console;
	cout<<endl<<endl<<"\t\t\tVOICI LE CONTENU DE VOTRE PANIER"<<endl<<endl;
    int foundQuantity=	v.afficherPanier();

     cout<<endl<<endl<<"Taper pour continuer le processuss"<<endl<<endl;
     getch();
 
 if(foundQuantity>0){ 
    ostringstream idFact;
     int IdFacture=v.getIdFacture();//We get the int value created with vente Object
     time_t now = time(0);
    now = time(0);
   // convert now to string form
   char* date = ctime(&now);
   // convert now to string form
   char* dt = ctime(&now);
 	
	Facture f(IdFacture,this->Identifiant,this->Nom,date);
	
	int s,cancel;
	string nom;
	int c=1;
	string q,n;
	bool res=false;
	stringstream ss;
     ss <<IdFacture;
    string idFac = ss.str();//We convert the IdFacture to string 

	 
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
	 		
	 		while(getline(file2,line2)){
	 		
	 		
	 			if(line2!="\0"){
	 				char N[200];
	 				strcpy(N,line2.c_str());
	 				tempon=strtok(N,"|");
	 				tempon=strtok(NULL,"|");
	 				string nom=tempon;
	 				tempon=strtok(NULL,"|");
	 				string qte=tempon;
	 				v.reduireLaQuantiteMedicament(nom,qte);
				 }
	 			
	 			
			 }
			
			 
	 	file2.close();
	    f.GenererFacture();
	 		 
	 		
	 		 res=true;///This variable shows that the basket is empty because user has validate the sell
		    }
		    else{
		    	cout<<"VOUS AVEZ DEJA CONFIRME LA VENTE"<<endl;
			}
		    	
	 	break;
	 	case 2:
	
	      if(res==false){
	      	
	      	     cout<<"Entrer le nom du medicament a supprimer"<<endl;
	      		 cin>>nom;
		      foundQuantity= v.supprimerDuPanier(nom);
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
	 			else {
	 			  cout<<endl<<endl<<"<==============VOTRE FACTURE SELON VOS ENTREES=============>"<<endl<<endl;
	 				f.afficherFacture(idFac);
	 		    	cout<<endl<<endl<<"<===========================================================>"<<endl<<endl;
	 			  
				 }
	 	break;

	
	 } 
	  cout<<endl<<endl<<"Taper 1  pour continuer le processus de vente ou 0 pour quitter definitivement"<<endl;
	 cin>>c;
	 if(foundQuantity==0){
	 	system("cls");
	 	cout<<endl<<endl<<"\t\t\t AUCUN MEDICAMENT DISPONIBLE CAR VOUS AVEZ TOUT SUPPRIME"<<endl;
	 	
	 	break;
	 }
 } while(c==1);
	
}
	
	
  
	
	


}

void Pharmacien::voirTotalVentes(string role){
	
	 bool trouve=false;
     ifstream file("facture.txt",ios::in);
      if(file.bad()) cout<<"Pas ouvert";
	
	   float sommeTotal=0;
	 if(file.bad()){
	 	cout<<"Erreur d'ouverture fichier"<<endl;
	

	 }

	 else{
	 	cout<<endl<<"DESIGNATION "<<"VENDEUR  "<<"QUANTITE  "<<"PrixTotal  "<<"Date   "<<endl<<endl;
	 	 
	 		 string line,line2,nom,date,idF;
			  int idV;
	 		 
	 	 while(getline(file,line)){
	 	 	
	 	 
	 	 	
	 	 	char N[200];
	 	 	if(line!="\0"){//Verfifier si la ligne n'est pas vide
	 	 	
	 	 		  strcpy(N,line.c_str());
	 	 	char *tempon=strtok(N,"|");
	 	 	    idF=tempon;
	 	 	 	tempon=strtok(NULL,"|");
	 	 	 	idV=atoi(tempon);
	 	 		tempon=strtok(NULL,"|");
	 	 	    nom=tempon;
	 	 		tempon=strtok(NULL,"|");
	 	 	    date=tempon;
	 	 	  
	 	 	     ifstream file2("vente.txt",ios::in);
	 	 	    
	 	 	    while(getline(file2,line2)){
	 	 	    	if(line2!="\0"){ 
				
	 	 	    	char L[200];
	 	 	    	strcpy(L,line2.c_str());
	 	 	    	char *neutre=strtok(L,"|");
	 	 	       if(role=="user"){//Si c'est un simple pharmacien ,alors lui afficher ce qu il a vendu
	 	 	           	if(!strcmp(neutre,idF.c_str()) && this->Identifiant==idV){
	 	 	    	     trouve=true;
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
					 else{//Sinon c;est un admin;,on lui affiche tout
					 
					   	if(!strcmp(neutre,idF.c_str())){
	 	 	    	     trouve=true;
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
				  }
				   file2.close();
				 
			  }
			
				  
				
	 	 	    
	 	 		
			  }
			  file.close();
			 
			  cout<<"La somme total de la vente est :    "<<sommeTotal<<endl;
	 	 	
	 	 	
          
		  }
		  
		  if(trouve==false)cout<<endl<<endl<<"\t\t\tAUCUNE VENTE N'A ETE ENREGISTRE"<<endl;
	 	
	   }

void Pharmacien::afficherToutesFacture(string role){
	   
	  ifstream file("facture.txt",ios::in);
	
	 int i=0;
	 if(file.bad())cout<<"Erreur d'ouverture fichier"<<endl;

	 else{
	 		 string line,line2,nom,date;
	 	 while(getline(file,line)){
	 	 
	 	   if(line!="\0"){
	 	   	
	 	   	   	char N[200];
	 	 	strcpy(N,line.c_str());
	 	 	char *tempon=strtok(N,"|");
	 	 	    string idF=tempon;
	 	 		tempon=strtok(NULL,"|");
	 	 		int idV=atoi(tempon);
	 	 		tempon=strtok(NULL,"|");
	 	 	    nom=tempon;
	 	 		tempon=strtok(NULL,"|");
	 	 	    date=tempon;
	 	 	    
	 	 	    if(role=="user"){
	 	 	     int sommeTotal=0;
	 	 	    	if(this->Identifiant==idV){		  
	 	    	i=i+1;//Compteur de factures
   				cout<<"<========================VOTRE FACTURE No"<<i<<"================================>"<<endl;
	 	 	    cout<<endl<<endl<<"Nom de la societe: Pharmacie Nouvelle"<<endl;
	 	 	    cout<<"Vendeur:   "<<nom<<endl;
	 	 	    cout<<"Date de vente:    "<<date<<endl;
	 	 	    cout<<"Identifiant de la facture:   "<<idF<<endl<<endl;
	 	 	    cout<<"MEDICAMENTS ACHETES "<<endl;
	 	 	    cout<<"Designation|Quantite|Posologie|Prix unitaire|Prix total|"<<endl<<endl;
	 	 	    bool trouve=false;
	 	 	    
	 	 	     ifstream file2("vente.txt");
	 	 	     if(file2.bad())cout<<"Erreur d'ouverture fichier"<<endl;
	 	 	     
	 	 	    while(getline(file2,line2)){
	 	 	    	if(line2!="\0"){ 
					  
	 	 	    	char L[200];
	 	 	    	strcpy(L,line2.c_str());
	 	 	    	char *neutre=strtok(L,"|");
	 	 	    	      tempon=strtok(NULL,"|");
					      string designation=tempon;
					     tempon=strtok(NULL,"|");
					     string quantite=tempon;
					     tempon=strtok(NULL,"|");
					     string prixUnite=tempon;
					     tempon=strtok(NULL,"|");
					     string dosage=tempon;
					     tempon=strtok(NULL,"|");
					     int idVendeur=atoi(tempon);
					     tempon=strtok(NULL,"|");
					     float prixTotal=atof(tempon);
					   
					    
	 	 	    	if(!strcmp(neutre,idF.c_str()) && this->Identifiant==idVendeur){
	 	 	    		  sommeTotal+=prixTotal;
	 	 	    		
	 	 	    	     trouve=true;
	 	 	    	    
					     cout<<designation<<"     "<<quantite<<"    "<<prixUnite<<"  "<<dosage<<"   "<<prixTotal<<endl;
					 }
					   		
	 	 	    		
					}
				  }
				  if(trouve==true)cout<<endl<<"Montant total:     "<<sommeTotal<<endl;
				  file2.close();
				  trouve=false;
				  
					  }
	 	 	    	
				  }
				  else{
				  	
				  	  
	 	    	i=i+1;//Compteur de factures
                cout<<"<========================VOTRE FACTURE No"<<i<<"================================>"<<endl;
	 	 	    cout<<endl<<endl<<"Nom de la societe: Pharmacie Nouvelle"<<endl;
	 	 	    cout<<"Vendeur:   "<<nom<<endl;
	 	 	    cout<<"Date de vente:    "<<date<<endl;
	 	 	    cout<<"Identifiant de la facture:   "<<idF<<endl<<endl;
	 	 	    cout<<"MEDICAMENTS ACHETES "<<endl;
	 	 	    cout<<"Designation|Quantite|Posologie|Prix unitaire|Prix total|"<<endl<<endl;
	 	 	    float sommeTotal=0;
	 	 	    bool trouve=false;
	 	 	    
	 	 	     ifstream file2("vente.txt");
	 	 	     if(file2.bad())cout<<"Erreur d'ouverture fichier"<<endl;
	 	 	     
	 	 	    while(getline(file2,line2)){
	 	 	    	if(line2!="\0"){ 
					  
	 	 	    	char L[200];
	 	 	    	strcpy(L,line2.c_str());
	 	 	    	char *neutre=strtok(L,"|");
	 	 	    	if(!strcmp(neutre,idF.c_str())){
	 	 	    	     trouve=true;
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
					     cout<<designation<<"     "<<quantite<<"    "<<prixUnite<<"  "<<dosage<<"   "<<prixTotal<<endl;
					 }
					   		
	 	 	    		
					}
				  }
				  if(trouve==true)cout<<endl<<"Montant total:     "<<sommeTotal<<endl;
				  file2.close();
				  trouve=false;
				  
				  	
				  }
			  
				
	 	 	    
	 	 		
			  
	 	 	
	 	 
			}	
          
		  }
		    file.close();
	
	 	
	   }
}
	





