package com.mdgd.storeapp.dto

import android.os.Handler

import com.mdgd.storeapp.exception.InvalidTypeException
import com.mdgd.storeapp.exception.NotExistingKeyException

/**
 * Created by max
 * on 2/21/18.
 */

open class Store(private val delegateListener: StoreListener) {

    private val handler: Handler

    val architecture: String
        external get

    open val count: Int
        external get

    init {
        handler = Handler()
    }

    // from jni
    fun onAlert(pValue: Int) {
        handler.post { delegateListener.onAlert(pValue) }
    }

    fun onAlert(pValue: String) {
        handler.post { delegateListener.onAlert(pValue) }
    }

    fun onAlert(pValue: Color) {
        handler.post { delegateListener.onAlert(pValue) }
    }
    // from jni end

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getInteger(pKey: String): Int

    open external fun setInteger(pKey: String, pInt: Int)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getString(pKey: String): String

    open external fun setString(pKey: String, pString: String)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getBoolean(pKey: String): Boolean

    open external fun setBoolean(pKey: String, pBool: Boolean)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getByte(pKey: String): Byte

    open external fun setByte(pKey: String, pByte: Byte)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getChar(pKey: String): Char

    open external fun setChar(pKey: String, pChar: Char)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getDouble(pKey: String): Double

    open external fun setDouble(pKey: String, pDouble: Double)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getFloat(pKey: String): Float

    open external fun setFloat(pKey: String, pFloat: Float)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getLong(pKey: String): Long

    open external fun setLong(pKey: String, pLong: Long)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getShort(pKey: String): Short

    open external fun setShort(pKey: String, pShort: Short)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getColor(pKey: String): Color

    open external fun setColor(pKey: String, pColor: Color)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getIntArray(pKey: String): Array<Int>

    open external fun setIntArray(pKey: String, pIntArray: Array<Int>)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getColorArray(pKey: String): Array<Color>

    open external fun setColorArray(pKey: String, pColorArray: Array<Color>)

    open external fun setStringArray(key: String, arr: Array<String>)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getStringArray(key: String): Array<String>

    open external fun setBoolArray(key: String, arr: Array<Boolean>)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getBoolArray(key: String): Array<Boolean>

    open external fun setByteArray(key: String, arr: Array<Byte>)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getByteArray(key: String): Array<Byte>

    open external fun setCharArray(key: String, arr: Array<Char>)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getCharArray(key: String): Array<Char>

    open external fun setDoubleArray(key: String, arr: Array<Double>)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getDoubleArray(key: String): Array<Double>

    open external fun setFloatArray(key: String, arr: Array<Float>)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getFloatArray(key: String): Array<Float>

    open external fun setLongArray(key: String, arr: Array<Long>)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getLongArray(key: String): Array<Long>

    open external fun setShortArray(key: String, arr: Array<Short>)

    @Throws(NotExistingKeyException::class, InvalidTypeException::class)
    open external fun getShortArray(key: String): Array<Short>

    open external fun initializeStore(): Long

    open external fun finalizeStore(watcher: Long)

    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("store")
        }
    }
}

