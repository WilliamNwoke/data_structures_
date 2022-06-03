// p3x.cpp
// TODO: add functional documentation (and inline comments, as necessary)

#include "PatientPriorityQueuex.h"
#include "Patient.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string leftTrim(const string &);

string rightTrim(const string &);

void welcome();
// Prints welcome message.

void goodbye();
// Prints goodbye message.

void help();
// Prints help menu.

bool processLine(string, PatientPriorityQueue &);
// Process the line entered from the user or read from the file.

void addPatientCmd(string, PatientPriorityQueue &);
// Adds the patient to the waiting room.

void peekNextCmd(PatientPriorityQueue &);
// Displays the next patient in the waiting room that will be called.

void removePatientCmd(PatientPriorityQueue &);
// Removes a patient from the waiting room and displays the name on the screen.

void showPatientListCmd(PatientPriorityQueue &);
// Displays the list of patients in the waiting room.

void execCommandsFromFileCmd(string, PatientPriorityQueue &); 
// Reads a text file with each command on a separate line and executes the
// lines as if they were typed into the command prompt.

string delimitBySpace(string &);
// Delimits (by space) the string from user or file input.

void changePatientCmd(string line, PatientPriorityQueue &priQueue);

void savePatientCmd(string line, PatientPriorityQueue &priQueue);


int main() {
	// declare variables
	string line;

	// welcome message
	welcome();

	// process commands
	PatientPriorityQueue priQueue;
	do {
		cout << "\ntriage> ";
		getline(cin, line);
	} while (processLine(line, priQueue));

	// goodbye message
	goodbye();
}

string leftTrim(const string &str){
    int position = str.find_first_not_of(' ');
    if (position != string::npos)
        return str.substr(position);
    else
        return str;
}


string rightTrim(const string &str){
    int position = str.find_last_not_of(' ');
    if (position != string::npos)
        return str.substr(0, position +1);
    else
        return str;
}

bool processLine(string line, PatientPriorityQueue &priQueue) {
	// get command
	string cmd = delimitBySpace(line);
	if (cmd.length() == 0) {
		cout << "Error: no command given.";
		return false;
	}
	
	// process user input
	if (cmd == "help")
		help();
	else if (cmd == "add")
		addPatientCmd(line, priQueue);
	else if (cmd == "peek")
		peekNextCmd(priQueue);
	else if (cmd == "next")
		removePatientCmd(priQueue);
	else if (cmd == "list")
		showPatientListCmd(priQueue);
	else if (cmd == "load")
		execCommandsFromFileCmd(line, priQueue);
	else if (cmd == "quit")
		return false;
    else if (cmd == "change")
        changePatientCmd(line, priQueue);
    else if (cmd == "save")
        savePatientCmd(line, priQueue)
	else
		cout << "Error: unrecognized command: " << cmd << endl;

	return true;
}

void addPatientCmd(string line, PatientPriorityQueue &priQueue) { 
	string priority, name;


	// get priority and name
	priority = delimitBySpace(line);
	if (priority.length() == 0) {
		cout << "Error: no priority code given.\n";
		return;
	}
	name = line;
	if (name.length() == 0) {
		cout << "Error: no patient name given.\n";
		return;
	}

	// add logic to remove leading/trailing spaces
    name = rightTrim(leftTrim(name));
    priority = rightTrim(leftTrim(priority));

	// TODO: validate priority is between 1 and 4
    if (    priority != "immediate" &&
            priority != "emergency" &&
            priority != "urgent" &&
            priority != "minimal"
            ){
        cout << "Error: Invalid priority." << endl;
        return;
    }

	// add patient
    Patient newPatient(name, priority);
    priQueue.add(newPatient);
    cout << "Added patient \"";
    cout <<  newPatient.getName();
    cout << "\" to the priority System"
    << endl;
}

void peekNextCmd(PatientPriorityQueue &priQueue) {
	// REVIEW: shows next patient to be seen
    cout << "Highest priority patient to be called next: " <<
    priQueue.peek().getName() << endl;

}

void removePatientCmd(PatientPriorityQueue &priQueue) {
	// REVIEW: removes and shows next patient to be seen
    try {
        Patient next = priQueue.remove();
        cout << "This patient will now be seen: ";
        cout << next.getName() << endl;
    } catch(std::exception const &exc) {
        cout << "Nobody in queue." << endl;
    }
}

