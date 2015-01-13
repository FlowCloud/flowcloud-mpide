/****************************************************************************
 Copyright (c) 2014, Imagination Technologies Limited
 All rights reserved.

 Redistribution and use of the Software in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

     1. The Software (including after any modifications that you make to it) must support the FlowCloud Web Service API provided by Licensor and accessible at  http://ws-uat.flowworld.com and/or some other location(s) that we specify.

     2. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

     3. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

     4. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this Software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

#ifndef _FLOW_CERT_INCLUDED
#define _FLOW_CERT_INCLUDED

#include <stdint.h>

/**
 * \memberof FlowCert
 * \brief Used internally to validate SSL connections
 *
 * Returns a pointer to currently installed certificate for a domain. There is a default *.flowworld.com certificate, which can be overridden.
 * \param domain Domain for which certificate applies to.
 * \ingroup Certificate
*/
char *FlowCert_GetCertificate(char *domain);

/**
 * \memberof FlowCert
 * \brief Set CA certificate for domain, used to validate SSL connections. Passing NULL for certificate disables validation.
 *
 * Set CA certificate (including chain) for domain, which is in standard format as below
 * -----BEGIN CERTIFICATE-----
 * MIIGyTCCBbGgAwIBAgIQCC0zwWltDYOZXW2C/T3P8jANBgkqhkiG9w0BAQUFADBm
 * ...
 * AZp3Cn3TX8DBFIhQXQ==
 * -----END CERTIFICATE-----
 * \param domain Domain for which certificate applies to.
 * \param certificate CA certificate (including chain). Passing NULL disables validation.
 * \ingroup Certificate
*/
void FlowCert_SetCertificate(char *domain, char *certificate);


#endif // _FLOW_CERT_INCLUDED
