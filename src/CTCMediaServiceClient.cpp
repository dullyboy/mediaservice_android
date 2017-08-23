#define TAG "CTCMediaServiceClient"

#include "IPTVMediaService.h"
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

CTCMediaServiceClient::CTCMediaServiceClient()
{
    LOGD("%s line(%d);", __func__, __LINE__);
}

CTCMediaServiceClient::~CTCMediaServiceClient()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    android_iptvmplayer_CTC_IPTVPlayer_deinit();
}

void CTCMediaServiceClient::initCTCMediaPlayer()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    //临时初始化
    int volume = 20;
    int mute = 0;
    char* url = "";
    static mplayer_status mpStatus = {volume, mute, url, (mplayer_event_handler)EventMsg};
    android_iptvmplayer_CTC_IPTVPlayer_init((void*)&(mpStatus));
}

int CTCMediaServiceClient::EventMsg(void *arg)                                                                                                   
{
   LOGD("%s line(%d);", __func__, __LINE__);
   IPTVMediaService::MediaMsg(arg);
   return 0;

}



void CTCMediaServiceClient::reset()
{
    LOGD("%s line(%d);", __func__, __LINE__);
}

void CTCMediaServiceClient::play()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* url = "";
    android_iptvmplayer_CTC_IPTVPlayer_play(url);
}

void CTCMediaServiceClient::stop()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    android_iptvmplayer_CTC_IPTVPlayer_stop();
}

void CTCMediaServiceClient::pause()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    android_iptvmplayer_CTC_IPTVPlayer_pause();
}

void CTCMediaServiceClient::resume()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    android_iptvmplayer_CTC_IPTVPlayer_resume();
}

void CTCMediaServiceClient::seek(int time)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    android_iptvmplayer_CTC_IPTVPlayer_seek(time);
}

void CTCMediaServiceClient::fast(int speed)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  speed=%d;", __func__, __LINE__, speed);
    android_iptvmplayer_CTC_IPTVPlayer_ff(speed);
}

void CTCMediaServiceClient::rewind(int speed)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  speed=%d;", __func__, __LINE__, speed);
    android_iptvmplayer_CTC_IPTVPlayer_fb(speed);
}

int  CTCMediaServiceClient::getVolume()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_Volume = 0;
    m_Volume = android_iptvmplayer_CTC_IPTVPlayer_getvolume();
    LOGD("%s line(%d)  m_Volume = %d;", __func__, __LINE__, m_Volume);
    return m_Volume;
}
void CTCMediaServiceClient::setVolume(int volume)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  volume=%d;", __func__, __LINE__, volume);
    android_iptvmplayer_CTC_IPTVPlayer_setvolume(volume);
}

int  CTCMediaServiceClient::getMute()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::setMute(int volume)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  volume=%d;", __func__, __LINE__, volume);
}

void CTCMediaServiceClient::setRatio()
{
    LOGD("%s line(%d);", __func__, __LINE__);

}

int  CTCMediaServiceClient::getPlayMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

int  CTCMediaServiceClient::getCurrentPos()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

int  CTCMediaServiceClient::getVideoPixels()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoPixels = 0;
    m_VideoPixels = android_iptvmplayer_CTC_IPTVPlayer_getvideopixels();
    return m_VideoPixels;
}

int  CTCMediaServiceClient::getDuration()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_MediaDuration = 0;
    m_MediaDuration = android_iptvmplayer_CTC_IPTVPlayer_getduration();
    return m_MediaDuration;
}

int  CTCMediaServiceClient::getVersion()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_Version = 0;
    m_Version = android_iptvmplayer_CTC_IPTVPlayer_getversion();
    return m_Version;
}

void CTCMediaServiceClient::setVideoWindow(int x, int y, int width, int height, int mode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

int  CTCMediaServiceClient::getPlayerInstaceId()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::setAlpha()
{
    LOGD("%s line(%d);", __func__, __LINE__);

}

//liubin add 

char* CTCMediaServiceClient::set(char*& ioStr, char*& wrStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return "";
} 
    
char* CTCMediaServiceClient::get(char* ioStr)                                                                                                
{ 
    LOGD("%s line(%d);", __func__, __LINE__);
    return "";
}


int CTCMediaServiceClient::getNativePlayerInstanceID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_NativePlayerInstanceID = 0;
    m_NativePlayerInstanceID = android_iptvmplayer_CTC_IPTVPlayer_getplayerinstaceID;
    LOGD("%s line(%d)  m_NativePlayerInstanceID = %d;", __func__, __LINE__, m_NativePlayerInstanceID);
    return m_NativePlayerInstanceID;
}

