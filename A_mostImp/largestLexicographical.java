/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class GFG {
    public static void largestString(String str, int k) {
        StringBuilder st = new StringBuilder();
        for (char i : str.toCharArray()) {
            while (st.length() > 0 && st.charAt(st.length() - 1) < i && k > 0) {
                int n = st.length();
                st.deleteCharAt(n - 1);
                k--;
            }

            st.append(i);
        }

        //remove remaining elements when k>0
        while (st.length() > 0 && k-- > 0) {
            st.deleteCharAt(st.length() - 1);
        }

        System.out.println(st.toString());
    }

    public static void main (String[] args) {
        String str = "zyxedcba";
        int k = 1;

        largestString(str, k);

    }
}