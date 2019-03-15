#pragma once

#include <string>

inline std::string	Gen_GetDocOperatorEquals( const std::string& fullTypeName );
inline std::string	Gen_GetDocOperatorNotEquals( const std::string& fullTypeName );


std::string Gen_GetDocOperatorEquals( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns true if the all the components of the left-hand-side " + fullTypeName + " match the other one, otherwise returns false.\n";
}

std::string Gen_GetDocOperatorNotEquals( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns true if not all of the components of the left-hand-side " + fullTypeName + " match the other one, otherwise returns false.\n";
}