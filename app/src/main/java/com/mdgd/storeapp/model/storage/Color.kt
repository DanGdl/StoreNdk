package com.mdgd.storeapp.model.storage

/**
 * Created by max
 * on 2/23/18.
 */
class Color(pColor: String) {
    val color: Int = android.graphics.Color.parseColor(pColor)

    override fun toString() = String.format("#%06X", color)

    override fun hashCode() = color

    override fun equals(other: Any?): Boolean {
        if (this === other) {
            return true
        }
        if (other == null) {
            return false
        }
        if (javaClass != other.javaClass) {
            return false
        }
        val pColor = other as Color?
        return color == pColor!!.color
    }
}
