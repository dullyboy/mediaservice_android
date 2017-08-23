#define TAG "IPTVMediaClient"

#include "IPTVMediaClient.h"
#include "ITVMediaClient.h"
#include "TVMediaClient.h"
#include "ITVMediaService.h"

#include <map>

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

std::map< int, sp<ITVMediaService> > mClientMaps;
std::map< int, TVMediaClient* > mMediaClientMaps;

IPTVMediaClient::IPTVMediaClient(getIptvUrl url, mediaIptvMsg msg)
    :m_mediaMsg(msg),
    m_getUrl(url)
{
    //TVMediaClient *mediaClient = new TVMediaClient(this);
    //mMediaClientMaps.insert(std::map < int, TVMediaClient* >::value_type((int)this, mediaClient));
}

//liubin add 
/*IPTVMediaClient& IPTVMediaClient::operator=(IPTVMediaClient& mIPTVMediaClient)
{
    if (this == &mIPTVMediaClient)
        return *this;
    if (m_getUrl != NULL)
        delete m_getUrl;
    if (m_mediaMsg != NULL)
        delete m_mediaMsg;
    m_getUrl = new char[strlen(mIPTVMediaClient.m_getUrl)+1];
    m_mediaMsg = new char[strlen(mIPTVMediaClient.m_mediaMsg)+1];
    if (m_getUrl != NULL)
        strcpy(m_getUrl,mIPTVMediaClient.m_getUrl);
    if (m_mediaMsg != NULL)
        strcpy(m_mediaMsg,mIPTVMediaClient.m_mediaMsg);
    return *this;  
}*/

int IPTVMediaClient::connect()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> ibinder = sm->getService(String16(SERVICE_NAME));
    if (ibinder == NULL){
        LOGD( "Client can't find Service" );
        return 0;
    }
    
    sp<ITVMediaService> itvMediaService =  android::interface_cast<ITVMediaService>(ibinder); 
    mClientMaps.insert(std::map < int, sp<ITVMediaService> >::value_type((int)this, itvMediaService));
    
    //std::map < int, TVMediaClient* >::iterator iter;
    //iter = mMediaClientMaps.find((int)this);
    //itvMediaService->init(iter->second != NULL);
    TVMediaClient *mediaClient = NULL;

    if (m_getUrl != NULL && m_mediaMsg != NULL) {
        LOGD("%s line(%d);", __func__, __LINE__);
        mediaClient = new TVMediaClient(this);
        itvMediaService->init(mediaClient);
    }

    mMediaClientMaps.insert(std::map < int, TVMediaClient* >::value_type((int)this, mediaClient));

    LOGD("%s line(%d);", __func__, __LINE__);
    return 1;
}

void IPTVMediaClient::disconnect()
{
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    mClientMaps.erase(iter);
}

IPTVMediaClient::~IPTVMediaClient()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    m_getUrl = NULL;
    m_mediaMsg = NULL;
    std::map < int, TVMediaClient* >::iterator iter;
    if (iter->second != NULL)
        iter = mMediaClientMaps.find((int)this);

    mMediaClientMaps.erase(iter);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::getUrl(int id)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char *url = NULL;
    if (m_getUrl)
        url = m_getUrl(id);
    
    //get extern save id is rul run call player
    if (url) {
        std::map < int, sp<ITVMediaService> >::iterator iter;
        iter = mClientMaps.find((int)this);
        if (iter->second != NULL)
            iter->second->create(url, id);
    }
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::mediaMsg(char* msg)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("mediaMsg msg=%s", msg);
    if (m_mediaMsg)
        m_mediaMsg(msg);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::create(const char* url, int id)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    
    LOGD("IPTVMediaClient::callback start");
    if (iter->second != NULL)
        iter->second->create(url, id);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::reset()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->reset();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::play()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->play();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::stop()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->stop();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::pause()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->pause();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::resume()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->resume();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::seek(int time)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->seek(time);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::fast(int speed)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->fast(speed);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::rewind(int speed)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->rewind(speed);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int  IPTVMediaClient::getVolume()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int volume = 0;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        volume = iter->second->getVolume();
    LOGD("%s line(%d);", __func__, __LINE__);
    return volume;
}

void IPTVMediaClient::setVolume(int volume)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setVolume(volume);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int  IPTVMediaClient::getMute()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int mute = 0;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        mute = iter->second->getMute();
    LOGD("%s line(%d);", __func__, __LINE__);
    return mute;
}

void IPTVMediaClient::setMute(int volume)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setMute(volume);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::setRatio()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setRatio();
    LOGD("%s line(%d);", __func__, __LINE__);
}

