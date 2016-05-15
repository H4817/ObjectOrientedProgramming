#include "UrlParsingError.h"

CUrlParsingError::CUrlParsingError(std::string invalidArgument) try : std::invalid_argument(invalidArgument),
                                                                      m_invalidArgument(invalidArgument)
{

}

catch (std::exception const& e)
{
    std::cout << "Error: " << e.what() << std::endl;
}

catch (...)
{
    std::cout << "Unable to construct CUrlParsingError instance, unknown exception has been caught\n";
}
