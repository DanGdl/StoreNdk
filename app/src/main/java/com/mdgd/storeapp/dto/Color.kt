package com.mdgd.storeapp.dto

/**
 * Created by max
 * on 2/23/18.
 */

class Color(pColor: String) {
    val color: Int = android.graphics.Color.parseColor(pColor)

    override fun toString(): String {
        return String.format("#%06X", color)
    }

    override fun hashCode(): Int {
        return color
    }

    override fun equals(pOther: Any?): Boolean {
        if (this === pOther) {
            return true
        }
        if (pOther == null) {
            return false
        }
        if (javaClass != pOther.javaClass) {
            return false
        }
        val pColor = pOther as Color?
        return color == pColor!!.color
    }
}
