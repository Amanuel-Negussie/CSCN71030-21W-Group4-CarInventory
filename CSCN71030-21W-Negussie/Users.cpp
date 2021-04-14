#include "Users.h"

char* userArray[MAX_USERS][MAX_PARAMS];

int userCount = 0;


Users::Users()
{
	strcpy_s(this->username, MAX_LEN, "");
	strcpy_s(this->password, MAX_LEN, "");
	strcpy_s(this->userid, MAX_LEN, "");
	
	this->type = UNSET;

}

void Users::displayUser()
{
	cout << "\nUsername: " << this->username << "\nUserId: " << this->userid << "\nUser Type: " << this->type << endl;
}

void Users::changeUsername(char name[MAX_LEN])
{
	strcpy_s(this->username, MAX_LEN, name);
	
}

void Users::changePassword(char password[MAX_LEN])
{
	strcpy_s(this->password, MAX_LEN, password);
}

void Users::changeUserId(char ID[MAX_LEN])
{
	strcpy_s(this->userid, MAX_LEN, ID);
}

void Users::addArray()
{
	if (userCount < MAX_USERS)
	{
		userArray[userCount][0] = this->username;
		userArray[userCount][1] = this->password;

		userCount++;
	}
}

void Users::save(ofstream& out) {

	SAVE(this, sizeof(*this), out);

}

void Users::load(ifstream& in) {

	LOAD(this, sizeof(*this), in);

}



Admin::Admin()
{
	strcpy_s(this->username, MAX_LEN, "");
	strcpy_s(this->password, MAX_LEN, "");
	strcpy_s(this->userid, MAX_LEN, "");
	
	this->type = ADM;
}

Admin::Admin(char user[MAX_LEN], char pass[MAX_LEN], char id[MAX_LEN])
{
	strcpy_s(this->username, MAX_LEN, user);
	strcpy_s(this->password, MAX_LEN, pass);
	strcpy_s(this->userid, MAX_LEN, id);
	
	this->type = ADM;

	addArray();
}

void Admin::displayAdmin()
{
	cout << "\nUsername: " << this->username << "\nUserId: " << this->userid << "\nUser Type: " << this->type << endl;
}




Manager::Manager()
{
	strcpy_s(this->username, MAX_LEN, "");
	strcpy_s(this->password, MAX_LEN, "");
	strcpy_s(this->userid, MAX_LEN, "");
	
	this->type = MNG;
}

Manager::Manager(char user[MAX_LEN], char pass[MAX_LEN], char id[MAX_LEN])
{
	strcpy_s(this->username, MAX_LEN, user);
	strcpy_s(this->password, MAX_LEN, pass);
	strcpy_s(this->userid, MAX_LEN, id);

	this->type = MNG;

	
	addArray();
}


SalesRep::SalesRep()
{
	strcpy_s(this->username, MAX_LEN, "");
	strcpy_s(this->password, MAX_LEN, "");
	strcpy_s(this->userid, MAX_LEN, "");
	
	this->type = SAL;
}

SalesRep::SalesRep(char user[MAX_LEN], char pass[MAX_LEN], char id[MAX_LEN])
{
	strcpy_s(this->username, MAX_LEN, user);
	strcpy_s(this->password, MAX_LEN, pass);
	strcpy_s(this->userid, MAX_LEN, id);
	
	this->type = SAL;

	addArray();
}




void initializeElementsUserArray()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			userArray[i][j] = NULL;
		}
	}
}

void displayArray()
{
	cout << "\n" << endl;
	bool isTrue = false;
	for (int i = 0; i < MAX_USERS, !isTrue; i++)
	{
		
		if (userArray[i][0] != NULL)
		{
			cout << "Username: " << userArray[i][0] << endl;

			cout << "Password: " << userArray[i][1] << endl;
		}
		else
			isTrue = true;
		

		cout << "\n" << endl;
	}
}




bool verifyCredentials(char username[MAX_LEN], char password[MAX_LEN])
{


	for (int i = 0; i < MAX_USERS; i++)
	{
		if (userArray[i][0] == NULL)
		{
			return false;
		}
		else
		{
			int retUsername = strcmp(userArray[i][0], username);
			int retPassword = strcmp(userArray[i][1], password);

			if (retUsername == 0 && retPassword == 0)
			{
				return true;
			}
		}

	}

	return false;
}


//void saveArray()
//{
//	
//	ofstream fp("2DArray.txt");
//	for (int i = 0; i < MAX_USERS; i++)
//	{
//		for (int j = 0; j < MAX_LEN; j++)
//		{
//			fp.write(reinterpret_cast<char*>(addressOfObject), sizeOfClass);
//		}
//	}
//	
//
//	
//
//	fp.close();
//
//}
//
//void loadArray()
//{
//	ifstream fp("2DArray.txt");
//	fp.read(reinterpret_cast<char*>(&userArray), 20*sizeof(char));
//	fp.close();
//}


