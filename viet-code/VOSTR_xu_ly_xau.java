import java.util.ArrayList;

/**
 * VOSTR_xu_ly_xau
 */
public class VOSTR_xu_ly_xau {
    int[] pow = new int[1000000];

    ArrayList<Integer> makeHash(String a) {
        ArrayList<Integer> h = new ArrayList<Integer>(a.length());
        h.set(0, a.charAt(0) - 'a');
        return h;
    }

}