void showPatientListCmd(PatientPriorityQueue &priQueue) {
	cout << "# patients waiting: " << priQueue.size() << endl;
	cout << "  Arrival #   Priority Code   Patient Name\n"
		  << "+-----------+---------------+--------------+\n";
	// REVIEW: shows patient detail in heap order
    cout << priQueue.to_String() << endl;
}

void execCommandsFromFileCmd(string filename, PatientPriorityQueue &priQueue) {
	ifstream infile;
	string line;

	// open and read from file
	infile.open(filename);
	if (infile) {
		while (getline(infile, line)) {
			cout << "\ntriage> " << line;
			// process file input 
			processLine(line, priQueue);
		} 
	} else {
		cout << "Error: could not open file.\n";
	}
	// close file
	infile.close();
}

string delimitBySpace(string &s) {
    unsigned pos = 0;
    char delimiter = ' ';
    string result = "";

    pos = s.find(delimiter);
    if (pos != ((unsigned int)string::npos)) {
        result = s.substr(0, pos);
        s.erase(0, pos + 1);
    }
    return result;
}

void welcome() {
	cout << "Welcome to One stop Medicine\n";
}

void goodbye() {
	cout << "\nThanks for stopping by, we hope to never see you again";
}

void changePatientCmd(string line, PatientPriorityQueue &priQueue) {
    string arrivalIDStr, newPriority;

    // get priority and name
    arrivalIDStr = delimitBySpace(line);
    if (arrivalIDStr.length() == 0) {
        cout << "Error: no patient id provided." << endl;
        return;
    }
    newPriority = line;
    if (newPriority.length() == 0) {
        cout << "Error: no priority code given." << endl;
        return;
    }

    // trim whitespace from name and priority
    arrivalIDStr = rightTrim(leftTrim(arrivalIDStr));
    newPriority = rightTrim(leftTrim(newPriority));

    // determine if arrivalIDStr is an integer
    for (char &c : arrivalIDStr) {
        if (!isdigit(c)) {
            cout << "Error: invalid arrival code provided." << endl;
            return;
        }
    }
    // convert arrivalID to int
    int arrivalID = stoi(arrivalIDStr);

    // determine if priority is valid
    if (
            newPriority != "immediate" &&
            newPriority != "emergency" &&
            newPriority != "urgent"    &&
            newPriority != "minimal"
            )
    {
        cout << "Error: priority is invalid." << endl;
        return;
    }

    try {
        Patient newPatient = priQueue.change(arrivalID, newPriority);
        cout << "Chaned patient \"";
        cout << newPatient.getName();
        cout << "\"'s priority to ";
        cout << newPriority << endl;
    } catch (std::exception const &exc) {
        cout << "Error: no patient with the given id was found" << endl;
    }
}

void savePatientCmd(string line, PatientPriorityQueue &priQueue) {
    string fileName;

    // get priority and name
    fileName = delimitBySpace(line);
    if (fileName.length() == 0) {
        cout << "Error: no file name provided." << endl;
        return;
    }

    // create new vector to store the triage for saving
    vector<Patient> triage;

    // empty priQueue into triage vector
    while (!priQueue.empty()) {
        triage.push_back(priQueue.dequeue());
    }

    // sort the triage by arrival order
    sort(triage.begin(), triage.end(), compareArrivals);

    ofstream fileTriage;

    fileTriage.open(fileName);

    if (fileTriage) {
        for (auto & patient : triage) {
            fileTriage << "add ";
            fileTriage << patient.getPriorityCode() << " ";
            fileTriage << patient.getName() << "\n";
        }
    } else {
        // Filepath was invalid, exit application
        cout << "ERROR: cannot open/create patient triage file";
        return;
    }

    // Cleanup
    fileTriage.close();
}

void help() {
	cout << "add <priority-code> <patient-name>\n"
<< "            Adds the patient to the triage system.\n"
<< "            <priority-code> must be one of the 4 accepted priority codes:\n"
<< "                1. immediate 2. emergency 3. urgent 4. minimal\n"
<< "            <patient-name>: patient's full legal name (may contain spaces)\n"
<< "next        Announces the patient to be seen next. Takes into account the\n"
<< "            type of emergency and the patient's arrival order.\n"
<< "peek        Displays the patient that is next in line, but keeps in queue\n"
<< "change      change <arrival-id> <new-priority-code> changes the priority of the arrival order of the patient\n"
<< "list        Displays the list of all patients that are still waiting\n"
<< "            in the order that they have arrived.\n"
<< "load <file> Reads the file and executes the command on each line\n"
<< "help        Displays this menu\n"
<< "quit        Exits the program\n";
}