void CTCMediaServiceClient::setSingleOrPlaylistMode(int mode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  mode=%d;", __func__, __LINE__, mode);
}

int CTCMediaServiceClient::getSingleOrPlaylistMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::setVideoDisplayMode(int videoDisplayMode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  videoDisplayMode=%d;", __func__, __LINE__, videoDisplayMode);
}

int CTCMediaServiceClient::getVideoDisplayMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::setVideoDisplayArea(int x, int y, int width, int height)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    android_iptvmplayer_CTC_IPTVPlayer_setvideowin(x, y, width, height, 0);
}

int CTCMediaServiceClient::getVideoDisplayLeft()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

int CTCMediaServiceClient::getVideoDisplayTop()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

int CTCMediaServiceClient::getVideoDisplayWidth()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

int CTCMediaServiceClient::getVideoDisplayHeight()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::setNativeUIFlag(int nativeUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  nativeUIFlag = %d;", __func__, __LINE__, nativeUIFlag);
}

int CTCMediaServiceClient::getNativeUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::setMuteUIFlag(int muteUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  muteUIFlag = %d;", __func__, __LINE__, muteUIFlag);
}

int CTCMediaServiceClient::getMuteUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::setAudioVolumeUIFlag(int audioVolumeUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  audioVolumeUIFlag = %d;", __func__, __LINE__, audioVolumeUIFlag);
}

int CTCMediaServiceClient::getAudioVolumeUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::setAudioTrackUIFlag(int audioTrackUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  audioTrackUIFlag = %d;", __func__, __LINE__, audioTrackUIFlag);
}

int CTCMediaServiceClient::getAudioTrackUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::setProgressBarUIFlag(int progressBarUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  progressBarUIFlag = %d;", __func__, __LINE__, progressBarUIFlag);
}

int CTCMediaServiceClient::getProgressBarUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::setChannelNoUIFlag(int channelNOUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  channelNOUIFlag = %d;", __func__, __LINE__, channelNOUIFlag);
}

int CTCMediaServiceClient::getChannelNoUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::setSubtitileFlag(int subtitileFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  subtitileFlag =%d;", __func__, __LINE__, subtitileFlag);
}

int CTCMediaServiceClient::getSubtitileFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::setAllowTrickmodeFlag(int allowTrickmodeFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  allowTrickmodeFlag = %d;", __func__, __LINE__, allowTrickmodeFlag);
}

int CTCMediaServiceClient::getAllowTrickmodeFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::setCycleFlag(int cycleFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  cycleFlag = %d;", __func__, __LINE__, cycleFlag);
}

int CTCMediaServiceClient::getCycleFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::setRandomFlag(int randomFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  randomFlag = %d;", __func__, __LINE__, randomFlag);
}

int CTCMediaServiceClient::getRandomFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::setVendorSpecificAttr(const char*& vendorSpecificAttr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  vendorSpecificAttr = %s;", __func__, __LINE__, vendorSpecificAttr);
}

char* CTCMediaServiceClient::getVendorSpecificAttr()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return "";
}

char* CTCMediaServiceClient::getMediaCode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return "";
}

/*char* CTCMediaServiceClient::getCurrentPlayTime()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
    char* m_CurrentPlayTime = "";
    m_CurrentPlayTime = android_iptvmplayer_CTC_IPTVPlayer_getcurpos(); 
    LOGD("%s line(%d)  m_CurrentPlayTime = %s;", __func__, __LINE__, m_CurrentPlayTime);
    return m_CurrentPlayTime;
}*/

int CTCMediaServiceClient::getCurrentPlayTime()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
    int m_CurrentPlayTime = "";
    m_CurrentPlayTime = android_iptvmplayer_CTC_IPTVPlayer_getcurpos(); 
    LOGD("%s line(%d)  m_CurrentPlayTime = %s;", __func__, __LINE__, m_CurrentPlayTime);
    return m_CurrentPlayTime;
}

