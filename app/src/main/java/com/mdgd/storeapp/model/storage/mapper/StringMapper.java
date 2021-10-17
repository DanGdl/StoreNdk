package com.mdgd.storeapp.model.storage.mapper;

import com.mdgd.storeapp.model.storage.Store;
import com.mdgd.storeapp.model.storage.exception.InvalidTypeException;
import com.mdgd.storeapp.model.storage.exception.NotExistingKeyException;

public interface StringMapper<T> {

    void store(Store storage, String key, String value);

    String remove(Store storage, String key) throws NotExistingKeyException, InvalidTypeException;
}
