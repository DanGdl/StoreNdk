package com.mdgd.storeapp.ui

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import com.mdgd.storeapp.R

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        supportFragmentManager.beginTransaction().add(R.id.fragmentContainer, StoreFragment.newInstance()).commit()
    }
}
