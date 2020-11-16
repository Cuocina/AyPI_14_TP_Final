#include "User.h"
using namespace UUser;

struct UUser::User {
	string nickName;
	string name;
	string lastName;
};

// Precondicion: Ninguna
// Postdondicion: Crea una instancia valida de un User el cual tiene como nick name @nickName y
// un string vacio como nombre y como apellido
UUser::User* UUser::CreateUser(string nickName) {
	User* newUser = new User;
	newUser->nickName = nickName;
	newUser->name = "";
	newUser->lastName = "";
	return newUser;
}

// Precondicion: @user es una instancia valida
// Postcondicion: Devuelve el nick name de @user
string UUser::GetNickName(const User* user) {
	return user->nickName;
}

// Precondicion: @user es una instancia valida
// Postcondicion: Devuelve el apellido de @user
string UUser::GetLastName(const User* user) {
	return user->lastName;
}


// Precondicion: @user es una instancia valida
// Postcondicion: Devuelve el nombre de @user
string UUser::GetName(const User* user) {
	return user->name;
}


// Precondicion: @user es una instancia valida
// Postcondicion: Cambia el nombre de @user por @name
void UUser::SetName(User* user, string name) {
	user->name = name;
}


// Precondicion: @user es una instancia valida
// Postcondicion: Cambia el apellido de @user por @apellido
void UUser::SetLastName(User* user, string lastName) {
	user->lastName = lastName;
}

// Precondicion: @user es una instancia valida
// Postcondicion: Libera todos los recursos asociados a @user
void UUser::DestroyUser(User* user) {
	delete user;
}
