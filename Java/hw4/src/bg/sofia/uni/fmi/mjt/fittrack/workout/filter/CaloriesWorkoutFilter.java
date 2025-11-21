package bg.sofia.uni.fmi.mjt.fittrack.workout.filter;

import bg.sofia.uni.fmi.mjt.fittrack.workout.Workout;

public class CaloriesWorkoutFilter implements WorkoutFilter {
    private final int min;
    private final int max;

    public CaloriesWorkoutFilter(int min, int max) {
        if (min < 0 || max < 0 || min > max) {
            throw new IllegalArgumentException("Invalid min/max values");
        }
        this.min = min;
        this.max = max;
    }

    @Override
    public boolean matches(Workout workout) {
        if (workout == null) {
            return false;
        }
        int calories = workout.getCaloriesBurned();
        return calories >= min && calories <= max;
    }
}