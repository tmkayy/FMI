public class TaskDistributor {
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
}
