/*
 * UserInterface.cpp
 *
 *  Created on: 05/04/2017
 *      Author: up201504570
 */

#include "UserInterface.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto



UserInterface::~UserInterface() {
	// TODO Auto-generated destructor stub
}



void gotoXY(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}


void UserInterface::writeStreetName(int i, vector<string> streetNames){

    if(i == 1)
        cout << setw(15) << " " << left << setw(30)<< streetNames[i] << setw(10) <<  " " << endl;
    else
        cout << setw(15) << " " << left << setw(30)<< streetNames[i] << setw(20) <<  " " << endl;
}


string UserInterface::chooseStreetName(){

    int menu_item = 0, x = 7;
    bool running = true;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    vector<string> streetNames = currentParking->getStreetNames();

    SetConsoleTextAttribute(console, 240);
    gotoXY(25, 7); writeStreetName(0,streetNames);

    SetConsoleTextAttribute(console, 15);
    for(int i = 1; i < streetNames.size(); i++){
        gotoXY(25, i+7);  writeStreetName(i,streetNames);
    }

    gotoXY(1,1);
    system("pause>nul");
    if(GetAsyncKeyState(VK_RETURN)) gotoXY(1,1);

    while(running){

        system("pause>nul");

        if (GetAsyncKeyState(VK_DOWN) && x < streetNames.size()+6) //down button pressed
        {
            gotoXY(25, x);SetConsoleTextAttribute(console, 15);
            writeStreetName(x-7,streetNames);
            x++;

            gotoXY(25, x); SetConsoleTextAttribute(console, 240);
            writeStreetName(x-7,streetNames);

            SetConsoleTextAttribute(console, 15);
            menu_item++;
            continue;

        }

        if (GetAsyncKeyState(VK_UP) && x > 7) //up button pressed
        {
            gotoXY(25, x); SetConsoleTextAttribute(console, 15);
            writeStreetName(x-7,streetNames);
            x--;

            gotoXY(25, x); SetConsoleTextAttribute(console, 240);
            writeStreetName(x-7,streetNames);

            SetConsoleTextAttribute(console, 15);
            menu_item--;
            continue;
        }

        if (GetAsyncKeyState(VK_RETURN))  // Enter key pressed
        {
        	return streetNames[x-7];
        }
    }
}

void UserInterface::writeNodes(int i, vector<Vertex *> streetNodes){

	cout << setw(9) << " " << left << setw(5)<< i<< setw(5) <<  " " << endl;
}


Vertex * UserInterface::chooseVertex(string street){

    int menu_item = 0, x = 7;
    bool running = true;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    vector<Vertex *> streetNodes = currentParking->getStreetNodes(street);

    SetConsoleTextAttribute(console, 240);
    gotoXY(50, 7); writeNodes(1,streetNodes);

    SetConsoleTextAttribute(console, 15);
    for(int i = 1; i < streetNodes.size(); i++){
        gotoXY(50, i+7);  writeNodes(i+1,streetNodes);
    }

    gotoXY(1,1);
    system("pause>nul");
    if(GetAsyncKeyState(VK_RETURN)) gotoXY(1,1);

    while(running){

        system("pause>nul");

        if (GetAsyncKeyState(VK_DOWN) && x < streetNodes.size()+6) //down button pressed
        {
            gotoXY(50, x);SetConsoleTextAttribute(console, 15);
            writeNodes(x-6,streetNodes);
            x++;

            gotoXY(50, x); SetConsoleTextAttribute(console, 240);
            writeNodes(x-6,streetNodes);

            SetConsoleTextAttribute(console, 15);
            menu_item++;
            continue;

        }

        if (GetAsyncKeyState(VK_UP) && x > 7) //up button pressed
        {
            gotoXY(50, x); SetConsoleTextAttribute(console, 15);
            writeNodes(x-6,streetNodes);
            x--;

            gotoXY(50, x); SetConsoleTextAttribute(console, 240);
            writeNodes(x-6,streetNodes);

            SetConsoleTextAttribute(console, 15);
            menu_item--;
            continue;
        }

        if (GetAsyncKeyState(VK_RETURN))  // Enter key pressed
        {
        	return streetNodes[x-7];
        }
    }
}


