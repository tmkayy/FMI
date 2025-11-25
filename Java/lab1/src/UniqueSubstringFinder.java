public class UniqueSubstringFinder {
    public static String longestUniqueSubstring(String s){
        int maxLen = 0;
        int maxStart = 0;
        for(int i = 0; i < s.length(); i++){
            boolean[] found = new boolean[26];
            int currLen = 0;
            for(int j = i; j < s.length(); j++){
                int idx = s.charAt(j) - 'a';
                if(!found[idx]) {
                    currLen++;
                    found[idx] = true;
                }
                else
                    break;
            }
            if(currLen > maxLen){
                maxLen = currLen;
                maxStart = i;
            }
        }
        return s.substring(maxStart, maxStart + maxLen);
    }
}
