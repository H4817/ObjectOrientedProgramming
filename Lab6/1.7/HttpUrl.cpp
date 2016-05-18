#include "HttpUrl.h"
#include "UrlParsingError.h"
#include <algorithm>
#include <stdlib.h>

CHttpUrl::CHttpUrl(std::string const &domain, std::string const &document, Protocol protocol, unsigned short port)
        : m_domain(domain), m_document(document), m_port(port)
{
}

void CHttpUrl::InitializePartsOfUrl(std::string const &domain, std::string const &document, Protocol protocol,
                                    unsigned short port)
{
    InitializePartsOfUrl(domain, document, protocol, port);
}

bool CHttpUrl::IsDomainCorrect(const std::string &domain) const
{
    return (domain.find_first_of(" \t") == std::string::npos);
}

void CHttpUrl::InitializePartsOfUrl(std::string const &domain, std::string const &document, Protocol protocol,
                                    unsigned short port)
{
    m_domain = domain;
<<<<<<< HEAD
    if (document != "")
    {
        m_document = document;
    }
    else
    {
        m_document = "/";
    }
=======
    m_document = document;
>>>>>>> 52b10b1396edbd753d06904d0c21f062e65c2cc4
    m_port = port;
    if (protocol == HTTP)
        m_protocol = "http";
    else
        m_protocol = "https";
    if (port == 80 || port == 443)
    {
        m_url = m_protocol + "://" + domain + document;
    }
    else
    {
        m_url = m_protocol + "://" + domain + ":" + std::to_string(port) + document;
    }
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
        auto positionOfDocument = str.substr(1).find_first_of("/");
        if (positionOfDocument != std::string::npos)
        {
            document = str.substr(positionOfDocument + 1);
        }
<<<<<<< HEAD
        if (IsDomainCorrect(str.substr(1, positionOfDocument)))
        {
            domain = str.substr(1, positionOfDocument);
        }
        else
        {
            throw CUrlParsingError("Domain can't contain a whitespaces");
        }

=======
        domain = str.substr(1, positionOfDocument);
>>>>>>> 52b10b1396edbd753d06904d0c21f062e65c2cc4
        if (protocol == HTTPS)
        {
            port = 443;
            InitializePartsOfUrl(domain, document, protocol, port);
        }
        else
        {
            InitializePartsOfUrl(domain, document, protocol);
        }
    }
    else
    {
        auto positionOfDocument = str.substr(1).find_first_of("/");
        std::string expectedPort = str.substr(portPosition + 1, positionOfDocument - portPosition);

        if (!IsNumber(expectedPort))
        {
            throw CUrlParsingError("Unknown port");
        }
        port = static_cast<unsigned short>(atoi(expectedPort.c_str()));
        if (positionOfDocument != std::string::npos)
        {
            document = str.substr(positionOfDocument + 1);
<<<<<<< HEAD
        }

        if (IsDomainCorrect(str.substr(1, portPosition - 1)))
        {
            domain = str.substr(1, portPosition - 1);
        }
        else
        {
            throw CUrlParsingError("Domain can't contain a whitespaces");
        }
=======
        }
        domain = str.substr(1, portPosition - 1);
>>>>>>> 52b10b1396edbd753d06904d0c21f062e65c2cc4
        InitializePartsOfUrl(domain, document, protocol, port);
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

std::string CHttpUrl::GetProtocol() const
{
    return m_protocol;
}
