#define TAG "TVMediaClient"

#include "TVMediaClient.h"

#define DEBUG
#ifdef DEBUG                                                                                                              
#include <android/log.h>
#undef XLOGD
#define XLOGD(...)  __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__) // 定义LOGD类型  
#else
#undef XLOGD
#define XLOGD(...)
#define LOGD(...)
#endif // DEBUG 

void TVMediaClient::instantiate()
{
    LOGD("TVMediaClient::instantiate\n");
    //defaultServiceManager()->addService(String16(SERVICE_NAME),new TVMediaClient());
}

TVMediaClient::TVMediaClient(IPTVMediaClient *iptvMClient)
:BnTVMediaClient(),
 m_iptvMClient(iptvMClient)
{
    LOGD("TVMediaClient::TVMediaClient\n");
}

TVMediaClient::~TVMediaClient()
{
    LOGD("TVMediaClient::~TVMediaClient\n");
}

void TVMediaClient::getUrl(int id)
{
    if (m_iptvMClient)
        m_iptvMClient->getUrl(id);
    return;
}

void TVMediaClient::mediaMsg(char *msg)
{
    LOGD("TVMediaClient::mediaMsg start");
    LOGD("TVMediaClient::mediaMsg msg=%s", msg);
    if (m_iptvMClient)
        m_iptvMClient->mediaMsg(msg); 
    LOGD("TVMediaClient::mediaMsg msg");
    return;
}

void TVMediaClient::notify(int msg, int ext1, int ext2, const Parcel *obj)
{
    return;
}
