package com.mdgd.storeapp.dto;

import androidx.annotation.NonNull;

import com.mdgd.storeapp.exception.InvalidTypeException;
import com.mdgd.storeapp.exception.NotExistingKeyException;

/**
 * Created by max
 * on 3/16/18.
 */

public class StoreThreadSafe extends Store {
    protected static Object LOCK; // set in jni

    public StoreThreadSafe(StoreListener pListener) {
        super(pListener);
    }

    @Override
    public int getCount() {
        synchronized (LOCK) {
            return super.getCount();
        }
    }

    @Override
    public int getInteger(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getInteger(pKey);
        }
    }

    @Override
    public void setInteger(@NonNull String pKey, int pInt) {
        synchronized (LOCK) {
            super.setInteger(pKey, pInt);
        }
    }

    @Override
    public boolean getBoolean(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getBoolean(pKey);
        }
    }

    @Override
    public void setBoolean(@NonNull String pKey, boolean pBool) {
        synchronized (LOCK) {
            super.setBoolean(pKey, pBool);
        }
    }

    @Override
    public byte getByte(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getByte(pKey);
        }
    }

    @Override
    public void setByte(@NonNull String pKey, byte pByte) {
        synchronized (LOCK) {
            super.setByte(pKey, pByte);
        }
    }

    @Override
    public char getChar(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getChar(pKey);
        }
    }

    @Override
    public void setChar(@NonNull String pKey, char pChar) {
        synchronized (LOCK) {
            super.setChar(pKey, pChar);
        }
    }

    @Override
    public double getDouble(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getDouble(pKey);
        }
    }

    @Override
    public void setDouble(@NonNull String pKey, double pDouble) {
        synchronized (LOCK) {
            super.setDouble(pKey, pDouble);
        }
    }

    @Override
    public float getFloat(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getFloat(pKey);
        }
    }

    @Override
    public void setFloat(@NonNull String pKey, float pFloat) {
        synchronized (LOCK) {
            super.setFloat(pKey, pFloat);
        }
    }

    @Override
    public long getLong(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getLong(pKey);
        }
    }

    @Override
    public void setLong(@NonNull String pKey, long pLong) {
        synchronized (LOCK) {
            super.setLong(pKey, pLong);
        }
    }

    @Override
    public short getShort(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getShort(pKey);
        }
    }

    @Override
    public void setShort(@NonNull String pKey, short pShort) {
        synchronized (LOCK) {
            super.setShort(pKey, pShort);
        }
    }

    @Override
    @NonNull
    public String getString(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getString(pKey);
        }
    }

    @Override
    public void setString(@NonNull String pKey, @NonNull String pString) {
        synchronized (LOCK) {
            super.setString(pKey, pString);
        }
    }

    @Override
    @NonNull
    public Color getColor(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getColor(pKey);
        }
    }

    @Override
    public void setColor(@NonNull String pKey, @NonNull Color pColor) {
        synchronized (LOCK) {
            super.setColor(pKey, pColor);
        }
    }

    @Override
    @NonNull
    public Boolean[] getBoolArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getBoolArray(pKey);
        }
    }

    @Override
    public void setBoolArray(@NonNull String pKey, @NonNull Boolean[] pBoolArray) {
        synchronized (LOCK) {
            super.setBoolArray(pKey, pBoolArray);
        }
    }

    @Override
    @NonNull
    public Byte[] getByteArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getByteArray(pKey);
        }
    }

    @Override
    public void setByteArray(@NonNull String pKey, @NonNull Byte[] pByteArray) {
        synchronized (LOCK) {
            super.setByteArray(pKey, pByteArray);
        }
    }

    @Override
    @NonNull
    public Character[] getCharArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getCharArray(pKey);
        }
    }

    @Override
    public void setCharArray(@NonNull String pKey, @NonNull Character[] pCharArray) {
        synchronized (LOCK) {
            super.setCharArray(pKey, pCharArray);
        }
    }

    @Override
    @NonNull
    public Double[] getDoubleArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getDoubleArray(pKey);
        }
    }

    @Override
    public void setDoubleArray(@NonNull String pKey, @NonNull Double[] pDoubleArray) {
        synchronized (LOCK) {
            super.setDoubleArray(pKey, pDoubleArray);
        }
    }

    @Override
    @NonNull
    public Float[] getFloatArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getFloatArray(pKey);
        }
    }

    @Override
    public void setFloatArray(@NonNull String pKey, @NonNull Float[] pFloatArray) {
        synchronized (LOCK) {
            super.setFloatArray(pKey, pFloatArray);
        }
    }

    @Override
    @NonNull
    public Integer[] getIntArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getIntArray(pKey);
        }
    }

    @Override
    public void setIntArray(@NonNull String pKey, @NonNull Integer[] pIntArray) {
        synchronized (LOCK) {
            super.setIntArray(pKey, pIntArray);
        }
    }

    @Override
    @NonNull
    public Long[] getLongArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getLongArray(pKey);
        }
    }

    @Override
    public void setLongArray(@NonNull String pKey, @NonNull Long[] pLongArray) {
        synchronized (LOCK) {
            super.setLongArray(pKey, pLongArray);
        }
    }

    @Override
    @NonNull
    public Short[] getShortArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getShortArray(pKey);
        }
    }

    @Override
    public void setShortArray(@NonNull String pKey, @NonNull Short[] pShortArray) {
        synchronized (LOCK) {
            super.setShortArray(pKey, pShortArray);
        }
    }

    @Override
    @NonNull
    public String[] getStringArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getStringArray(pKey);
        }
    }

    @Override
    public void setStringArray(@NonNull String pKey, @NonNull String[] pStringArray) {
        synchronized (LOCK) {
            super.setStringArray(pKey, pStringArray);
        }
    }

    @Override
    @NonNull
    public Color[] getColorArray(@NonNull String pKey) throws NotExistingKeyException, InvalidTypeException {
        synchronized (LOCK) {
            return super.getColorArray(pKey);
        }
    }

    @Override
    public void setColorArray(String pKey, Color[] pColorArray) {
        synchronized (LOCK) {
            super.setColorArray(pKey, pColorArray);
        }
    }

    @Override
    public void finalizeStore(long watcher) {
        synchronized (LOCK) {
            super.finalizeStore(watcher);
        }
    }
}
