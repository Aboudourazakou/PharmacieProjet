#include <iostream>
#include"Fournisseur.h"
#include"Facture.h"
#include"Medicament.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	

	Medicament m;
 m.setcode(457);
	m.setdate_xp("10/09/2000");
	m.setDCI("dolipranne");
	m.setdosage(21.2);
	m.setnbrvente(4);
	m.setnomc(" vitamine c");
	m.setprix_unite(45.30);
	m.setquantite(20);
cin>>m;
	 
	return 0;
}
