package bg.sofia.uni.fmi.mjt.fittrack.workout.filter;

import bg.sofia.uni.fmi.mjt.fittrack.workout.Workout;
import bg.sofia.uni.fmi.mjt.fittrack.workout.WorkoutType;

public class TypeWorkoutFilter implements WorkoutFilter {
    private WorkoutType workoutType;

    public WorkoutType getWorkoutType() {
        return workoutType;
    }

    public void setWorkoutType(WorkoutType workoutType) {
        if(workoutType == null){
            throw new IllegalArgumentException("workoutType is null");
        }
        this.workoutType = workoutType;
    }

    public TypeWorkoutFilter(WorkoutType type){
        setWorkoutType(type);
    }

    @Override
    public boolean matches(Workout workout) {
        if(workout == null){
            throw new IllegalArgumentException("workout is null");
        }

        return workoutType == workout.getType();
    }
}
