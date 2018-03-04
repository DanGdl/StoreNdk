package com.packtub;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;

public class StoreActivity extends AppCompatActivity implements View.OnClickListener, StoreListener {

    private EditText etKey, etValue;
    private Spinner typeSpn;
    private View setValBtn, getValBtn, colorTest;
    private Store store;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_store);

        colorTest = findViewById(R.id.colorTest);
        etKey = findViewById(R.id.keyInput);
        etValue = findViewById(R.id.valueInput);
        typeSpn = findViewById(R.id.typeSelector);
        setValBtn = findViewById(R.id.setValueBtn);
        getValBtn = findViewById(R.id.getValueBtn);

        typeSpn.setAdapter(new ArrayAdapter<>(this, android.R.layout.simple_list_item_1,
                new ArrayList<>(Arrays.asList(StoreType.values()))));

        setValBtn.setOnClickListener(this);
        getValBtn.setOnClickListener(this);

        store = new Store(this);
    }

    @Override
    protected void onStart() {
        super.onStart();
        store.initializeStore();
    }

    @Override
    protected void onStop() {
        store.finalizeStore();
        super.onStop();
    }

    @Override
    public void onClick(View v) {
        if(v == setValBtn){
            executeSetValue();
        }
        else if(v == getValBtn){
            executeGetValue();
        }
    }

    private void executeSetValue() {
        String key = etKey.getText().toString();
        String value = etValue.getText().toString();
        StoreType lType = (StoreType) typeSpn.getSelectedItem();
        try {
            switch (lType) {
                case Integer: {
                    store.setInteger(key, Integer.parseInt(value));
                }break;

                case String: {
                    store.setString(key, value);
                }break;

                case Bool: {
                    store.setBoolean(key, Boolean.parseBoolean(value));
                }break;

                case Byte: {
                    store.setByte(key, Byte.parseByte(value));
                }break;

                case Char: {
                    if(value.length() == 1) {
                        store.setChar(key, value.charAt(0));
                    }
                    else{
                        Toast.makeText(this, R.string.too_long_string, Toast.LENGTH_SHORT).show();
                        return;
                    }
                }break;

                case Double: {
                    store.setDouble(key, Double.parseDouble(value));
                }break;

                case Float: {
                    store.setFloat(key, Float.parseFloat(value));
                }break;

                case Long: {
                    store.setLong(key, Long.parseLong(value));
                }break;

                case Short: {
                    store.setShort(key, Short.parseShort(value));
                }break;

                case Color: {
                    Color color = new Color(value);
                    colorTest.setBackgroundColor(color.getColor());
                    store.setColor(key, color);
                    Toast.makeText(this, R.string.done, Toast.LENGTH_SHORT).show();
                    return;
                }

                case IntArray: {
                    String[] vals = value.split("; ");
                    int[] arr = new int[vals.length];
                    for(int i = 0; i < vals.length; i++){
                        arr[i] = Integer.parseInt(vals[i]);
                    }
                    store.setIntArray(key, arr);
                }break;

                case StringArray: {
                    String[] arr = value.split("; ");
                    store.setStringArray(key, arr);
                }break;

                case BoolArray: {
                    String[] vals = value.split("; ");
                    boolean[] arr = new boolean[vals.length];
                    for(int i = 0; i < vals.length; i++){
                        arr[i] = Boolean.parseBoolean(vals[i]);
                    }
                    store.setBoolArray(key, arr);
                }break;

                case ByteArray: {
                    String[] vals = value.split("; ");
                    byte[] arr = new byte[vals.length];
                    for(int i = 0; i < vals.length; i++){
                        arr[i] = Byte.parseByte(vals[i]);
                    }
                    store.setByteArray(key, arr);
                }break;

                case CharArray: {
                    String[] vals = value.split("; ");
                    char[] arr = new char[vals.length];
                    for(int i = 0; i < vals.length; i++){
                        arr[i] = vals[i].charAt(0);
                    }
                    store.setCharArray(key, arr);
                }break;

                case DoubleArray: {
                    String[] vals = value.split("; ");
                    double[] arr = new double[vals.length];
                    for(int i = 0; i < vals.length; i++){
                        arr[i] = Double.parseDouble(vals[i]);
                    }
                    store.setDoubleArray(key, arr);
                }break;

                case FloatArray: {
                    String[] vals = value.split("; ");
                    float[] arr = new float[vals.length];
                    for(int i = 0; i < vals.length; i++){
                        arr[i] = Float.parseFloat(vals[i]);
                    }
                    store.setFloatArray(key, arr);
                }break;

                case LongArray: {
                    String[] vals = value.split("; ");
                    long[] arr = new long[vals.length];
                    for(int i = 0; i < vals.length; i++){
                        arr[i] = Long.parseLong(vals[i]);
                    }
                    store.setLongArray(key, arr);
                }break;

                case ShortArray: {
                    String[] vals = value.split("; ");
                    short[] arr = new short[vals.length];
                    for(int i = 0; i < vals.length; i++){
                        arr[i] = Short.parseShort(vals[i]);
                    }
                    store.setShortArray(key, arr);
                }break;

                case ColorArray: {
                    String[] vals = value.split("; ");
                    Color[] arr = new Color[vals.length];
                    for(int i = 0; i < vals.length; i++){
                        arr[i] = new Color(vals[i]);
                    }
                    store.setColorArray(key, arr);
                }break;
            }
            Toast.makeText(this, R.string.done, Toast.LENGTH_SHORT).show();
        }
        catch (Throwable e){
            e.printStackTrace();
            Toast.makeText(this, e.getMessage(), Toast.LENGTH_SHORT).show();
        }
        colorTest.setBackgroundColor(0);
    }

    private void executeGetValue() {
        String key = etKey.getText().toString();
        StoreType lType = (StoreType) typeSpn.getSelectedItem();
        try {
            switch (lType) {
                case Integer: {
                    etValue.setText(String.valueOf(store.getInteger(key)));
                }break;

                case String: {
                    etValue.setText(String.valueOf(store.getString(key)));
                }break;

                case Bool: {
                    etValue.setText(String.valueOf(store.getBoolean(key)));
                }break;

                case Byte: {
                    etValue.setText(String.valueOf(store.getByte(key)));
                }break;

                case Char: {
                    etValue.setText(store.getChar(key));
                }break;

                case Double: {
                    etValue.setText(String.valueOf(store.getDouble(key)));
                }break;

                case Float: {
                    etValue.setText(String.valueOf(store.getFloat(key)));
                }break;

                case Long: {
                    etValue.setText(String.valueOf(store.getLong(key)));
                }break;

                case Short: {
                    etValue.setText(String.valueOf(store.getShort(key)));
                }break;

                case Color: {
                    Color color = store.getColor(key);
                    colorTest.setBackgroundColor(color.getColor());
                    etValue.setText(color.toString());
                }break;

                case IntArray: {
                    etValue.setText(Arrays.toString(store.getIntArray(key)));
                }break;

                case StringArray: {
                    etValue.setText(Arrays.toString(store.getStringArray(key)));
                }break;

                case BoolArray: {
                    etValue.setText(Arrays.toString(store.getBoolArray(key)));
                }break;

                case ByteArray: {
                    etValue.setText(Arrays.toString(store.getByteArray(key)));
                }break;

                case CharArray: {
                    etValue.setText(Arrays.toString(store.getCharArray(key)));
                }break;

                case DoubleArray: {
                    etValue.setText(Arrays.toString(store.getDoubleArray(key)));
                }break;

                case FloatArray: {
                    etValue.setText(Arrays.toString(store.getFloatArray(key)));
                }break;

                case LongArray: {
                    etValue.setText(Arrays.toString(store.getLongArray(key)));
                }break;

                case ShortArray: {
                    etValue.setText(Arrays.toString(store.getShortArray(key)));
                }break;

                case ColorArray: {
                    etValue.setText(Arrays.toString(store.getColorArray(key)));
                }break;
            }
        }
        catch (Exception e){
            e.printStackTrace();
            Toast.makeText(this, e.getMessage(), Toast.LENGTH_SHORT).show();
        }
    }

    @Override
    public void onAlert(int pValue) {
        displayError(String.format(Locale.getDefault(), "%1$d is not an allowed integer", pValue));
    }

    @Override
    public void onAlert(String pValue) {
        displayError(String.format(Locale.getDefault(), "%1$s is not an allowed string", pValue));
    }

    @Override
    public void onAlert(Color pValue) {
        displayError(String.format(Locale.getDefault(), "%1$s is not an allowed color", pValue.toString()));
    }

    private void displayError(String format) {
        Toast.makeText(this, format, Toast.LENGTH_SHORT).show();
    }
}