void UserInterface::writeDestiny(int i, vector<DestPlace *> destinations){

	cout << setw(11) << " " << left << setw(10)<< destinations.at(i)->getPlace() << setw(9) <<  " " << endl;
}


Vertex * UserInterface::chooseDestiny(){

    int menu_item = 0, x = 7;
    bool running = true;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    vector<DestPlace *> destinations= currentParking->getDestinations();

    SetConsoleTextAttribute(console, 240);
    gotoXY(45, 7); writeDestiny(0,destinations);

    SetConsoleTextAttribute(console, 15);
    for(int i = 1; i < destinations.size(); i++){
        gotoXY(45, i+7);  writeDestiny(i,destinations);
    }

    gotoXY(1,1);
    system("pause>nul");
    if(GetAsyncKeyState(VK_RETURN)) gotoXY(1,1);

    while(running){

        system("pause>nul");

        if (GetAsyncKeyState(VK_DOWN) && x < destinations.size()+6) //down button pressed
        {
            gotoXY(45, x);SetConsoleTextAttribute(console, 15);
            writeDestiny(x-7,destinations);
            x++;

            gotoXY(45, x); SetConsoleTextAttribute(console, 240);
            writeDestiny(x-7,destinations);

            SetConsoleTextAttribute(console, 15);
            menu_item++;
            continue;

        }

        if (GetAsyncKeyState(VK_UP) && x > 7) //up button pressed
        {
            gotoXY(45, x); SetConsoleTextAttribute(console, 15);
            writeDestiny(x-7,destinations);
            x--;

            gotoXY(45, x); SetConsoleTextAttribute(console, 240);
            writeDestiny(x-7,destinations);

            SetConsoleTextAttribute(console, 15);
            menu_item--;
            continue;
        }

        if (GetAsyncKeyState(VK_RETURN))  // Enter key pressed
        {
        	return destinations.at(x-7)->getNode();
        }
    }
}

void UserInterface::writePreference(int i){

	if(i == 0)
		cout << "          Nearest  car park                                     " << endl;
	else
		cout << "          Cheapest car park within a maximum distances          " << endl;
}


int UserInterface::choosePreference(){

    int menu_item = 0, x = 7;
    bool running = true;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console, 240);
    gotoXY(30, 7); writePreference(0);

    SetConsoleTextAttribute(console, 15);
    gotoXY(30, 8); writePreference(1);


    gotoXY(1,1);
    system("pause>nul");
    if(GetAsyncKeyState(VK_RETURN)) gotoXY(1,1);

    while(running){

        system("pause>nul");

        if (GetAsyncKeyState(VK_DOWN) && x < 8) //down button pressed
        {
            gotoXY(30, x);SetConsoleTextAttribute(console, 15);
            writePreference(x-7);
            x++;

            gotoXY(30, x); SetConsoleTextAttribute(console, 240);
            writePreference(x-7);

            SetConsoleTextAttribute(console, 15);
            menu_item++;
            continue;

        }

        if (GetAsyncKeyState(VK_UP) && x > 7) //up button pressed
        {
            gotoXY(30, x); SetConsoleTextAttribute(console, 15);
            writePreference(x-7);
            x--;

            gotoXY(30, x); SetConsoleTextAttribute(console, 240);
            writePreference(x-7);

            SetConsoleTextAttribute(console, 15);
            menu_item--;
            continue;
        }

        if (GetAsyncKeyState(VK_RETURN))  // Enter key pressed
        	return x-7;
    }
}


void UserInterface::writeMaxDistance(int i){

	switch(i){
	case 0:
		cout << "      50m       " << endl;
		break;
	case 1:
		cout << "      100m      " << endl;
		break;
	case 2:
		cout << "      200m      " << endl;
		break;
	case 3:
		cout << "      300m      " << endl;
		break;
	case 4:
		cout << "      400m      " << endl;
		break;
	}
}


