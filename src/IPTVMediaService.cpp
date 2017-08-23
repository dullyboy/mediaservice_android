#define TAG "IPTVMediaService"

#include "IPTVMediaService.h"
#include "TVMediaService.h"
#include "CTCMediaServiceClient.h"
#include "CTC_MediaControl.h"

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

//void IPTVMediaService::instantiate()
//{
//
//}


CTCMediaServiceClient *m_CTCMediaServiceClient = new CTCMediaServiceClient();


IPTVMediaService* IPTVMediaService::create(TVMediaService *service)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return new IPTVMediaService(service);
}

IPTVMediaService::IPTVMediaService(TVMediaService *service)
{
    LOGD("%s line(%d);", __func__, __LINE__);
}

IPTVMediaService::~IPTVMediaService()
{
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IPTVMediaService::MediaMsg(void *arg)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    TVMediaService::iptvMediaMsg(arg);
    LOGD("%s line(%d);", __func__, __LINE__);
}


int  IPTVMediaService::create(const char* url)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    m_CTCMediaServiceClient->initCTCMediaPlayer();
    //android_iptvmplayer_CTC_IPTVPlayer_init(""); 
    //android_iptvmplayer_CTC_IPTVPlayer_stop();
    setVolume(20);    
    setVideoDisplayArea(0,0,1280,720);
    //playFromStart();
    android_iptvmplayer_CTC_IPTVPlayer_play(url); 
    LOGD("%s line(%d) url=%s;", __func__, __LINE__, url);
    return 0;
}




void IPTVMediaService::reset()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->reset();
    
    return;
}

void IPTVMediaService::play()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->play();

    return;
}

void IPTVMediaService::stop()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->stop();

    return;
}

void IPTVMediaService::pause()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->pause();

    return;
}

void IPTVMediaService::resume()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->resume();

    return;
}

void IPTVMediaService::seek(int time)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  time = %d;", __func__, __LINE__, time);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->seek(time);

    return;
}

void IPTVMediaService::fast(int speed)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  speed = %d;", __func__, __LINE__, speed);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->fast(speed);

    return;
}

void IPTVMediaService::rewind(int speed)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  speed = %d;", __func__, __LINE__, speed);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->rewind(speed);

    return;
}

int  IPTVMediaService::getVolume()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVolume();

    return -1;
}
void IPTVMediaService::setVolume(int volume)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  volume = %d;", __func__, __LINE__, volume);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setVolume(volume);

    return;
}

int  IPTVMediaService::getMute()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getMute();
    
    return -1;
}

void IPTVMediaService::setMute(int volume)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  volume = %d;", __func__, __LINE__, volume);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setMute(volume);

    return;
}

void IPTVMediaService::setRatio()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setRatio();

    return;
}

int  IPTVMediaService::getPlayMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getPlayMode();
    
    return -1;
}

int  IPTVMediaService::getCurrentPos()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getCurrentPos();

    return -1;
}

int  IPTVMediaService::getVideoPixels()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVideoPixels();

    return -1;
}

int  IPTVMediaService::getDuration()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getDuration();

    return -1;
}

int  IPTVMediaService::getVersion()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVersion();

    return -1;
}

void IPTVMediaService::setVideoWindow(int x, int y, int width, int height, int mode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setVideoWindow(x, y, width, height, mode);

    return;    
}

int IPTVMediaService::getPlayerInstaceId()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getPlayerInstaceId();

    return -1;
}

void IPTVMediaService::setAlpha()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setAlpha();

    return;
}

//liubin add 

char* IPTVMediaService::set(char*& ioStr, char*& wrStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if(m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->set(ioStr, wrStr);

    return "";
} 
    
char* IPTVMediaService::get(char* ioStr)                                                                                                
{ 
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->get(ioStr);

    return "";
}


int IPTVMediaService::getNativePlayerInstanceID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getNativePlayerInstanceID();

    return -1;
}

void IPTVMediaService::setSingleOrPlaylistMode(int mode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  mode = %d;", __func__, __LINE__, mode);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setSingleOrPlaylistMode(mode);

    return;
}

int IPTVMediaService::getSingleOrPlaylistMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getSingleOrPlaylistMode();

    return -1;
}

