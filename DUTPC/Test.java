import java.util.HashSet;

public class Test {
    public int countConsistentStrings(String allowed, String[] words) {
        HashSet<String> h = new HashSet<>();

        String[] allowCh = allowed.split("");

        for (int i = 0; i < allowCh.length; i++) {
            h.add(allowCh[i]);
        }
        int count = 0;
        for (String word : words) {
            boolean isAllow = true;
            for (int i = 0; i < word.length(); i++) {
                if (!h.contains(word.charAt(i) + ""))
                    isAllow = false;
            }
            if (isAllow) {
                count++;
                break;
            }
        }
        return count;
    }

    public static void main(String[] args) {

    }
}
