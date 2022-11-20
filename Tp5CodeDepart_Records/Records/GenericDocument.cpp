#include "GenericDocument.h"

// GenericDocument.cpp : � COMPL�TER

GenericDocument::GenericDocument(std::string name, std::string dateTime, std::string description)
	: AbsDocument(name, dateTime)
{
}

GenericDocument* GenericDocument::clone(void) const
{
	return new GenericDocument(*this);
}
