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
/** @file */

#ifndef FLOW_CORE_H_
#define FLOW_CORE_H_

#include "flow/core/accessright.h"
#include "flow/core/api.h"
#include "flow/core/authenticationmethods.h"
#include "flow/core/authenticationtokencreatedresponse.h"
#include "flow/core/authorisation.h"
#include "flow/core/authorisations.h"
#include "flow/core/badrequestresponse.h"
#include "flow/core/base_types.h"
#include "flow/core/base_types_methods.h"
#include "flow/core/capabilities.h"
#include "flow/core/capability.h"
#include "flow/core/client.h"
#include "flow/core/common_messaging_defines.h"
#include "flow/core/common_messaging_main.h"
#include "flow/core/contact.h"
#include "flow/core/contactrequest.h"
#include "flow/core/contactrequests.h"
#include "flow/core/contacts.h"
#include "flow/core/contactstatus.h"
#include "flow/core/contentcontainer.h"
#include "flow/core/contentcontainers.h"
#include "flow/core/core.h"
#include "flow/core/countries.h"
#include "flow/core/country.h"
#include "flow/core/datastore.h"
#include "flow/core/datastoreitem.h"
#include "flow/core/datastoreitems.h"
#include "flow/core/datastores.h"
#include "flow/core/device.h"
#include "flow/core/devicecategory.h"
#include "flow/core/devicecreatedresponse.h"
#include "flow/core/deviceregistrationkey.h"
#include "flow/core/deviceregistrationkeys.h"
#include "flow/core/devicerole.h"
#include "flow/core/deviceroles.h"
#include "flow/core/devices.h"
#include "flow/core/devicesettings.h"
#include "flow/core/devicetype.h"
#include "flow/core/devicetypename.h"
#include "flow/core/devicetypes.h"
#include "flow/core/deviceuserregistrationcredentials.h"
#include "flow/core/deviceusersettings.h"
#include "flow/core/device_helpers.h"
#include "flow/core/discoverable.h"
#include "flow/core/download_helper.h"
#include "flow/core/emailtype.h"
#include "flow/core/error.h"
#include "flow/core/errortype.h"
#include "flow/core/error_methods.h"
#include "flow/core/eventlog.h"
#include "flow/core/eventlogs.h"
#include "flow/core/eventseverity.h"
#include "flow/core/externalloginrequest.h"
#include "flow/core/facebookloginrequest.h"
#include "flow/core/facebookpost.h"
#include "flow/core/facebookpostaction.h"
#include "flow/core/facebookpostactions.h"
#include "flow/core/facebookpostlink.h"
#include "flow/core/firmwareimage.h"
#include "flow/core/firmwareimages.h"
#include "flow/core/flowserverlicence.h"
#include "flow/core/flow_activitylog.h"
#include "flow/core/flow_cert.h"
#include "flow/core/flow_debug.h"
#include "flow/core/flow_enum.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_list.h"
#include "flow/core/flow_memalloc.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_nvs.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/flow_queue.h"
#include "flow/core/flow_task_scheduler.h"
#include "flow/core/flow_threading.h"
#include "flow/core/flow_time.h"
#include "flow/core/flow_timer.h"
#include "flow/core/generalsettings.h"
#include "flow/core/http_query.h"
#include "flow/core/image.h"
#include "flow/core/item.h"
#include "flow/core/label.h"
#include "flow/core/labels.h"
#include "flow/core/link.h"
#include "flow/core/list_support.h"
#include "flow/core/mediastatus.h"
#include "flow/core/pageinfo.h"
#include "flow/core/permission.h"
#include "flow/core/permissionname.h"
#include "flow/core/permissions.h"
#include "flow/core/resetpasswordresponse.h"
#include "flow/core/resourcecreatedresponse.h"
#include "flow/core/resourcescreatedresponse.h"
#include "flow/core/service.h"
#include "flow/core/serviceendpoint.h"
#include "flow/core/serviceendpoints.h"
#include "flow/core/serviceidentity.h"
#include "flow/core/servicesettings.h"
#include "flow/core/setting.h"
#include "flow/core/settings.h"
#include "flow/core/settings_helper.h"
#include "flow/core/socialnetworks.h"
#include "flow/core/sortorderoption.h"
#include "flow/core/strings.h"
#include "flow/core/time.h"
#include "flow/core/timeperiod.h"
#include "flow/core/timespan_methods.h"
#include "flow/core/timezone.h"
#include "flow/core/timezones.h"
#include "flow/core/tokencreatedresponse.h"
#include "flow/core/tokencredentials.h"
#include "flow/core/updateids.h"
#include "flow/core/upgrade.h"
#include "flow/core/upgrades.h"
#include "flow/core/user.h"
#include "flow/core/usergrant.h"
#include "flow/core/usergrants.h"
#include "flow/core/userrefertype.h"
#include "flow/core/users.h"
#include "flow/core/usersettings.h"
#include "flow/core/user_helpers.h"
#include "flow/core/visibledevice.h"
#include "flow/core/visibledevices.h"
#include "flow/core/vouchertype.h"
#include "flow/core/xmlparser.h"
#include "flow/core/xmltree.h"
#include "flow/core/xml_serialisation.h"

