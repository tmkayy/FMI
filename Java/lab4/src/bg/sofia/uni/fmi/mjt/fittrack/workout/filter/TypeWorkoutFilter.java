package bg.sofia.uni.fmi.mjt.fittrack.workout.filter;

import bg.sofia.uni.fmi.mjt.fittrack.workout.Workout;
import bg.sofia.uni.fmi.mjt.fittrack.workout.WorkoutType;

public class TypeWorkoutFilter implements WorkoutFilter {
    private final WorkoutType workoutType;

    public TypeWorkoutFilter(WorkoutType type) {
        if (type == null) {
            throw new IllegalArgumentException("workoutType is null");
        }
        this.workoutType = type;
    }

    @Override
    public boolean matches(Workout workout) {
        if (workout == null) {
            return false;
        }
        return workoutType == workout.getType();
    }
}