int UserInterface::chooseMaxDistance(){

    int menu_item = 0, x = 7;
    bool running = true;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console, 240);
    gotoXY(50, 7); writeMaxDistance(0);

    SetConsoleTextAttribute(console, 15);
    gotoXY(50, 8); writeMaxDistance(1);
    gotoXY(50, 9); writeMaxDistance(2);
    gotoXY(50, 10); writeMaxDistance(3);
    gotoXY(50, 11); writeMaxDistance(4);

    gotoXY(1,1);
    system("pause>nul");
    if(GetAsyncKeyState(VK_RETURN)) gotoXY(1,1);

    while(running){

        system("pause>nul");

        if (GetAsyncKeyState(VK_DOWN) && x < 11) //down button pressed
        {
            gotoXY(50, x);SetConsoleTextAttribute(console, 15);
            writeMaxDistance(x-7);
            x++;

            gotoXY(50, x); SetConsoleTextAttribute(console, 240);
            writeMaxDistance(x-7);

            SetConsoleTextAttribute(console, 15);
            menu_item++;
            continue;

        }

        if (GetAsyncKeyState(VK_UP) && x > 7) //up button pressed
        {
            gotoXY(50, x); SetConsoleTextAttribute(console, 15);
            writeMaxDistance(x-7);
            x--;

            gotoXY(50, x); SetConsoleTextAttribute(console, 240);
            writeMaxDistance(x-7);

            SetConsoleTextAttribute(console, 15);
            menu_item--;
            continue;
        }

        if (GetAsyncKeyState(VK_RETURN))  // Enter key pressed
        {
        	switch(x-7){
        	case 0 :
        		return 50;
        	case 1 :
        		return 100;
        	case 2 :
        		return 200;
        	case 3 :
        		return 300;
        	case 4 :
        		return 400;
        	}
        }
    }
}


void UserInterface::writeGasoline(int i){

	if(i == 0)
		cout << "      Yes     " << endl;
	else
		cout << "      No      " << endl;
}


bool UserInterface::wantGasoline(){

    int menu_item = 0, x = 7;
    bool running = true;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console, 240);
    gotoXY(50, 7); writeGasoline(0);

    SetConsoleTextAttribute(console, 15);
    gotoXY(50, 8); writeGasoline(1);


    gotoXY(1,1);
    system("pause>nul");
    if(GetAsyncKeyState(VK_RETURN)) gotoXY(1,1);

    while(running){

        system("pause>nul");

        if (GetAsyncKeyState(VK_DOWN) && x < 8) //down button pressed
        {
            gotoXY(50, x);SetConsoleTextAttribute(console, 15);
            writeGasoline(x-7);
            x++;

            gotoXY(50, x); SetConsoleTextAttribute(console, 240);
            writeGasoline(x-7);

            SetConsoleTextAttribute(console, 15);
            menu_item++;
            continue;

        }

        if (GetAsyncKeyState(VK_UP) && x > 7) //up button pressed
        {
            gotoXY(50, x); SetConsoleTextAttribute(console, 15);
            writeGasoline(x-7);
            x--;

            gotoXY(50, x); SetConsoleTextAttribute(console, 240);
            writeGasoline(x-7);

            SetConsoleTextAttribute(console, 15);
            menu_item--;
            continue;
        }

        if (GetAsyncKeyState(VK_RETURN))  // Enter key pressed
        {	if(x-7 == 0)
        		return true;
        	else return false;
        }
    }
}

void UserInterface::writeInterest(int i){

	if(i == 0)
		cout << "       Name of the road       " << endl;
	else
		cout << "       Interest point         " << endl;
}

