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
import com.mdgd.storeapp.model.storage.Color
import com.mdgd.storeapp.model.storage.StoreListener
import com.mdgd.storeapp.model.storage.StoreThreadSafe
import com.mdgd.storeapp.model.storage.StoreType
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

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        return inflater.inflate(R.layout.fragment_store, container, false)
    }

    override fun onViewCreated(v: View, savedInstanceState: Bundle?) {
        super.onViewCreated(v, savedInstanceState)
        colorTest = v.findViewById(R.id.colorTest)
        etKey = v.findViewById(R.id.keyInput)
        etValue = v.findViewById(R.id.valueInput)
        typeSpn = v.findViewById(R.id.typeSelector)
        setValBtn = v.findViewById(R.id.setValueBtn)
        getValBtn = v.findViewById(R.id.getValueBtn)

        typeSpn?.adapter =
            ArrayAdapter(requireContext(), android.R.layout.simple_list_item_1, StoreType.values())

        setValBtn?.setOnClickListener(this)
        getValBtn?.setOnClickListener(this)

        activity?.title = "${store.count}, Build ${store.architecture}"
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
            lType.mapper.store(store, key, value)
            if (lType == StoreType.Color) {
                colorTest?.setBackgroundColor(Color(value).color)
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
            val value = lType.mapper.remove(store, key)
            etValue?.setText(value)
            if (lType == StoreType.Color) {
                colorTest?.setBackgroundColor(Color(value).color)
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
