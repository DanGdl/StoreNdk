package com.mdgd.storeapp.model.storage;

import com.mdgd.storeapp.model.storage.exception.InvalidTypeException;
import com.mdgd.storeapp.model.storage.exception.NotExistingKeyException;
import com.mdgd.storeapp.model.storage.mapper.StringMapper;

import java.util.StringJoiner;

public enum StoreType {

    Integer(new StringMapper<Integer>() {

        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            storage.setInteger(key, java.lang.Integer.parseInt(value));
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            return java.lang.Integer.toString(storage.getInteger(key));
        }
    }),
    String(new StringMapper<java.lang.String>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            storage.setString(key, value);
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            return storage.getString(key);
        }
    }),
    Bool(new StringMapper<Boolean>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            storage.setBoolean(key, java.lang.Boolean.parseBoolean(value));
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            return java.lang.Boolean.toString(storage.getBoolean(key));
        }
    }),
    Byte(new StringMapper<java.lang.Byte>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            storage.setByte(key, java.lang.Byte.parseByte(value));
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            return java.lang.Byte.toString(storage.getByte(key));
        }
    }),
    Char(new StringMapper<java.lang.Character>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            if (value.length() == 1) {
                storage.setChar(key, value.charAt(0));
            } else {
                throw new RuntimeException("Value is too long");
            }
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            return java.lang.Character.toString(storage.getChar(key));
        }
    }),
    Double(new StringMapper<java.lang.Double>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            storage.setDouble(key, java.lang.Double.parseDouble(value));
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            return java.lang.Double.toString(storage.getDouble(key));
        }
    }),
    Float(new StringMapper<java.lang.Float>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            storage.setFloat(key, java.lang.Float.parseFloat(value));
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            return java.lang.Float.toString(storage.getFloat(key));
        }
    }),
    Long(new StringMapper<java.lang.Long>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            storage.setLong(key, java.lang.Long.parseLong(value));
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            return java.lang.Long.toString(storage.getLong(key));
        }
    }),
    Short(new StringMapper<java.lang.Short>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            storage.setLong(key, java.lang.Short.parseShort(value));
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            return java.lang.Short.toString(storage.getShort(key));
        }
    }),
    Color(new StringMapper<com.mdgd.storeapp.model.storage.Color>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            storage.setColor(key, new Color(value));
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            return storage.getColor(key).toString();
        }
    }),


    IntArray(new StringMapper<int[]>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            final java.lang.String[] split = value.split(",");
            final int[] arr = new int[split.length];
            for (int i = 0; i < split.length; i++) {
                arr[i] = java.lang.Integer.parseInt(split[i]);
            }
            storage.setIntArray(key, arr);
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            final StringJoiner joiner = new StringJoiner(",");
            final int[] array = storage.getIntArray(key);
            for (int v : array) {
                joiner.add(java.lang.Integer.toString(v));
            }
            return joiner.toString();
        }
    }),
    StringArray(new StringMapper<java.lang.String[]>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            final java.lang.String[] split = value.split(",");
            final String[] arr = new String[split.length];
            System.arraycopy(split, 0, arr, 0, split.length);
            storage.setStringArray(key, arr);
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            final StringJoiner joiner = new StringJoiner(",");
            final String[] array = storage.getStringArray(key);
            for (String v : array) {
                joiner.add(v);
            }
            return joiner.toString();
        }
    }),
    BoolArray(new StringMapper<boolean[]>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            final java.lang.String[] split = value.split(",");
            final boolean[] arr = new boolean[split.length];
            for (int i = 0; i < split.length; i++) {
                arr[i] = java.lang.Boolean.parseBoolean(split[i]);
            }
            storage.setBoolArray(key, arr);
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            final StringJoiner joiner = new StringJoiner(",");
            final boolean[] array = storage.getBoolArray(key);
            for (boolean v : array) {
                joiner.add(java.lang.Boolean.toString(v));
            }
            return joiner.toString();
        }
    }),
    ByteArray(new StringMapper<byte[]>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            final java.lang.String[] split = value.split(",");
            final byte[] arr = new byte[split.length];
            for (int i = 0; i < split.length; i++) {
                arr[i] = java.lang.Byte.parseByte(split[i]);
            }
            storage.setByteArray(key, arr);
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            final StringJoiner joiner = new StringJoiner(",");
            final byte[] array = storage.getByteArray(key);
            for (byte v : array) {
                joiner.add(java.lang.Byte.toString(v));
            }
            return joiner.toString();
        }
    }),
    CharArray(new StringMapper<char[]>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            final java.lang.String[] split = value.split(",");
            final char[] arr = new char[split.length];
            for (int i = 0; i < split.length; i++) {
                arr[i] = split[i].charAt(0);
            }
            storage.setCharArray(key, arr);
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            final StringJoiner joiner = new StringJoiner(",");
            final char[] array = storage.getCharArray(key);
            for (char v : array) {
                joiner.add(java.lang.Character.toString(v));
            }
            return joiner.toString();
        }
    }),
    DoubleArray(new StringMapper<double[]>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            final java.lang.String[] split = value.split(",");
            final double[] arr = new double[split.length];
            for (int i = 0; i < split.length; i++) {
                arr[i] = java.lang.Double.parseDouble(split[i]);
            }
            storage.setDoubleArray(key, arr);
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            final StringJoiner joiner = new StringJoiner(",");
            final double[] array = storage.getDoubleArray(key);
            for (double v : array) {
                joiner.add(java.lang.Double.toString(v));
            }
            return joiner.toString();
        }
    }),
    FloatArray(new StringMapper<float[]>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            final java.lang.String[] split = value.split(",");
            final float[] arr = new float[split.length];
            for (int i = 0; i < split.length; i++) {
                arr[i] = java.lang.Float.parseFloat(split[i]);
            }
            storage.setFloatArray(key, arr);
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            final StringJoiner joiner = new StringJoiner(",");
            final float[] array = storage.getFloatArray(key);
            for (float v : array) {
                joiner.add(java.lang.Float.toString(v));
            }
            return joiner.toString();
        }
    }),
    LongArray(new StringMapper<long[]>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            final java.lang.String[] split = value.split(",");
            final long[] arr = new long[split.length];
            for (int i = 0; i < split.length; i++) {
                arr[i] = java.lang.Long.parseLong(split[i]);
            }
            storage.setLongArray(key, arr);
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            final StringJoiner joiner = new StringJoiner(",");
            final long[] array = storage.getLongArray(key);
            for (long v : array) {
                joiner.add(java.lang.Long.toString(v));
            }
            return joiner.toString();
        }
    }),
    ShortArray(new StringMapper<short[]>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            final java.lang.String[] split = value.split(",");
            final short[] arr = new short[split.length];
            for (int i = 0; i < split.length; i++) {
                arr[i] = java.lang.Short.parseShort(split[i]);
            }
            storage.setShortArray(key, arr);
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            final StringJoiner joiner = new StringJoiner(",");
            final short[] array = storage.getShortArray(key);
            for (short v : array) {
                joiner.add(java.lang.Short.toString(v));
            }
            return joiner.toString();
        }
    }),
    ColorArray(new StringMapper<Color[]>() {
        @Override
        public void store(Store storage, java.lang.String key, java.lang.String value) {
            final java.lang.String[] split = value.split(",");
            final Color[] arr = new Color[split.length];
            for (int i = 0; i < split.length; i++) {
                arr[i] = new Color(split[i]);
            }
            storage.setColorArray(key, arr);
        }

        @Override
        public java.lang.String remove(Store storage, java.lang.String key) throws NotExistingKeyException, InvalidTypeException {
            final StringJoiner joiner = new StringJoiner(",");
            final Color[] array = storage.getColorArray(key);
            for (Color v : array) {
                joiner.add(v.toString());
            }
            return joiner.toString();
        }
    });


    public final StringMapper mapper;

    StoreType(StringMapper mapper) {
        this.mapper = mapper;
    }
}