int UserInterface::chooseInterest(){

    int menu_item = 0, x = 7;
    bool running = true;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console, 240);
    gotoXY(43, 7); writeInterest(0);

    SetConsoleTextAttribute(console, 15);
    gotoXY(43, 8); writeInterest(1);


    gotoXY(1,1);
    system("pause>nul");
    if(GetAsyncKeyState(VK_RETURN)) gotoXY(1,1);

    while(running){

        system("pause>nul");

        if (GetAsyncKeyState(VK_DOWN) && x < 8) //down button pressed
        {
            gotoXY(43, x);SetConsoleTextAttribute(console, 15);
            writeInterest(x-7);
            x++;

            gotoXY(43, x); SetConsoleTextAttribute(console, 240);
            writeInterest(x-7);

            SetConsoleTextAttribute(console, 15);
            menu_item++;
            continue;

        }

        if (GetAsyncKeyState(VK_UP) && x > 7) //up button pressed
        {
            gotoXY(43, x); SetConsoleTextAttribute(console, 15);
            writeInterest(x-7);
            x--;

            gotoXY(43, x); SetConsoleTextAttribute(console, 240);
            writeInterest(x-7);

            SetConsoleTextAttribute(console, 15);
            menu_item--;
            continue;
        }

        if (GetAsyncKeyState(VK_RETURN))  // Enter key pressed
        	return x-7;
    }
}


void UserInterface::writeSearchType(int i){

	if(i == 0)
		cout << "       String Matching                     " << endl;
	else
		cout << "       Approximate String Matching         " << endl;
}

int UserInterface::chooseSearchType(){

    int menu_item = 0, x = 7;
    bool running = true;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console, 240);
    gotoXY(40, 7); writeSearchType(0);

    SetConsoleTextAttribute(console, 15);
    gotoXY(40, 8); writeSearchType(1);


    gotoXY(1,1);
    system("pause>nul");
    if(GetAsyncKeyState(VK_RETURN)) gotoXY(1,1);

    while(running){

        system("pause>nul");

        if (GetAsyncKeyState(VK_DOWN) && x < 8) //down button pressed
        {
            gotoXY(40, x);SetConsoleTextAttribute(console, 15);
            writeSearchType(x-7);
            x++;

            gotoXY(40, x); SetConsoleTextAttribute(console, 240);
            writeSearchType(x-7);

            SetConsoleTextAttribute(console, 15);
            menu_item++;
            continue;

        }

        if (GetAsyncKeyState(VK_UP) && x > 7) //up button pressed
        {
            gotoXY(40, x); SetConsoleTextAttribute(console, 15);
            writeSearchType(x-7);
            x--;

            gotoXY(40, x); SetConsoleTextAttribute(console, 240);
            writeSearchType(x-7);

            SetConsoleTextAttribute(console, 15);
            menu_item--;
            continue;
        }

        if (GetAsyncKeyState(VK_RETURN))  // Enter key pressed
        	return x-7;
    }
}



string UserInterface::insertStreetName(){

	string str;

	gotoXY(42, 7); cout << "Street Name : ";
	//cin >> str;
	getline(cin, str);
	/*
	vector<string> result = currentParking->ApproximateStringMatching(str);
	if(result.size() == 0) cout << "vetor vazio :(\n";
	cout << endl;
	cout << "tamanho do vetor: " << result.size() << endl << endl;
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
		cout << "i = " << i << endl << endl;
	}
	*/
	return str;
}

string UserInterface::insertDistrictName(){

	string str;

	gotoXY(42, 7); cout << "District Name : ";
	cin >> str;
	//getline(cin, str);

	return str;
}

bool UserInterface::strMatchingDistrict(){

	clearScreen();
	gotoXY(45,4); cout << "|| Insert the district name ||" << endl;
	string str  = insertDistrictName();
	cout << "\no inputo do utilizador foi: " << str <<"\n\n";
	clearScreen();


	//gotoXY(45,4); cout << "|| String Matching ||" << endl;

	string result  =  stringMatchingDistrict(str);


	if(result == "")return false;


	//currentParking = new Parking(result);

	currentParking = new Parking(result);




	return true;


}

Vertex * UserInterface::strMatching(){

	clearScreen();
	gotoXY(45,4); cout << "|| Insert the street name ||" << endl;
	string str  = insertStreetName();
	clearScreen();


	//gotoXY(45,4); cout << "|| String Matching ||" << endl;

	string result  =  currentParking->stringMatchingRoads(str);
	Vertex * dst;

	if(result == ""){
		dst = NULL;
	}
	else {

		normalize2(str);
		currentParking->toogleStreetNodes(str,"orange");

		clearScreen();

		gotoXY(28,4); cout << "|| From the orange dots choose the closest to your position ||" << endl;
		dst = chooseVertex(result);
		clearScreen();
	}

	return dst;

}