void IPTVMediaService::setVideoDisplayMode(int videoDisplayMode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  videoDisplayMode = %d;", __func__, __LINE__, videoDisplayMode);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setVideoDisplayMode(videoDisplayMode);
    
    return;
}

int IPTVMediaService::getVideoDisplayMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVideoDisplayMode();

    return -1;
}

void IPTVMediaService::setVideoDisplayArea(int x, int y, int width, int height)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setVideoDisplayArea(x, y, width, height);

    return;
}

int IPTVMediaService::getVideoDisplayLeft()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVideoDisplayLeft();

    return -1;
}

int IPTVMediaService::getVideoDisplayTop()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVideoDisplayTop();

    return -1;
}

int IPTVMediaService::getVideoDisplayWidth()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVideoDisplayWidth();

    return -1;
}

int IPTVMediaService::getVideoDisplayHeight()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVideoDisplayHeight();

    return -1;
}

void IPTVMediaService::setNativeUIFlag(int nativeUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  nativeUIFlag = %d;", __func__, __LINE__, nativeUIFlag);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setNativeUIFlag(nativeUIFlag);

    return;
}

int IPTVMediaService::getNativeUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getNativeUIFlag();

    return -1;
}

void IPTVMediaService::setMuteUIFlag(int muteUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  muteUIFlag = %d;", __func__, __LINE__, muteUIFlag);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setMuteUIFlag(muteUIFlag);
    
    return;
}

int IPTVMediaService::getMuteUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getMuteUIFlag();

    return -1;
}

void IPTVMediaService::setAudioVolumeUIFlag(int audioVolumeUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  audioVolumeUIFlag = %d;", __func__, __LINE__, audioVolumeUIFlag);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setAudioVolumeUIFlag(audioVolumeUIFlag);

    return; 
}

int IPTVMediaService::getAudioVolumeUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getAudioVolumeUIFlag();

    return -1;
}

void IPTVMediaService::setAudioTrackUIFlag(int audioTrackUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  audioTrackUIFlag = %d;", __func__, __LINE__, audioTrackUIFlag);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setAudioTrackUIFlag(audioTrackUIFlag);
    
    return;
}

int IPTVMediaService::getAudioTrackUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient>getAudioTrackUIFlag();

    return -1;
}

void IPTVMediaService::setProgressBarUIFlag(int progressBarUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  progressBarUIFlag = %d;", __func__, __LINE__, progressBarUIFlag);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setProgressBarUIFlag(progressBarUIFlag);
    
    return;
}

int IPTVMediaService::getProgressBarUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getProgressBarUIFlag();

    return -1;
}

void IPTVMediaService::setChannelNoUIFlag(int channelNOUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  channelNOUIFlag = %d;", __func__, __LINE__, channelNOUIFlag);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setChannelNoUIFlag(channelNOUIFlag);

    return; 
}

int IPTVMediaService::getChannelNoUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getChannelNoUIFlag();

    return -1;
}

void IPTVMediaService::setSubtitileFlag(int subtitileFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  subtitileFlag = %d;", __func__, __LINE__, subtitileFlag);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setSubtitileFlag(subtitileFlag);

    return;
}

int IPTVMediaService::getSubtitileFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getSubtitileFlag();

    return -1;
}

void IPTVMediaService::setAllowTrickmodeFlag(int allowTrickmodeFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  allowTrickmodeFlag = %d;", __func__, __LINE__, allowTrickmodeFlag);
    if(m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setAllowTrickmodeFlag(allowTrickmodeFlag);

    return;   
}

int IPTVMediaService::getAllowTrickmodeFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getAllowTrickmodeFlag();

    return -1;
}

void IPTVMediaService::setCycleFlag(int cycleFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  cycleFlag = %d;", __func__, __LINE__, cycleFlag);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setCycleFlag(cycleFlag);
   
    return;
}

int IPTVMediaService::getCycleFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getCycleFlag();

    return -1;
}

void IPTVMediaService::setRandomFlag(int randomFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  randomFlag = %d;", __func__, __LINE__, randomFlag);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setRandomFlag(randomFlag);
   
    return;
}

int IPTVMediaService::getRandomFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getRandomFlag();

    return -1;
}

void IPTVMediaService::setVendorSpecificAttr(const char*& vendorSpecificAttr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  vendorSpecificAttr = %s;", __func__, __LINE__, vendorSpecificAttr);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setVendorSpecificAttr(vendorSpecificAttr);

    return; 
}

