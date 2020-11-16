#include "Context.h" 

using namespace UContext;
using namespace UUser;

UUser::User* uniqueInstance = UUser::CreateUser("nickname");

// Precondicion: Ninguna
// Postcondicion: Obtiene el usuario actual.
// Para la entrega actual debe crear un unico usuario
// y siempre debe devolver esa misma instancia de usuario
UUser::User* UContext::GetCurrentUser() {
	return uniqueInstance;
}

// Precondicion: Ninguna
// Postcondicion: Libera todos los recursos asociados al contexto
UDateTime::DateTime* UContext::GetNow() {
	return UDateTime::Now();
}

// Precondicion: Ninguna
// Postcondicion: Libera todos los recursos asociados al contexto
void UContext::DestroyContext() {
	if (uniqueInstance != NULL) {
		UUser::DestroyUser(uniqueInstance);
		uniqueInstance = NULL;
	}
}