static inline void FlowCore_RegisterTypes()
{
	FlowAccessRight_RegisterType();
	FlowAPI_RegisterType();
	FlowAuthenticationMethods_RegisterType();
	FlowAuthenticationTokenCreatedResponse_RegisterType();
	FlowAuthorisation_RegisterType();
	FlowAuthorisations_RegisterType();
	FlowBadRequestResponse_RegisterType();
	FlowCapabilities_RegisterType();
	FlowCapability_RegisterType();
	FlowContact_RegisterType();
	FlowContactRequest_RegisterType();
	FlowContactRequests_RegisterType();
	FlowContacts_RegisterType();
	FlowContactStatus_RegisterType();
	FlowContentContainer_RegisterType();
	FlowContentContainers_RegisterType();
	FlowCountries_RegisterType();
	FlowCountry_RegisterType();
	FlowDataStore_RegisterType();
	FlowDataStoreItem_RegisterType();
	FlowDataStoreItems_RegisterType();
	FlowDataStores_RegisterType();
	FlowDevice_RegisterType();
	FlowDeviceCategory_RegisterType();
	FlowDeviceCreatedResponse_RegisterType();
	FlowDeviceRegistrationKey_RegisterType();
	FlowDeviceRegistrationKeys_RegisterType();
	FlowDeviceRole_RegisterType();
	FlowDeviceRoles_RegisterType();
	FlowDevices_RegisterType();
	FlowDeviceType_RegisterType();
	FlowDeviceTypeName_RegisterType();
	FlowDeviceTypes_RegisterType();
	FlowDeviceUserRegistrationCredentials_RegisterType();
	FlowDiscoverable_RegisterType();
	FlowEmailType_RegisterType();
	FlowError_RegisterType();
	FlowEventLog_RegisterType();
	FlowEventLogs_RegisterType();
	FlowEventSeverity_RegisterType();
	FlowExternalLoginRequest_RegisterType();
	FlowFacebookLoginRequest_RegisterType();
	FlowFacebookPost_RegisterType();
	FlowFacebookPostAction_RegisterType();
	FlowFacebookPostActions_RegisterType();
	FlowFacebookPostLink_RegisterType();
	FlowFirmwareImage_RegisterType();
	FlowFirmwareImages_RegisterType();
	FlowFlowServerLicence_RegisterType();
	FlowImage_RegisterType();
	FlowItem_RegisterType();
	FlowLabel_RegisterType();
	FlowLabels_RegisterType();
	FlowLink_RegisterType();
	FlowMediaStatus_RegisterType();
	FlowPageInfo_RegisterType();
	FlowPermission_RegisterType();
	FlowPermissionName_RegisterType();
	FlowPermissions_RegisterType();
	FlowResetPasswordResponse_RegisterType();
	FlowResourceCreatedResponse_RegisterType();
	FlowResourcesCreatedResponse_RegisterType();
	FlowService_RegisterType();
	FlowServiceEndpoint_RegisterType();
	FlowServiceEndpoints_RegisterType();
	FlowServiceIdentity_RegisterType();
	FlowServiceSettings_RegisterType();
	FlowSetting_RegisterType();
	FlowSettings_RegisterType();
	FlowSocialNetworks_RegisterType();
	FlowSortOrderOption_RegisterType();
	FlowStrings_RegisterType();
	FlowTime_RegisterType();
	FlowTimePeriod_RegisterType();
	FlowTimeZone_RegisterType();
	FlowTimeZones_RegisterType();
	FlowTokenCreatedResponse_RegisterType();
	FlowTokenCredentials_RegisterType();
	FlowUpdateIDs_RegisterType();
	FlowUpgrade_RegisterType();
	FlowUpgrades_RegisterType();
	FlowUser_RegisterType();
	FlowUserGrant_RegisterType();
	FlowUserGrants_RegisterType();
	FlowUserReferType_RegisterType();
	FlowUsers_RegisterType();
	FlowVisibleDevice_RegisterType();
	FlowVisibleDevices_RegisterType();
	FlowVoucherType_RegisterType();
}

#endif /* FLOW_CORE_H_ */
