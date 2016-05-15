#include "HttpUrl.h"
#include "UrlParsingError.h"
#include <algorithm>

CHttpUrl::CHttpUrl(std::string const &domain, std::string const &document, Protocol protocol, unsigned short port)
{
    m_domain = domain;
    m_document = document;
    m_protocol = protocol;
    m_port = port;
}

bool CHttpUrl::IsProtocolInUrl(const std::string &protocol, const std::string &url) const
{
    return url.find(protocol) != std::string::npos;
}

bool CHttpUrl::IsNumber(const std::string &s)
{
    return !s.empty() && std::find_if(s.begin(),
                                      s.end(), [](char c)
                                      { return !std::isdigit(c); }) == s.end();
}

CHttpUrl::CHttpUrl(std::string const &url)
{
    const std::string http("http://");
    const std::string https("https://");
    unsigned long protocolPosition;

    std::string domain;
    std::string document;
    Protocol protocol;
    unsigned short port;

    if (IsProtocolInUrl(http, url))
    {
        protocolPosition = url.substr(0, http.size()).find_last_of(http);
        protocol = HTTP;
    }
    else if (IsProtocolInUrl(https, url))
    {
        protocolPosition = url.substr(0, https.size()).find_last_of(https);
        protocol = HTTPS;
    }
    else
    {
        throw CUrlParsingError(
                "You should pass a url with protocol at the beginning. For example: <https://www.amazon.com>");
    }


    std::string str = url.substr(protocolPosition);
    auto portPosition = str.find_first_of(":");

    if (portPosition == std::string::npos)
    {
        auto documentPosition = url.substr(protocolPosition).find_first_of("/");
        if (documentPosition != std::string::npos)
        {
            document = url.substr(documentPosition);
        }
        domain = url.substr(protocolPosition);
        CHttpUrl(domain, document, protocol);
    }
    else
    {
        auto positionOfDocument = url.substr(portPosition).find_first_of("/");

        std::string expectedPort = url.substr(portPosition, positionOfDocument - portPosition);

        if (!IsNumber(expectedPort))
        {
            throw CUrlParsingError("Unknown port");
        }
        port = static_cast<unsigned short>(atoi(url.substr(portPosition, positionOfDocument - portPosition).c_str()));
        std::cout << port << std::endl;
        if (positionOfDocument != std::string::npos)
        {
            document = url.substr(positionOfDocument);
        }
        CHttpUrl(domain, document, protocol, port);
    }
}

std::string CHttpUrl::GetDocument() const
{
    return m_document;
}

std::string CHttpUrl::GetURL() const
{
    return m_url;
}

std::string CHttpUrl::GetDomain() const
{
    return m_domain;
}

unsigned short CHttpUrl::GetPort() const
{
    return m_port;
}

Protocol CHttpUrl::GetProtocol() const
{
    return m_protocol;
}

