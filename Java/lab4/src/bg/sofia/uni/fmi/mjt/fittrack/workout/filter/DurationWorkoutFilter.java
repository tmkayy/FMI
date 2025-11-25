package bg.sofia.uni.fmi.mjt.fittrack.workout.filter;

import bg.sofia.uni.fmi.mjt.fittrack.workout.Workout;

public class DurationWorkoutFilter implements WorkoutFilter {
    private final int min;
    private final int max;

    public DurationWorkoutFilter(int min, int max) {
        if (min < 0 || max < 0 || min > max) { // Fixed: validate in constructor
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
        int duration = workout.getDuration();
        return duration >= min && duration <= max;
    }
}