char* IPTVMediaService::getVendorSpecificAttr()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVendorSpecificAttr();

    return "";
}

char* IPTVMediaService::getMediaCode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getMediaCode();

    return "";
}

char* IPTVMediaService::getCurrentPlayTime()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getCurrentPlayTime();

    return "";
}

int IPTVMediaService::GetLastError()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->GetLastError();

    return -1;
}

char* IPTVMediaService::getSubtitle()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getSubtitle();

    return "";
}

int IPTVMediaService::getMediaCount()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getMediaCount();

    return -1;
}

int IPTVMediaService::getCurrentIndex()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getCurrentIndex();

    return -1;
}

char* IPTVMediaService::getEntryID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getEntryID();

    return "";
}

char* IPTVMediaService::getPlaylist()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getPlaylist();

    return "";
}

void IPTVMediaService::initMediaPlayer(int nativePlayerInstanceID,
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
    /*if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->initMediaPlayer(nativePlayerInstanceID, playlistFlag, videoDisplayMode, height, width,
                left, top, muteFlag, useNativeUIFlag, subtitleFlag, videoAlpha, cycleFlag, randomFlag);

    return;*/

}

int IPTVMediaService::addSingleMedia(int index, const char*& mediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->addSingleMedia(index, mediaStr);

    return -1;
}

int IPTVMediaService::addBatchMedia(const char*& batchMediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->addBatchMedia(batchMediaStr);

    return -1;
}

void IPTVMediaService::removeMediaByEntryID(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->removeMediaByEntryID(entryID);

    return;
}

void IPTVMediaService::removeMediaByIndex(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->removeMediaByIndex(index);
    
    return;
}

void IPTVMediaService::clearAllMedia()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->clearAllMedia();

    return;
}

void IPTVMediaService::moveMediaByIndex(const char*& entryID, int toIndex)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaByIndex(entryID, toIndex);

    return;
}

void IPTVMediaService::moveMediaByOffset(const char*& entryID, int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaByOffset(entryID, offset);

    return;
}

void IPTVMediaService::moveMediaByIndex1(int index, int toIndex)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaByIndex1(index, toIndex);

    return;
}

void IPTVMediaService::moveMediaByOffset1(int index, int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaByOffset1(index, offset);
    
    return;
}

void IPTVMediaService::moveMediaToNext(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaToNext(entryID);
    
    return;
}

void IPTVMediaService::moveMediaToPrevious(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaToPrevious(entryID);
    
    return;
}

void IPTVMediaService::moveMediaToFirst(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaToFirst(entryID);
    
    return;
}

void IPTVMediaService::moveMediaToLast(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaToLast(entryID);

    return;
}

void IPTVMediaService::moveMediaToNext1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
       m_CTCMediaServiceClient->moveMediaToNext1(index);

    return;
}

void IPTVMediaService::moveMediaToPrevious1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
       m_CTCMediaServiceClient->moveMediaToPrevious1(index);
    
    return; 
}

void IPTVMediaService::moveMediaToFirst1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaToFirst1(index);
    
    return;
}

void IPTVMediaService::moveMediaToLast1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaToLast1(index);    

    return;
}

void IPTVMediaService::selectMediaByIndex(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
       m_CTCMediaServiceClient->selectMediaByIndex(index);

    return; 
}

void IPTVMediaService::selectMediaByOffset(int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
       m_CTCMediaServiceClient->selectMediaByOffset(offset);

    return;
}

void IPTVMediaService::selectNext()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
       m_CTCMediaServiceClient->selectNext();

    return; 
}

void IPTVMediaService::selectPrevious()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
       m_CTCMediaServiceClient->selectPrevious();
    
    return; 
}

void IPTVMediaService::selectFirst()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
       m_CTCMediaServiceClient->selectFirst();

    return;
}

void IPTVMediaService::selectLast()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->selectLast();

    return;
}

void IPTVMediaService::selectMediaByEntryID(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
       m_CTCMediaServiceClient->selectMediaByEntryID(entryID);

    return;
}

