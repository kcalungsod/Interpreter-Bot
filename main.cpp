#include "learner.h"

using namespace std;

void mainmenu(string& name);

void goodbye(string& name){

	cout << "[Bot]: Goodbye, " << name << "! I hope you've found our conversation pleasant. Have a nice day." << endl; 
	cout << "\t\t       _____________________\n";
	cout << "\t\t       | ___________________ |\n";
	cout << "\t\t       ||   _           _   ||\n";
	cout << "\t\t       ||  | |         | |  ||\n"; 
	cout << "\t\t       ||      _______      ||\n";  
	cout << "\t\t       ||     |_|_|_|_|     ||\n";
	cout << "\t\t       ||___________________||\n";
	cout << "\t\t       |_____________________|\n";
	cout << "\t\t              _|     |_\n";
	cout << "\t\t             |_________|\n";
	cout << "__________________________________________________________\n\n";
	
	cout << "[Bot]: ";
	system("pause");
	exit(0);
}

int main (){
	
	system ("title Interpreter Bot - IBot");
	
	string username;
	
	cout << "\t\t        _____________________\n";
	cout << "\t\t       | ___________________ |\n";
	cout << "\t\t       ||                   ||\n";
	cout << "\t\t       ||  [.]         [.]  ||\n";
	cout << "\t\t       ||                   ||\n";
	cout << "\t\t       ||     |_______|     ||\n";
	cout << "\t\t       ||___________________||\n";
	cout << "\t\t       |_____________________|\n";
	cout << "\t\t              _|     |_\n";
	cout << "\t\t             |_________|\n";
	cout << "_______________________________________________________________________\n\n";
	cout << "[Bot]: Hello, I am Interpreter Bot (IBot) - your English to Filipino and English to Chinese Mandarin translator! What's your name?" << endl << endl; 
	cout << "[User]: "; cin >> username; cout << endl;
	cout << "[Bot]: Hey, " << username <<". Here's a few quick reminders that you should take note of when replying to IBot. ";
	system ("pause");
	cout << endl;
	cout << "[Bot]: First, if you want to quit the conversation, just reply x or X to terminate to loop. This applies to every prompt for input from the program. ";
	system ("pause");
	cout << endl;
	cout << "[Bot]: Second, tone marks on pinyin - the romanization of Chinese characters - don't render well on Dev C++ console. Furthermore, the IDE itself doesn't support Chinese characters. ";
	cout << " All translations for English to Chinese are without tone marks and should be verified online for better understanding on how it's pronounced and written. ";
	system ("pause");
	cout << endl;
	cout << "[Bot]: Lastly, please be mindful when adding new words into the database! Added words and phrases by users are tagged as 'under validation' and therefore, should be taken with a grain of salt. ";
	system ("pause");
	cout << endl;
	cout << "[Bot]: With all of these in mind, let's get started! ";
	system ("pause");
	cout << endl; 

	mainmenu(username);
	return(0);
}
