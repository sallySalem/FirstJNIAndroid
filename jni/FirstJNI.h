#include <string.h>
#include <jni.h>

extern "C"
{
	JNIEXPORT jstring JNICALL Java_com_example_firstjni_NativeLibrary_getStringFromJNI(
                        JNIEnv * env, jobject obj);
};
