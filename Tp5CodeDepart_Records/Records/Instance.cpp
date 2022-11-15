///////////////////////////////////////////////////////////
//  Instance.cpp
//  Implementation of the Class Instance
//  Created on:      2022-10-14
//  Based on previous material (2022-03-19)
///////////////////////////////////////////////////////////

#include "Instance.h"
#include <memory>

Instance::Instance(std::string name)
    : AbsInstanceComponent(name)
{
}
// Instance a(b); // avec b qui est deja une Instance
Instance::Instance(const Instance& mdd)
	: AbsInstanceComponent(mdd.getName())
{
	// � compl�ter pour copier toutes les instances de niveau inf�rieur contenues dans l'instance
	for (InstanceComponentBaseIterator_const it = (mdd.m_instanceContainer).begin(); it != (mdd.m_instanceContainer).end(); it++) {
		addInstanceComponent(mdd);
	}

}

Instance* Instance::clone() const
{
	// � compl�ter pour construire un nouvel objet Instance en appelant le constructeur de copie

	return new Instance(*this); 
}


InstanceComponentIterator Instance::begin() {

	return m_instanceContainer.begin();
}


InstanceComponentIterator_const Instance::cbegin() const {

	return m_instanceContainer.cbegin();
}


InstanceComponentIterator_const Instance::cend() const
{
	return m_instanceContainer.cend();
}

InstanceComponentIterator Instance::end()
{
	return  m_instanceContainer.end();
}

AbsInstanceComponent& Instance::addInstanceComponent(const AbsInstanceComponent& member)
{
	// � compl�ter pour construire par clonage une copie de l'objet re�u en param�tre
	// et l'ins�rer dans le conteneur des instances. On retourne une r�f�rence � l'objet
	// qui vient d'�tre ins�r� dans le conteneur.
	auto a = std::unique_ptr<class AbsInstanceComponent>(member.clone());
	m_instanceContainer.push_back(a);

	return a; // erreur!
}

void Instance::deleteInstanceComponent(InstanceComponentIterator_const child)
{
	// � compl�ter pour �liminer des instances l'�l�ment auquel r�f�re l'it�rateur
}

void Instance::deleteAllComponents(void)
{
	// � compl�ter pour �liminer tous les �l�ments de l'instance
}

std::ostream& Instance::printToStream(std::ostream& o) const
{
	// � compl�ter pour imprimer sur un stream une instance et ses �l�ments
	return o;
}

