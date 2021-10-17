package com.mdgd.storeapp.ui

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ArrayAdapter
import android.widget.EditText
import android.widget.Spinner
import android.widget.Toast
import androidx.fragment.app.Fragment
import com.mdgd.storeapp.R
import com.mdgd.storeapp.dto.Color
import com.mdgd.storeapp.dto.StoreListener
import com.mdgd.storeapp.dto.StoreThreadSafe
import com.mdgd.storeapp.dto.StoreType
import java.util.*


class StoreFragment : Fragment(), StoreListener, View.OnClickListener {

    private val store = StoreThreadSafe(this)
    private var watcher: Long? = null
    private var etKey: EditText? = null
    private var etValue: EditText? = null
    private var typeSpn: Spinner? = null
    private var setValBtn: View? = null
    private var getValBtn: View? = null
    private var colorTest: View? = null

    companion object {

        fun newInstance(): StoreFragment {
            return StoreFragment()
        }
    }

    override fun onCreateView(inflater: LayoutInflater, container: ViewGroup?, savedInstanceState: Bundle?): View? {
        val v = inflater.inflate(R.layout.fragment_store, container, false)
        colorTest = v.findViewById(R.id.colorTest)
        etKey = v.findViewById(R.id.keyInput)
        etValue = v.findViewById(R.id.valueInput)
        typeSpn = v.findViewById(R.id.typeSelector)
        setValBtn = v.findViewById(R.id.setValueBtn)
        getValBtn = v.findViewById(R.id.getValueBtn)

        typeSpn!!.adapter = ArrayAdapter<StoreType>(context!!, android.R.layout.simple_list_item_1, StoreType.values())

        setValBtn!!.setOnClickListener(this)
        getValBtn!!.setOnClickListener(this)
        return v
    }

    override fun onActivityCreated(savedInstanceState: Bundle?) {
        super.onActivityCreated(savedInstanceState)
        if (activity != null) {
            activity!!.title = String.format("Store (%1\$s)", store.count.toString() + ", Build " + store.architecture)
        }
    }

    override fun onStart() {
        super.onStart()
        watcher = store.initializeStore()
    }

    override fun onStop() {
        store.finalizeStore(watcher!!)
        super.onStop()
    }

    override fun onClick(v: View) {
        if (v === setValBtn) {
            executeSetValue()
        }
        else if (v === getValBtn) {
            executeGetValue()
        }
    }

    private fun executeSetValue() {
        val key = etKey?.text.toString()
        val value = etValue?.text.toString()
        val lType = typeSpn?.selectedItem as StoreType
        try {
            when (lType) {
                StoreType.Integer -> {
                    store.setInteger(key, Integer.parseInt(value))
                }

                StoreType.String -> {
                    store.setString(key, value)
                }

                StoreType.Bool -> {
                    store.setBoolean(key, value.toBoolean())
                }

                StoreType.Byte -> {
                    store.setByte(key, value.toByte())
                }

                StoreType.Char -> {
                    if(value.length == 1) {
                        store.setChar(key, value[0])
                    }
                    else{
                        Toast.makeText(activity, R.string.too_long_string, Toast.LENGTH_SHORT).show()
                        return
                    }
                }

                StoreType.Double -> {
                    store.setDouble(key, value.toDouble())
                }

                StoreType.Float -> {
                    store.setFloat(key, value.toFloat())
                }

                StoreType.Long -> {
                    store.setLong(key, value.toLong())
                }

                StoreType.Short -> {
                    store.setShort(key, value.toShort())
                }

                StoreType.Color -> {
                    val color = Color(value)
                    colorTest!!.setBackgroundColor(color.color)
                    store.setColor(key, color)
                    Toast.makeText(activity, R.string.done, Toast.LENGTH_SHORT).show()
                    return
                }

                StoreType.IntArray -> {
                    store.setIntArray(key, ArrayConverter({size -> Array(size){_ -> 0}},
                            {vlue -> vlue.toInt()}).convertArray(value))
                }

                StoreType.StringArray -> {
                    store.setStringArray(key, value.split("; ").toTypedArray())
                }

                StoreType.BoolArray -> {
                    store.setBoolArray(key, ArrayConverter({size -> Array(size){_ -> false}},
                            {vlue -> vlue.toBoolean()}).convertArray(value))
                }

                StoreType.ByteArray -> {
                    store.setByteArray(key, ArrayConverter({size -> Array(size){_ -> 0.toByte()}},
                            {vlue -> vlue.toByte()}).convertArray(value))
                }

                StoreType.CharArray -> {
                    store.setCharArray(key, ArrayConverter({size -> Array(size){_ -> 0.toChar()}},
                            {vlue -> vlue.first()}).convertArray(value))
                }

                StoreType.DoubleArray -> {
                    store.setDoubleArray(key, ArrayConverter({size -> Array(size){_ -> 0.toDouble()}},
                            {vlue -> vlue.toDouble()}).convertArray(value))
                }

                StoreType.FloatArray -> {
                    store.setFloatArray(key, ArrayConverter({size -> Array(size){_ -> 0.toFloat()}},
                            {vlue -> vlue.toFloat()}).convertArray(value))
                }

                StoreType.LongArray -> {
                    store.setLongArray(key, ArrayConverter({size -> Array(size){_ -> 0.toLong()}},
                            {vlue -> vlue.toLong()}).convertArray(value))
                }

                StoreType.ShortArray -> {
                    store.setShortArray(key, ArrayConverter({size -> Array(size){_ -> 0.toShort()}},
                            {vlue -> vlue.toShort()}).convertArray(value))
                }

                StoreType.ColorArray -> {
                    store.setColorArray(key, ArrayConverter({size -> Array(size){_ -> Color("#000")}},
                            {vlue -> Color(vlue)}).convertArray(value))
                }
            }
            Toast.makeText(activity, R.string.done, Toast.LENGTH_SHORT).show()
        } catch (e: Throwable) {
            e.printStackTrace()
            displayError(e.message!!)
        }

        colorTest?.setBackgroundColor(0)
    }