Vertex * UserInterface::aproxStrMatching(){

	clearScreen();
	gotoXY(45,4); cout << "|| Insert the street name ||" << endl;
	string str  = insertStreetName();
	clearScreen();


	gotoXY(33,4); cout << "|| Approximate String Matching ||" << endl;
	vector<string> result = currentParking->ApproximateStringMatching(str);
	Vertex * dst;

	if(result.size() == 1){ // perfect match


		currentParking->toogleStreetNodes(str,"orange");
		clearScreen();

		gotoXY(28,4); cout << "|| From the orange dots choose the closest to your position ||" << endl;
		dst = chooseVertex(result.at(0));
		clearScreen();
	}
	else {

		clearScreen();
		gotoXY(40,4); cout << "|| Maybe you are looking for one of those ||" << endl;
		string street = chooseAproxStreetName(result);

		currentParking->toogleStreetNodes(street,"orange");
		clearScreen();

		gotoXY(28,4); cout << "|| From the orange dots choose the closest to your position ||" << endl;
		dst = chooseVertex(street);
		clearScreen();
	}

	return dst;
}




void UserInterface::writeAproxStreetName(int i, vector<string> streetNames){

    if(streetNames[i] == "Adams Street Brooklyn Bridge Boulevard")
        cout << setw(15) << " " << left << setw(30)<< streetNames[i] << setw(12) <<  " " << endl;
    else
        cout << setw(15) << " " << left << setw(30)<< streetNames[i] << setw(20) <<  " " << endl;
}


string UserInterface::chooseAproxStreetName(vector<string> streetNames){

    int menu_item = 0, x = 7;
    bool running = true;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console, 240);
    gotoXY(30, 7); writeAproxStreetName(0,streetNames);

    SetConsoleTextAttribute(console, 15);
    for(int i = 1; i < streetNames.size(); i++){
        gotoXY(30, i+7);  writeAproxStreetName(i,streetNames);
    }

    gotoXY(1,1);
    system("pause>nul");
    if(GetAsyncKeyState(VK_RETURN)) gotoXY(1,1);

    while(running){

        system("pause>nul");

        if (GetAsyncKeyState(VK_DOWN) && x < streetNames.size()+6) //down button pressed
        {
            gotoXY(30, x);SetConsoleTextAttribute(console, 15);
            writeAproxStreetName(x-7,streetNames);
            x++;

            gotoXY(30, x); SetConsoleTextAttribute(console, 240);
            writeAproxStreetName(x-7,streetNames);

            SetConsoleTextAttribute(console, 15);
            menu_item++;
            continue;
        }

        if (GetAsyncKeyState(VK_UP) && x > 7) //up button pressed
        {
            gotoXY(30, x); SetConsoleTextAttribute(console, 15);
            writeAproxStreetName(x-7,streetNames);
            x--;

            gotoXY(30, x); SetConsoleTextAttribute(console, 240);
            writeAproxStreetName(x-7,streetNames);

            SetConsoleTextAttribute(console, 15);
            menu_item--;
            continue;
        }

        if (GetAsyncKeyState(VK_RETURN))  // Enter key pressed
        {
        	return streetNames[x-7];
        }
    }
}

