#include "Context.h"
#include "DateTime.h"
#include "User.h"
#include <string>
#include <ctime>
#include <random>
#include "Commit.h"

using namespace UGit;
using namespace UContext;
using namespace UDateTime;
using namespace UUser;
using namespace std;

struct UGit::Commit {
	UGit::Commit* parent;
	string message;
	string hashCode;
	UDateTime::DateTime* context;
	UUser::User* user;
};

//Funciones auxiliares
string CreateHashCode() {
	string hashCode;
	char chars[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9' };
	srand(time(NULL));
	while (hashCode.length() < 40) {
		hashCode += chars[rand() % 35];
	}
	return hashCode;
}

// Precondicion: Ninguna
// Postdondicion: Crea una instancia valida de un Commit el cual debe tener
// - Un commit predecesor (@parent) el cual puede ser NULL
// - Un mensaje (@message) que describe los objetivos de los cambios que se hicieron en el commit
// - Un HashCode que por ahora sera simplemente un codigo alfanumerico de 40 caracteres randoms, los caracteres deben estar en minusculas
// - Una fecha y hora actual del momento de creacion obtenida de Context.h
// - El usuario que se encuentra en el contexto de la operacion obtenido de Context.h
UGit::Commit* UGit::CreateCommit(Commit* parent, string message) {
	Commit* commit = new Commit;
	commit->parent = parent;
	commit->message = message;
	commit->hashCode = CreateHashCode();
	commit->context = UContext::GetNow();
	commit->user = UContext::GetCurrentUser();
	return commit;
}

// Precondicion: @commit es una intancia valida
// Postcondicion: Devuelve la fecha y hora de creacion del @commit
UDateTime::DateTime* UGit::GetDate(const Commit* commit) {
	return commit->context;
}

// Precondicion: @commit es una intancia valida
// Postcondicion: Devuelve el usuario autor del @commit
UUser::User* UGit::GetAuthor(const Commit* commit) {
	return commit->user;
}

// Precondicion: @commit es una intancia valida
// Postcondicion: Devuelve el mensaje asociado al @commit
string UGit::GetMessage(const Commit* commit) {
	return commit->message;
}
// Precondicion: @commit es una intancia valida
// Postcondicion: Devuelve el commit predecesor de @commit
Commit* UGit::GetParent(const Commit* commit) {
	return commit->parent;
}

// Precondicion: @commit es una intancia valida
// Postcondicion: Devuelve el hash code de @commit
string UGit::GetHashCode(const Commit* commit) {
	return commit->hashCode;
}

// Precondicion: @commit es una intancia valida
// Postcondicion: Devuelve los primero ocho caracteres del hash code de @commit
string UGit::GetShortHashCode(const Commit* commit) {//8
	return commit->hashCode.substr(0, 7);
}

// Precondicion: @commit es una intancia valida
// Postcondicion: Libera todos los recursos asociados de @commit
void UGit::DestroyCommit(Commit* commit) {
	if (commit->message != "") {
		delete commit;
		
	}
}
