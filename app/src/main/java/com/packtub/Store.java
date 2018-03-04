package com.packtub;

import android.os.Handler;

import com.packtub.exception.InvalidTypeException;
import com.packtub.exception.NotExistingKeyException;

/**
 * Created by max
 * on 2/21/18.
 */

public class Store {
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("store");
    }

    private Handler handler;

    private StoreListener delegateListener;

    public Store(StoreListener pListener) {
        handler = new Handler();
        delegateListener = pListener;
    }

    public void onAlert(final int pValue) {
        handler.post(new Runnable() {
            public void run() {
                delegateListener.onAlert(pValue);
            }
        });
    }

    public void onAlert(final String pValue) {
        handler.post(new Runnable() {
            public void run() {
                delegateListener.onAlert(pValue);
            }
        });
    }

    public void onAlert(final Color pValue) {
        handler.post(new Runnable() {
            public void run() {
                delegateListener.onAlert(pValue);
            }
        });
    }

    public synchronized native int getInteger(String pKey) throws NotExistingKeyException, InvalidTypeException;
    public synchronized native void setInteger(String pKey, int pInt);

    public synchronized native String getString(String pKey) throws NotExistingKeyException, InvalidTypeException;
    public synchronized native void setString(String pKey, String pString);

    public synchronized native boolean getBoolean(String pKey) throws NotExistingKeyException, InvalidTypeException;
    public synchronized native void setBoolean(String pKey, boolean pBool);

    public synchronized native byte getByte(String pKey) throws NotExistingKeyException, InvalidTypeException;
    public synchronized native void setByte(String pKey, byte pByte);

    public synchronized native char getChar(String pKey) throws NotExistingKeyException, InvalidTypeException;
    public synchronized native void setChar(String pKey, char pChar);

    public synchronized native double getDouble(String pKey) throws NotExistingKeyException, InvalidTypeException;
    public synchronized native void setDouble(String pKey, double pDouble);

    public synchronized native float getFloat(String pKey) throws NotExistingKeyException, InvalidTypeException;
    public synchronized native void setFloat(String pKey, float pFloat);

    public synchronized native long getLong(String pKey) throws NotExistingKeyException, InvalidTypeException;
    public synchronized native void setLong(String pKey, long pLong);

    public synchronized native short getShort(String pKey) throws NotExistingKeyException, InvalidTypeException;
    public synchronized native void setShort(String pKey, short pShort);

    public synchronized native Color getColor(String pKey) throws NotExistingKeyException, InvalidTypeException;
    public synchronized native void setColor(String pKey, Color pColor);

    public synchronized native int[] getIntArray(String pKey) throws NotExistingKeyException, InvalidTypeException;
    public synchronized native void setIntArray(String pKey, int[] pIntArray);

    public synchronized native Color[] getColorArray(String pKey) throws NotExistingKeyException, InvalidTypeException;
    public synchronized native void setColorArray(String pKey, Color[] pColorArray);

    public synchronized native void setStringArray(String key, String[] arr);
    public synchronized native String[] getStringArray(String key);

    public synchronized native void setBoolArray(String key, boolean[] arr);
    public synchronized native boolean[] getBoolArray(String key);

    public synchronized native void setByteArray(String key, byte[] arr);
    public synchronized native byte[] getByteArray(String key);

    public synchronized native void setCharArray(String key, char[] arr);
    public synchronized native char[] getCharArray(String key);;

    public synchronized native void setDoubleArray(String key, double[] arr);
    public synchronized native double[] getDoubleArray(String key);

    public synchronized native void setFloatArray(String key, float[] arr);;
    public synchronized native float[] getFloatArray(String key);

    public synchronized native void setLongArray(String key, long[] arr);
    public synchronized native long[] getLongArray(String key);

    public synchronized native void setShortArray(String key, short[] arr);
    public synchronized native short[] getShortArray(String key);

    public native void initializeStore();
    public native short[] finalizeStore();
}
