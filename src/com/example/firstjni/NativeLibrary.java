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
