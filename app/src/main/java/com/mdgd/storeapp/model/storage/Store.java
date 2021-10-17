package com.mdgd.storeapp.model.storage;

import android.os.Handler;
import android.os.Looper;

import androidx.annotation.NonNull;

import com.mdgd.storeapp.model.storage.exception.InvalidTypeException;
import com.mdgd.storeapp.model.storage.exception.NotExistingKeyException;

/**
 * Created by max
 * on 3/16/18.
 */
public class Store {

    static {
        System.loadLibrary("store");
    }

    private final Handler handler = new Handler(Looper.getMainLooper());
    private final StoreListener delegateListener;

    public Store(StoreListener pListener) {
        delegateListener = pListener;
    }

    // from jni
    public void onAlert(int pValue) {
        handler.post(() -> delegateListener.onAlert(pValue));
    }

    public void onAlert(String pValue) {
        handler.post(() -> delegateListener.onAlert(pValue));
    }

    public void onAlert(Color pValue) {
        handler.post(() -> delegateListener.onAlert(pValue));
    }
    // from jni end

    public native int getCount();

    public native int getArchitecture();

    public native long initializeStore();

    public native void finalizeStore(long watcher);


    public native int getInteger(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setInteger(@NonNull String pKey, int pInt);

    public native boolean getBoolean(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setBoolean(@NonNull String pKey, boolean pBool);

    public native byte getByte(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setByte(@NonNull String pKey, byte pByte);

    public native char getChar(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setChar(@NonNull String pKey, char pChar);

    public native double getDouble(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setDouble(@NonNull String pKey, double pDouble);

    public native float getFloat(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setFloat(@NonNull String pKey, float pFloat);

    public native long getLong(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setLong(@NonNull String pKey, long pLong);

    public native short getShort(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setShort(@NonNull String pKey, short pShort);

    @NonNull
    public native String getString(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setString(@NonNull String pKey, @NonNull String pString);

    @NonNull
    public native Color getColor(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setColor(@NonNull String pKey, @NonNull Color pColor);


    @NonNull
    public native boolean[] getBoolArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setBoolArray(@NonNull String pKey, @NonNull boolean[] pBoolArray);

    @NonNull
    public native byte[] getByteArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setByteArray(@NonNull String pKey, @NonNull byte[] pByteArray);

    @NonNull
    public native char[] getCharArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setCharArray(@NonNull String pKey, @NonNull char[] pCharArray);

    @NonNull
    public native double[] getDoubleArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setDoubleArray(@NonNull String pKey, @NonNull double[] pDoubleArray);

    @NonNull
    public native float[] getFloatArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setFloatArray(@NonNull String pKey, @NonNull float[] pFloatArray);

    @NonNull
    public native int[] getIntArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setIntArray(@NonNull String pKey, @NonNull int[] pIntArray);

    @NonNull
    public native long[] getLongArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setLongArray(@NonNull String pKey, @NonNull long[] pLongArray);

    @NonNull
    public native short[] getShortArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setShortArray(@NonNull String pKey, @NonNull short[] pShortArray);

    @NonNull
    public native String[] getStringArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setStringArray(@NonNull String pKey, @NonNull String[] pStringArray);

    @NonNull
    public native Color[] getColorArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException;

    public native void setColorArray(String pKey, Color[] pColorArray);
}
