LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := eng

LOCAL_SRC_FILES := \
	IPTVMediaClient.cpp \
	ITVMediaClient.cpp \
	ITVMediaService.cpp \
	TVMediaClient.cpp \
	IPTVMediaService.cpp \
	TVMediaService.cpp \
    CTCMediaServiceClient.cpp	
LOCAL_C_INCLUDES += \
    $(LOCAL_PATH)/../include \
    $(LOCAL_PATH)/.. \
	bionic \
	bionic/libstdc++/include \
	external/stlport/stlport
  
#LOCAL_SHARED_LIBRARIES := libbinder libutils liblog libTVMediaService
LOCAL_SHARED_LIBRARIES := \
	    libcutils \
		libdl \
		libstlport \
		libbinder \
		libutils \
		liblog   \
		libCTC_MediaProcessor \
		libCTC_MediaControl
#LOCAL_CFLAGS := -DRIL_SHLIB -fpermissive

LOCAL_CFLAGS += -pie -fPIE -fpermissive
#LOCAL_LDFLAGS += -pie -fPIE

LOCAL_CERTIFICATE := platform

LOCAL_MODULE := libTVMediaService

include $(BUILD_SHARED_LIBRARY)