int IPTVMediaService::joinChannel(int userchannelid)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  userchannelid = %d;", __func__, __LINE__, userchannelid);
    //临时初始化
    int x = 0;
    int y = 0;
    int width = 1280;
    int height =720;
    setVideoDisplayArea(x,y,width,height);
    
    char* url = ""; 
    char* channelname = "";
    if (m_CTCMediaServiceClient)
    {
        m_CTCMediaServiceClient->joinChannel(url, channelname, userchannelid);
        return 0;
    }
    return -1;
}

void IPTVMediaService::leaveChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->leaveChannel();

    return;
}

void IPTVMediaService::playFromStart()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    //临时初始化
    int x = 0;
    int y = 0;
    int width = 1280;
    int height =720;
    setVideoDisplayArea(x,y,width,height);
    
    char* url = "";   
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->playFromStart(url);
    
    return;
}

void IPTVMediaService::playByTime(int type, char*& timestamp, int speed)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
    //临时初始化
    int x = 0;
    int y = 0;
    int width = 1280;
    int height =720;
    setVideoDisplayArea(x,y,width,height);
    
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->playByTime(type, timestamp, speed);

    return;
}

void IPTVMediaService::switchSubtitle()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->switchSubtitle();

    return;
}

void IPTVMediaService::sendVendorSpecificCommand(const char*& xml)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->sendVendorSpecificCommand(xml);

    return;
}

int IPTVMediaService::getAudioPID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getAudioPID();

    return -1;
}

int IPTVMediaService::getAudioPIDs()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getAudioPIDs();

    return -1;
}

void IPTVMediaService::setAudioPID(int pid)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setAudioPID(pid);

    return;
}

int IPTVMediaService::getSubtitlePID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getSubtitlePID();

    return -1;
}

int IPTVMediaService::getSubtitlePIDs()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getSubtitlePIDs();

    return -1;
}

void IPTVMediaService::setSubtitlePID(int pid)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setSubtitlePID(pid);

    return;
}

int IPTVMediaService::Data(int start, int end)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->Data(start, end);

    return -1;
}

void IPTVMediaService::videoshow()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->videoshow();

    return;
}

void IPTVMediaService::videohide()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->videohide();

    return; 
}

int IPTVMediaService::bindNativePlayerInstance(int nativePlayerInstanceID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  nativePlayerInstanceID = %d;", __func__, __LINE__, nativePlayerInstanceID);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->bindNativePlayerInstance(nativePlayerInstanceID);

    return -1;
}

void IPTVMediaService::releaseMediaPlayer(int nativePlayerInstanceID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  nativePlayerInstanceID = %d;", __func__, __LINE__, nativePlayerInstanceID);
    stop();
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->releaseMediaPlayer(nativePlayerInstanceID);

    return;
}


void IPTVMediaService::setMuteFlag(int muteFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  muteFlag = %d;", __func__, __LINE__, muteFlag);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setMuteFlag(muteFlag);

    return;
}

int IPTVMediaService::getMuteFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getMuteFlag();

    return -1;
}

void IPTVMediaService::setVideoAlpha(int videoAlpha)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  videoAlpha = %d;", __func__, __LINE__, videoAlpha);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setVideoAlpha(videoAlpha);

    return;
}

int IPTVMediaService::getVideoAlpha()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVideoAlpha();

    return -1;    
}
    
char* IPTVMediaService::getPlaybackMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getPlaybackMode();

    return "";
}

int IPTVMediaService::getChannelNum()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getChannelNum();

    return;
}

char* IPTVMediaService::getCurrentAudioChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getCurrentAudioChannel();

    return "";
}

char* IPTVMediaService::getAudioTrack()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getAudioTrack();

    return "";
}

void IPTVMediaService::setSingleMedia(char*& mediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  mediaStr = %s;", __func__, __LINE__, mediaStr);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setSingleMedia(mediaStr);

    return;
}

void IPTVMediaService::gotoStart()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->gotoStart();

    return;
}

void IPTVMediaService::gotoEnd()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->gotoEnd();

    return;
}

void IPTVMediaService::refreshVideoDisplay()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->refreshVideoDisplay();

    return;
}

void IPTVMediaService::switchAudioChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->switchAudioChannel();

    return;
}
void IPTVMediaService::switchAudioTrack()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->switchAudioTrack();

    return;
}

//game call function                                                                                                                 
void IPTVMediaService::runGame(const char* values)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->runGame(values);

    return;
}

 
