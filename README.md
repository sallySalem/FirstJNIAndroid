# FirstJNIAndroid
it's simple app to start call jni function from android 

 - Change eclipse to support C/C++ environment

 - Download ndk 
[https://developer.android.com/ndk/downloads/index.html](https://developer.android.com/ndk/downloads/index.html)
 
 - From “Window” select “Preferences”
![](https://github.com/sallySalem/FirstJNIAndroid/blob/master/Images/1.png)

 - Under “Android” select “NDK” and add the path of ndk then click “Apply”
![](https://github.com/sallySalem/FirstJNIAndroid/blob/master/Images/2.png)

 - From “File” -> “New” -> “Project”

![](https://github.com/sallySalem/FirstJNIAndroid/blob/master/Images/3.png)

![](https://github.com/sallySalem/FirstJNIAndroid/blob/master/Images/4.png)

![](https://github.com/sallySalem/FirstJNIAndroid/blob/master/Images/5.png)

 - Then “Next” to “Next” … until “Finish”

 - From “Project Explorer” -> right click on Project then select “Android Tools”  -> “Add Native Support”

![](https://github.com/sallySalem/FirstJNIAndroid/blob/master/Images/6.png)

 - You can change the library Name to any name you want Then “Finish”

![](https://github.com/sallySalem/FirstJNIAndroid/blob/master/Images/7.png)

 - You can see “jni” folder by default created

![](https://github.com/sallySalem/FirstJNIAndroid/blob/master/Images/8.png)

 - Under project package add new class “NativeLibrary.java”
``` Java      
package com.example.firstjni;
     public class NativeLibrary {
	static
        {
           System.loadLibrary("FirstJNI");//library Name
        }
    
	//function return string 
	//write the function implementation on .cpp class
    public static native String getStringFromJNI(); 
}      
```

 - Open “MainActivity.java”  and start call the native function
``` Java      
@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		// setContentView(R.layout.activity_main);
	
		TextView tv = new TextView(this);
		tv.setText(NativeLibrary.getStringFromJNI());
		setContentView(tv);
	}
```
 - Open “Android.mk”
``` C++     
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := FirstJNI #libraryName
LOCAL_SRC_FILES := FirstJNI.cpp # we can here the c++ class 

include $(BUILD_SHARED_LIBRARY)  
```
 - Right click to “jni” then add new file “FirstJNI.h”
``` C++
#include <string.h>
#include <jni.h>

extern "C"
{
	JNIEXPORT jstring JNICALL Java_com_example_firstjni_NativeLibrary_getStringFromJNI
                        JNIEnv * env, jobject obj);
};

```

 - Open “FirstJNI.cpp” class and start write the “getStringFromJNI” implementation 
``` c++
#include "FirstJNI.h"

JNIEXPORT jstring //return type string if not return any will be void
JNICALL
//function name must start with Java_packageName(replace "." with "_") then libraryName then functionName
Java_com_example_firstjni_NativeLibrary_getStringFromJNI (
                JNIEnv * env, jobject obj)
{
	return env->NewStringUTF("Hello from C++ over JNI!");
}

```

# If your project have error like this “Type 'JNICALL' could not be resolved”
![](https://github.com/sallySalem/FirstJNIAndroid/blob/master/Images/9.png)

To solve this problem 

* Open “.project” then remove
`      <nature>org.eclipse.cdt.core.ccnature</nature>     `
* To be like that
```
    <natures>
		<nature>com.android.ide.eclipse.adt.AndroidNature</nature>
		<nature>org.eclipse.jdt.core.javanature</nature>
		<nature>org.eclipse.cdt.managedbuilder.core.managedBuildNature</nature>
		<nature>org.eclipse.cdt.managedbuilder.core.ScannerConfigNature</nature>
	</natures>

```
* Then we need to add “Add Native Support”
From “Project Explorer” -> right click on Project then select “Android Tools”  -> “Add Native Support”

* Clean and build
