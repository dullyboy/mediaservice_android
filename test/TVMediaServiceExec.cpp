#define TAG "TVMediaServiceExec"

#include "TVMediaService.h"

#include <android/log.h>
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__) // 定义LOGD类型  

#define SERVICE_NAME "TVMediaService"
//using namespace android;

int main(int argc, char **argv)
{
    sp<ProcessState> proc(ProcessState::self());
    sp<IServiceManager> sm = defaultServiceManager();
    LOGD("TVMediaService: %p",sm.get());
    TVMediaService::instantiate();
    sm->addService(String16(SERVICE_NAME),new TVMediaService());
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
}
