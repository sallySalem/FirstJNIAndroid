#include "FirstJNI.h"

JNIEXPORT jstring //return type string if not return any will be void
JNICALL
//function name must start with Java_packageName(replace "." with "_") then libraryName then functionName
Java_com_example_firstjni_NativeLibrary_getStringFromJNI(
                JNIEnv * env, jobject obj)
{
	return env->NewStringUTF("Hello from C++ over JNI!");
}
