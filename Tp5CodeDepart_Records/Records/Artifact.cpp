///////////////////////////////////////////////////////////
//  Artifact.cpp
//  Implementation of the Class Artifact
//  Created on:      2022-10-12
//  Based on previous material (2022-03-19)
///////////////////////////////////////////////////////////

#include "Artifact.h"

Artifact::Artifact(std::string name, const AbsDirectoryComponent& document)
	: AbsInstanceComponent(name), m_document(document)
{
}

Artifact* Artifact::clone() const
{
	// └ complÚter pour construire un nouvel objet Artifact en appelant le constructeur de copie
	return new Artifact(*this);
}

const AbsDirectoryComponent& Artifact::getDocument() const
{
	return m_document;
}

std::ostream& Artifact::printToStream(std::ostream& o) const
{
	// └ complÚter pour imprimer sur un stream le nom de l'artefact ainsi que le nom du document qui y est reference.
	o << "Artifact: " << getName() << "\n";
	o << "  --> Document: " << AbsInstanceComponent::getName() << "\n";
	return o;
}

