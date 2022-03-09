#include "learner.h"

using namespace std;
void goodbye(string& name);

void error(string& name){
	cout << "\n[Bot]: Unfortunately, IBot can't understand your answer, " + name + ". :( Please retry and follow the instructions. Thank you!" << endl << endl;
}

void error2(string& name){
	cout << "[Bot]: Unfortunately, IBot can't accept this input. :( Please retry and only input alphabetic characters, " + name + "."<< endl << endl;
}

void exit_program(string& name, string& userInput){
	if ((userInput=="X") || (userInput=="x")){
		goodbye(name);
	}
}
