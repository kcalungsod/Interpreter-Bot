#include "learner.h"

using namespace std;

int mainfilipino(string& name, string& userInput);
int mainchinese(string& name, string& userInput);
void error(string& name);
void error2(string& name);
void exit_program(string& name, string& userInput);

void againFilipino(string& name){
	
	string userInput, language, yn;
	char a;
	
	AGAIN:
	cout << "[Bot - Eng to Fil]: Do you want to proceed with more English to Filipino translations? Yes or no?" << endl << endl;
	cout << "[" + name + "]: "; cin >> yn;
	cout << endl;
	
	exit_program(name, yn);

	if ((yn == "Yes") || (yn == "YES") || (yn == "yes") ||(yn == "Y") ||(yn == "y")){
		ASK:
		cout << "[Bot - Eng to Fil]: Please enter the English word or phrase you would like to translate in Filipino." << endl << endl;
		cout << "[" + name + "]: "; 
		cin.ignore();
		getline(cin, userInput);
		
		cout << endl;
		
		exit_program(name, userInput);
		
		for (int i = 0; i < userInput.length(); i++){
		a = userInput.at(i);
			if (!((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a == ' ') || (a == '?') || (a == '\''))){
			    cin.clear();
				error2(name);
				goto ASK;
		    }
		}
		
		if (userInput==""){
			error2(name);
			goto ASK;
		}
		
		
		mainfilipino(name, userInput);
		goto AGAIN;	
	}
	else if ((yn == "No") || (yn == "NO") || (yn == "no") ||(yn == "N") ||(yn == "n")){
		cout << "[Bot - Eng to Fil]: Understood. ";
		system ("pause");
		cout << endl << endl;
	}
	else{
		error(name);
		goto AGAIN;
	}
}

void againChinese(string& name){
	string userInput, language, yn;
	char a;
	
	AGAIN:
	cout << "[Bot - Eng to Cn]: Do you want to proceed with more English to Chinese translations? [Yes/No]" << endl << endl;
	cout << "[" + name + "]: "; cin >> yn;
	cout << endl;

	exit_program(name, yn);

	if ((yn == "Yes") || (yn == "YES") || (yn == "yes") ||(yn == "Y") ||(yn == "y")){
		ASK:
		cout << "[Bot - Eng to Cn]: Please enter the English word or phrase you would like to translate in Chinese." << endl << endl;
		cout << "[" + name + "]: "; 
		cin.ignore();
		getline(cin, userInput);
		
		cout << endl;
		
		exit_program(name, userInput);
		
		for (int i = 0; i < userInput.length(); i++){
		a = userInput.at(i);
			if (!((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a == ' ') || (a == '?') || (a == '\''))){
			    cin.clear();
				error2(name);
				goto ASK;
		    }
		}
		
		if (userInput==""){
			error2(name);
			goto ASK;
		}
		
		mainchinese(name, userInput);
		goto AGAIN;	
	}
	else if ((yn == "No") || (yn == "NO") || (yn == "no") ||(yn == "N") ||(yn == "n")){
		cout << "[Bot - Eng to Cn]: Understood. ";
		system ("pause");
		cout << endl << endl;
	}
	else{
		error(name);
		goto AGAIN;
	}
}

void mainmenu(string& name) 
{ 
	string userInput, language;
	char a;
	
	START:
	cout << "[Bot]: What word or phrase in English would you want to translate to another language?" << endl << endl;
	cout << "[" + name + "]: ";
	cin.ignore();
	getline(cin, userInput);
	
	cout << endl;
	
	exit_program(name, userInput);		
	for (int i = 0; i < userInput.length(); i++){
		a = userInput.at(i);
			if (!((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a == ' ') || (a == '?') || (a == '\''))){
			    cin.clear();
				error2(name);
				goto START;
		    }
		}	
	
	if (userInput==""){
			error2(name);
			goto START;
		}
	
	ASKLANGUAGE:
	cout << "[Bot]: What language would you like to translate '" << userInput << "' into? Filipino or Chinese?" << endl << endl;
	cout << "[" + name + "]: ";
	cin >> language;
	cout << endl;
	
	exit_program(name, language);
	
	if ((language == "Filipino") || (language == "filipino") || (language == "FILIPINO") || (language == "F") || (language == "f")){
		mainfilipino(name, userInput);
		againFilipino(name);
		goto START;	
	}
	else if ((language == "Chinese") || (language == "chinese") || (language == "CHINESE" || (language == "C") || (language == "c"))){
		mainchinese(name, userInput);
		againChinese(name);
		goto START;
	}
	else{
		error(name);
		goto ASKLANGUAGE;
	}
}
