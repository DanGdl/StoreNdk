package com.mdgd.storeapp.ui

class ArrayConverter<T>(private val cConverter: (size: Int) -> Array<T>, private val vConverter: (value: String) -> T) {

    fun convertArray(array: String): Array<T> {
        val vals = array.split("; ".toRegex()).dropLastWhile { it.isEmpty() }.toTypedArray()
        val arr = cConverter.invoke(vals.size)
        for (i in vals.indices) {
            arr[i] = vConverter.invoke(vals[i])
        }
        return arr
    }
}