int CTCMediaServiceClient::GetLastError()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

char* CTCMediaServiceClient::getSubtitle()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return "";
}

int CTCMediaServiceClient::getMediaCount()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

int CTCMediaServiceClient::getCurrentIndex()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

char* CTCMediaServiceClient::getEntryID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return "";
}

char* CTCMediaServiceClient::getPlaylist()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return "";
}

void CTCMediaServiceClient::initMediaPlayer(int nativePlayerInstanceID,
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

}

int CTCMediaServiceClient::addSingleMedia(int index, const char*& mediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

int CTCMediaServiceClient::addBatchMedia(const char*& batchMediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::removeMediaByEntryID(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);

}

void CTCMediaServiceClient::removeMediaByIndex(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::clearAllMedia()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::moveMediaByIndex(const char*& entryID, int toIndex)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::moveMediaByOffset(const char*& entryID, int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::moveMediaByIndex1(int index, int toIndex)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::moveMediaByOffset1(int index, int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::moveMediaToNext(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::moveMediaToPrevious(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::moveMediaToFirst(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::moveMediaToLast(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::moveMediaToNext1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::moveMediaToPrevious1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::moveMediaToFirst1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::moveMediaToLast1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::selectMediaByIndex(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::selectMediaByOffset(int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::selectNext()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::selectPrevious()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::selectFirst()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::selectLast()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

void CTCMediaServiceClient::selectMediaByEntryID(const char*& entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
}

/*int CTCMediaServiceClient::joinChannel(int userchannelid)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  userchannelid = %d;", __func__, __LINE__, userchannelid);
    char* url = "";
    LOGD("liubin CTCMediaServiceClient::joinChannel url = %s", url);
    android_iptvmplayer_CTC_IPTVPlayer_join(url, userchannelid); 
    return 0;
}*/

void CTCMediaServiceClient::joinChannel(char *url, char* channelname, int channelid)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  url = %s;", __func__, __LINE__, url);
    LOGD("%s line(%d)  channelname = %s;", __func__, __LINE__, channelname);
    LOGD("%s line(%d)  channelid = %d;", __func__, __LINE__, channelid);
    android_iptvmplayer_CTC_IPTVPlayer_join(url, channelid);
}

void CTCMediaServiceClient::leaveChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
}

/*void CTCMediaServiceClient::playFromStart()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* url = "igmp://239.93.0.123:5140|rtsp://182.139.229.78/PLTV/88888888/224/3221226241/00000100000000060000000000035215_0.smil?rrsip=182.138.3.139&icpid=SSPID&accounttype=1&limitflux=-1&limitdur=-1&accountinfo=:20161116192559,DMTJDTTEST16@ITVP,10.99.167.54,20161116192559,Umai:CHAN/111131@BESTV.SMG.SMG,C0E3AF94294C7B9D0F4E1E5D58F38994,-1,1,1,,,7,,,,4,END";
    android_iptvmplayer_CTC_IPTVPlayer_play(url);
}*/


void CTCMediaServiceClient::playFromStart(char*& mediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    //char* url = "igmp://239.93.0.123:5140|rtsp://182.139.229.78/PLTV/88888888/224/3221226241/00000100000000060000000000035215_0.smil?rrsip=182.138.3.139&icpid=SSPID&accounttype=1&limitflux=-1&limitdur=-1&accountinfo=:20161116192559,DMTJDTTEST16@ITVP,10.99.167.54,20161116192559,Umai:CHAN/111131@BESTV.SMG.SMG,C0E3AF94294C7B9D0F4E1E5D58F38994,-1,1,1,,,7,,,,4,END";
    android_iptvmplayer_CTC_IPTVPlayer_play(mediaStr);
}


void CTCMediaServiceClient::playByTime(int type, char*& timestamp, int speed)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  timestamp = %s;", __func__, __LINE__, timestamp);
    android_iptvmplayer_CTC_IPTVPlayer_seek(timestamp);
}

void CTCMediaServiceClient::switchSubtitle()
{
    LOGD("%s line(%d);", __func__, __LINE__);

}

void CTCMediaServiceClient::sendVendorSpecificCommand(const char*& xml)
{
    LOGD("%s line(%d);", __func__, __LINE__);

}

int CTCMediaServiceClient::getAudioPID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

int CTCMediaServiceClient::getAudioPIDs()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::setAudioPID(int pid)
{
    LOGD("%s line(%d);", __func__, __LINE__);

}

int CTCMediaServiceClient::getSubtitlePID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

int CTCMediaServiceClient::getSubtitlePIDs()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

void CTCMediaServiceClient::setSubtitlePID(int pid)
{
    LOGD("%s line(%d);", __func__, __LINE__);

}

int CTCMediaServiceClient::Data(int start, int end)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return start + end + 1;
}

void CTCMediaServiceClient::videoshow()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    android_iptvmplayer_CTC_IPTVPlayer_videoshow();
}

void CTCMediaServiceClient::videohide()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    android_iptvmplayer_CTC_IPTVPlayer_videohide();
}

int CTCMediaServiceClient::bindNativePlayerInstance(int nativePlayerInstanceID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  nativePlayerInstanceID = %d;", __func__, __LINE__, nativePlayerInstanceID);
    return 0;
}

void CTCMediaServiceClient::releaseMediaPlayer(int nativePlayerInstanceID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  nativePlayerInstanceID = %d;", __func__, __LINE__, nativePlayerInstanceID);
    return;
}


void CTCMediaServiceClient::setMuteFlag(int muteFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  muteFlag = %d;", __func__, __LINE__, muteFlag);
    android_iptvmplayer_CTC_IPTVPlayer_setmute(muteFlag);
}

int CTCMediaServiceClient::getMuteFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_MuteFlag = 0;
    m_MuteFlag = android_iptvmplayer_CTC_IPTVPlayer_getmute();
    LOGD("%s line(%d)  m_MuteFlag = %d;", __func__, __LINE__, m_MuteFlag);
    return m_MuteFlag;
}

void CTCMediaServiceClient::setVideoAlpha(int videoAlpha)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  videoAlpha = %d;", __func__, __LINE__, videoAlpha);
    android_iptvmplayer_CTC_IPTVPlayer_setalpha(videoAlpha); 
}

int CTCMediaServiceClient::getVideoAlpha()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;     
}
    
char* CTCMediaServiceClient::getPlaybackMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_PlaybackMode = "";
    char* xingcan = "";//临时的形参赋值
    m_PlaybackMode = android_iptvmplayer_CTC_IPTVPlayer_getplaymode(xingcan); 
    LOGD("%s line(%d)  m_PlaybackMode = %s;", __func__, __LINE__, m_PlaybackMode);
    return m_PlaybackMode;
}

