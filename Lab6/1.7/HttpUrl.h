#pragma once

#include <iostream>

enum Protocol
{
    HTTP,
    HTTPS
};

class CHttpUrl
{
public:
    CHttpUrl(std::string const &url);

    CHttpUrl(
            std::string const &domain,
            std::string const &document,
            Protocol protocol = HTTP,
            unsigned short port = 80);

    std::string GetURL() const;

    std::string GetDomain() const;

    std::string GetDocument() const;

    std::string GetProtocol() const;

    unsigned short GetPort() const;

private:
    void InitializePartsOfUrl(
            std::string const &domain,
            std::string const &document,
            Protocol protocol = HTTP,
            unsigned short port = 80);
    bool IsNumber(const std::string &s);
    bool IsProtocolInUrl(const std::string &protocol, const std::string &url) const;
    bool IsDomainCorrect(const std::string & domain) const;
    std::string m_url;
    std::string m_domain;
    std::string m_document;
    std::string m_protocol;
    unsigned short m_port;
};