    private fun executeGetValue() {
        val key = etKey?.text.toString()
        val lType = typeSpn?.selectedItem as StoreType
        try {
            when (lType) {
                StoreType.Integer -> {
                    etValue?.setText(store.getInteger(key).toString())
                }

                StoreType.String -> {
                    etValue?.setText(store.getString(key))
                }

                StoreType.Bool -> {
                    etValue?.setText(store.getBoolean(key).toString())
                }

                StoreType.Byte -> {
                    etValue?.setText(store.getByte(key).toString())
                }

                StoreType.Char -> {
                    etValue?.setText(store.getChar(key).toInt())
                }

                StoreType.Double -> {
                    etValue?.setText(store.getDouble(key).toString())
                }

                StoreType.Float -> {
                    etValue?.setText(store.getFloat(key).toString())
                }

                StoreType.Long -> {
                    etValue?.setText(store.getLong(key).toString())
                }

                StoreType.Short -> {
                    etValue?.setText(store.getShort(key).toString())
                }

                StoreType.Color -> {
                    val color = store.getColor(key)
                    colorTest?.setBackgroundColor(color.color)
                    etValue?.setText(color.toString())
                }

                StoreType.IntArray -> {
                    etValue?.setText(Arrays.toString(store.getIntArray(key)))
                }

                StoreType.StringArray -> {
                    etValue?.setText(Arrays.toString(store.getStringArray(key)))
                }

                StoreType.BoolArray -> {
                    etValue?.setText(Arrays.toString(store.getBoolArray(key)))
                }

                StoreType.ByteArray -> {
                    etValue?.setText(Arrays.toString(store.getByteArray(key)))
                }

                StoreType.CharArray -> {
                    etValue?.setText(Arrays.toString(store.getCharArray(key)))
                }

                StoreType.DoubleArray -> {
                    etValue?.setText(Arrays.toString(store.getDoubleArray(key)))
                }

                StoreType.FloatArray -> {
                    etValue?.setText(Arrays.toString(store.getFloatArray(key)))
                }

                StoreType.LongArray -> {
                    etValue?.setText(Arrays.toString(store.getLongArray(key)))
                }

                StoreType.ShortArray -> {
                    etValue?.setText(Arrays.toString(store.getShortArray(key)))
                }

                StoreType.ColorArray -> {
                    etValue?.setText(Arrays.toString(store.getColorArray(key)))
                }
            }
        } catch (e: Exception) {
            e.printStackTrace()
            displayError(e.message!!)
        }
    }

    override fun onAlert(pValue: Int) {
        displayError(String.format(Locale.getDefault(), "%1\$d is put", pValue))
    }

    override fun onAlert(pValue: String) {
        displayError(String.format(Locale.getDefault(), "%1\$s is put", pValue))
    }

    override fun onAlert(pValue: Color) {
        displayError(String.format(Locale.getDefault(), "%1\$s put", pValue.toString()))
    }

    private fun displayError(format: String) {
        Toast.makeText(activity, format, Toast.LENGTH_SHORT).show()
    }
}
