void main() {
    System.out.println(longestUniqueSubstring("helloworld"));
    System.out.println(minDifference(new int[]{1,2,3,4,5}));
}

//1
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

//2
public static int getSum(int[] arr) {
    int sum = 0;
    for (int num: arr) {
        sum += num;
    }
    return sum;
}

public static int minDifference(int[] tasks){
    if (tasks == null || tasks.length == 0)
        return 0;
    if (tasks.length == 1)
        return tasks[0];

    int maxSum = getSum(tasks);

    int totalSubsets = 1 << tasks.length - 1;
    int minDiff = Integer.MAX_VALUE;

    for (int mask = 1; mask < totalSubsets; mask++) {
        int firstTeamSum = 0;

        for (int i = 0; i < tasks.length; i++) {
            if ((mask & (1 << i)) != 0) {
                firstTeamSum += tasks[i];
            }
        }
        int secondTeamSum = maxSum - firstTeamSum;
        minDiff = Math.min(Math.abs(firstTeamSum - secondTeamSum), minDiff);
    }
    return minDiff;
}