int  IPTVMediaClient::getPlayMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int mode = 0;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        mode = iter->second->getPlayMode();
    LOGD("%s line(%d);", __func__, __LINE__);
    return mode;
}

int  IPTVMediaClient::getCurrentPos()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int currentpos = 0; 
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        currentpos = iter->second->getCurrentPos();
    LOGD("%s line(%d);", __func__, __LINE__);
    return currentpos;
}

int  IPTVMediaClient::getVideoPixels()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int pixels = 0;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        pixels = iter->second->getVideoPixels();
    LOGD("%s line(%d);", __func__, __LINE__);
    return pixels;
}

int  IPTVMediaClient::getDuration()
{
    int duration = 0;
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        duration = iter->second->getDuration();
    LOGD("%s line(%d);", __func__, __LINE__);
    return duration;
}

int  IPTVMediaClient::getVersion()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int version = -1;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        version = iter->second->getVersion();
    LOGD("%s line(%d);", __func__, __LINE__);
    return version;
}

void IPTVMediaClient::setVideoWindow(int x, int y, int width, int height, int mode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setVideoWindow(x, y, width, height, mode);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int  IPTVMediaClient::getPlayerInstaceId()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int id = -1;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        id = iter->second->getPlayerInstaceId();
    LOGD("%s line(%d);", __func__, __LINE__);
    return id;
}

void IPTVMediaClient::setAlpha()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setAlpha();
    LOGD("%s line(%d);", __func__, __LINE__);
}

//liubin add

char* IPTVMediaClient::set(char*& ioStr, char*& wrStr)
{
    return "";
} 
    
char* IPTVMediaClient::get(char* ioStr)                                                                                                
{ 
    return "";
}

int IPTVMediaClient::getNativePlayerInstanceID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_NativePlayerInstanceID = 0;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_NativePlayerInstanceID = iter->second->getNativePlayerInstanceID();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_NativePlayerInstanceID;
}

void IPTVMediaClient::setSingleOrPlaylistMode(int mode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setSingleOrPlaylistMode(mode);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::getSingleOrPlaylistMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_SingleOrPlaylistMode = 0;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_SingleOrPlaylistMode = iter->second->getSingleOrPlaylistMode();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_SingleOrPlaylistMode;
}

void IPTVMediaClient::setVideoDisplayMode(int videoDisplayMode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setVideoDisplayMode(videoDisplayMode);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::getVideoDisplayMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoDisplayMode = 0;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_VideoDisplayMode = iter->second->getVideoDisplayMode();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VideoDisplayMode;
}

void IPTVMediaClient::setVideoDisplayArea(int x, int y, int width, int height)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setVideoDisplayArea(x, y, width,height); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::getVideoDisplayLeft()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoDisplayLeft = 0;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_VideoDisplayLeft = iter->second->getVideoDisplayLeft();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VideoDisplayLeft;
}

int IPTVMediaClient::getVideoDisplayTop()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoDisplayTop = 0;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_VideoDisplayTop = iter->second->getVideoDisplayTop();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VideoDisplayTop;
}

int IPTVMediaClient::getVideoDisplayWidth()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoDisplayWidth = 0;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_VideoDisplayWidth = iter->second->getVideoDisplayWidth();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VideoDisplayWidth;
}

int IPTVMediaClient::getVideoDisplayHeight()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoDisplayHeight = 0;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_VideoDisplayHeight = iter->second->getVideoDisplayHeight();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VideoDisplayHeight;
}

