/******************************************************************************
 *   Copyright (C) 2006 Chris Lukassen
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 ******************************************************************************/
package luky.util;


import java.util.*;


/******************************************************************************
 * SortVector is a vector that you can sort
 * <p>
 *
 *  <ul>
 *   <li> 1.0.0 - Release under LGPL (a.b.c) (a=major, b=class compatible, c=api compatible)</li>
 * </ul>
 *
 * @author Chris Lukassen <lukassen@hitt.nl>
 * @version 1.0.0
 ******************************************************************************/
public class SortVector extends Vector {

    private final static long serialVersionUID = 42L;
    private Compare compare; // To hold the callback
    public SortVector(Compare comp) {
        compare = comp;
    }

    public void sort() {
        quickSort(0, size() - 1);
    }

    private void quickSort(int left, int right) {
        if (right > left) {
            Object o1 = elementAt(right);
            int i = left - 1;
            int j = right;

            while (true) {
                while (compare.lessThan(elementAt(++i), o1)) {
                    ;
                }
                while (j > 0) {
                    if (compare.lessThanOrEqual(elementAt(--j), o1)) {
                        break;
                    }
                } // out of while
                if (i >= j) {
                    break;
                }
                swap(i, j);
            }
            swap(i, right);
            quickSort(left, i - 1);
            quickSort(i + 1, right);
        }
    }

    private void swap(int loc1, int loc2) {
        Object tmp = elementAt(loc1);

        setElementAt(elementAt(loc2), loc1);
        setElementAt(tmp, loc2);
    }
} 
