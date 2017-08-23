#define TAG "ITVMediaClient"

#include "ITVMediaClient.h"

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

enum{
    NOTIFY = IBinder::FIRST_CALL_TRANSACTION,
    GETURL,
    MEDIAMSG
};

class BpTVMediaClient: public BpInterface<ITVMediaClient>                                                                                   
{
    public:
        BpTVMediaClient(const sp<IBinder>& impl)
            : BpInterface<ITVMediaClient>(impl)
        {
        }
        
        virtual void notify(int msg, int ext1, int ext2, const Parcel *obj)
        {                                                                                                                                               
            LOGD("ITVMediaClient::notify start");
            Parcel data, reply;
            //data.writeInterfaceToken(IMediaPlayerClient::getInterfaceDescriptor());
            data.writeInt32(msg);
            data.writeInt32(ext1);        
            data.writeInt32(ext2);        
            if (obj && obj->dataSize() > 0) {
                data.appendFrom(const_cast<Parcel *>(obj), 0, obj->dataSize());
            }
            remote()->transact(NOTIFY, data, &reply, IBinder::FLAG_ONEWAY);
            LOGD("ITVMediaClient::notify end");
        }


        virtual void getUrl(int id)
        {
            LOGD("ITVMediaClient::getUrl start id=%d", id);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaClient::getInterfaceDescriptor());
            data.writeInt32(id);
            status_t status = remote()->transact(GETURL, data, &reply, IBinder::FLAG_ONEWAY);
            LOGD("ITVMediaClient::getUrl end");
            return; 
        }

        virtual void mediaMsg(char *msg)
        {
            LOGD("ITVMediaClient::mediaMsg start msg=%s", msg);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaClient::getInterfaceDescriptor());
            data.writeCString(msg);
            remote()->transact(MEDIAMSG, data, &reply, IBinder::FLAG_ONEWAY);
            LOGD("ITVMediaClient::mediaMsg end");
            return; 
        }
};

IMPLEMENT_META_INTERFACE(TVMediaClient, "com.iptvmedia.ITVMediaClient");
// ----------------------------------------------------------------------

status_t BnTVMediaClient::onTransact(
        uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    LOGD("BnTVMediaClient::onTransact");
    switch (code) {
        case NOTIFY: 
            {                                                                                                                              
                //CHECK_INTERFACE(IMediaPlayerClient, data, reply);
                int msg = data.readInt32();
                int ext1 = data.readInt32();
                int ext2 = data.readInt32();
                Parcel obj;
                if (data.dataAvail() > 0) {
                    obj.appendFrom(const_cast<Parcel *>(&data), data.dataPosition(), data.dataAvail());
                }

                notify(msg, ext1, ext2, &obj);
                return NO_ERROR;
            } break;

        case GETURL: 
            {
                CHECK_INTERFACE(ITVMediaClient, data, reply);
                getUrl(data.readInt32()); 
                return NO_ERROR;
            } break;

        case MEDIAMSG:
            {
                CHECK_INTERFACE(ITVMediaClient, data, reply);
                mediaMsg(data.readCString());
                return NO_ERROR;
            } break;

        default:
             return BBinder::onTransact(code, data, reply, flags);
    }
}

