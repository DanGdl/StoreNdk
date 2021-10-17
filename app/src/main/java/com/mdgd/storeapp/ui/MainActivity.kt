package com.mdgd.storeapp.ui

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.mdgd.storeapp.R

/**
 * Created by max
 * on 3/16/18.
 */
class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        supportFragmentManager.beginTransaction().add(R.id.fragmentContainer, StoreFragment.newInstance()).commit()
    }
}
