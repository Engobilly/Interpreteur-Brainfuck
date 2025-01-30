#include <iostream> // biblioth�que permettant d'afficher du texte a l'�cran et de lire l'entr�e de l'utilisateur
void brainfuck(const std::string &code, bool debug){ // fonction qui va analyser et ex�cuter ce que l'utilisateur a tap�
	const int MEMOIRE = 30000;// cr�ation du tableau avec sa m�moire 
	unsigned char memory[MEMOIRE] = {0};
	int pointeur = 0 ; // variable pointeur pour la position actuelle du pointeur 
	for (size_t i = 0; i < code.size(); ++i) {
		switch (code[i]) {
			case '>': //avance � droite dans la m�moire
				pointeur = (pointeur +1) % MEMOIRE;
				break;
			case '<'://recule � gauche
				pointeur = (pointeur - 1 + MEMOIRE) % MEMOIRE;
				break;
			case '+':
					memory[pointeur]++; //incr�menter � la position du pointeur
				break;
			case '-':
						memory[pointeur]--;  //d�crementer � la position du pointeur 
				break;
			case '.':  //affiche le caract�re ASCII correspondant � la valeur de la cellule
							std::cout <<(memory[pointeur]);
							std :: cout<< "valeur ASCII: " <<(int)memory[pointeur] << "]" ;
							std :: cout <<(memory[pointeur]) << std :: endl;
				break;
			case ',': // permet a l'utilisateur d'entrer un caract�re qui est stock� dans la cellule actuelle
								memory[pointeur]=std :: cin.get();
				break;
				case '#':// affiche la valeur num�rique de la cellule au lieu du caract�re ASCII 
				std :: cout <<"[" << (int)memory[pointeur]<<"]";
				break;
			case '[': // debut de la boucle
									if (memory[pointeur]==0){	
						        	int valeur_actuel=1;
									while(valeur_actuel > 0 && ++i < code.size()) {
										if (code[i]== '[') valeur_actuel++;
									else	if (code[i]==']')valeur_actuel--;
									}
								}
				break;
			case ']': // fin de la boucle
								if(memory[pointeur]!= 0){
									int valeur_actuel = 1;
									while (valeur_actuel > 0 && --i >= 0) {
										if (code[i]==']') valeur_actuel++;
										else if (code[i] =='[') valeur_actuel--;
									}
								}	
				break; // si la valeur actuelle est 0 la boucle est ignor�e jusqu'� ']' et si la valeur actuelle n'est pas 0 le programme revient au d�but de la boucle
								}
								if(debug) {
									std :: cout << "\n[debug] pointeur: "<<pointeur << "|valeur: " << (int)memory[pointeur]<<"\n";
								}//si debug est activ� le programme affiche la position du pointeur et la valeur de la cellule actuelle apres chaque instruction
		}
	}
	int main() {
		std :: cout << "1:TRANSCRIPTION(taper directement le code )\n";
		std :: cout << "2:TRANCRIPTION ET MODE DEBUG (TAPER 'debug' pour activer et desactiver ce mode)\n";
			std :: cout << "3: TAPER 'exit'POUR SORTIR\n";
		bool debug = false;
		while(true){
			std :: cout<<"\n";
		
		std :: string brainfuckCode;
		std:: cout<< "entrez le code brainfuck: ";
		std :: getline (std::cin, brainfuckCode);
		std :: cout << "resultat :\n";
		if (brainfuckCode=="exit")break;
		if (brainfuckCode=="debug"){
			debug= !debug;
			std:: cout << (debug? "mode debug active": "mode debug desactive")<< "\n";
			continue;
		}
		brainfuck(brainfuckCode, debug);
	}
		return 0;
	}

