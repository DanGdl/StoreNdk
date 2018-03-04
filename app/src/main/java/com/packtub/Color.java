package com.packtub;

/**
 * Created by max
 * on 2/23/18.
 */

public class Color {
    private int color;

    public Color(String pColor) {
        super();
        color = android.graphics.Color.parseColor(pColor);
    }

    @Override
    public String toString() {
        return String.format("#%06X", color);
    }

    public int getColor() {
        return color;
    }

    @Override
    public int hashCode() {
        return color;
    }
    @Override
    public boolean equals(Object pOther) {
        if (this == pOther) { return true; }
        if (pOther == null) { return false; }
        if (getClass() != pOther.getClass()) { return false; }
        Color pColor = (Color) pOther;
        return (color == pColor.color);
    }
}
