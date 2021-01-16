#include "Jeu.hh"

using namespace std;

Jeu::Jeu() {
	param=Parametres();
	partie=new PartieADeux(param);

}

void Jeu::menu(){
	//mettre ca dans le main avant la creation du Jeu
	int entree;
	cout<<"----------------------------------------------"<<endl;
	cout<<"Bonjour, ceci est un jeu de puissance 4."<<endl;
	cout<<"Tape l'un des chiffres indiques pour aller vers ce qui t'interesse!"<<endl;
	cout<<"1: Jouer	contre IA		2: Jouer a 2		3: Parametres"<<endl;
	cin>>entree;
	decisionMenu(entree);


}

//suivant la decision du joueur, on initialise l'attribut partie
void Jeu::decisionMenu(int entree){
	switch(entree){

		case 1:
			if (param.getNivDifficulte()==0){
				//partie=new PartieIAfacile(param);

			}
			else if(param.getNivDifficulte()==1){
				//partie=new PartieIAmoyen(param);

			}
			else{
				//partie=new PartieIAdifficile(param);

			}
			lancerPartie();
			break;


		case 2:
			//avecResume=0, on crée une partie sans recap a la fin
			if (!param.getAvecResume()){
				partie=new PartieADeux(param);

			}
			//sinon on crée une partie avec recap
			else{
				partie=new PartieAvecResume(param);

			}
			lancerPartie();
			break;

		case 3:
			lancerParam();
			break;
	}

}


void Jeu::lancerPartie(){
	//si le joueur veut rejouer alors partie.jeu()=0
	partie->debutPartie();
	while(partie->jeu()!=3);

	menu();
}

void Jeu::lancerParam(){
	while(!param.consulteParam());
	menu();
}