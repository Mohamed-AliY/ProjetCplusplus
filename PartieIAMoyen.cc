#include "PartieIAMoyen.hh"

PartieIAMoyen::PartieIAMoyen(Parametres param):Partie(param){

}
void PartieIAMoyen::debutPartie(){
    
    if(demandeNom){

        cout<< "Quel est le nom du joueur ?" << endl;
        cin>>joueurnom;
    }
    if(JoueurCourant==0){
        cout<<endl;
 		cout<<"C'est " << joueurnom << " qui commence"<<endl;
    }else{

        cout<<"C'est IA qui commence"<<endl;
    }
}
 
int PartieIAMoyen::finPartie(int issue){
    int choixFin;
    cout<<"----------------------------------"<<endl;
    switch (issue){
 		case 0:
 			cout<<"Felicitations ! Tu as gagne "<<endl;
 			break;
 		case 1:
 			cout<<"C'est dommage, Tu as perdue "<<endl;

 			break;
 		case 2:
 			cout<<"Match nul. Un coude à coude VREUMENT"<<endl; 
 			break;
 	}
    cout<<"Tu veux faire quoi maintenant?"<<endl;
 	cout<<"1:Recommencer		2:Recommencer en changeant les noms			3:Menu"<<endl;
 	cin>>choixFin;
     

    //on met a jour demandeNom pour savoir si on demande les noms a la prochaine partie
 	if (choixFin==1){
 		demandeNom=0;
 	}
 	else{
 		demandeNom=1;
 	}
 	//si le choix n'est pas le menu, on recommence une partie
 	if (choixFin!=3){
         reinitialisePartie();

     }
 	return choixFin;
}

 void PartieIAMoyen::reinitialisePartie() {
 	//on remet tous les attributs a leur état de base
	ligneRemplieMax=-1;
	compteurTour=0;
	srand(time(NULL));
	JoueurCourant=rand()%2;
	map<int,int>::iterator it;
	//on remet le nombre de jetons par colonne à 0 partout
	for (it = nbParColonne.begin(); it  !=  nbParColonne.end(); ++it){
		it->second=0;

	}

 	for (int i=0; i<6; i++)  
	{
		for (int j=0; j<7; j++)
		{
			grille[i][j]=-1;
		}
	}

	//cas où le joueur a choisi de renommer les participants
	if (demandeNom){
		debutPartie();
	}

 }
void PartieIAMoyen::remplitGrille(){
	int colonne;
	cout<<"A ton tour. Tes jetons sont les:";
	if (!(par.getAffichageSymboles())){
		if (!JoueurCourant){
			cout<<"X"<<endl;
		}
		else{
			cout<<"O"<<endl;
		}
	}
	else{
		if (!JoueurCourant){
			cout<<"1"<<endl;
		}
		else{
			cout<<"2"<<endl;
		}

	}
	cout<<"Remplis la colonne de ton choix"<<endl;
	cin>>colonne;
	cout<<endl;
	
	//tant que la colonne choisie est remplie, on redemande au joueur de jouer
	while(nbParColonne[colonne]==6){
			
		majAffichage();
		cout<<"choisis une colonne non remplie"<<endl;
		cin>>colonne;
	} 
	

	grille[nbParColonne[colonne]][colonne]=JoueurCourant;
	nbParColonne[colonne]++; //maj ligneRemplieMax

}
int PartieIAMoyen::verifieLigne(){
    int ligneRemplieMax=getLigneRemplieMax();
    int i,j;
	for(i=0;i<ligneRemplieMax;i++){
		PionsAlignes pions;
		for(j=0;j<=6;j++){
			pions.ajouterPion(grille[i][j]);
		}
		if(pions.estGagnant()!=-1)
			return pions.estGagnant();
	}
    if (compteurTour==42){
		return 2;
	}
    return -1;
}

int PartieIAMoyen::verifieColonne(){
    int i,j;
    for(j=0;j<=6;j++){
		if(!(nbParColonne[j]<4)){
			PionsAlignes pions;
			for(i=0;i<nbParColonne[j];i++){
				pions.ajouterPion(grille[i][j]);
			}
			if(pions.estGagnant()!=-1)
				return pions.estGagnant();
		}
	}
    f (compteurTour==42){
		return 2;
	}
    return -1;
}


 	
void PartieIAMoyen::tourOrdi(){
    int colonne=rand()%6;
    if (!(par.getAffichageSymboles())){
		if (!JoueurCourant){
			cout<<"X"<<endl;
		}
		else{
			cout<<"O"<<endl;
		}
	}
	else{
		if (!JoueurCourant){
			cout<<"1"<<endl;
		}
		else{
			cout<<"2"<<endl;
		}

	}
    
    if(verifieLigneLigne()==-1 && verifieLigne()==-1){
        while(nbParColonne[colonne]!=6){

            grille[nbParColonne[colonne]][colonne]=JoueurCourant;
	        nbParColonne[colonne]++;
        }
    }
}


 int PartieIAMoyen::jeu(){

 	while(VerifieFin()==-1){
 		remplitGrille();
 		majAttributs();
 		majAffichage();

 	}
 	return finPartie(VerifieFin());
 	
 }