int CTCMediaServiceClient::getChannelNum()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return 0;
}

char* CTCMediaServiceClient::getCurrentAudioChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_AudioChannel = 0;
    m_AudioChannel = android_iptvmplayer_CTC_IPTVPlayer_getaudiobalance();
    LOGD("CTCMediaServiceClient::getCurrentAudioChannel m_AudioChannel = %d", m_AudioChannel);
    switch (m_AudioChannel) {
        case 0:             
            return "Stereo";
        case 1:             
            return "Left";
        case 2:                                                                                                                                
            return "Right";
        case 3:           
            return "JointStereo";
        default:          
            return "";
    } 
}

char* CTCMediaServiceClient::getAudioTrack()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return "";
}

void CTCMediaServiceClient::setSingleMedia(char*& mediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  mediaStr = %s;", __func__, __LINE__, mediaStr);
    android_iptvmplayer_CTC_IPTVPlayer_play(mediaStr);
}

void CTCMediaServiceClient::gotoStart()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    android_iptvmplayer_CTC_IPTVPlayer_gotostart();
}

void CTCMediaServiceClient::gotoEnd()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    android_iptvmplayer_CTC_IPTVPlayer_gotoend();
}

void CTCMediaServiceClient::refreshVideoDisplay()
{
    LOGD("%s line(%d);", __func__, __LINE__);
}

void CTCMediaServiceClient::switchAudioChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    android_iptvmplayer_CTC_IPTVPlayer_switchaudiobalance();
}

void CTCMediaServiceClient::switchAudioTrack()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    android_iptvmplayer_CTC_IPTVPlayer_switchaudiotrack();
}

//game call function                                                                                                                 
void CTCMediaServiceClient::runGame(const char* values)
{
    LOGD("%s line(%d);", __func__, __LINE__);

}
