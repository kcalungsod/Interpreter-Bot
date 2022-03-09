#include "learner.h"

using namespace std;

int mainmenu(string& name);
int againFilipino(string& name);
int getFPhrase(string phrase);
void Flearner(string storePhrase, string& name);
void error(string& name);
void error2(string& name);
void exit_program(string& name, string& userInput);


string convert1(string s){
	for (int i = 0; i < s.length(); i++){
		s[i] = tolower(s[i]);
	}
	return s;
}
string convert2(string s){
	int i = 0;
	s[i] = toupper(s[i]);
	return s;
}

int mainfilipino (string& name, string& userInput){	
	
	if(getFPhrase(userInput)){;
			//keep going
			} 
	else{
		//need to learn this phrase and response
		Flearner(userInput, name);
	}
}	
		
int getFPhrase(string userInput){ //searching database
 	ifstream filipinoFile ( "brain/filipino.txt" );
	
	string phrase;
	string response;
	 
	cout << "[Bot - Eng to Fil]: IBot is processing your input. ";
	system ("pause");
	cout << endl << endl;
	 
		while (getline(filipinoFile, phrase, '|')) {
		getline(filipinoFile, response);
		 
		if(convert1(userInput) == phrase) {
			cout << "[Bot - Eng to Fil]: The translation of '" << convert1(userInput) << "' in Filipino is '"  << convert2(response) << "'." << endl << endl;
			filipinoFile.close();
			return 1;
				
			cout << "[Bot - Eng to Fil]: ";
			system ("pause");
			cout << endl;	
			}
		}
	 
	//we couldn't find the phrase, so we'll need to go to the other function
	// After you are done with the file always close it.
	filipinoFile.close();
	return 0;
}

void Flearner(string inputPhrase, string& name) {
	string storePhrase = inputPhrase, learningResponse;
	string yn;
	char a;
	
	YN:
	cout << "[Bot - Eng to Fil]: Sorry. " + name + ". Unfortunately, I can't find '" << convert1(inputPhrase) << "' in my vocabulary. Would you like to include it in my database instead? [Yes/No]" << endl;
	cout << "\n[" + name + "]: ";
	cin >> yn;
	cout << endl;
	
	exit_program(name, yn);
	
	if ((yn == "Yes") || (yn == "YES") || (yn == "yes") ||(yn == "Y") ||(yn == "y")){
		
		cout << "[Bot - Eng to Fil]: Disclaimer - any input manually added by the user in the database will be tagged as 'under validation'. ";
		cout << "This will be done in order to uphold the integrity and accuracy of the database. It will accordingly be revised once the developers review and approve the entry. ";
		system ("pause");
		cout << endl << endl;
		
		FILIPINOWORD:
			
			cout << "[" + name + "]: English: " << storePhrase << " | Filipino: ";
			cin.ignore();
			getline(cin, learningResponse);
			
			
			exit_program(name, learningResponse);
			for (int i = 0; i < learningResponse.length(); i++){
			    a = learningResponse.at(i);
				if (!((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a == ' ') || (a == '?') || (a == '\''))){
					cin.clear();
					error2(name);
					goto FILIPINOWORD;
		    	}
			}
			
			if (learningResponse==""){
			error2(name);
			goto FILIPINOWORD;
			}
			
			cout << endl;
			
			//open file for writing: parameters indicate that you will APPEND to end
			std::ofstream saveBrain;
			saveBrain.open("brain/filipino.txt", std::ios::out | std::ios::app);
			if(!saveBrain.is_open()) {
				std::cout << "[Bot - Eng to Fil]: Database does not exist." << endl;
				} 
				else{
					saveBrain << endl << convert1(storePhrase) << "|" << convert1(learningResponse) << " (under validation)";
					saveBrain.close();
					
					cout << "[Bot - Eng to Fil]: Successfully added to the database! Thank you for your contribution! ";
					system("pause");
					cout << endl << endl;
				}
	}
	
	else if ((yn == "No") || (yn == "NO") || (yn == "no") ||(yn == "N") ||(yn == "n")){
		cout << "[Bot - Eng to Fil]: Understood. ";
		system ("pause");
		cout << endl << endl;
	}
	else {
		error(name);
		goto YN;
	}
}

