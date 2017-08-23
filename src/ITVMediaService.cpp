#define TAG "ITVMediaService"

#include "TVMediaService.h"

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

/***********************************************/
/*       liubin add 
 *       因为实现ITVMediaService接口的方法时，
 *       必须使用binder 引用类
 ***********************************************/       
class BpTVMediaService: public BpInterface<ITVMediaService> {
    public:
        BpTVMediaService(const sp<IBinder>& impl) : BpInterface<ITVMediaService>(impl)
        {
        }
        void init(const sp<ITVMediaClient>& client)
        {
            LOGD("BpTVMediaService::init start");
            LOGD("BpTVMediaService init.");
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeStrongBinder(client->asBinder());
            remote()->transact(MEDIA_INIT, data, &reply);
            LOGD("BpTVMediaService::init end");
            return;
        }

        int create(const char* url, int id)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeCString(url != NULL ? url : "");
            data.writeInt32(id);
            remote()->transact(MEDIA_CREATE, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        void reset()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_RESET, data, &reply);
        }
        void play()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_PLAY, data, &reply);
        }

        void stop()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_STOP, data, &reply);
        }

        void pause()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_PAUSE, data, &reply);
        }

        void resume()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_RESUME, data, &reply);
        }

        void seek(int time)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(time);
            remote()->transact(MEDIA_SEEK, data, &reply);
        }

        void fast(int speed)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(speed);
            remote()->transact(MEDIA_FAST, data, &reply);
        }

        void rewind(int speed)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(speed);
            remote()->transact(MEDIA_REWIND, data, &reply);
        }

        int getVolume()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETVOLUME, data, &reply);
            int volume = reply.readInt32();
            return volume;
        }

        void setVolume(int volume)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(volume);
            remote()->transact(MEDIA_SETVOLUME, data, &reply);
        }

        int getMute()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETMUTE, data, &reply);
            int mute = reply.readInt32();
            return mute;
        }

        void setMute(int mute)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(mute);
            remote()->transact(MEDIA_SETMUTE, data, &reply);
        }

        void setRatio()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_SETRATIO, data, &reply);
        }

        int getPlayMode()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETPLAYMODE, data, &reply);
            int mode = reply.readInt32();
            return mode;
        }

        int getCurrentPos()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETCURRENTPOS, data, &reply);
            int pos = reply.readInt32();
            return pos;
        }

        int getVideoPixels()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETVIDEOPIXELS, data, &reply);
            int pixels = reply.readInt32();
            return pixels;
        }

        int getDuration()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETDURATION, data, &reply);
            int duration = reply.readInt32();
            return duration;
        }

        int getVersion()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETVERSION, data, &reply);
            int version = reply.readInt32();
            return version;
        }

        void setVideoWindow(int x, int y, int width, int height, int mode)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(x);
            data.writeInt32(y);
            data.writeInt32(width);
            data.writeInt32(height);
            data.writeInt32(mode);
            remote()->transact(MEDIA_SETVIDEOWINDOW, data, &reply);
        }

        int getPlayerInstaceId()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETPLAYERINSTACEID, data, &reply);
            int id = reply.readInt32();
            return id;
        }

        void setAlpha()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_SETALPHA, data, &reply);
        }
        
        //liubin add
        char* set(char*& ioStr, char*& wrStr)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeCString(ioStr);
            data.writeCString(wrStr);
            remote()->transact(MEDIA_SET, data, &reply);
            char* res = reply.readCString();
            return res;
        }   

        char* get(char* ioStr)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeCString(ioStr);
            remote()->transact(MEDIA_GET, data, &reply);
            char* res = reply.readCString();
            return res;
        }

        int getNativePlayerInstanceID()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETNATIVEPLAYERINSTANCEID, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        void setSingleOrPlaylistMode(int mode)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(mode);
            remote()->transact(MEDIA_SETSINGLEORPLAYLISTMODE, data, &reply);
        }

        int getSingleOrPlaylistMode()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETSINGLEORPLAYLISTMODE, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        void setVideoDisplayMode(int videoDisplayMode)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(videoDisplayMode);
            remote()->transact(MEDIA_SETVIDEODISPLAYMODE, data, &reply);
        }

        int getVideoDisplayMode()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETVIDEODISPLAYMODE, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        void setVideoDisplayArea(int x, int y, int width, int height)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(x);
            data.writeInt32(y);
            data.writeInt32(width);
            data.writeInt32(height);
            remote()->transact(MEDIA_SETVIDEODISPLAYAREA, data, &reply);
        }


        int getVideoDisplayLeft()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETVIDEODISPLAYLEFT, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        int getVideoDisplayTop()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETVIDEODISPLAYTOP, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        int getVideoDisplayWidth()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETVIDEODISPLAYWIDTH, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        int getVideoDisplayHeight()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETVIDEODISPLAYHEIGHT, data, &reply);
            int res = reply.readInt32();
            return res;
        }
        
        void setNativeUIFlag(int nativeUIFlag)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(nativeUIFlag);
            remote()->transact(MEDIA_SETNATIVEUIFLAG, data, &reply);
        }

        int getNativeUIFlag()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETNATIVEUIFLAG, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        void setMuteUIFlag(int muteUIFlag)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(muteUIFlag);
            remote()->transact(MEDIA_SETMUTEUIFLAG, data, &reply);
        }

        int getMuteUIFlag()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETMUTEUIFLAG, data, &reply);
            int res = reply.readInt32();
            return res;
        }
          
        void setAudioVolumeUIFlag(int audioVolumeUIFlag)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(audioVolumeUIFlag);
            remote()->transact(MEDIA_SETAUDIOVOLUMEUIFLAG, data, &reply);
        }
        
        int getAudioVolumeUIFlag()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETAUDIOVOLUMEUIFLAG, data, &reply);
            int res = reply.readInt32();
            return res;
        }
       
        void setAudioTrackUIFlag(int audioTrackUIFlag)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(audioTrackUIFlag);
            remote()->transact(MEDIA_SETAUDIOTRACKUIFLAG, data, &reply);
        }

        int getAudioTrackUIFlag()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETAUDIOTRACKUIFLAG, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        void setProgressBarUIFlag(int progressBarUIFlag)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(progressBarUIFlag);
            remote()->transact(MEDIA_SETPROGRESSBARUIFLAG, data, &reply);
        }

        int getProgressBarUIFlag()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETPROGRESSBARUIFLAG, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        void setChannelNoUIFlag(int channelNOUIFlag)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(channelNOUIFlag);
            remote()->transact(MEDIA_SETCHANNELNOUIFLAG, data, &reply);
        }

        int getChannelNoUIFlag()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETCHANNELNOUIFLAG, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        void setSubtitileFlag(int subtitileFlag)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(subtitileFlag);
            remote()->transact(MEDIA_SETSUBTITILEFLAG, data, &reply);
        }

        int getSubtitileFlag()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETSUBTITILEFLAG, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        void setAllowTrickmodeFlag(int allowTrickmodeFlag)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(allowTrickmodeFlag);
            remote()->transact(MEDIA_SETALLOWTRICKMODEFLAG, data, &reply);
        }

        int getAllowTrickmodeFlag()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETALLOWTRICKMODEFLAG, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        void setCycleFlag(int cycleFlag)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(cycleFlag);
            remote()->transact(MEDIA_SETCYCLEFLAG, data, &reply);
        }

        int getCycleFlag()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETCYCLEFLAG, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        void setRandomFlag(int randomFlag)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(randomFlag);
            remote()->transact(MEDIA_SETRANDOMFLAG, data, &reply);
        }

        int getRandomFlag()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETRANDOWFLAG, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        void setVendorSpecificAttr(const char*& vendorSpecificAttr)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeCString(vendorSpecificAttr);
            remote()->transact(MEDIA_SETVENDORSPECIFICATTR, data, &reply);
        }

        char* getVendorSpecificAttr()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETVENDORSPECIFICATTR, data, &reply);
            char* res = reply.readCString();
            return res;
        }

        char* getMediaCode()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETMEDIACODE, data, &reply);
            char* res = reply.readCString();
            return res;
        }
        
        char* getCurrentPlayTime()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETCURRENTPLAYTIME, data, &reply);
            char* res = reply.readCString();
            return res;
        }
        
        int GetLastError()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETLASTERROR, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        char* getSubtitle()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETSUBTITLE, data, &reply);
            char* res = reply.readCString();
            return res;
        }
        
        int getMediaCount()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETMEDIACOUNT, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        int getCurrentIndex()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETCURRENTINDEX, data, &reply);
            int res = reply.readInt32();
            return res;
        }
        
        char* getEntryID()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETENTRYID, data, &reply);
            char* res = reply.readCString();
            return res;
        }
        
        char* getPlaylist()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETPLAYLIST, data, &reply);
            char* res = reply.readCString();
            return res;
        }

        void initMediaPlayer(int nativePlayerInstanceID,
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
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(nativePlayerInstanceID);
            data.writeInt32(playlistFlag);
            data.writeInt32(videoDisplayMode);
            data.writeInt32(height);
            data.writeInt32(width);
            data.writeInt32(left);
            data.writeInt32(top);
            data.writeInt32(muteFlag);
            data.writeInt32(useNativeUIFlag);
            data.writeInt32(subtitleFlag);
            data.writeInt32(videoAlpha);
            data.writeInt32(cycleFlag);
            data.writeInt32(randomFlag);
            remote()->transact(MEDIA_INITMEDIAPLAYER, data, &reply);
        }

        int addSingleMedia(int index, const char*& mediaStr)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(index);
            data.writeCString(mediaStr);
            remote()->transact(MEDIA_ADDSINGLEMEDIA, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        int addBatchMedia(const char*& batchMediaStr)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeCString(batchMediaStr);
            remote()->transact(MEDIA_ADDBATCHMEDIA, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        void removeMediaByEntryID(const char*& entryID)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeCString(entryID);
            remote()->transact(MEDIA_REMOVEMEDIABYENTRYID, data, &reply);
        }

        void removeMediaByIndex(int index)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(index);
            remote()->transact(MEDIA_REMOVEMEDIABYINDEX, data, &reply);
        }

        void clearAllMedia()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_CLEARALLMEDIA, data, &reply);
        }

        void moveMediaByIndex(const char*& entryID, int toIndex)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeCString(entryID); 
            data.writeInt32(toIndex);
            remote()->transact(MEDIA_MOVEMEDIABYINDEX, data, &reply);
        }
        
        void moveMediaByOffset(const char*& entryID, int offset)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeCString(entryID); 
            data.writeInt32(offset);
            remote()->transact(MEDIA_MOVEMEDIABYOFFSET, data, &reply);
        }
        
        void moveMediaByIndex1(int index, int toIndex)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(index); 
            data.writeInt32(toIndex);
            remote()->transact(MEDIA_MOVEMEDIABYINDEX1, data, &reply);
        }
        
        void moveMediaByOffset1(int index, int offset)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(index); 
            data.writeInt32(offset);
            remote()->transact(MEDIA_MOVEMEDIABYOFFSET1, data, &reply);
        }

        void moveMediaToNext(const char*& entryID)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeCString(entryID);
            remote()->transact(MEDIA_MOVEMEDIATONEXT, data, &reply);
        }

        void moveMediaToPrevious(const char*& entryID)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeCString(entryID);
            remote()->transact(MEDIA_MOVEMEDIATOPREVIOUS, data, &reply);
        }

        void moveMediaToFirst(const char*& entryID)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeCString(entryID);
            remote()->transact(MEDIA_MOVEMEDIATOFIRST, data, &reply);
        }

        void moveMediaToLast(const char*& entryID)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeCString(entryID);
            remote()->transact(MEDIA_MOVEMEDIATOLAST, data, &reply);
        }

        void moveMediaToNext1(int index)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(index);
            remote()->transact(MEDIA_MOVEMEDIATONEXT1, data, &reply);
        }

        void moveMediaToPrevious1(int index)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(index);
            remote()->transact(MEDIA_MOVEMEDIATOPREVIOUS1, data, &reply);
        }

        void moveMediaToFirst1(int index)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(index);
            remote()->transact(MEDIA_MOVEMEDIATOFIRST1, data, &reply);
        }

        void moveMediaToLast1(int index)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(index);
            remote()->transact(MEDIA_MOVEMEDIATOLAST1, data, &reply);
        }

        void selectMediaByIndex(int index)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(index);
            remote()->transact(MEDIA_SELECTMEDIABYINDEX, data, &reply);
        }

        void selectMediaByOffset(int offset)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(offset);
            remote()->transact(MEDIA_SELECTMEDIABYOFFSET, data, &reply);
        }

        void selectNext()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_SELECTNEXT, data, &reply);
        }

        void selectPrevious()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_SELECTPREVIOUS, data, &reply);
        }

        void selectFirst()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_SELECTFIRST, data, &reply);
        }

        void selectLast()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_SELECTLAST, data, &reply);
        }

        void selectMediaByEntryID(const char*& entryID)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeCString(entryID);
            remote()->transact(MEDIA_SELECTMEDIABYENTRYID, data, &reply);
        }

        int joinChannel(int userchannelid)
        { 
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(userchannelid);
            remote()->transact(MEDIA_JOINCHANNEL, data, &reply);
            int res = reply.readInt32();
            return res;
        }
        
        void leaveChannel()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_LEAVECHANNEL, data, &reply);
        }

        void playFromStart()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_PLAYFROMSTART, data, &reply);
        }   

        void playByTime(int type, char*& timestamp, int speed)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(type); 
            data.writeCString(timestamp);
            data.writeInt32(speed);
            remote()->transact(MEDIA_PLAYBYTIME, data, &reply);
        }

        void switchSubtitle()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_SWITCHSUBTITLE, data, &reply);
        }   

        void sendVendorSpecificCommand(const char*& xml)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeCString(xml);
            remote()->transact(MEDIA_SENDVENDORSPECIFICCOMMAND, data, &reply);
        }   

        int getAudioPID()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETAUDIOPID, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        int getAudioPIDs()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETAUDIOPIDS, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        void setAudioPID(int pid)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(pid);
            remote()->transact(MEDIA_SETAUDIOPID, data, &reply);
        }

        int getSubtitlePID()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETSUBTITLEPID, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        int getSubtitlePIDs()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETSUBTITLEPIDS, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        void setSubtitlePID(int pid)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(pid);
            remote()->transact(MEDIA_SETSUBTITLEPID, data, &reply);
        }
        
        int Data(int start, int end)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(start);
            data.writeInt32(end);
            remote()->transact(MEDIA_DATA, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        void videoshow()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_VIDEOSHOW, data, &reply);
        }

        void videohide()
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_VIDEOHIDE, data, &reply);
        }

        int bindNativePlayerInstance(int nativePlayerInstanceID)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(nativePlayerInstanceID);
            remote()->transact(MEDIA_BINDNATIVEPLAYERINSTANCE, data, &reply);
            int res = reply.readInt32();
            return res;
        }

        void releaseMediaPlayer(int nativePlayerInstanceID)
        {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(nativePlayerInstanceID);
            remote()->transact(MEDIA_RELEASEMEDIAPLAYER, data, &reply);
        }
 
       void setMuteFlag(int muteFlag)
       {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(muteFlag);
            remote()->transact(MEDIA_SETMUTEFLAG, data, &reply);
       }

       int getMuteFlag()
       {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETMUTEFLAG, data, &reply);
            int res = reply.readInt32();
            return res;
       }
 
       void setVideoAlpha(int videoAlpha)
       {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeInt32(videoAlpha);
            remote()->transact(MEDIA_SETVIDEOALPHA, data, &reply);
       }

       int getVideoAlpha()
       {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETVIDEOALPHA, data, &reply);
            int res = reply.readInt32();
            return res;
       }
 
       char* getPlaybackMode()
       {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETPLAYBACKMODE, data, &reply);
            char* res = reply.readCString();
            return res;
       }
       
       int getChannelNum()
       {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETCHANNELNUM, data, &reply);
            int res = reply.readInt32();
            return res;
       }
       
      char* getCurrentAudioChannel()
      {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETCURRENTAUDIOCHANNEL, data, &reply);
            char* res = reply.readCString();
            return res;
      }
      
      char* getAudioTrack()
      {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GETAUDIOTRACK, data, &reply);
            char* res = reply.readCString();
            return res;
      }
            
      void setSingleMedia(char*& mediaStr)
      {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            data.writeCString(mediaStr);
            remote()->transact(MEDIA_SETSINGLEMEDIA, data, &reply);
      }
       
      void gotoStart()
      {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GOTOSTART, data, &reply);
      }

      void gotoEnd()
      {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_GOTOEND, data, &reply);
      }
      
      void refreshVideoDisplay()
      {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_REFRESHVIDEODISPLAY, data, &reply);
      }
      
      void switchAudioChannel()
      {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_SWITCHAUDIOCHANNEL, data, &reply);
      }

      void switchAudioTrack()
      {
            LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
            Parcel data, reply;
            data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
            remote()->transact(MEDIA_SWITCHAUDIOTRACK, data, &reply);
      }

      //game call function                                                                                                                 
      void runGame(const char* values)
      {
          LOGD("BpTVMediaService::%s line(%d);", __func__, __LINE__);
          Parcel data, reply;
          data.writeInterfaceToken(ITVMediaService::getInterfaceDescriptor());
          data.writeCString(values);
          remote()->transact(MEDIA_RUNGAME, data, &reply);
      }

 

};
//liubin add 实现ITVMediaService接口的方法
IMPLEMENT_META_INTERFACE(TVMediaService, "com.iptvmedia.ITVMediaService");
