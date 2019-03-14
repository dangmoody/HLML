#pragma once

#include <string>

inline std::string	Gen_GetDocCtorDefault( void );
inline std::string	Gen_GetDocCtorCopy( void );

inline std::string	Gen_GetDocOperatorEquals( const std::string& fullTypeName );
inline std::string	Gen_GetDocOperatorNotEquals( const std::string& fullTypeName );


std::string Gen_GetDocCtorDefault( void ) {
	return "\t/// Default constructor.  Initializes all values to zero.\n";
}

std::string Gen_GetDocCtorCopy( void ) {
	return "\t/// Copy constructor.  Copies the elements of the given vector via memcpy.\n";
}

std::string Gen_GetDocOperatorEquals( const std::string& fullTypeName ) {
	std::string doc;
	doc += "/// \\relates " + fullTypeName + "\n";
	doc += "/// \\brief Returns true if the all the components of the left-hand-side " + fullTypeName + " match the other one, otherwise returns false.\n";

	return doc;
}

std::string Gen_GetDocOperatorNotEquals( const std::string& fullTypeName ) {
	std::string doc;
	doc += "/// \\relates " + fullTypeName + "\n";
	doc += "/// \\brief Returns true if not all of the components of the left-hand-side " + fullTypeName + " match the other one, otherwise returns false.\n";

	return doc;
}