void IPTVMediaClient::setNativeUIFlag(int nativeUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setNativeUIFlag(nativeUIFlag); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::getNativeUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_NativeUIFlag = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_NativeUIFlag = iter->second->getNativeUIFlag(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_NativeUIFlag;
}

void IPTVMediaClient::setMuteUIFlag(int muteUIFlag)
{ LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setMuteUIFlag(muteUIFlag); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::getMuteUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_MuteUIFlag = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_MuteUIFlag = iter->second->getMuteUIFlag(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_MuteUIFlag;
}

void IPTVMediaClient::setAudioVolumeUIFlag(int audioVolumeUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setAudioVolumeUIFlag(audioVolumeUIFlag); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::getAudioVolumeUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_AudioVolumeUIFlag = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_AudioVolumeUIFlag = iter->second->getAudioVolumeUIFlag(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AudioVolumeUIFlag;
}

void IPTVMediaClient::setAudioTrackUIFlag(int audioTrackUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setAudioTrackUIFlag(audioTrackUIFlag); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::getAudioTrackUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_AudioTrackUIFlag = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_AudioTrackUIFlag = iter->second->getAudioTrackUIFlag(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AudioTrackUIFlag;
}

void IPTVMediaClient::setProgressBarUIFlag(int progressBarUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setProgressBarUIFlag(progressBarUIFlag); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::getProgressBarUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_ProgressBarUIFlag = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_ProgressBarUIFlag = iter->second->getProgressBarUIFlag(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_ProgressBarUIFlag;
}

void IPTVMediaClient::setChannelNoUIFlag(int channelNOUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setChannelNoUIFlag(channelNOUIFlag); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::getChannelNoUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_ChannelNoUIFlag = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_ChannelNoUIFlag = iter->second->getChannelNoUIFlag(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_ChannelNoUIFlag;
}

void IPTVMediaClient::setSubtitileFlag(int subtitileFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setSubtitileFlag(subtitileFlag); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::getSubtitileFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_SubtitileFlag = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_SubtitileFlag = iter->second->getSubtitileFlag(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_SubtitileFlag;
}

void IPTVMediaClient::setAllowTrickmodeFlag(int allowTrickmodeFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setAllowTrickmodeFlag(allowTrickmodeFlag); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::getAllowTrickmodeFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_AllowTrickmodeFlag = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_AllowTrickmodeFlag = iter->second->getAllowTrickmodeFlag(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AllowTrickmodeFlag;
}

void IPTVMediaClient::setCycleFlag(int cycleFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setCycleFlag(cycleFlag); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::getCycleFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_CycleFlag = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_CycleFlag = iter->second->getCycleFlag(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_CycleFlag;
}

void IPTVMediaClient::setRandomFlag(int randomFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setRandomFlag(randomFlag); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::getRandomFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_RandomFlag = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_RandomFlag = iter->second->getRandomFlag(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_RandomFlag;
}

void IPTVMediaClient::setVendorSpecificAttr(const char*& vendorSpecificAttr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setVendorSpecificAttr(vendorSpecificAttr); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

char* IPTVMediaClient::getVendorSpecificAttr()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_VendorSpecificAttr = NULL;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_VendorSpecificAttr = iter->second->getVendorSpecificAttr(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VendorSpecificAttr;
}

char* IPTVMediaClient::getMediaCode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_MediaCode = NULL;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_MediaCode = iter->second->getMediaCode(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_MediaCode;
}
    
char* IPTVMediaClient::getCurrentPlayTime()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_CurPlayTime = NULL;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_CurPlayTime = iter->second->getCurrentPlayTime(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_CurPlayTime;
}

int IPTVMediaClient::GetLastError()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_LastError = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_LastError = iter->second->GetLastError(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_LastError;
}

char* IPTVMediaClient::getSubtitle()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_Subtitle = NULL;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_Subtitle = iter->second->getSubtitle(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_Subtitle;
}

int IPTVMediaClient::getMediaCount()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_MediaCount = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_MediaCount = iter->second->getMediaCount(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_MediaCount;
}

int IPTVMediaClient::getCurrentIndex()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_CurrentIndex = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_CurrentIndex = iter->second->getCurrentIndex(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_CurrentIndex;
}

char* IPTVMediaClient::getEntryID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_EntryID = NULL;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_EntryID = iter->second->getEntryID(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_EntryID;
}

char* IPTVMediaClient::getPlaylist()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_Playlist = NULL;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_Playlist = iter->second->getPlaylist(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_Playlist;
}

void IPTVMediaClient::initMediaPlayer(int nativePlayerInstanceID,
        int playlistFlag,
        int videoDisplayMode,
        int height,
        int width,
        int left,
        int top,
        int muteFlag,
        int useNativeUIFlag,
        int subtitleFlag,
        int videoAlpha,
        int cycleFlag,
        int randomFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->initMediaPlayer(nativePlayerInstanceID, playlistFlag, videoDisplayMode,height,width,
                left, top, muteFlag, useNativeUIFlag, subtitleFlag, videoAlpha,cycleFlag,randomFlag);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::addSingleMedia(int index, const char*& mediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_SingleMedia = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_SingleMedia = iter->second->addSingleMedia(index, mediaStr); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_SingleMedia;
}

int IPTVMediaClient::addBatchMedia(const char*& batchMediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_BatchMedia = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_BatchMedia = iter->second->addBatchMedia(batchMediaStr); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_BatchMedia;
}

void IPTVMediaClient::removeMediaByEntryID(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->removeMediaByEntryID(entryID); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::removeMediaByIndex(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->removeMediaByIndex(index); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::clearAllMedia()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->clearAllMedia(); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::moveMediaByIndex(const char*& entryID, int toIndex)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaByIndex(entryID, toIndex); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::moveMediaByOffset(const char*& entryID, int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaByOffset(entryID, offset); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::moveMediaByIndex1(int index, int toIndex)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaByIndex1(index, toIndex); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::moveMediaByOffset1(int index, int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaByOffset1(index,offset); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::moveMediaToNext(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaToNext(entryID); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::moveMediaToPrevious(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaToPrevious(entryID); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::moveMediaToFirst(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaToFirst(entryID); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::moveMediaToLast(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaToLast(entryID); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::moveMediaToNext1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaToNext1(index); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::moveMediaToPrevious1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaToPrevious1(index); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::moveMediaToFirst1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaToFirst1(index); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::moveMediaToLast1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaToLast1(index); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::selectMediaByIndex(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->selectMediaByIndex(index); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::selectMediaByOffset(int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->selectMediaByOffset(offset); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::selectNext()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->selectNext(); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::selectPrevious()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->selectPrevious(); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::selectFirst()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->selectFirst(); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::selectLast()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->selectLast(); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::selectMediaByEntryID(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->selectMediaByEntryID(entryID); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::joinChannel(int userchannelid)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_JoinChannel = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_JoinChannel = iter->second->joinChannel(userchannelid); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_JoinChannel;
}

void IPTVMediaClient::leaveChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->leaveChannel();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::playFromStart()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->playFromStart();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::playByTime(int type, char*& timestamp, int speed)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->playByTime(type, timestamp, speed);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::switchSubtitle()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->switchSubtitle();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::sendVendorSpecificCommand(const char*& xml)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->sendVendorSpecificCommand(xml);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::getAudioPID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_AudioPID = 0;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_AudioPID = iter->second->getAudioPID();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AudioPID;
}

int IPTVMediaClient::getAudioPIDs()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_AudioPIDs = 0;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_AudioPIDs = iter->second->getAudioPIDs();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AudioPIDs;
}

void IPTVMediaClient::setAudioPID(int pid)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setAudioPID(pid);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::getSubtitlePID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_SubtitlePID = 0;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_SubtitlePID = iter->second->getSubtitlePID();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_SubtitlePID;
}

int IPTVMediaClient::getSubtitlePIDs()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_SubtitlePIDs = 0;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_SubtitlePIDs = iter->second->getSubtitlePIDs();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_SubtitlePIDs;
}

void IPTVMediaClient::setSubtitlePID(int pid)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setSubtitlePID(pid);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::Data(int start, int end)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_Data = 0;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_Data = iter->second->Data(start, end);
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_Data;
}

void IPTVMediaClient::videoshow()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->videoshow();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::videohide()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->videohide();
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::bindNativePlayerInstance(int nativePlayerInstanceID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_BindnativePlayerInstanceID = 0;
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_BindnativePlayerInstanceID = iter->second->bindNativePlayerInstance(nativePlayerInstanceID);
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_BindnativePlayerInstanceID;
}

void IPTVMediaClient::releaseMediaPlayer(int nativePlayerInstanceID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->releaseMediaPlayer(nativePlayerInstanceID);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::setMuteFlag(int muteFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setMuteFlag(muteFlag); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::getMuteFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_MuteFlag = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_MuteFlag = iter->second->getMuteFlag(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_MuteFlag;
}

void IPTVMediaClient::setVideoAlpha(int videoAlpha)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setVideoAlpha(videoAlpha); 
    LOGD("%s line(%d);", __func__, __LINE__);
}

int IPTVMediaClient::getVideoAlpha()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoAlpha = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_VideoAlpha = iter->second->getVideoAlpha(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VideoAlpha;
}

char* IPTVMediaClient::getPlaybackMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_PlaybackMode = NULL;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_PlaybackMode = iter->second->getPlaybackMode(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_PlaybackMode;
}

int IPTVMediaClient::getChannelNum()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_ChannelNum = 0;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_ChannelNum = iter->second->getChannelNum(); 
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_ChannelNum;
}

char* IPTVMediaClient::getCurrentAudioChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_CurAudioChannel = NULL;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
       m_CurAudioChannel = iter->second->getCurrentAudioChannel();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_CurAudioChannel;
}

char* IPTVMediaClient::getAudioTrack()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_AudioTrack = NULL;
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_AudioTrack = iter->second->getAudioTrack();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AudioTrack;
}

void IPTVMediaClient::setSingleMedia(char*& mediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map< int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setSingleMedia(mediaStr);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::gotoStart()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->gotoStart();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::gotoEnd()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->gotoEnd();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::refreshVideoDisplay()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->refreshVideoDisplay();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::switchAudioChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->switchAudioChannel();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaClient::switchAudioTrack()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->switchAudioTrack();
    LOGD("%s line(%d);", __func__, __LINE__);
}

//game call function                                                                                                                 
void IPTVMediaClient::runGame(const char* values)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    std::map < int, sp<ITVMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->runGame(values);
    LOGD("%s line(%d);", __func__, __LINE__);
}
