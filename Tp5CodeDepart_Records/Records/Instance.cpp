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
	// À compléter pour copier toutes les instances de niveau inférieur contenues dans l'instance
	for (InstanceComponentBaseIterator_const it = (mdd.m_instanceContainer).begin(); it != (mdd.m_instanceContainer).end(); it++) {
		addInstanceComponent(mdd);
	}

}

Instance* Instance::clone() const
{
	// À compléter pour construire un nouvel objet Instance en appelant le constructeur de copie

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
	// À compléter pour construire par clonage une copie de l'objet reçu en paramètre
	// et l'insérer dans le conteneur des instances. On retourne une référence à l'objet
	// qui vient d'être inséré dans le conteneur.
	auto a = std::unique_ptr<class AbsInstanceComponent>(member.clone());
	m_instanceContainer.push_back(a);

	return a; // erreur!
}

void Instance::deleteInstanceComponent(InstanceComponentIterator_const child)
{
	// À compléter pour éliminer des instances l'élément auquel réfère l'itérateur
}

void Instance::deleteAllComponents(void)
{
	// À compléter pour éliminer tous les éléments de l'instance
}

std::ostream& Instance::printToStream(std::ostream& o) const
{
	// À compléter pour imprimer sur un stream une instance et ses éléments
	return o;
}

