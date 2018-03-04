package com.packtub;

/**
 * Created by max
 * on 3/3/18.
 */

public interface StoreListener {
    void onAlert(int pValue);
    void onAlert(String pValue);
    void onAlert(Color pValue);
}
