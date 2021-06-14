#include "Vente.h"
#include<fstream>
#include<string.h>
#include<iostream>
#include<string> 
#include <cstdlib>
using namespace std;

Vente::Vente(string nom,int qte,float prix,string dose,int idF,int idV,float total){
	nomc=nom;
	prix_unite=prix;
	quantite=qte;
	dosage=dose;
    idFacture=idF;
	idVendeur=idV;
	prixTotal=total;
			
};

void Vente::ajouterAuPanier(){
	   
	//On verifie si le medicament existe deja dans le panier//
	  ifstream file1("panier.txt",ios::in);
	  ofstream file2("tempon.txt",ios::app);
	  string line;
	  float prix;
	  int qte;
	  float prixT;
	  int Qt;
	  int trouve=false;
	  
	   while(getline(file1,line)){
	   	 char N[200];
	   	 strcpy(N,line.c_str());
	   	  char *tempon=strtok(N,"|");
	   	  tempon=strtok(NULL,"|");
	   	  if(!strcmp(tempon,nomc.c_str())){
	   	  	trouve=true;
	   	  	 tempon=strtok(NULL,"|");
	   	  	 
	   	  	 qte=atoi(tempon);
	   	  	 tempon=strtok(NULL,"|");
	   	  	 tempon=strtok(NULL,"|");
	   	  	 tempon=strtok(NULL,"|");
	   	  	 tempon=strtok(NULL,"|");
	   	  	 tempon=strtok(NULL,"|");
	   	  	 tempon=strtok(NULL,"|");
	   	  	 prix=atof(tempon);
	   	  	 
	   
		
				   float prixT=(qte+quantite)*prix_unite;
	   	  	          Qt=quantite+qte;
		
			
	   	  	file2<<idFacture<<"|"<<nomc<<"|"<<Qt<<"|"<<prix_unite<<"|"<<"hsdhjjhsdjhsd"<<"|"
		     <<idVendeur<<"|"<<prixT<<endl;
			 }
		  else{
		  	file2<<line<<endl;
		  }
	   }
	file1.close();
	remove("panier.txt");
	file2.close();
	ofstream file3("panier.txt",ios::app);
	ifstream file4("tempon.txt",ios::in);
	
	while(getline(file4,line)){
		file3<<line<<endl;
	}
	file3.close();
	file4.close();
	remove("tempon.txt");
	
	
	//////////////////////////////////////////////////////////
     if(trouve==false){	 ///Si le medicament n'est pas duplique	
     
     
    ofstream file("panier.txt",ios::app);
	 if(file.bad())cout<<"Erreur d'ouverture fichier"<<endl;
	

	 else{
		file<<idFacture<<"|"<<nomc<<"|"<<quantite<<"|"<<prix_unite<<"|"<<"jksdjds"<<"|"<<idVendeur<<"|"<<prixTotal<<endl;
	    cout<<"Medicament ajoute avec succes dans le panier"<<endl;
	   }
	 }
}

int Vente::afficherPanier(){
	int trouve=0;
	ifstream file("panier.txt",ios::in);
	if(file.bad())cout<<"Erreur d;ouverture"<<endl;

	string line;
	while(getline(file,line)){
			 if(line!="\0") trouve=true;
		 trouve=trouve+1;
	      cout<<"\t\t"<<line<<endl;
	}
	if(trouve==0){
		cout<<"Aucun medicament ajoute au panier"<<endl;
		return trouve;
	}
	
	return trouve;
}

int Vente::supprimerDuPanier(string nom){
  
    int trouve=0;
	ifstream file("panier.txt",ios::in);
	ofstream file2("tempon.txt",ios::app);
	if(file.bad())cout<<"Erreur d;ouverture"<<endl;
	string line,line2;
	
	while(getline(file,line)){
		char N[200];
		strcpy(N,line.c_str());
		
		if(line!="\0"){
			
			char *neutre=strtok(N,"|");
			neutre=strtok(NULL,"|");
			if(strcmp(neutre,nom.c_str())){
		       
				file2<<line<<endl;
			}
			
		}
		
	}
	file.close();
	file2.close();
	remove("panier.txt");
	ifstream file3("tempon.txt",ios::in);
	ofstream file4("panier.txt",ios::app);
    while(getline(file3,line)){
    	trouve=trouve+1;
    	file4<<line<<endl;
	}
	
	file3.close();
	file4.close();
	remove("tempon.txt");
	
	cout<<"Operation terminee!"<<endl;
	return trouve;
	
	 
}