void UserInterface::start(){


	while(!strMatchingDistrict()){

		gotoXY(45,4); cout << "|| Insert the street name ||" << endl;
		gotoXY(36,8); cout << "This district does not exist, please insert again";
		system("pause>nul");
	}




	while(1){


		currentParking->createGraphViewer();

		currentParking->readParks();
		currentParking->readDestinations();
		currentParking->readGasPumps();
		currentParking->getGraphViewer()->rearrange();

		clearScreen();
		SetConsoleTextAttribute(console, 15);

		gotoXY(45,6); cout << " || PARKING SA || ";
		gotoXY(40,10); cout << "PRESS ENTER TO CALCULATE ROUTE" << endl;
		pauseScreen();
		clearScreen();

		gotoXY(37,4); cout << "|| Please choose the street your in ||" << endl;
		string street  = chooseStreetName();
		currentParking->toogleStreetNodes(street,"green");
		clearScreen();

		gotoXY(28,4); cout << "|| From the green dots choose the closest to your position ||" << endl;
		Vertex * src = chooseVertex(street);
		clearScreen();

		gotoXY(45,4); cout << "|| What is your interest ||" << endl; // turning point
		int interest = chooseInterest();
		clearScreen();


		Vertex * dst;


		/*
		 * Segunda parte
		 */
		if(interest == 0) {

			gotoXY(45,4); cout << "|| Choose the type of search ||" << endl;
			int type = chooseSearchType();

			if(type == 0) {  // pesquisa exata

				Vertex * aux = strMatching();
				clearScreen();

				while(aux == NULL){

					gotoXY(45,4); cout << "|| Insert the street name ||" << endl;
					gotoXY(36,8); cout << "This road does not exist, please insert again";
					system("pause>nul");
					aux = strMatching();
				}

				dst = aux;
			}
			else {

				dst = aproxStrMatching();
			}

		}


		/*
		 * Primeira Parte
		 */
		else {
			gotoXY(45,4); cout << "|| Where do you want to go? ||" << endl;
			Vertex * dst = chooseDestiny();
			clearScreen();
		}



		/*
		 * Common part
		 */

		gotoXY(52,4); cout << "|| Park Option ||" << endl;
		int pref = choosePreference();
		clearScreen();

		gotoXY(35,4); cout << "|| Do you want to pass by a Gasoline Bump? ||" << endl;
		bool gasBump = wantGasoline();
		clearScreen();

		ParkType * car_park;

		switch(pref){
		case 0:
			if(gasBump)
				car_park = currentParking->planGasPumpShortPath(src,dst);
			else
				car_park = currentParking->planDirectShortPath(src, dst);

			if(car_park != NULL) displayRouteInformation(src,dst,car_park);
			break;
		case 1:

			gotoXY(30,4); cout << "|| Max distance between the Car Park and your Destination ||"  << endl;
			long max_distance = chooseMaxDistance();
			clearScreen();


			if(gasBump)
				car_park = currentParking->planGasPumpCheapestPath(src,dst, max_distance);
			else
				car_park = currentParking->planDirectCheapestPath(src,dst, max_distance);


			if(car_park != NULL) displayRouteInformation(src,dst,car_park);
			break;
		}

		system("pause>nul");

		if(GetAsyncKeyState (VK_ESCAPE))
			exit(1);

		currentParking->getGraphViewer()->closeWindow();

	}
}


void UserInterface::displayRouteInformation(Vertex * src, Vertex * dst, ParkType * park)const {

	vector<Vertex *> pathToPark = currentParking->getGraph().getPath(src, park->getNode());

	currentParking->drawPath(pathToPark, "red");


	gotoXY(45,4); cout << "|| Parking Information ||" << endl;

	gotoXY(1,6); cout << "----------------------------------------------------------------------------------------------------------------------" << endl;

	gotoXY(20,8); cout << "                     Total Distance : "
						<< dst->getDist() << " m   ( "<< park->getNode()->getDist()
						<< " by car and " << dst->getDist() - park->getNode()->getDist()
						<< " by foot )" << endl;

	gotoXY(20,9); cout << "                       Type of Park : ";
	if(park->getType() == "meter") {
		cout << "Parking meter\n";
	} else
		cout << "Garage\n";

	gotoXY(20,10);cout << "                              Price : " << park->getPrice() << " euros/h\n";

	gotoXY(1,12); cout << "----------------------------------------------------------------------------------------------------------------------" << endl;


}

string UserInterface::stringMatchingDistrict (string input) {
	normalize(input);
	if(kmp("BROOKLYN", input))
		return "Brooklyn";

	if(kmp("MANHATTAN", input))
		return "Manhattan";


	return "";
}
