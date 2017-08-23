#ifndef ITVMediaClient_H
#define ITVMediaClient_H

#include <binder/Parcel.h>
#include <binder/IInterface.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <cutils/properties.h>
#include <utils/Log.h>
#include <unistd.h>

#include <binder/IBinder.h>
#include <binder/IInterface.h>
 
#include <utils/Log.h>
#include <utils/String16.h> 

using namespace android;

class ITVMediaClient: public IInterface {
    public:
        DECLARE_META_INTERFACE(TVMediaClient);
        
        virtual void notify(int msg, int ext1, int ext2, const Parcel *obj) = 0;
        virtual void getUrl(int id) = 0;
        virtual void mediaMsg(char* msg) = 0;
};

class BnTVMediaClient : public BnInterface<ITVMediaClient> {  
    public:  
        virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags);   
};  

#endif //TVMediaClient_H
