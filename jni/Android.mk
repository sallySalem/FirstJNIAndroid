LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := FirstJNI #libraryName
LOCAL_SRC_FILES := FirstJNI.cpp # we can here the c++ class 

include $(BUILD_SHARED_LIBRARY)
