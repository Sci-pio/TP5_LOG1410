#include <string>

#include "Minutes.h"

Minutes::Minutes(std::string name, std::string dateTime)
	: AbsDocument(name, dateTime)
{
}

Minutes* Minutes::clone(void) const
{
	// À compléter pour construire un nouvel objet Minutes en appelant le constructeur de copie
	// Kamil : dans le fond , supposons tu as un objet Minutes m1; on veut faire Minute* m2 = m1.clone();
	Minutes* m = new Minutes(this->m_name, getDateTime()); // c'est fort probablement de la grosse merde
							
	return m; 
}