string Vente::reduireLaQuantite(string nom,string qte){
	  
	  string response="echec";
	  string  nomc;
	  string idF;
	  string idV;
	  int qty;
	  string dosage;
	  float prixUnite;
	  float prixT;
	  ifstream file("panier.txt",ios::in);
	  ofstream file2("tempon.txt",ios::app);
	  if(file.bad())cout<<"Erreur d'ouverture"<<endl;
	  else{
	  	string line;
	  	
	  	while(getline(file,line)){
	  	if(line!="\0"){
	  		 	 char N[200];
	  		 strcpy(N,line.c_str());
	  		 char *neutre=strtok(N,"|");
	  		 idF=neutre;
	  		 neutre=strtok(NULL,"|");
	  		 
	  		 if(line!="\0"){
	  		 	 if(!strcmp(neutre,nom.c_str())){
	  		 	 neutre=strtok(NULL,"|");
	  		 	 qty=atoi(neutre);
	  		 	 neutre=strtok(NULL,"|");
	  		 	 prixUnite=atof(neutre);
	  		 	 neutre=strtok(NULL,"|");
	  		 	 dosage=neutre;
	  		 	 neutre=strtok(NULL,"|");
	  		 	 idV=neutre;
	  		 	 neutre=strtok(NULL,"|");
	  		 	 prixT=atof(neutre);
	  		 	 
	  		 	 int q=qty-atoi(qte.c_str());
	  		 	 float p=q*prixUnite;
	  		 	 
	  		 	 
	  		 	 if(q>0){
	  		 	 	   response="success";
	  		 	 	   file2<<idF<<"|"<<nom<<"|"<<q<<"|"<<prixUnite<<"|"<<dosage<<"|"<<idV<<"|"<<p<<endl;
					}
					else{
						file2<<line<<endl;
						response="negatif";
					}
			   }
			else{
				file2<<line<<endl;
			}
			   
			   }
		  }
		  }
		  
		  file.close();
		  file2.close();
		  remove("panier.txt");
		  ofstream file3("panier.txt",ios::app);
		  ifstream file4("tempon.txt",ios::in);
		  if(file3.bad()||file4.bad())cout<<"Erreur";
		  else{
		  	string line;
		  	while(getline(file4,line)){
		  		
		  		if(line!="\0"){
		  			file3<<line<<endl;
				  }
				  
			  }
		  }
		  
		  file3.close();
		  file4.close();
		  remove("tempon.txt");
		  return response;
		  
		  
		  
	  }
	
}

void Vente::reduireLaQuantiteMedicament(string nom,string qte){
	  
	  cout<<endl<<endl<<"Je suis dans REDUCTION"<<endl<<endl;
	  string  nomc;
	  int qty;
	  ifstream file("medicament.txt",ios::in);
	  ofstream file2("tempon.txt",ios::app);
	  if(file.bad())cout<<"Erreur d'ouverture"<<endl;
	  else{
	  	string line;
	  	
	  	while(getline(file,line)){
	  		 char N[200];
	  		 strcpy(N,line.c_str());
	  		 char *neutre=strtok(N,"|");
	  		 string code=neutre;
	  		 neutre=strtok(NULL,"|");
	  		 
	  		 nomc=neutre;//nomc ici prend le nom commercial du medicament
	  		 
	  		 if(line!="\0"){
	  		 	 if(!strcmp(neutre,nom.c_str())){
	  		 	
	  		 	 neutre=strtok(NULL,"|");//Ici nom international
	  		 	 string dci=neutre;
	  		 	 neutre=strtok(NULL,"|");//Ici la quantite;
	  		 	 int qty=atoi(neutre);
	  		 	 qty=qty-atoi(qte.c_str());//Icii on reduit la quantite,en coonvertissant la chaine quantite recue en int;
	  		 	  cout<<endl<<endl<<"Je suis dans REDUCTION de"<<atoi(qte.c_str())<<endl<<endl;
	  		 	 neutre=strtok(NULL,"|");
	  		 	 string prixUnit=neutre;//Nous declarons des varaibles en string car  les donnees recuees du fichiers sont en string.Et puisque 
	  		 	 						//nous n'avons aucun besoin de les modifier,on les ramene telles qu'elles etaient par nature
	  		 	 neutre=strtok(NULL,"|");
	  		 	 string dosage=neutre;
	  		 	 neutre=strtok(NULL,"|");
	  		     string date=neutre;
	  		 	 neutre=strtok(NULL,"|");
	  		 	 int nbrevente=atoi(neutre)+atoi(qte.c_str());
	  		 	 
	  		 	 	   file2<<code<<"|"<<nomc<<"|"<<dci<<"|"<<qty<<"|"<<prixUnit<<"|"<<dosage<<"|"<<date<<"|"<<nbrevente<<endl;
					
				
			   }
			else{
				file2<<line<<endl;
			}
			   
			   }
		  }
		  
		  file.close();
		  file2.close();
		  remove("medicament.txt");
		  ofstream file3("medicament.txt",ios::app);
		  ifstream file4("tempon.txt",ios::in);
		  if(file3.bad()||file4.bad())cout<<"Erreur";
		  else{
		  	string line;
		  	while(getline(file4,line)){
		  		
		  		if(line!="\0"){
		  			file3<<line<<endl;
				  }
				  
			  }
		  }
		  
		  file3.close();
		  file4.close();
		  remove("tempon.txt");
	
		  
		  
		  
	  }
	
}
