package com.mdgd.storeapp.model.storage

/**
 * Created by max
 * on 3/3/18.
 */
interface StoreListener {
    fun onAlert(pValue: Int)
    fun onAlert(pValue: String)
    fun onAlert(pValue: Color)
}
