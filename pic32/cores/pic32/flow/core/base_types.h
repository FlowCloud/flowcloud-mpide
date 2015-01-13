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

#ifndef FLOW_CORE_BASE_TYPES_H_
#define FLOW_CORE_BASE_TYPES_H_
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

typedef enum
{
	FlowType__Unknown = 0,
	FlowType_Array,
	FlowType_Boolean,
	FlowType_Char,
	FlowType_Datetime,
	FlowType_ID,
	FlowType_Integer,
	FlowType_String,
	FlowType_Timespan,
	FlowType_Token,
	FlowType_RawString,

	FlowType_AccessRight,
	FlowType_Activities,
	FlowType_Album,
	FlowType_Albums,
	FlowType_AlbumType,
	FlowType_API,
	FlowType_Artist,
	FlowType_Artists,
	FlowType_AuthenticationMethods,
	FlowType_AuthenticationTokenCreatedResponse,
	FlowType_Authorisation,
	FlowType_Authorisations,
	FlowType_BadRequestResponse,
	FlowType_Capabilities,
	FlowType_Capability,
	FlowType_Card,
	FlowType_Categories,
	FlowType_Category,
	FlowType_CategoryItem,
	FlowType_CategoryItems,
	FlowType_Contact,
	FlowType_ContactRequest,
	FlowType_ContactRequests,
	FlowType_Contacts,
	FlowType_ContactStatus,
	FlowType_Content,
	FlowType_ContentContainer,
	FlowType_ContentContainers,
	FlowType_ContentItem,
	FlowType_ContentItems,
	FlowType_ContentLocationGroup,
	FlowType_ContentLocationGroups,
	FlowType_ContentSortOrder,
	FlowType_ContentType,
	FlowType_Countries,
	FlowType_Country,
	FlowType_Currencies,
	FlowType_Currency,
	FlowType_CurrencyAmount,
	FlowType_DataStore,
	FlowType_DataStoreItem,
	FlowType_DataStoreItems,
	FlowType_DataStores,
	FlowType_Device,
	FlowType_DeviceCategory,
	FlowType_DeviceCreatedResponse,
	FlowType_DeviceRegistrationKey,
	FlowType_DeviceRegistrationKeys,
	FlowType_DeviceRole,
	FlowType_DeviceRoles,
	FlowType_Devices,
	FlowType_DeviceType,
	FlowType_DeviceTypeName,
	FlowType_DeviceTypes,
	FlowType_DeviceUserRegistrationCredentials,
	FlowType_Discoverable,
	FlowType_DownloadUrl,
	FlowType_EmailType,
	FlowType_Episode,
	FlowType_Episodes,
	FlowType_Error,
	FlowType_EventLog,
	FlowType_EventLogs,
	FlowType_EventSeverity,
	FlowType_ExternalLoginRequest,
	FlowType_FacebookLoginRequest,
	FlowType_FacebookPost,
	FlowType_FacebookPostAction,
	FlowType_FacebookPostActions,
	FlowType_FacebookPostLink,
	FlowType_Favourite,
	FlowType_FavouriteAlbum,
	FlowType_FavouriteAlbums,
	FlowType_FavouriteArtist,
	FlowType_FavouriteArtists,
	FlowType_FavouriteMusic,
	FlowType_FavouritePlaylist,
	FlowType_FavouritePlaylists,
	FlowType_Favourites,
	FlowType_FavouriteTrack,
	FlowType_FavouriteTracks,
	FlowType_FeaturedContent,
	FlowType_FeaturedContentItem,
	FlowType_FeaturedContentItems,
	FlowType_FeaturedContents,
	FlowType_FirmwareImage,
	FlowType_FirmwareImages,
	FlowType_FlowServerLicence,
	FlowType_FlowSongs,
	FlowType_Genre,
	FlowType_GeoLocation,
	FlowType_Image,
	FlowType_InstantMessage,
	FlowType_Item,
	FlowType_JukeUser,
	FlowType_Label,
	FlowType_Labels,
	FlowType_Link,
	FlowType_ListeningActivities,
	FlowType_ListeningActivity,
	FlowType_ListeningActivityStatus,
	FlowType_LiveRadioItem,
	FlowType_LiveRadioItems,
	FlowType_MediaStatus,
	FlowType_Merchant,
	FlowType_Merchants,
	FlowType_Music,
	FlowType_MusicGenre,
	FlowType_MusicGenres,
	FlowType_OfflineStatus,
	FlowType_OndemandItems,
	FlowType_PageInfo,
	FlowType_PausedActivities,
	FlowType_PausedActivity,
	FlowType_PaymentMethod,
	FlowType_PaymentProvider,
	FlowType_PaymentProviderForm,
	FlowType_PaymentProviderFormType,
	FlowType_PaymentProviders,
	FlowType_Permission,
	FlowType_PermissionName,
	FlowType_Permissions,
	FlowType_Plan,
	FlowType_Plans,
	FlowType_Playlist,
	FlowType_Playlists,
	FlowType_PreviewUrl,
	FlowType_Protocol,
	FlowType_ProtocolInfo,
	FlowType_PublishEvent,
	FlowType_RecentContentItem,
	FlowType_RecentContentItems,
	FlowType_RecentTrack,
	FlowType_RecentTracks,
	FlowType_Region,
	FlowType_Regions,
	FlowType_ResetPasswordResponse,
	FlowType_ResourceCreatedResponse,
	FlowType_ResourcesCreatedResponse,
	FlowType_SearchResult,
	FlowType_Service,
	FlowType_ServiceEndpoint,
	FlowType_ServiceEndpoints,
	FlowType_ServiceIdentity,
	FlowType_ServiceSettings,
	FlowType_ServiceType,
	FlowType_Setting,
	FlowType_Settings,
	FlowType_ShareStatus,
	FlowType_ShoppingCart,
	FlowType_ShowItem,
	FlowType_ShowItems,
	FlowType_SiriusXMConfiguration,
	FlowType_SiriusXMContent,
	FlowType_SiriusXMListeningActivities,
	FlowType_SiriusXMListeningActivity,
	FlowType_SiriusXMUser,
	FlowType_SocialNetworks,
	FlowType_SortOrderOption,
	FlowType_StoredValueAccount,
	FlowType_StoredValueAccounts,
	FlowType_StreamingUrl,
	FlowType_Strings,
	FlowType_Subscription,
	FlowType_SubscriptionPrice,
	FlowType_Subscriptions,
	FlowType_SubscriptionType,
	FlowType_Time,
	FlowType_TimePeriod,
	FlowType_TimeZone,
	FlowType_TimeZones,
	FlowType_TokenCreatedResponse,
	FlowType_TokenCredentials,
	FlowType_TopicPermission,
	FlowType_TopicPermissions,
	FlowType_TopicPermissionType,
	FlowType_TopupAmounts,
	FlowType_Track,
	FlowType_TrackActivitySource,
	FlowType_Tracks,
	FlowType_TrackSortOrder,
	FlowType_TrackType,
	FlowType_Transaction,
	FlowType_Transactions,
	FlowType_TransactionStatus,
	FlowType_TransactionType,
	FlowType_TurnCredentials,
	FlowType_UpdateIDs,
	FlowType_Upgrade,
	FlowType_Upgrades,
	FlowType_User,
	FlowType_UserGrant,
	FlowType_UserGrants,
	FlowType_UserReferType,
	FlowType_Users,
	FlowType_VisibleDevice,
	FlowType_VisibleDevices,
	FlowType_Voucher,
	FlowType_VoucherProduct,
	FlowType_Vouchers,
	FlowType_VoucherType,

	FlowType__Max
} FlowType;

#define FLOW_DEFAULT_PAGE_SIZE 20

typedef time_t FlowDatetime;

typedef char* FlowID;

typedef long int FlowTimespan;

typedef char* FlowToken;

#ifndef	FLOW_STDTYPES_INCLUDED

typedef	int8_t int8;
typedef	uint8_t	uint8;

typedef	int16_t	int16;
typedef	uint16_t uint16;

typedef	int32_t	int32;
typedef	uint32_t uint32;

typedef	int64_t int64;
typedef	uint64_t uint64;

typedef	unsigned char uchar;
typedef	unsigned short ushort;
typedef	unsigned int uint;
typedef	unsigned long ulong;

#define FLOW_STDTYPES_INCLUDED
#endif

#endif /* FLOW_CORE_BASE_TYPES_H_ */
