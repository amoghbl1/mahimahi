/* -*-mode:c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include <string>

#include "config.h"

#ifndef APACHE_CONFIGURATION_HH
#define APACHE_CONFIGURATION_HH

const std::string apache_main_config = "LoadModule mpm_prefork_module " + std::string( MOD_MPM_PREFORK ) + "\nLoadModule authz_core_module " + std::string( MOD_AUTHZ_CORE ) + "\nMutex pthread\nLoadFile " + std::string( MOD_DEEPCGI ) + "\nLoadModule deepcgi_module " + std::string( MOD_DEEPCGI ) +
    "\nLoadModule log_config_module modules/mod_log_config.so" +
    "\nLoadModule unixd_module modules/mod_unixd.so" +
    "\nLoadModule access_compat_module modules/mod_access_compat.so" +
    "\nSetHandler deepcgi-handler\n";

const std::string apache_ssl_config = "LoadModule ssl_module " + std::string( MOD_SSL ) + "\nSSLEngine on\nSSLCertificateFile      " + std::string( MOD_SSL_CERTIFICATE_FILE ) + "\nSSLCertificateKeyFile " + std::string( MOD_SSL_KEY ) +"\n";

#endif /* APACHE_CONFIGURATION_HH */
