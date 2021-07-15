#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User newUser) {
    CMarkup xml;

    bool fileExists = xml.Load( USERS_FILE_NAME );

    if(!fileExists) {
        xml.AddElem( "USERSLIST" );
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "USER" );
    xml.IntoElem();
    xml.AddElem( "ID", newUser.getUserId() );
    xml.AddElem( "NAME", newUser.getName() );
    xml.AddElem( "SURNAME", newUser.getSurname() );
    xml.AddElem( "LOGIN", newUser.getLogin() );
    xml.AddElem( "PASSWORD", newUser.getPassword() );

    xml.Save("Users.xml");
}

vector <User> FileWithUsers::loadUsersFromFile() {
    User user;
    int id = 0;
    string idNumber = "";
    string name = "";
    string surname = "";
    string login = "";
    string password = "";
    vector <User> users;
    CMarkup xml;

    bool fileExists = xml.Load( USERS_FILE_NAME );

    if(!fileExists) {
        cout << "No user registered." << endl;
    }
        xml.FindElem(); // root USERSLIST element
        xml.IntoElem(); // inside USERSLIST
        while ( xml.FindElem( "USER" ) ) {
            xml.IntoElem();
            //Pobiera i ustawia id
            xml.FindElem( "ID" );
            idNumber = xml.GetData();
            id = AuxiliaryMethods::convertStringToInt(idNumber);
            user.setUserId(id);
            xml.OutOfElem();
            xml.IntoElem();
            //Pobiera i ustawia imię
            xml.FindElem( "NAME" );
            name = xml.GetData();
            user.setName(name);
            xml.OutOfElem();
            xml.IntoElem();
            //Pobiera i ustawia nazwisko
            xml.FindElem( "SURNAME" );
            surname = xml.GetData();
            user.setSurname(surname);
            xml.OutOfElem();
            xml.IntoElem();
            //Pobiera i ustawia login
            xml.FindElem( "LOGIN" );
            login = xml.GetData();
            user.setLogin(login);
            xml.OutOfElem();
            xml.IntoElem();
            //Pobiera i ustawia hasło
            xml.FindElem( "PASSWORD" );
            password = xml.GetData();
            user.setPassword(password);
            xml.OutOfElem();
            //Zapisuje użytkownika do wektora
            users.push_back(user);
        }

    return users;
}

void FileWithUsers::changePasswordInFile(int activeUserId, string newPassword)
{
    string idNumber = "";
    int id = 0;
    CMarkup xml;

    bool fileExists = xml.Load( USERS_FILE_NAME );

    if(!fileExists) {
        cout << "No user registered." << endl;
    }
        xml.FindElem(); // root USERSLIST element
        xml.IntoElem(); // inside USERSLIST
        while ( xml.FindElem( "USER" ) ) {
            xml.IntoElem();
            xml.FindElem( "ID" );
            idNumber = xml.GetData();
            id = AuxiliaryMethods::convertStringToInt(idNumber);
            if(id == activeUserId)
            {
            xml.FindElem( "PASSWORD" );
            xml.RemoveElem();
            xml.AddElem( "PASSWORD", newPassword );
            }
            xml.OutOfElem();
        }

    xml.Save("Users.xml");
}
