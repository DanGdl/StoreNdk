package com.packtub.exception;

/**
 * Created by max
 * on 2/24/18.
 */

public class StoreFullException extends RuntimeException {

    public StoreFullException(String message) {
        super(message);
    }
}
