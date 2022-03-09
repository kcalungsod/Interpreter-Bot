#include "learner.h"

using namespace std;

int mainmenu(string& name);
int againChinese(string& name);
int getCPhrase(string phrase);
string convert1(string s);
string convert2(string s);
void Clearner(string storePhrase, string& name);
void error(string& name);
void error2(string& name);
void exit_program(string& name, string& userInput);


int mainchinese (string& name, string& userInput){
	
	if(getCPhrase(userInput)){;
				//keep going
			} 
	else{
		//need to learn this phrase and response
		Clearner(userInput, name);
	}
	
}

int getCPhrase(string userInput){
	ifstream chineseFile ( "brain/chinese.txt" );
	       
	string phrase;
	string response;
	 
	cout << "[Bot - Eng to Cn]: IBot is processing your input. ";
	system ("pause");
	cout << endl << endl; 
	 
		while (getline(chineseFile, phrase, '|')) {
		getline(chineseFile, response);
		 
		if(convert1(userInput) == phrase) {
			cout << "[Bot - Eng to Cn]: The translation of '" << convert1(userInput) << "' in Chinese Mandarin is '" << convert2(response) << "'." << endl << endl;
			chineseFile.close();
			return 1;
			
			cout << "[Bot - Eng to Cn]: ";
			system ("pause");
			cout << endl;	
		}
	}
	 
	//we couldn't find the phrase, so we'll need to go to the other function
	// After you are done with the file always close it.
	chineseFile.close();
	return 0;
}

void Clearner(string inputPhrase, string& name) {
	string storePhrase = inputPhrase, learningResponse;
	string yn;
	char a;
	
	YN:
	cout << "[Bot - Eng to Cn]: Sorry. " + name + ". Unfortunately, I can't find '" << convert1(inputPhrase) << "' in my vocabulary. Would you like to include it in my database instead? [Yes/No]" << endl;
	cout << "\n[" + name + "]: ";
	cin >> yn;
	cout << endl;
	
	exit_program(name, yn);
	
	if ((yn == "Yes") || (yn == "YES") || (yn == "yes") ||(yn == "Y") ||(yn == "y")){
		
		cout << "[Bot - Eng to Cn]: Disclaimer - any input manually added by the user in the database will be tagged as 'under validation'. ";
		cout << "This will be done in order to uphold the integrity and accuracy of the database. It will accordingly be revised once the developers review and approve the entry. ";
		system ("pause");
		cout << endl << endl;
		
		cout << "[Bot - Eng to Cn]: Furthermore, for the English to Chinese function, it's okay if the user can only enter the pinyin equivalent of the word or phrase ";
		cout << "The developers will include the chinese characters once the suggested translation's passed validation. ";
		system ("pause");
		cout << endl << endl;
		
		CHINESEWORD:
			cout << "[" + name + "]: English: " << storePhrase << " | Chinese: ";
			cin.ignore();
			getline(cin, learningResponse);
			
			cout << endl;
			
			exit_program(name, learningResponse);
			for (int i = 0; i < learningResponse.length(); i++){
			    a = learningResponse.at(i);
				if (!((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a == ' ') || (a == '?') || (a == '\''))){
					cin.clear();
					error2(name);
					goto CHINESEWORD;
		    	}
			}
			
			if (learningResponse==""){
			error2(name);
			goto CHINESEWORD;
			}
			
		//open file for writing: parameters indicate that you will APPEND to end
			std::ofstream saveBrain;
			saveBrain.open("brain/chinese.txt", std::ios::out | std::ios::app);
			if(!saveBrain.is_open()) {
				std::cout << "[Bot - Eng to Cn]: Database does not exist." << endl;
				} 
				else{
					saveBrain << endl << convert1(storePhrase) << "|" << convert1(learningResponse) << " (under validation)";
					saveBrain.close();
					
					cout << "[Bot - Eng to Cn]: Successfully added to the database! Thank you for your contribution! ";
					system("pause");
					cout << endl << endl;
				}
	}
	
	else if ((yn == "No") || (yn == "NO") || (yn == "no") ||(yn == "N") ||(yn == "n")){
		cout << "[Bot - Eng to Cn]: Understood. ";
		system ("pause");
		cout << endl << endl;
	}
	else {
		error(name);
		goto YN;
	}		
}
