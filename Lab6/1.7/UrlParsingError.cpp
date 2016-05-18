#include "UrlParsingError.h"

CUrlParsingError::CUrlParsingError(std::string invalidArgument) : std::invalid_argument(invalidArgument)
{

}
